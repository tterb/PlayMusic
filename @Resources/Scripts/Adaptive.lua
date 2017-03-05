-- ## Information ##############################################################
-- Filename: Adaptive.lua
-- Project: PlayMusic
-- Author: Brett Stevenson
-- Version: v1.2.1
-- License: GNU AGPLv3.0
-- Updated: March 1, 2017
-- Copyright (c) 2016 Brett Stevenson
-- #############################################################################


-- ## Description ##############################################################
-- This Lua script allows for the optimization of the adaptive functionalities
-- of PlayMusic by analyzing and selecting the best color collected from the
-- active album artwork.
-- #############################################################################


function Initialize()
    ForegroundMeasure = SKIN:GetMeasure('ColorForeground')
    BackgroundMeasure = SKIN:GetMeasure('ColorBackground')
    currentF = ForegroundMeasure:GetOption('Color')
    currentB = BackgroundMeasure:GetOption('Color')
    SKIN:Bang('!SetOption', ForegroundMeasure, 'Color', 'Foreground2')
    SKIN:Bang('!SetOption', BackgroundMeasure, 'Color', 'Background2')
    -- Update()
end


function Update()
    local foreground1 = SELF:GetOption('foreground')
    local background1 = SELF:GetOption('background')
    local foreground2 = SELF:GetOption('foreground2')
    local background2 = SELF:GetOption('background2')
    local foreground3 = SELF:GetOption('foreground3')
    local background3 = SELF:GetOption('background3')
    local average = SELF:GetOption('average')
    -- if (analyze(foreground1, foreground2) == foreground1) then
    --     foreground = 'Foreground2'
    -- else
    --     foreground = 'Light1'
    -- end
    -- if (analyze(background1, background2) == background1) then
    --     background = 'Background2'
    -- else
    --     background = 'Dark1'
    -- end
    local H1,S1,L1 = RGBtoHSL(HextoRGB(foreground1))
    local H2,S2,L2 = RGBtoHSL(HextoRGB(background1))
    local H3,S3,L3 = RGBtoHSL(HextoRGB(foreground2))
    local H4,S4,L4 = RGBtoHSL(HextoRGB(background2))
    local H5,S5,L5 = RGBtoHSL(HextoRGB(foreground3))
    local H6,S6,L6 = RGBtoHSL(HextoRGB(background3))
    print('foreground1 - '..H1..','..S1..','..L1)
    print('background1 - '..H2..','..S2..','..L2)
    print('foreground2 - '..H3..','..S3..','..L3)
    print('background2 - '..H4..','..S4..','..L4)
    print('foreground3 - '..H5..','..S5..','..L5)
    print('background3 - '..H6..','..S6..','..L6)

    local foreground = analyze(foreground3, analyze(foreground1, foreground2))
    local background = analyze(background3, analyze(background1, background2))
    -- if(foreground == background)

    SKIN:Bang('!WriteKeyValue', 'Variables', 'foregroundColor', tostring(foreground))
    SKIN:Bang('!WriteKeyValue', 'Variables', 'backgroundColor', tostring(background))
end

-- Returns the preferable accent color
function analyze(color1, color2)
    if(color1 == '') or (color2 == '') then
        return
    end
    local H1,S1,L1 = RGBtoHSL(HextoRGB(color1))
    local H2,S2,L2 = RGBtoHSL(HextoRGB(color2))

    if (H1 == 0) and (L1 == 0) then
        -- too dark
        return color2
    elseif (H2 == 0) and (L2 == 0) then
        -- too dark
        return color1
    end
    if (S1 == S2) then
        if (L1 > L2) then
            return color1
        else
            return color2
        end
    elseif (S1 > S2) then
        return color1
    else
        return color2
    end
end

-- Convert Hex to RGB
function HextoRGB(hex)
    hex = hex:gsub("#","")
    if(string.len(hex) == 3) then
        return tonumber("0x"..hex:sub(1,1)) * 17, tonumber("0x"..hex:sub(2,2)) * 17, tonumber("0x"..hex:sub(3,3)) * 17
    elseif(string.len(hex) == 6) then
        return tonumber("0x"..hex:sub(1,2)), tonumber("0x"..hex:sub(3,4)), tonumber("0x"..hex:sub(5,6))
    end
end

-- Convert RGB to HSL
function RGBtoHSL(r,g,b)
    r = tonumber(r)/255
    g = tonumber(g)/255
    b = tonumber(b)/255
    local max = math.max(r,g,b)
    local min = math.min(r,g,b)
    local h, s, l
    l = (max + min)/2
    if (max == min) then
        -- achromatic
        h = 0
        s = 0
    else
        local d = max - min
        if (l > 0.5) then
            s = (d / (2 - max - min))
        else
            s = (d / (max + min))
        end
        if (r == max) then
            h = (g - b) / d
            if (g < b) then
                h = h + 6
            end
        elseif (g == max) then
            h = ((b - r) / d + 2)
        else
            h = ((r - g) / d + 4)
        end
    end
    h = h/6
    return h,s,l
end

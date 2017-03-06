-- ## Information ##############################################################
-- Filename: Adaptive.lua
-- Project: PlayMusic
-- Author: Brett Stevenson
-- Version: v1.2.2
-- License: GNU AGPLv3.0
-- Updated: March 5, 2017
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
    Update()
end


function Update()
    local foreground1 = SELF:GetOption('foreground')
    local background1 = SELF:GetOption('background')
    local foreground2 = SELF:GetOption('foreground2')
    local background2 = SELF:GetOption('background2')
    local foreground3 = SELF:GetOption('foreground3')
    local background3 = SELF:GetOption('background3')
    local average = SELF:GetOption('average')
    -- logs for debugging
    -- local H1,S1,L1 = RGBtoHSL(HextoRGB(foreground1))
    -- local H2,S2,L2 = RGBtoHSL(HextoRGB(background1))
    -- local H3,S3,L3 = RGBtoHSL(HextoRGB(foreground2))
    -- local H4,S4,L4 = RGBtoHSL(HextoRGB(background2))
    -- local H5,S5,L5 = RGBtoHSL(HextoRGB(foreground3))
    -- local H6,S6,L6 = RGBtoHSL(HextoRGB(background3))
    -- print('foreground2 - '..H1..','..S1..','..L1)
    -- print('background2 - '..H2..','..S2..','..L2)
    -- print('light1 - '..H5..','..S5..','..L5)
    -- print('dark1 - '..H6..','..S6..','..L6)
    -- print('light2 - '..H3..','..S3..','..L3)
    -- print('dark2 - '..H4..','..S4..','..L4)
    local foreground = foreground(foreground3, foreground(foreground1, foreground2))
    local background = background(background3, background(background1, background2, foreground), foreground)
    SKIN:Bang('!WriteKeyValue', 'Variables', 'foregroundColor', tostring(foreground))
    SKIN:Bang('!WriteKeyValue', 'Variables', 'backgroundColor', tostring(background))
end

-- Returns the preferable accent color
function background(color1, color2, foreground)
    -- if(color1 == '') or (color2 == '') or (foreground = '') then
    --     return
    -- end
    local H1,S1,L1 = RGBtoHSL(HextoRGB(color1))
    local H2,S2,L2 = RGBtoHSL(HextoRGB(color2))
    local H3,S3,L3 = RGBtoHSL(HextoRGB(foreground))

    -- check that color isn't too dark
    if (L1 < 0.15) and (L2 < 0.15) then
        return 'EDEDED'
    elseif (L1 < 0.15) then
        return color2
    elseif (L2 < 0.15) then
        return color1
    end
    -- contrast with foreground color
    if (math.abs(H1 - H3) < 0.004) or (math.abs(H2 - H3) < 0.004) then
        if (math.abs(H1 - H3) < math.abs(H2 - H3)) then
            return color2
        else
            return color1
        end
    end
    if (S1 == S2) then
        if (L1 > L2) then
            return color1
        else
            return color2
        end
    elseif (S1 < S2) then
        return color2
    else
        return color1
    end
end

function foreground(color1, color2)
    -- if(color1 == '') or (color2 == '') then
    --     return
    -- end
    local H1,S1,L1 = RGBtoHSL(HextoRGB(color1))
    local H2,S2,L2 = RGBtoHSL(HextoRGB(color2))

    -- check that color isn't too light or too dark
    if (L1 < 0.23) and (L2 < 0.23) then
        return 'EDEDED'
    elseif (L1 < 0.23) or (L1 > 0.9) then
        return color2
    elseif (L2 < 0.23) or (L2 > 0.9) then
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

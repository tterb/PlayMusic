-- ## Information ##############################################################
-- Filename: Config.lua
-- Project: PlayMusic
-- Author: Brett Stevenson
-- License: BSD 3-Clause
-- Updated: Dec 30, 2016
-- #############################################################################

-- ## Description ##############################################################
-- This is the Lua script which allows the PlayMusic skin to read and write the 
-- user's settings to 'settings.txt'
-- #############################################################################


function Initialize()
	path = SELF:GetOption('WriteTo')
	Update()
end

function Update()
	local file = io.open(path, "r")
	io.input(file)
	data = io.read("*all")
	return tostring(data)
end

function Write()
	local file = io.open(path, "w")
	local variant = SELF:GetOption('Input1')
	local minimize = SELF:GetOption('Input2')
	local icon = SELF:GetOption('Input3')
	SKIN:Bang('!SetVariable', 'Minimize', 1)
	io.output(file)
	io.write("variant: ")
	io.write(tostring(variant))
	io.write("\nminimize: ")
	io.write(tostring(minimize))
	io.write("\nIcon style: ")
	io.write(tostring(icon))
	io.close(file)
	if(tonumber(minimize) > 0) then
		SKIN:Bang('!SetVariable', 'Minimize', 1)
	else
		SKIN:Bang('!SetVariable', 'Minimize', 0)
	end
	return tostring(minimize)
end

;PlayMusic/@Resources/ConfigStyles.inc

[Variables]
@include2=#@#Variables.inc
GPMDPPath="%HOMEDRIVE%%HOMEPATH%\AppData\Local\GPMDP_3\Update.exe --processStart Google%20Play%20Music%20Desktop%20Player.exe"
SpotifyPath="%HOMEDRIVE%%HOMEPATH%"\AppData\Roaming\Spotify\Spotify.exe"
;White
color1=FFFFFFD9
;Cyan
color2=00BCD4E1
;Light Orange
color3=FF9800E1
;Purple
color4=673AB7B5
;Teal
color5=008A9EEE
;Light Green
color6=689F38EE
;Pink
color7=F94E73E2
;Yellow
color8=FFDE00E6
;Green
color9=43A047EE
;Red
color10=E53935E8
;Indigo
color11=3F51B5E8
;Orange
color12=FA5722EA


[HeadingText]
FontSize=24
FontFace=Open Sans
FontColor=230,90,0,190
StringEffect=Shadow
FontEffectColor= 0,0,0,20
X=64
Y=171
ClipString=2
AntiAlias=1

[SubHeading]
FontSize=17
FontFace=Segoe UI Historic
FontColor=0,0,0,185
StringStyle=Bold
X=83
Y=190
ClipString=2
AntiAlias=1

[BodyText]
FontFace=Open Sans
FontSize=11
FontColor=0,0,0,200
StringStyle=Normal
InlineSetting=CharacterSpacing | -0.25
X=5R
Y=r
ClipString=2
AntiAlias=1

[SubtleText]
FontFace=Open Sans
FontSize=9
FontColor=0,0,0,115
Y=2r
ClipString=2
AntiAlias=1

[InputText]
FontFace=Open Sans
FontSize=11
FontColor=0,0,0,175
DynamicVariables=1
ClipString=2
AntiAlias=1

[ToggleStyle]
X=75
Y=35r
H=20
PreserveAspectRatio=1
DynamicVariables=1
AntiAlias=1

[ColorOption]
Group=PageTwo
X=1R
Y=r
H=40
W=40
Hidden=1

[PageIcons]
X=r
Y=35R
H=20
PreserveAspectRatio=1
AntiAlias=1

[IconStyle]
ImageTint=#accent#
H=58
PreserveAspectRatio=1
LeftMouseUpAction=[!WriteKeyValue Variables icon #@#Images\headphoneIcon.png "#ROOTCONFIGPATH#\PlayMusic(Square).ini"][!WriteKeyValue Variables  icon #@#Images\headphoneIcon.png "#ROOTCONFIGPATH#\PlayMusic(Landscape).ini"][!WriteKeyValue Variables icon #@#Images\headphoneIcon.png "#ROOTCONFIGPATH#\Settings\Settings.ini"][!SetOption icon2 "(1-#icon2#)"][!SetVariable icon2 "(1-#icon2#)"][!SetVariable icon1 "(1-#icon1#)"][!SetVariable icon1 "(1-#icon1#)"][!CommandMeasure MeasureLuaScript "Write()"][!UpdateMeasure MeasureButton][!Refresh PlayMusic][!Refresh PlayMusic\Settings]

[BorderStyle]
SolidColor=190,190,190, 140
X=60
H=1
W=336

[IconButton]
H=72
W=72
DynamicVariables=1
AntiAlias=1

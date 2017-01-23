;PlayMusic/@Resources/ConfigStyles.inc

[Variables]
;White
color1=FFFFFFB9
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


[SubHeading]
FontSize=16
FontFace=Segoe UI
FontColor=0,0,0,170
X=83
Y=200
ClipString=2
AntiAlias=1

[BodyText]
FontFace=Segoe UI
FontSize=12
FontColor=30,30,30,240
StringStyle=Normal
StringEffect=Shadow
FontEffectColor = 0,0,0,0
X=3R
ClipString=2
AntiAlias=1

[Checkbox]
FontSize=11
FontColor=40,40,40,255
SolidColor=0,0,0,0
Padding=5,5,5,5
X=100
DynamicVariables=1
AntiAlias=1

[ColorOption]
Group=StylePage
H=40
W=40
X=1R
Y=r
Hidden=1

[PageIcons]
X=379
H=20
PreserveAspectRatio=1
AntiAlias=1

[IconStyle]
ImageTint=#accent#
PreserveAspectRatio=1
H=60
LeftMouseUpAction=[!WriteKeyValue Variables icon #@#images\headphoneIcon.png "#ROOTCONFIGPATH#\PlayMusic(Square).ini"][!WriteKeyValue Variables  icon #@#images\headphoneIcon.png "#ROOTCONFIGPATH#\PlayMusic(Landscape).ini"][!WriteKeyValue Variables icon #@#images\headphoneIcon.png "#ROOTCONFIGPATH#\Settings\Settings.ini"][!SetOption icon2 "(1-#icon2#)"][!SetVariable icon2 "(1-#icon2#)"][!SetVariable icon1 "(1-#icon1#)"][!SetVariable icon1 "(1-#icon1#)"][!CommandMeasure MeasureLuaScript "Write()"][!UpdateMeasure MeasureButton][!Refresh PlayMusic][!Refresh PlayMusic\Settings]

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

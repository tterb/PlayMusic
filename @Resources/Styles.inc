;PlayMusic/@Resources/Styles.inc

[Variables]
@include=#@#Variables.inc
MeterTitleName=MeterTitle
MeterArtistName=MeterArtist
MeterAlbumName=MeterAlbum
MeterCurrentTime=MeterTime
StatusImg=#@#Images\play.png
AppPath="%HOMEDRIVE%%HOMEPATH%\AppData\Local\GPMDP_3\Update.exe --processStart Google%20Play%20Music%20Desktop%20Player.exe"
PlaybackPath="%HOMEDRIVE%%HOMEPATH%\AppData\Roaming\Google Play Music Desktop Player\json_store\playback.json"
DesktopSettingsPath="%HOMEDRIVE%%HOMEPATH%\AppData\Roaming\Google Play Music Desktop Player\json_store\.settings.json"

[TextStyle]
FontFace=Roboto
FontSize=(#size#*2.85)
FontColor=255,255,255,250
StringEffect=Shadow
FontEffectColor=0,0,0,245
X=(#size#*20.4)
W=(#size#*35)
ClipString=1
DynamicVariables=1
AntiAlias=1
UpdateRate=100

[SquareText]
FontFace=Roboto
FontSize=(#size#*2.75)
FontColor=255,255,255,255
StringEffect=Shadow
FontEffectColor=0,0,0,255
X=(#size#*1.5)+((#size#-5)*2)
W=(#size#*28.75)
ClipString=1
DynamicVariables=1
AntiAlias=1
UpdateRate=100

[RoundText]
FontFace=Roboto
FontSize=(#size#*2.85)
FontColor=255,255,255,250
StringEffect=Shadow
FontEffectColor=0,0,0,245
; X=(#size#*(3.3+#align#))
W=(#size#*34.7)
ClipString=1
DynamicVariables=1
AntiAlias=1
UpdateRate=100

[Status]
ImageTint=245,245,245
PreserveAspectRatio=1
X=(#size#*57.6)
H=(#size#*4.9)
UpdateRate=100

[TimeStyle]
Group=Active
BarOrientation=HORIZONTAL
MaxValue=100
SolidColor=225,225,225,75
BarColor=#accent#
X=(#size#*0.2)
H=(#size#*0.9)
BackgroundMode=3
DynamicVariables=1
AntiAlias=1
UpdateRate=50

[VisualizerStyle]
Group=Active | Visualizer
BarOrientation=Vertical
BarColor=[ColorForeground2]
X=3R
Y=r
W=#BarWidthScale#
H=#BarHeightScale#
DynamicVariables=1
AntiAlias=1
UpdateRate=40

[RoundVisStyle]
Group=Active | Visualizer
BarOrientation=Vertical
BarColor=[ColorForeground2]
X=(#barWidth#-1.5)R
Y=r
W=#BarWidthScale#
H=#BarHeightScale#
DynamicVariables=1
AntiAlias=1
UpdateRate=30

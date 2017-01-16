;PlayMusic/@Resources/Styles.inc

[Variables]
MeterTitleName=MeterTitle
MeterArtistName=MeterArtist
MeterAlbumName=MeterAlbum
MeterCurrentTime=MeterTime
StatusImg=#@#images\play.png
AppPath="C:%HOMEPATH%\AppData\Local\GPMDP_3\Update.exe --processStart Google%20Play%20Music%20Desktop%20Player.exe"
PlaybackPath="C:%HOMEPATH%\AppData\Roaming\Google Play Music Desktop Player\json_store\playback.json"
SettingsPath="C:%HOMEPATH%\AppData\Roaming\Google Play Music Desktop Player\json_store\.settings.json"

[TextStyle]
FontFace=Segoe UI
FontSize=12
FontColor=255,255,255,250
StringEffect=Shadow
FontEffectColor=0,0,0,245
X=(#size#*21.1)
H=(#size#*4.4)
W=(#size#*34.7)
ClipString=1
DynamicVariables=1
AntiAlias=1

[SquareText]
FontFace=Segoe UI
FontSize=12
FontColor=255,255,255,255
StringEffect=Shadow
FontEffectColor=0,0,0,255
X=(#size#*32.7)
H=(#size#*4.4)
W=(#size#*27.1)
ClipString=1
DynamicVariables=1
AntiAlias=1

[Status]
ImageTint=245,245,245
PreserveAspectRatio=1
X=(#size#*56.4)
H=(#size#*4.9)

[TimeStyle]
BarOrientation=HORIZONTAL
MaxValue=100
SolidColor=225,225,225,75
BarColor=#accent#
X=(#size#*0.2)
H=(#size#*0.9)
BackgroundMode=3
DynamicVariables=1
AntiAlias=1

[VisualizerStyle]
Group=Active | Visualizer
BarColor=255,255,255,90
X=(3*#Scale#)R
Y=r
W=#BarWidthScale#
H=#BarHeightScale#
BarOrientation=Vertical

;PlayMusic/@Resources/Styles.inc

[Variables]
MeterTitleName=MeterTitle
MeterArtistName=MeterArtist
MeterAlbumName=MeterAlbum
MeterCurrentTime=MeterTime
StatusImg=#@#Images\play.png
PlaybackPath="%HOMEDRIVE%%HOMEPATH%\AppData\Roaming\Google Play Music Desktop Player\json_store\playback.json"
DesktopSettingsPath="%HOMEDRIVE%%HOMEPATH%\AppData\Roaming\Google Play Music Desktop Player\json_store\.settings.json"

[TextStyle]
FontFace=Open Sans
FontSize=(#Size#*2.85)
FontColor=255,255,255,250
StringEffect=Shadow
FontEffectColor=0,0,0,245
X=(#Size#*20.7)
W=(#Size#*35)
ClipString=1
DynamicVariables=1
AntiAlias=1

[SquareText]
FontFace=Open Sans
FontSize=(#Size#*2.75)
FontColor=255,255,255,255
StringEffect=Shadow
FontEffectColor=0,0,0,255
X=(#SkinWidth#/17)
W=(#Size#*29.5)
ClipString=1
DynamicVariables=1
AntiAlias=1

[RoundText]
FontFace=Open Sans
FontSize=(#Size#*2.85)
FontColor=255,255,255,250
StringEffect=Shadow
FontEffectColor=0,0,0,245
; X=(#Size#*(3.3+#align#))
W=(#Size#*34.7)
ClipString=1
DynamicVariables=1
AntiAlias=1

[Status]
ImageTint=245,245,245
PreserveAspectRatio=1
X=(#Size#*57.6)
H=(#Size#*4.9)

[TimeStyle]
Group=Active
BarOrientation=HORIZONTAL
MaxValue=100
SolidColor=225,225,225,75
BarColor=#accent#
X=(#Size#*0.2)
H=(#Size#*0.9)
; BackgroundMode=3
DynamicVariables=1
UpdateDivider=1
AntiAlias=1

[VisualizerStyle]
Group=Active | Visualizer
BarOrientation=Vertical
BarColor=[ColorForeground2]
X=(#bandSpace#)R
Y=r
W=#BarWidth#
H=#BarHeight#
DynamicVariables=1
; UpdateRate=40
UpdateDivider=1
AntiAlias=1

[RoundVisStyle]
Group=Active | Visualizer
BarOrientation=Vertical
BarColor=[ColorForeground2]
; X=((#SkinWidth#)/69)R
X=(#RoundBarWidth#-0.5)R
; X=3.75R
Y=r
W=#RoundBarWidth#
H=#BarHeightScale#
DynamicVariables=1
; UpdateRate=30
UpdateDivider=1
AntiAlias=1

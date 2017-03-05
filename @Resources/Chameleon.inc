; Chameleon stuff!
[MeasureCoverColors]
Measure=Calc
Formula=1
IfAboveValue=0
IfAboveAction=[!SetOption ColorBackground Parent "ChameleonNowPlaying"][!SetOption ColorForeground Parent "ChameleonNowPlaying"][!SetVariable ColorForeground ColorForeground][!SetVariable ColorBackground ColorBackground#][!Redraw]
UpdateDivider=-1

[ChameleonNowPlaying]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=#SKINSPATH#PlayMusic\DownloadFile\image.jpg
; Path=[MeterArtwork]
UpdateDivider=100

[ColorForeground1]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Foreground1
; Substitute="":"#Foreground#","0,0,0":"#Foreground#"

[ColorBackground1]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Background1
; Substitute="":"#Background#","255,255,255":"#Background#"

[ColorForeground2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Foreground2

[ColorBackground2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Background2
; Substitute="":"#Background#","255,255,255":"#Background#"

[ColorAvg]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Average

[ColorLight1]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light1

[ColorDark1]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark1

[ColorLight2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light2

[ColorDark2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark2

[ColorLight3]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light3

[ColorDark3]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark3

[ColorLight4]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light4

[ColorDark4]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark4

[ColorLuminance]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Luminance

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

[ColorBackground]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Background1
; Substitute="":"#Background#","255,255,255":"#Background#"

[ColorBackground2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Background2
; Substitute="":"#Background#","255,255,255":"#Background#"

[ColorForeground]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Foreground1
; Substitute="":"#Foreground#","0,0,0":"#Foreground#"

[ColorForeground2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Foreground2

[ColorAvg]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Average

[ColorDark]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark1

[ColorDark2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark2

[ColorDark3]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark3

[ColorDark4]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Dark4

[ColorLight]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light1

[ColorLight2]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light2

[ColorLight3]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light3

[ColorLight4]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Light4

[ColorLuminance]
Measure=Plugin
Plugin=Chameleon
Parent=ChameleonNowPlaying
Format=Hex
Color=Luminance

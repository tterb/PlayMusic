[MeasureLuaScript]
Measure=Script
ScriptFile=#@#Scripts\GPMDP.lua
JSONParser=#@#Scripts\JSON.lua
Playback=#PlaybackPath#
Settings=#DesktopSettingsPath#
WriteFile="#@#settings.txt"
UpdateDivider=10

[MeasureAdaptiveScript]
Measure=Script
ScriptFile=#@#Scripts\Adaptive.lua
foreground=[ColorForeground2]
background=[ColorBackground2]
foreground2=[ColorLight2]
background2=[ColorDark2]
foreground3=[ColorLight1]
background3=[ColorDark1]
average=[ColorAvg]
UpdateRate=80

[MeasureJSON]
Measure=Plugin
Plugin=WebParser
URL=file://#PlaybackPath#
RegExp=(?siU)"song.*songLyrics": (.*)"shuffle": "(.*)".*repeat": "(.*)"
UpdateDivider=5

[MeasurePlaybackAPI]
Measure=String
String=#EnabledPlaybackAPI#
IfMatch=true
IfNotMatchAction=[!HideMeterGroup Active][!ShowMeter Background][!ShowMeter MeterPlaybackPrompt]
DynamicVariables=1
UpdateDivider=10

[MeasureImageDownload]
Measure=Plugin
Plugin=WebParser
URL=#AlbumArtUrl#
Download=1
DownloadFile=image.jpg
DynamicVariables=1
UpdateDivider=10

[MeasureArtwork]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Cover
DefaultPath=#@#Images\nocover.png
CoverPath=#@#Images\cover.png
UpdateDivider=20

[MeasureRepeat]
Measure=Plugin
Plugin=WebParser
URL=[MeasureJSON]
StringIndex=2
IfMatch=NO_REPEAT
IfMatchAction=[!SetOption MeterRepeat ImageAlpha 125][!Redraw]
IfNotMatchAction=[!SetOption MeterRepeat ImageAlpha 255][!Redraw]
DynamicVariables=1
UpdateDivider=15

[MeasureShuffle]
Measure=Plugin
Plugin=WebParser
URL=[MeasureJSON]
StringIndex=1
IfMatch=NO_SHUFFLE
IfMatchAction=[!SetOption MeterShuffle ImageAlpha 125][!Redraw]
IfNotMatchAction=[!SetOption MeterShuffle ImageAlpha 255][!Redraw]
DynamicVariables=1
UpdateDivider=15

[HideActive]
Measure=Calc
Formula=#GPMDPOpen#
IfEqualValue=0
IfEqualAction=[!HideMeterGroup Active][!ShowMeterGroup Icon][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup Active][!HideMeterGroup Icon][!UpdateMeter *][!Redraw]
DynamicVariables=1
UpdateDivider=5

[MeasureTime]
Measure=Calc
Formula=#Length#
DynamicVariables=1

[MeasureVolumeControl]
Measure=Calc
Formula=#EnableVolumeControl#
IfEqualValue=0
IfEqualAction=[!DisableMeasure MeasureVolume][!DisableMeasure MeasureVolumeValue][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!EnableMeasure MeasureVolume][!EnableMeasure MeasureVolumeValue][!UpdateMeter *][!Redraw]

[MeasureVolume]
Measure=Plugin
Plugin=Win7AudioPlugin

[MeasureVolumeValue]
Measure=CALC
Formula=MeasureVolume
Substitute="-1":"Muted"

[MeasureAudio]
Measure=Plugin
Plugin=AudioLevel
Port=Output
FFTSize=#FFTSize#
FFTOverlap=#FFTOverlap#
FFTAttack=#FFTAttack#
FFTDecay=#FFTDecay#
RMSAttack=10
RMSDecay=1000
RMSGain=20
Bands=#bandCount#
Sensitivity=([MeasureAverageVolume]*([MeasureAverageVolume]*38))
FreqMin=40
FreqMax=12000
DynamicVariables=1

[MeasureAudioAverage]
Measure=Plugin
Plugin=AudioLevel
Port=Output
RMSAttack=10
RMSDecay=2500
RMSGain=1000
Sensitivity=100
FreqMin=20
FreqMax=18000
DynamicVariables=1

[MeasureAverageVolume]
Measure=Plugin
Plugin=AudioLevel
Parent=MeasureAudioAverage
Channel=Avg
Type=RMS

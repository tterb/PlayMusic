[MeasureLuaScript]
Measure=Script
ScriptFile=#@#Scripts\GPMDP.lua
JSONParser=#@#Scripts\JSON.lua
Playback=#PlaybackPath#
Settings=#DesktopSettingsPath#
WriteFile="#@#settings.txt"
UpdateDivider=5

[MeasureAdaptiveScript]
Measure=Script
ScriptFile=#@#Scripts\Adaptive.lua
foreground=[ColorLight1]
background=[ColorBackground2]
foreground2=[ColorLight2]
background2=[ColorDark2]
foreground3=[ColorLight3]
background3=[ColorDark1]
average=[ColorAvg]
UpdateDivider=45

[MeasureJSON]
Measure=Plugin
Plugin=WebParser
URL=file://#PlaybackPath#
RegExp=(?siU)"song.*songLyrics": (.*)"shuffle": "(.*)".*repeat": "(.*)"
UpdateDivider=25

[MeasurePlaybackAPI]
Measure=String
String=#EnabledPlaybackAPI#
IfMatch=true
IfNotMatchAction=[!HideMeterGroup Active][!ShowMeter Background][!ShowMeter MeterPlaybackPrompt]
DynamicVariables=1
UpdateDivider=-1

[MeasureImageDownload]
Measure=Plugin
Plugin=WebParser
URL=#AlbumArtUrl#
Download=1
DownloadFile=image.jpg
DynamicVariables=1
UpdateDivider=-1

[MeasureArtwork]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Cover
DefaultPath=#@#Images\nocover.png
CoverPath=#@#Images\cover.png
UpdateDivider=20

; [MeasureShuffle]
; Measure=Plugin
; Plugin=WebParser
; URL=[MeasureJSON]
; StringIndex=2
; IfMatch=NO_SHUFFLE
; IfMatchAction=[!SetOption MeterShuffle ImageAlpha 75][!UpdateMeter MeterShuffle][!Redraw]
; IfNotMatchAction=[!SetOption MeterShuffle ImageAlpha 245][!UpdateMeter MeterShuffle][!Redraw]
; DynamicVariables=1
; UpdateDivider=25

; [MeasureRepeat]
; Measure=Plugin
; Plugin=WebParser
; URL=[MeasureJSON]
; StringIndex=3
; IfMatch=NO_REPEAT
; IfMatchAction=[!SetOption MeterRepeat ImageAlpha 75][UpdateMeter MeterRepeat][!Redraw]
; IfNotMatchAction=[!SetOption MeterRepeat ImageAlpha 240][UpdateMeter MeterRepeat][!Redraw]
; DynamicVariables=1
; UpdateDivider=25

[MeasureRepeat]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Repeat
IfEqualValue=0
IfEqualAction=[!SetOption MeterRepeat ImageAlpha 75][!UpdateMeter MeterRepeat][!Redraw]
IfAboveValue=0
IfAboveAction=[!SetOption MeterRepeat ImageAlpha 240][!UpdateMeter MeterRepeat][!Redraw]
DynamicVariables=1

[MeasureShuffle]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Shuffle
IfEqualValue=0
IfEqualAction=[!SetOption MeterShuffle ImageAlpha 75][!UpdateMeter MeterRepeat][!Redraw]
IfAboveValue=0
IfAboveAction=[!SetOption MeterShuffle ImageAlpha 240][!UpdateMeter MeterRepeat][!Redraw]
DynamicVariables=1

[MeasureShowVisualizer]
Measure=Calc
Formula=#showVisualizer#
IfEqualValue=0
IfEqualAction=[!HideMeterGroup Visualizer][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup Visualizer][!UpdateMeter *][!Redraw]
DynamicVariables=1

[HideActive]
Measure=Calc
; Formula=#GPMDPOpen#
Formula=[MeasureState]
IfEqualValue=0
IfEqualAction=[!HideMeterGroup Active][!HideMeterGroup Visualizer][!ShowMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup Active][!ShowMeterGroup Visualizer][!HideMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
DynamicVariables=1
UpdateDivider=25

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
UpdateDivider=5

[MeasureVolume]
Measure=Plugin
Plugin=Win7AudioPlugin

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
Bands=#BandCount#
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

[MeasureStatus]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Status
DynamicVariables=1

[MeasureState]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=State
Formula=[MeasureState]
IfEqualValue=0
IfEqualAction=[!HideMeterGroup Active][!HideMeterGroup Visualizer][!ShowMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup Active][!ShowMeterGroup Visualizer][!HideMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
DynamicVariables=1

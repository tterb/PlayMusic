[MeasureStatus]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Status
DynamicVariables=1

[MeasureState]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=State
DynamicVariables=1

[MeasureLuaScript]
Measure=Script
ScriptFile=#@#Scripts\GPMDP.lua
JSONParser=#@#Scripts\JSON.lua
Playback=#PlaybackPath#
Settings=#DesktopSettingsPath#
WriteFile="#@#settings.txt"
UpdateDivider=5

; [MeasureAdaptiveScript]
; Measure=Script
; ScriptFile=#@#Scripts\Adaptive.lua
; foreground=[ColorLight1]
; background=[ColorBackground2]
; foreground2=[ColorLight2]
; background2=[ColorDark2]
; foreground3=[ColorLight3]
; background3=[ColorDark1]
; average=[ColorAvg]
; UpdateDivider=30

[MeasureJSON]
Measure=Plugin
Plugin=WebParser
URL=file://#PlaybackPath#
RegExp=(?siU)"song.*songLyrics": (.*)"shuffle": "(.*)".*repeat": "(.*)"
; UpdateDivider=25

[MeasurePlaybackAPI]
Measure=String
String=#EnabledPlaybackAPI#
IfMatch=true
IfNotMatchAction=[!HideMeterGroup Active][!ShowMeter Background][!ShowMeter MeterPlaybackPrompt]
DynamicVariables=1
; UpdateDivider=-1

[MeasurePlayPause]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=State

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
OnChangeAction=[!Redraw]
; UpdateDivider=20

[MeasureRepeat]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Repeat
IfBelowValue=1
IfBelowAction=[!SetOption MeterRepeat ImageAlpha 75][!SetOption MeterRepeat ImageName "#@#Images\repeat.png"][!UpdateMeter MeterRepeat][!Redraw]
IfEqualValue=1
IfEqualAction=[!SetOption MeterRepeat ImageAlpha 240][!SetOption MeterRepeat ImageName "#@#Images\repeat1.png"][!UpdateMeter MeterRepeat][!Redraw]
IfAboveValue=1
IfAboveAction=[!SetOption MeterRepeat ImageAlpha 240][!SetOption MeterRepeat ImageName "#@#Images\repeat.png"][!UpdateMeter MeterRepeat][!Redraw]
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
Formula=#ShowVisualizer#
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
IfEqualAction=[!HideMeterGroup Active][!HideMeterGroup Visualizer][!PauseMeasureGroup Visualizer][!ShowMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup Active][!ShowMeterGroup Visualizer][!HideMeterGroup Info][!HideMeterGroup Volume][!UnpauseMeasureGroup Visualizer][!HideMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
DynamicVariables=1
; UpdateDivider=25

[MeasureSkinSize]
Measure=Calc
Formula=#CURRENTCONFIGHEIGHT#
IfAboveValue=0
IfAboveAction=[!WriteKeyValue Variables SkinHeight #CURRENTCONFIGHEIGHT# "#@#Variables.inc"][!WriteKeyValue Variables SkinWidth #CURRENTCONFIGWIDTH# "#@#Variables.inc"][!UpdateMeasure *][!UpdateMeter *]
DynamicVariables=1

[MeasureTime]
Measure=Calc
Formula=#Length#
DynamicVariables=1
UpdateDivider=1

[MeasureVolumeControl]
Measure=Calc
Formula=#EnableVolumeControl#
IfEqualValue=0
IfEqualAction=[!DisableMeasure MeasureVolume][!DisableMeasure MeasureVolumeValue][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!EnableMeasure MeasureVolume][!EnableMeasure MeasureVolumeValue][!UpdateMeter *][!Redraw]
UpdateDivider=1

[MeasureVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
UpdateDivider=1

[MeasureAudio]
Measure=Plugin
Plugin=AudioLevel
Group=Visualizer
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
UpdateDivider=1

[MeasureAudioAverage]
Measure=Plugin
Plugin=AudioLevel
Group=Visualizer
Port=Output
RMSAttack=10
RMSDecay=2500
RMSGain=1000
Sensitivity=100
FreqMin=20
FreqMax=18000
DynamicVariables=1
UpdateDivider=1

[MeasureAverageVolume]
Measure=Plugin
Plugin=AudioLevel
Group=Visualizer
Parent=MeasureAudioAverage
Channel=Avg
Type=RMS
UpdateDivider=1

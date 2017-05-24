[MeasurePlayer]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=Spotify

[MeasureTitle]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=TrackName

[MeasureArtist]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=ArtistName

[MeasureAlbum]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=AlbumName

[MeasureArtwork]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=AlbumArt
Res=640
DefaultPath=#@#Images\nocover.png
CoverPath=#@#Images\Cover.png
OnChangeAction=[!CommandMeasure "MeasureAdaptiveScript" "Update()""][!Redraw]

[MeasureRepeat]
Measure=Plugin
Plugin=SpotifyPlugin.dll
PlayerInfo=Repeat
IfBelowValue=1
IfBelowAction=[!SetOption MeterRepeat ImageAlpha 75][!SetOption MeterRepeat ImageName "#@#Images\repeat.png"][!SetOption MeterRepeat LeftMouseUpAction "[!CommandMeasure MeasurePlayPause "Shuffle"][!Redraw]"][!UpdateMeter MeterRepeat][!Redraw]
IfEqualValue=1
IfEqualAction=[!SetOption MeterRepeat ImageAlpha 240][!SetOption MeterRepeat ImageName "#@#Images\repeatOne.png"][!SetOption MeterRepeat LeftMouseUpAction "[!CommandMeasure MeasurePlayPause "Shuffle"][!Redraw]"][!UpdateMeter MeterRepeat][!Redraw]
IfAboveValue=1
IfAboveAction=[!SetOption MeterRepeat ImageAlpha 240][!SetOption MeterRepeat ImageName "#@#Images\repeat.png"][!SetOption MeterRepeat LeftMouseUpAction "[!CommandMeasure MeasurePlayPause "Shuffle"][!Redraw]"][!UpdateMeter MeterRepeat][!Redraw]
DynamicVariables=1

[MeasureShuffle]
Measure=Plugin
Plugin=SpotifyPlugin.dll
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
Measure=Plugin
Plugin=Process
ProcessName=Spotify.exe
IfBelowValue=1
IfBelowAction=[!HideMeterGroup Active][!HideMeterGroup Visualizer][!PauseMeasureGroup Visualizer][!ShowMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup Active][!ShowMeterGroup Visualizer][!HideMeterGroup Info][!HideMeterGroup Volume][!UnpauseMeasureGroup Visualizer][!HideMeterGroup Icon][!UpdateMeasure *][!UpdateMeter *][!Redraw]
DynamicVariables=1

[MeasureSkinSize]
Measure=Calc
Formula=#CURRENTCONFIGHEIGHT#
IfAboveValue=0
IfAboveAction=[!WriteKeyValue Variables SkinHeight #CURRENTCONFIGHEIGHT# "#@#Variables.inc"][!WriteKeyValue Variables SkinWidth #CURRENTCONFIGWIDTH# "#@#Variables.inc"][!UpdateMeasure *][!UpdateMeter *]
DynamicVariables=1

[MeasureTime]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=Progress
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

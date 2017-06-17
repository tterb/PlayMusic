[Variables]

;This determines the PlayMusic variant used by the skin (Default: Landscape)
Variant=Landscape

;This is the variable used to scale each of the skins (Default: 5)
Size=5
SizeValue=2

;This determines the accent color used by the skin (Default: FFFFFF89)
Accent=FFFFFF89

; This variable stores the active page of the settings menu
MenuPage=2

;This variable determines whether the skin uses adaptable accent colors (0/1)
AdaptiveAccent=1

;This variable determines whether the song info is shown only on mouseover (0/1)
InfoOnHover=1

;Tells the skin whether volume control is enabled (0/1)
EnableVolumeControl=1

;This variable determines the increments that the volume increases/decreases
VolumeStep=2

;This variable allows the volume bar to remain visible with all accent colors FFFFC8
VolumeColor=FFFFFFC8

SourceIcon=C:\Users\there\Documents\Rainmeter\Skins\PlayMusic\@Resources\Images\spotifyIcon.png

;This is the icon variant used when the skin is minimized
Icon=C:\Users\there\Documents\Rainmeter\Skins\PlayMusic\@Resources\Images\playIcon.png

App=GPMDP
AppPath=C:\Users\there\AppData\Roaming\Spotify\Spotify.exe

;This determines whether the skin minimizes when GPMDP is closed (0/1)
minimizeOnClose=1

PlayerMeasures=Measures

;This variable contains the height of the current skin configuration
SkinHeight=226

;This variable contains the width of the current skin configuration
SkinWidth=228


;=================================================
; SOURCE

; These variables control whether the skin uses GPMDP or Spotify (not both)
useSpotify=0
useGPMDP=1


;=================================================
; VISUALIZER

;This variable determines whether the visualizer is shown (0/1)
ShowVisualizer=1

;This determines the color of the visualizer bars
BarColor=FFFFFF89

;This variable determines the width of the bands in the visualizer
BarWidth=5

;This variable determines the space between bands in the visualizer
; bandSpace=2

;This variable determines the average height of the visualizer bands
AverageSize=3

;This determines the values of the fallowing variables based of the selected performance setting.
VisualizerPerformance=Med

; A number value for the frequency resolution of the output data.
; Increasing this value will add more cpu load, so  if you are using a
; slower pc change the value to 1024, 512, or 256.
; This will increase/decrease performance and the quality of the visualization.
; Default: 1024
FFTSize=1024

; A number value for the frequency resolution overlapping the output data.
; Increasing this value will add more cpu load, so  if you are using a slower
; pc you can change this to 256 or 0 for better performance.
; This will increase/decrease performance and the quality of the visualization.
; Default: 512
FFTOverlap=512

; Time in Milliseconds till the bars rise to the signal level.
; Higher values adds delay to the visualization, but makes it much smoother
; and calmer.
; Default: 95
FFTAttack=95

; Time in Milliseconds till the bars fall from the signal level.
; Higher values will extend the time the bars stay viisible, lower values makes
; it quicker and more choppy.
; Default: 90
FFTDecay=90

; This variable determines the X-offset of the visualizer and is automatically
; set depending on the skin size
VisX=25.75

; This variable determines the width of the visualizer bands and is
; automatically set depending on the round skin size
RoundBarWidth=4.35

AlignValue=1
Alignment=Right
Align=30.7

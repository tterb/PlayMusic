[Variables]

;This determines the PlayMusic variant used by the skin (Default: Landscape)
variant=Round

;These variables determines which theme and text color is used by the skin
theme=Dark
textColor=255,255,255,250

;This is the variable used to scale each of the skins (Default: 5)
size=4.5

;This variable determines whether info is always present on the skin or shown only on mouse-over
;(For Square & Round variants only)
InfoHover=1

;Tells the skin whether volume control is enabled
enableVolumeControl=1

;This variable determines the increments that the volume increases/decreases
volumeStep=2

;This determines the accent color used by the skin (Default: FFFFFF89)
;This is the variable that determines the accent color used by the skin
accent=FF9800F1

;This is the icon variant used when the skin is minimized
icon=C:\Users\there\Documents\Rainmeter\Skins\PlayMusic\@Resources\images\playIcon.png

;This determines whether the skin minimizes when GPMDP is closed (0 = off, on = 1)
minimizeOnClose=1

;Tells the skin whether 'Playback API' is enabled in GPMDP
playbackAPI=1


;======================================
; VISUALIZER

;This variable determines whether the visualizer is shown
showVisualizer=1

;This determines the color of the visualizer bars
barColor=FF9800F1

;This variable determines the width of the bands in the visualizer
wideBands=0

; A number value for the frequency resolution of the output data.
; Increasing this value will add more cpu load, so  if you are using a slower pc change
; the value to 1024, 512, or 256.
; This will increase/decrease performance and the quality of the visualization.
; Default: 2048
FFTSize=2048

; A number value for the frequency resolution overlapping the output data.
; Increasing this value will add more cpu load, so  if you are using a slower pc you can
; change this to 256 or 0 for better performance.
; This will increase/decrease performance and the quality of the visualization.
; Default: 512
FFTOverlap=512

; Time in Milliseconds till the bars rise to the signal level.
; Higher values adds delay to the visualization, but makes it much smoother and calmer.
; Default: 45
FFTAttack=45

; Time in Milliseconds till the bars fall from the signal level.
; Higher values will extend the time the bars stay viisible, lower values makes it quicker and more choppy.
; Default: 60
FFTDecay=60
InfoOnHover=0

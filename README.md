# FrekvensMatrix
Send customized images to the Frekvens LED Matrix
https://www.ikea.com/ca/en/p/frekvens-led-multi-use-light-black-50420353/

Output example: https://www.instagram.com/p/B9pN1hCAAhr/

After opening the Frekvens Matrix, extract the circuit board and solder a ribbon cable to the pins below. I'm using an Arduino Uno for this example but any microcontroller shouuld do.

- GND -> GND
- LAK -> Latch -> Pin 8
- CLK -> Clock -> Pin 12
- DA -> Data -> Pin 11
- EN -> Enable - GND
- VCC -> Voltage In -> 3.3V

FrekvensLEDMatrix.toe is a TouchDesigner file to switch inputs and alter images on the matrix in realtime. Well, if 5 FPS counts as realtime. Notes are added to the TD File. You can download TouchDesigner (Non-Commercial) here: https://derivative.ca/download

The Arduino script is configured to accept a string of 256 zeros or ones with a \n at the end. Once received it will print the screen to the Shift Register. 

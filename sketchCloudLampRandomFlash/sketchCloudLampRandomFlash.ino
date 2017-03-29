// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            9

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      2

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//int delayval = 250; // delay for half a second
int delayval = 10;
int flash = 1;
int a = random(250);
int b = random(250);
int c = random(250);
int d = random(250);
int e = random(250);
int f = random(250);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.

//    pixels.setPixelColor(1, pixels.Color(0,0,100)); // Moderately bright green color.
//    pixels.setPixelColor(0, pixels.Color(255,255,0)); // Moderately bright green color.
//    pixels.show();
}

void loop() {
  // using a for loop to have the led increse in brightness till 
  // its max value followed by a decrese down to the starting value.
for(int i = 20; i < 255; i++)
{
    pixels.setPixelColor(0, pixels.Color(i,i,i));
    pixels.show();
    delay(delayval);
}

for(int i = 255; i > 20; i--)
{
    pixels.setPixelColor(0, pixels.Color(i,i,i));
    pixels.show();
    delay(delayval);
}
//flash = random(0,4)

// checking if flash var is set to 2 and if it is flashes neopixel 1 with a fade.
if(flash == 2)
{
  for(int i = 255; i >= 0; i--)
  {
    pixels.setPixelColor(1, pixels.Color(i,i,i));
    pixels.show();
    delay(3);
  }
  flash = 0;
}
flash++;
// pixels.setPixelColor(1, pixels.Color(0,255,0)); // Moderately bright green color.
// delay (3000);

// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
//  for(int i=0;i<NUMPIXELS;i++){
//
//    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(a,b,c)); // Moderately bright green color.
//
//    pixels.show(); // This sends the updated pixel color to the hardware.
// 
//    delay(delayval); // Delay for a period of time (in milliseconds).
//    pixels.setPixelColor(i, pixels.Color(d,e,f)); // Moderately bright green color.
//
//    pixels.show(); // This sends the updated pixel color to the hardware.

//  }
}

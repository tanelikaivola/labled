//#define FASTLED_FORCE_SOFTWARE_SPI

#include "FastLED.h"

#define NUM_LEDS 144
#define SCAN_WIDTH 10
#define SCAN_DELAY 20

#define DATA_PIN 11 // this is not used but must exist
#define CLOCK_PIN 13 // this is not used but must exist

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR , DATA_RATE_MHZ(5)>(leds, NUM_LEDS); // reduce data rate if glitchy
//  FastLED.setBrightness(70);
}

int pos = 0, i = 0, dir = 1;



void loop() {

  leds[pos]=CRGB::Red;

  if(((pos-dir)>=0) && ((pos-dir)<NUM_LEDS))
    leds[pos-dir]=CRGB::Black;
    
  pos = pos + dir;
  
  if ((pos==0) || (pos==NUM_LEDS-1))
     dir=-dir;

  FastLED.show();

  delay(SCAN_DELAY);

}


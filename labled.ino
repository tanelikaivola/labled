//#define FASTLED_FORCE_SOFTWARE_SPI

#include "FastLED.h"

#define NUM_LEDS 144

#define DATA_PIN 11 // this is not used but must exist
#define CLOCK_PIN 13 // this is not used but must exist

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB, DATA_RATE_MHZ(5)>(leds, NUM_LEDS); // reduce data rate if glitchy
//  FastLED.setBrightness(70);
}

int pos = 0, i = 0;

void loop1() {
//  fill_rainbow(leds, NUM_LEDS, i, 1);
  fill_solid(leds, NUM_LEDS, CHSV(i, 255, 50));

  i = (i + 1) % 0xFF;

  leds[pos] = CRGB::White;
  pos = (pos + 1) % NUM_LEDS;

  FastLED.show();

  delay(10);
}


void loop() {
  fadeToBlackBy(leds, NUM_LEDS, 1);

  i = (i + 1) % 0xFF;

  if(pos < NUM_LEDS)
    leds[pos] = CRGB::White;
   
  pos = (pos + 1) % (NUM_LEDS*10);

  FastLED.show();

//  delay(1);

}


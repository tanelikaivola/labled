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

void color_slide(int first, int last, CRGB first_color, CRGB last_color)
{
  int d=(last-first);
  int rd=(last_color.red-first_color.red)/d;
  int gd=(last_color.green-first_color.green)/d;
  int bd=(last_color.blue-first_color.blue)/d;
  int i=first;
  CRGB color=first_color;
  while(i<=last) {
    leds[i]=color;
    color.red+=rd;
    color.green+=gd;
    color.blue+=bd;
    i++;
  }
}

CRGB Rainbow[7] = { CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, 
                    CRGB::Blue, CRGB::Indigo, CRGB::Purple };
int front=1;
int back=0;

void loop() {

  color_slide(0,NUM_LEDS-1,Rainbow[back],Rainbow[front]);
  FastLED.show();
  back=front;
  front++;
  if (front==7) front=0;

  delay(SCAN_DELAY);

}


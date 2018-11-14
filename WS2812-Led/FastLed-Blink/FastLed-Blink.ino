#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 8

CRGB leds[NUM_LEDS];

void setup() { 
      FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Yellow;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Pink;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Cyan;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Magenta;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::White;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}

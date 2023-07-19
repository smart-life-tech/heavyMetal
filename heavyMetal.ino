#include <FastLED.h>

#define LED_PIN     6   // Pin connected to the Data Input of WS2812B LED strip
#define NUM_LEDS    20  // Number of LEDs in your strip
#define COLOR       CRGB::Purple  // The color you want for the breathing effect

#define BLOOM_UP_TIME    3000  // 3 seconds for the bloom up
#define BLOOM_DOWN_TIME  3000  // 3 seconds for the bloom down
#define OFF_TIME         1000  // 1 second for being off

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(64);  // Adjust brightness (0-255) as needed

  // Initialize all LEDs to the specified color
  fill_solid(leds, NUM_LEDS, COLOR);
  FastLED.show();

  // Wait for a moment to show the initial color
  delay(OFF_TIME);
}

void loop() {
  // Bloom up
  for (int brightness = 0; brightness <= 255; brightness++) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(BLOOM_UP_TIME / 255);
  }

  // Bloom down
  for (int brightness = 255; brightness >= 0; brightness--) {
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(BLOOM_DOWN_TIME / 255);
  }

  // Turn off
  FastLED.setBrightness(0);
  FastLED.show();
  delay(OFF_TIME);
}

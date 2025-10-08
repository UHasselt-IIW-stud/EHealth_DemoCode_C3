#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 8


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel Pixel = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Pixel.begin();
  Pixel.setBrightness(50);
  Pixel.show(); // Initialize all pixels to 'off'

  Serial.begin(115200);	
}

void loop() {
  for(int i=0; i<255; i++) {
    Pixel.setPixelColor(0, Pixel.Color(0, i, 0));
    Pixel.show(); 
    delay(100);
  }
  for(int i=0; i<255; i++) {
    Pixel.setPixelColor(0, Pixel.Color(0, 255-i, 0));
    Pixel.show(); 
    delay(100);
  }
}




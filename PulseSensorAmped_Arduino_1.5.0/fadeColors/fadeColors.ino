// fade in and out

#include <Adafruit_NeoPixel.h>
#define LEDPIN 6 // connect the Data from the strip to this pin on the Arduino
#define NUMBER_PIXELS 10 // the number of pixels in your LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_PIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

int waitTime = 5000;
unsigned long previousLEDTime = 0;
unsigned long currentLEDTime;

void setup() {
  strip.begin();
  Serial.begin(9600);

}

void loop() {
  currentLEDTime = millis();
  fadeIn(100, 0, 255, waitTime); // Blue
  currentLEDTime = millis();
  fadeOut(150, 0, 200, waitTime); // Magenta
  currentLEDTime = millis();
  fadeIn(255, 0, 150, waitTime); // Pink
  currentLEDTime = millis();
  fadeOut(200, 50, 50, waitTime); // Salmon Pink

}

void fadeIn(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {

  for(uint8_t b=0; b <255; b++) {
     if (currentLEDTime - previousLEDTime >= waitTime){
      Serial.print("fadein");
       for(uint8_t i=0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
       }
       strip.show();
     }
  };
  };
     

void fadeOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  
  for(uint8_t b=255; b > 0; b--) {
    if (currentLEDTime - previousLEDTime >= waitTime){
      Serial.print("fadeout");
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
     }
     strip.show();
  };
};
};




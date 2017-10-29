


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





// inhaleInterval is the amount of time before each inhale
// waitBeforeExhale is the amount of time between your inhale & exhale (holding breath)
// fadeDelay is the number of mS for each step of brightness (256 steps will take 8*255 = 2,048 mS)

// HOWEVER I think what you want to do will need two timers
// meaning, you can't use a for loop to increment/decrement fade, you have to do it manually, like the ledFadeToBeat function 

// and thus you need two previousTimes to keep track of, one for long timer one for short timer
// you need to use a short timer too otherwise all your code will be delayed while it does a complete fade in or out


//uint8_t b;    // fade brightness variable must be declared globally, so function remembers it in between being called
              // you should put this in main code with the other vars, I just put it here to show you
              // by the way uint8_t is the same as byte, they are just being fancy (it means unsigned integer with 8 bits, i.e. 0-255)



void fadeIn(uint8_t red, uint8_t green, uint8_t blue, uint8_t fadeDelay) {
Serial.println(millis() - previousLEDTime);
  if (millis() - previousInhaleTime >= inhaleInterval) { // check if it's time to do a complete fade (long timer)
    // make sure brightness is initialized only once, when it's first time to fade:
    if (!timeToFade) {
      timeToFade = true;
      b = 0;                    // initialize your fade brightness
      Serial.println("//////******fadein");   // remember to comment this out when you are finished debugging Arduino, because it will confuse your Processing code!
    }
    
    if (millis() - previousLEDFadeTime >= fadeDelay){  // check if it's time to increment fade a little bit (short timer)
        b++;                                      // increase fade brightness a little bit
        b = constrain(b,0,255);                   // keep LED fade from going out of range
        for(uint8_t i=0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
        }
        strip.show();
        Serial.print("                  ");
        Serial.println(b);
        previousLEDFadeTime = millis();   // reset your short timer
      }
    };
  
    if (b>=255) {
      // fade is done
      previousLEDTime = millis();         // reset your long timer
      timeToFade = false;
    }
};


//void fadeOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t fadeDelay) {
//
//  if (millis() - previousLEDTime >= waitTime) { // check if it's time to do a complete fade (long timer)
//    // make sure brightness is initialized only once, when it's first time to fade:
//    if (!timeToFade) {
//      timeToFade = true;
//      b = 255;                    // initialize your fade brightness
//      Serial.print("fadeout");   // remember to comment this out when you are finished debugging Arduino, because it will confuse your Processing code!
//    }
//    
//    if (millis() - previousLEDFadeTime >= fadeDelay){  // check if it's time to increment fade a little bit (short timer)
//        b--;                                      // decrease fade brightness a little bit
//        b = constrain(b,0,255);                   // keep LED fade from going out of range
//        for(uint8_t i=0; i < strip.numPixels(); i++) {
//          strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
//        }
//        strip.show();
//      }
//      previousLEDFadeTime = millis();   // reset your short timer
//    };
//  
//    if (b<=0) {
//      // fade is done
//      previousLEDTime = millis();         // reset your long timer
//      timeToFade = false;
//    }
//};


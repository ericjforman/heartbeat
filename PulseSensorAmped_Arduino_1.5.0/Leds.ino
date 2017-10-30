

// remember that wait and waitTime are different!
// you might want LEDs to flash every 10 seconds (10000mSec), that's waitTime
// but the delay to determine how fast fade effect happens might be 10mSec, that's wait
// (in which case one fade would take 10mSec * 256 = 2560mSec)
// NOTE: I would call one waitTime and the other fadeDelay or something, but up to you

// HOWEVER I think what you want to do will need two timers
// meaning, you can't use a for loop to increment/decrement fade, you have to do it manually, like the ledFadeToBeat function 

// and thus you need two previousTimes to keep track of, one for long timer one for short timer
// you need to use a short timer too otherwise all your code will be delayed while it does a complete fade in or out
// let's call them previousLEDTime for long timer and previousLEDFadeTime for short timer.
// (you can come up with better names)

// NOTE: get rid of currentLEDTime in main loop, do it all here
// also, you can use millis() instead of currentLEDTime, right?


uint8_t b;		// fade brightness variable must be declared globally, so function remembers it in between being called
						  // you should put this in main code with the other vars, I just put it here to show you
							// by the way uint8_t is the same as byte, they are just being fancy (it means unsigned integer with 8 bits, i.e. 0-255)

boolean timeToFade = false;		// flag to make sure fade doesn't start over every time code loops and long timer has elapsed


void fadeIn(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {  
	if (millis() - previousLEDTime >= waitTime) { // check if it's time to do a complete fade (long timer)
		// make sure brightness is initialized only once, when it's first time to fade:
		if (!timeToFade) {
			timeToFade = true;
			b = 0;									  // initialize your fade brightness
			Serial.print("fadein");		// remember to comment this out when you are finished debugging Arduino, because it will confuse your Processing code!
		}
		
		if (millis() - previousLEDFadeTime >= wait){  // check if it's time to increment fade a little bit (short timer)
				b++;																			// increase fade brightness a little bit
				b = constrain(b,0,255);   								// keep LED fade from going out of range
				for(uint8_t i=0; i < strip.numPixels(); i++) {
					strip.setPixelColor(i, red*b/255, green*b/255, blue*b/255);
				}
				strip.show();
			}
			previousLEDFadeTime = millis();		// reset your short timer
		};
	
		if (b>=255) {
			// fade is done
			previousLEDTime - millis();					// reset your long timer
			timeToFade = false;
		}
};


// old code, change to match:
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




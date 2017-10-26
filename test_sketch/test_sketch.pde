import processing.sound.*;
SoundFile file;

boolean songPlaying = false;
int time;
int wait = 1001;

void setup() {
  size(640, 360);
  background(255);
    
  // Load a soundfile from the /data folder of the sketch and play it back
  file = new SoundFile(this, "heartbeat.mp3");
  time = millis();
}      

void draw() {
  if (songPlaying == false){
    file.play();
    songPlaying = true;
      }
  if(millis() - time >= wait){
    songPlaying = false;
    time = millis();
  }
}
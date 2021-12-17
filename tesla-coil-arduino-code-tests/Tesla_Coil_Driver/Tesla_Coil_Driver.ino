#include <arduinoFFT.h>

const int teslaPin =  3;
const long pulse = .2;
char song1[10] = {'A', 'X', 'B', 'C', 'D', 'E', 'A', 'A', 'C', 'E'};
int notes = sizeof(song1);

void setup() {
  // set the digital pin as output:
  pinMode(teslaPin, OUTPUT);
}

void loop() {
  for (int noteNumber = 0; noteNumber < notes; noteNumber++){
    
}
float frequency(int noteNumber){
  if song1[noteNumber] = "A" return (1/32.70);
}
/*
void note(float frequency, float notetype, int tempo, int signature){
  for(int i=0; i<(notetype/signature); i+=(1/frequency)){
    digitalWrite(2, HIGH);
    Serial.println("--");
    delay(20);
    digitalWrite(2,LOW);
    Serial.println("__");
    delay(1/frequency);
  }
}
*/

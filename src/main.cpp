#include <Arduino.h>
#include "constants.h"
#include "autoTune.h"

using namespace constants;

float duration, distance; // variables for tracking distance from the sensor
float inchesToPitch(float inches); // initialize function so we can convert inches to pitch

void setup() {
  // initialize pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600); // begin serial so we can track data
}

void loop() {
  // set TRIG pin to low to ensure a clean pulse of sound from the distance sensor
  digitalWrite(TRIG, LOW);
  delay(2);

  // output sound for the sensor
  digitalWrite(TRIG, HIGH);
  delay(10); // make sound 10 milliseconds long to ensure the ECHO pin gets it
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH); // track duration it took for the sound to reach the ECHO input. In microseconds.

  // convert microseconds to inches
  // SPEED_OF_SOUND is in inches/microseconds
  // divide by 2 because the sound has to leave the sensor, bounce off, and come back, resulting in double the distance
  distance = (duration * SPEED_OF_SOUND) / 2; 

  // if the distance is in our range, output tone from the buzzer
  if(distance >= LOW_DIST && distance <= HIGH_DIST) {
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print("Current Frequency: ");
    Serial.println(autoTune(inchesToPitch(distance)));

    // output autoTuned pitch from the buzzer. make the duration 100 to ensure constant noise from the buzzer.
    tone(BUZZER, autoTune(inchesToPitch(distance)), 100);
  }
}

// convert inches to pitch using an equation
float inchesToPitch(float inches) {
  float minInches = LOW_DIST; // minimum inches we can be from the distance sensor
  float maxInches = HIGH_DIST; // maximum inches we can be from the distance sensor
  float minPitch = notes::C_4; // minimum possible pitch we want to play
  float maxPitch = notes::B_6; // maximum possible pitch we want to play

  // write equation in two-point form to get equation to convert input inches to output pitch
  /*
            change in y
    y =     ----------- * (x - minimum x) + minimum y
            change in x
   ---------------------------------------------------------------         
            change in pitch
    pitch = ----------------   * (current inches - minimum inches) + minimum pitch
            change in inches
  */
  return ((maxPitch-minPitch)/(maxInches-minInches))*(inches - LOW_DIST) + minPitch;
}
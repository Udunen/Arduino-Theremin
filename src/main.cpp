#include <Arduino.h>
#include "constants.h"
#include "autoTune.h"
#include "songs.h"

using namespace constants;

float duration, distance; // variables for tracking distance from the sensor
float inchesToPitch(float inches); // initialize function so we can convert inches to pitch


// need toggle for switching between theremin and pre-made songs
int togglePushCounter = 0;
int toggleState = 0;
int lasttoggleState = 0;

// toggle for each song
int song1PushCounter = 0;
int song1State = 0;
int lastSong1State = 0;

int song2PushCounter = 0;
int song2State = 0;
int lastSong2State = 0;


void setup() {
  // initialize pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(TOGGLE_LED, OUTPUT);
  pinMode(TOGGLE, INPUT);
  pinMode(SONG_1, INPUT);
  pinMode(SONG_2, INPUT);
  pinMode(SONG_1_LED, OUTPUT);
  pinMode(SONG_2_LED, OUTPUT);
  Serial.begin(9600); // begin serial so we can track data
}

void loop() {
  toggleState = digitalRead(TOGGLE); // state of the toggle buttom

  // edge detector for the toggle button
  if (toggleState != lasttoggleState) {
    if (toggleState == HIGH) {
      togglePushCounter++;
    }
    delay(50);
  }
  lasttoggleState = toggleState;

  // every press toggles, so theres 2 states
  if (togglePushCounter % 2 == 0) {
    digitalWrite(TOGGLE_LED, HIGH); // indicate that system is in theremin mode

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
    if (distance >= LOW_DIST && distance <= HIGH_DIST) {
      // print everything
      Serial.print("Distance: ");
      Serial.println(distance);
      Serial.print("Current Frequency: ");
      Serial.println(autoTune(inchesToPitch(distance)));

      // output autoTuned pitch from the buzzer. make the duration 100 to ensure constant noise from the buzzer.
      tone(BUZZER, autoTune(inchesToPitch(distance)), 100);
    }
  } else {
    digitalWrite(TOGGLE_LED, LOW); // not in theremin mode, so indicator LED is low

    // states of the song buttons
    song1State = digitalRead(SONG_1);
    song2State = digitalRead(SONG_2);


    // edge detectors for each song button
    if (song1State != lastSong1State) {
      if (song1State == HIGH) {
        song1PushCounter++;
      }
      delay(50);
    }
    lastSong1State = song1State;

    if (song2State != lastSong2State) {
      if (song2State == HIGH) {
        song2PushCounter++;
      }
      delay(50);
    }
    lastSong2State = song2State;

    // 2 states, song plays or not
    if (song1PushCounter % 2 == 0) {
      digitalWrite(SONG_1_LED, HIGH); // indicate the song is active
      hotToGo();
      song1PushCounter++; // make it only play the song once
    } else {
      digitalWrite(SONG_1_LED, LOW); // indicate the song is inactive
    }

    if (song2PushCounter % 2 == 0) {
      digitalWrite(SONG_2_LED, HIGH);
      minecraft();
      song2PushCounter++;
    } else {
      digitalWrite(SONG_2_LED, LOW);
    }
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
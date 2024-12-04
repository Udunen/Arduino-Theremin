#ifndef __SONGS_H__
#define __SONGS_H__

#include <Arduino.h>
#include "constants.h"

using namespace constants;
using namespace constants::notes;

float beatDuration;

void hotToGo() {
  beatDuration = 60.0/SONG_1_BPM * 1000.0; // how long each beat goes for
                                        // 60 sec
                                        // --------  * 1000 ms (convert to ms for the delay() function)
                                        //   BPM
  
  // play note, then delay for beat duration until next note
  // multiply and divide for longer or shorter notes
  tone(BUZZER, A_SHARP_3, beatDuration); // h
  delay(beatDuration);
  tone(BUZZER, C_SHARP_4, beatDuration); // o
  delay(beatDuration);
  tone(BUZZER, C_SHARP_4, beatDuration); // t
  delay(beatDuration);
  tone(BUZZER, C_SHARP_4, beatDuration); // t
  delay(beatDuration);
  tone(BUZZER, D_SHARP_4, beatDuration*1.5); // o
  delay(beatDuration*1.5);
  tone(BUZZER, C_SHARP_4, beatDuration/2); // g
  delay(beatDuration/2);
  tone(BUZZER, D_SHARP_4, beatDuration/2); // o 
  delay(beatDuration/2);
  tone(BUZZER, C_SHARP_4, beatDuration/2); // o PART 2
  delay(beatDuration/2);

  noTone(BUZZER); // rest
  delay(beatDuration/2);

  tone(BUZZER, A_SHARP_3, beatDuration); // you
  delay(beatDuration);
  tone(BUZZER, C_SHARP_4, beatDuration); // can
  delay(beatDuration);
  tone(BUZZER, F_SHARP_4, beatDuration); // take
  delay(beatDuration);
  tone(BUZZER, G_SHARP_4, beatDuration); // me
  delay(beatDuration);
  tone(BUZZER, G_SHARP_4, beatDuration*1.5); // hot
  delay(beatDuration*1.5);
  tone(BUZZER, A_SHARP_4, beatDuration/2); // to
  delay(beatDuration/2);
  tone(BUZZER, G_SHARP_4, beatDuration/2); // go
  delay(beatDuration/2);
  tone(BUZZER, F_SHARP_4, beatDuration/2); // go PART 2
  delay(beatDuration/2);

  noTone(BUZZER);
  delay(beatDuration); // delay before repeat
}

void minecraft() {
  beatDuration = 60.0/SONG_2_BPM * 1000.0;

  tone(BUZZER, A_SHARP_4, beatDuration*1.5);
  delay(beatDuration*1.5);
  tone(BUZZER, G_SHARP_4, beatDuration);
  delay(beatDuration);
  tone(BUZZER, D_SHARP_4, beatDuration*2);
  delay(beatDuration*2);
  tone(BUZZER, F_SHARP_4, beatDuration*2);
  delay(beatDuration*2);

  noTone(BUZZER);
  delay(beatDuration/2);
  
  tone(BUZZER, A_SHARP_4, beatDuration*1.5);
  delay(beatDuration*1.5);
  tone(BUZZER, G_SHARP_4, beatDuration);
  delay(beatDuration);
  tone(BUZZER, D_SHARP_4, beatDuration*2);
  delay(beatDuration*2);
  tone(BUZZER, C_SHARP_4, beatDuration*2);
  delay(beatDuration*2);

  noTone(BUZZER);
  delay(beatDuration/2);
}

#endif
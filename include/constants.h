#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__


// this is where we define all of our constants, like pin numbers, real-world variables and ranges we use for math
namespace constants {
    const int TRIG = 7;
    const int ECHO = 6;
    const int BUZZER = 8;

    const int SONG_1_LED = 2;
    const int SONG_2_LED = 3;
    const int TOGGLE_LED = 9;

    const int SONG_1 = 11;
    const int SONG_2 = 10;
    const int TOGGLE = 12;

    const float SONG_1_BPM = 140.0;
    const float SONG_2_BPM = 84.0;

    const float SPEED_OF_SOUND = 0.01350393302; // speed of sound in inches/microsecond

    const int LOW_DIST = 1; // minimum distance we can be from the sensor
    const int HIGH_DIST = 25; // maximum distance we can be from the sensor


    // these are all of the notes we use in hertz
    namespace notes {
        const float C_3 = 130.81;
        const float C_SHARP_3 = 138.59;
        const float D_3 = 146.83;
        const float D_SHARP_3 = 155.56;
        const float E_3 = 164.81;
        const float F_3 = 174.61;
        const float F_SHARP_3 = 185;
        const float G_3 = 196;
        const float G_SHARP_3 = 207.65;
        const float A_3 = 220;
        const float A_SHARP_3 = 233.08;
        const float B_3 = 246.94;

        const float C_4 = 261.63;
        const float C_SHARP_4 = 277.18;
        const float D_4 = 293.66;
        const float D_SHARP_4 = 311.13;
        const float E_4 = 329.63;
        const float F_4 = 349.23;
        const float F_SHARP_4 = 369.99;
        const float G_4 = 392;
        const float G_SHARP_4 = 415.30;
        const float A_4 = 440;
        const float A_SHARP_4 = 466.16;
        const float B_4 = 493.88;

        const float C_5 = 523.25;
        const float C_SHARP_5 = 554.37;
        const float D_5 = 587.33;
        const float D_SHARP_5 = 622.25;
        const float E_5 = 659.26;
        const float F_5 = 698.46;
        const float F_SHARP_5 = 739.99;
        const float G_5 = 783.99;
        const float G_SHARP_5 = 830.61;
        const float A_5 = 880;
        const float A_SHARP_5 = 932.33;
        const float B_5 = 987.77;

        const float C_6 = 1046.50;
        const float C_SHARP_6 = 1108.73;
        const float D_6 = 1174.66;
        const float D_SHARP_6 = 1244.51;
        const float E_6 = 1318.51;
        const float F_6 = 1396.91;
        const float F_SHARP_6 = 1476.98;
        const float G_6 = 1567.98;
        const float G_SHARP_6 = 1661.22;
        const float A_6 = 1760;
        const float A_SHARP_6 = 1864.66;
        const float B_6 = 1975.53;
    }
}

#endif
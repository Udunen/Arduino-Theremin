#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__


// this is where we define all of our constants, like pin numbers, real-world variables and ranges we use for math
namespace constants {
    const int TRIG = 7;
    const int ECHO = 6;
    const int BUZZER = 8;

    const float SPEED_OF_SOUND = 0.01350393302; // speed of sound in inches/microsecond

    const int LOW_DIST = 1; // minimum distance we can be from the sensor
    const int HIGH_DIST = 25; // maximum distance we can be from the sensor


    // these are all of the notes we use in hertz
    namespace notes {
        const float C_4 = 525.25;
        const float C_SHARP_4 = 554.37;
        const float D_4 = 587.33;
        const float D_SHARP_4 = 622.25;
        const float E_4 = 659.26;
        const float F_4 = 698.46;
        const float F_SHARP_4 = 739.99;
        const float G_4 = 783.99;
        const float G_SHARP_4 = 830.61;
        const float A_4 = 880;
        const float A_SHARP_4 = 932.33;
        const float B_4 = 987.77;

        const float C_5 = 1046.50;
        const float C_SHARP_5 = 1108.73;
        const float D_5 = 1174.66;
        const float D_SHARP_5 = 1244.51;
        const float E_5 = 1318.51;
        const float F_5 = 1396.91;
        const float F_SHARP_5 = 1476.98;
        const float G_5 = 1567.98;
        const float G_SHARP_5 = 1661.22;
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
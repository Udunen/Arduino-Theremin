#ifndef __AUTOTUNE_H__
#define __AUTOTUNE_H__

#include "constants.h"

using namespace constants::notes;

// we make a list of the notes so we can utilize autoTune
float noteList[] = {
    C_4,
    C_SHARP_4,
    D_4,
    D_SHARP_4,
    E_4,
    F_4,
    F_SHARP_4,
    G_4,
    G_SHARP_4,
    C_5,
    C_SHARP_5,
    D_5,
    D_SHARP_5,
    E_5,
    F_5,
    F_SHARP_5,
    G_5,
    G_SHARP_5,
    C_6,
    C_SHARP_6,
    D_6,
    D_SHARP_6,
    E_6,
    F_6,
    F_SHARP_6,
    G_6,
    G_SHARP_6,
};

// autoTune to the closest pitch in the list
float autoTune(double pitch) {
    float closestNote = noteList[0]; // make variable for the closest pitch we are at
    float minDifference = fabs(pitch - closestNote); // make variable to track the smallest difference from one of the notes

    // loop through the noteList
    for (const double& note : noteList) {
        double difference = fabs(pitch - note); // check distance from current note in the list
        // if current difference is smaller than the smallest difference
        if (difference < minDifference) {
            minDifference = difference; // set smallest difference to current difference
            closestNote = note; // set closest note to the current note
        }
    }

    return closestNote; // return the closest note
}

#endif
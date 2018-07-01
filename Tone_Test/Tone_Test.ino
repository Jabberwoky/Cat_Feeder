/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 15

  created 21 Jan 2010
  by Tom Igoe
  modified 27 April 2018
  by Demian Mendez
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone

*/

#include "pitches.h"
#define speaker 15 // Pin D8 on NodeMCU 1.0(ESP_12E Module)

// notes in the melody:
int melody[] = {
  NOTE_G5, NOTE_FS5, NOTE_DS5, NOTE_A4, NOTE_GS4, NOTE_E5, NOTE_GS5, NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
   8, 8, 8, 8, 8, 8, 8, 8
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speaker, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speaker);
  }
}

void loop() {
  // no need to repeat the melody.
}

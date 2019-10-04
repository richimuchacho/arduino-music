#include "Buzzer.h"
#include "Arduino.h"
#include "Song.h"

Buzzer::Buzzer(int mpin, int lpin) {

  _melodyPin = mpin;
  _ledPin = lpin;

  pinMode(_melodyPin, OUTPUT); //buzzer
  pinMode(_ledPin, OUTPUT);    //led indicator when singing a note

}

void Buzzer::playSong(Song *s) {

    int noteDuration = 1000;
    int pauseBetweenNotes;
    
    Serial.print("Song Title ");
    Serial.print(s->title);
    Serial.print("\n");
        
    Serial.print("Song Length is ");
    Serial.print(s->melodyLength);
    Serial.print("\n");
    
    // int size = sizeof(s->melody) / sizeof(int);
    // int size = s->melodyLength / sizeof(Note);

    for (int thisNote = 0; thisNote < s->melodyLength; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      noteDuration = 1000 / s->melody[thisNote].tempo;
      //noteDuration /= s->melody[thisNote].tempo;

      Serial.print("\n> INDEX ");
      Serial.print(thisNote); 
      Serial.print("\n");

      buzz(s->melody[thisNote].tone, noteDuration);
      //buzz(s->melody[thisNote]);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      stop(noteDuration);
  }  
}

void Buzzer::stop(int noteDuration) {
  buzz(0, noteDuration);  
}

void Buzzer::testTone() {
  buzz(450, 20);
  stop(20);
}

void Buzzer::buzz(int frequency, int length) {
  
  digitalWrite(_ledPin, HIGH);

  Serial.print("PLAY NOTE ");
  Serial.print(frequency);
  Serial.print(":");
  Serial.print(length);
  Serial.print('\n');
  
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle

  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce

  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(_melodyPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(_melodyPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  
  digitalWrite(_ledPin, LOW);

}

void Buzzer::buzz(Note n) {
  buzz(n.tone, n.tempo);
}

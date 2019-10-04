#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"
#include "Song.h"

class Buzzer {
  public:
    void playSong(Song *s);
    void buzz(int frequency, int length);
    void buzz(Note n);
    Buzzer(int mpin, int lpin);
    void stop(int noteDuration);
    void testTone();
  private:
    int _melodyPin;
    int _ledPin;
};

#endif
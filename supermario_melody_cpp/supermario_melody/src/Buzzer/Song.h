#ifndef Song_h
#define Song_h

#include "Arduino.h"
#include "Note.h"

class Song {
  public:
    Song();
    Song(int i);
    //Song(String tl, int* m, int* t);
    Song *createSong1();
    Song *createSong2();
    Song *createSongFromFile(String fileName);

    String title;
    int melodyLength;
    Note* melody;

    /*
	int* melody;
    int* tempo;
	*/
};

#endif
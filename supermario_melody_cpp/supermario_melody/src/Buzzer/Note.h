#ifndef Note_h
#define Note_h

#include "songs/notes_enum.h"

class Note {
  public:
    
    //char[8] tone;
    enum notes tone;
    int tempo;
};

#endif
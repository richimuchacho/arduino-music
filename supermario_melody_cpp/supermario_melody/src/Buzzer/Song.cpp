//#include "songs/notes.h"
// #include <iostream>

//#include <StandardCplusplus.h>

#include "Song.h"
#include "Arduino.h"

/*
Song::Song(String tl, int* m, int* t) {
	
	title = tl;
	melody = m;
	tempo = t;	
}
*/

Song::Song() {
	// createSongFromFile("mario_main_theme.song");
}

Song::Song(int i) {
	if (i == 1) {
		createSongFromFile("mario_main_theme");
	} else {
		//createSongFromFile("mario_underworld.song");
		createSong2();
	}
}

////////////////////////////////////////////////////////////


Song* Song::createSong2(){
	String myTitle = "Mario Underworld Theme";
	short myLength = 56;
	Note myMelody[myLength];
  short i;

	for (i = 0; i <= 10; i++) {
		myMelody[i].tempo=12;
		myMelody[i].tone=NOTE_AS3;
	}

  for (i = 11; i < 20; i++) {
    myMelody[i].tempo=12;
    myMelody[i].tone=NOTE_GS2;
  }

  for (i = 20; i <= 55; i++) {
    myMelody[i].tempo=12;
    myMelody[i].tone=NOTE_CS4;
  }

	this->title = myTitle;
	melodyLength = myLength;
	melody = myMelody;
	return this;
}

// TODO :: IMPLEMENT ME!

/*
Song *Song::createSongFromFile(String fileName){	

	char data[15];
  FILE *infile;

	// First line is Song Title

	// For the rest of the lines in the file...
	// ... until the end of the file. ..
	// Each line is a pair of

		-> New NOTE in Melody array 
			- Tone
			- Length
		-> Add one to melody length


  // open a file in read mode.
  //ifstream infile; 
  //infile.open(fileName + ".song"); 
  infile->fopen(fileName + ".song", "r"); 

  //cout << "Reading from the file" << endl; 
  //Serial.print("Reading from the file\n", s->title);    

  Serial.print("Reading from the file\n");    
  //infile >> data; 
  data = fscanf();

  // write the data at the screen.
  //cout << data << endl;
  Serial.println(data);

  // again read the data from the file and display it.
  //infile >> data; 
  data = fscanf();
  Serial.println(data);


  // close the opened file.
  infile->close();

  //return 0;

  String title = "Mario Theme";

  //Mario main theme melody
  int melody[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0
  };
  //Mario main them tempo
  int tempo[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  };

  // Song mySong = new Song(title, melody, tempo);
  //this = *(Song mySong (title, melody, tempo));

  this->title = title;
  
  this->melody = melody;
  this->tempo = tempo;
 
  return this;
}

*/

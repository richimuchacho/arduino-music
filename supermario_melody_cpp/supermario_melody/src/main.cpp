/*
  Arduino Mario Bros Tunes
  With Piezo Buzzer and PWM

  Connect the positive side of the Buzzer to pin 3,
  then the negative side to a 1k ohm resistor. Connect
  the other side of the 1 k ohm resistor to
  ground(GND) pin on the Arduino.

  by: Dipto Pratyaksa
  last updated: 31/3/13
*/
#include <Arduino.h>
#include "Buzzer/Buzzer.h"
//#include "Buzzer/Song.h"

////////////////////////////////////////////////////////////

/*
TODO Tasks:
  + Power Knob controls Volume
	+ Button changes theme
  + Button starts / stops
  + Two LEDs - Red & Green - For Start & Stop
  + Themes from files
  + Extra, longer themes / other melody formats
  + Play notes from PC Keyboard (StandardFirmata)

*/
////////////////////////////////////////////////////////////

const int buttonPin = 2;      // the number of the pushbutton pin
                              // TODO Move inside a class file
const int buzzerPin = 5;
const int redLEDPin = 13; 
const int greenLEDPin = 12; 

////////////////////////////////////////////////////////////

int buttonState = 0;          // variable for reading the pushbutton status
bool play = 0;
bool buttonPressed = 0;

Buzzer *buzzer;
Song *song2;

void setup(void)
{
  Serial.begin(9600);
  buzzer = new Buzzer (buzzerPin , greenLEDPin);
  song2 = new Song(2);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);

  digitalWrite(redLEDPin, HIGH); 
}

void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    Serial.print("BUTTON PRESSED DOWN\n");    
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      Serial.print("BUTTON RELEASED\n");
      buttonPressed = true;
    }
  }

  if (buttonPressed == true) {
    if (play == 0) {
      play = 1;
      Serial.print("PLAY\n");   
      digitalWrite(greenLEDPin, HIGH);
      buzzer->playSong(song2);
    } else if (play == 1) {
      play = 0;
      Serial.print("STOP\n"); 
      digitalWrite(greenLEDPin, LOW); 
      buzzer->stop(120);
    }
    buttonPressed = 0;
  } 


    /* 
    if (play == true) {
      play == false;
      Serial.print("STOP\n");    
    }
    else {
      play == true;
      Serial.print("PLAY\n"); 
      digitalWrite(ledPin, HIGH);
      //buzzer->playSong(song2);
    }
  } else if (buttonState == LOW) {
    if (play == false) {
      play == true;
      Serial.print("PLAY\n");   
      digitalWrite(ledPin, HIGH); 
    }
    else {
      play == false;
      Serial.print("STOP\n"); 
      
      //buzzer->playSong(song2);
    }
    */
  }

/*
  if (play) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    buzzer->playSong(song2);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

*/
  /*
    Serial.println("Song Title " + song1->title);
    
    // int size = sizeof(song1->melody) / sizeof(int);
    
    // int size = sizeof(song1->melody) / sizeof(int);
    

    for (int thisNote = 0; thisNote < song1->melodyLength; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      //int noteDuration = 1000 / song1->tempo[thisNote];

      int noteDuration = 1000 / song1->melody[thisNote].tempo;

      // buzzer->buzz(song1->melody[thisNote].tone, song1->melody[thisNote].tempo);
      buzzer->buzz(song1->melody[thisNote]);


      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      //buzz(melodyPin, 0, noteDuration);
      buzzer->stop(noteDuration);
  }  
  */

  // buzzer->testTone();



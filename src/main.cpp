#include <Arduino.h>
#include "A4988.h"
//pin macros
#define buttonPin 4
#define ledPin 13

// put variable declarations here:
int buttonState = LOW;
int ledState = LOW;
//A4988 stepper();

// put function declarations here:

//engage or disengage blinds based on buttonState
void toggleBlinds(A4988& stepper,int buttonState, int& blindState);
//toggles the led on the board on or off based on the press of a push button
void toggleLED(int buttonState, int& ledState);

void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  toggleLED(buttonState,ledState);

  //digitalWrite(LED_BUILTIN,LOW);
  //toggleBlinds(stepper, buttonState);

}



void toggleLED(int buttonState,int& ledState){
  if(buttonState == HIGH){
    if(ledState == HIGH){
      ledState = LOW;
      digitalWrite(ledPin,LOW);
    }else{
      ledState = HIGH;
      digitalWrite(ledPin,HIGH);
    }
    delay(500);
  }
  return;
}
//might be more efficient to put button logic outside toggle blinds if multiple button 
//dependant functions are used
void toggleBlinds(A4988& stepper,int buttonState,int& blindState){
  if(buttonState == HIGH){
      if()
  } 
  return;
}
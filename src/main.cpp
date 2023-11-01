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
void toggleBlinds(A4988& stepper,int& blindState);
//toggles the led on the board on or off based on the press of a push button
void toggleLED(int& ledState);
//spins the motor enough times that it sets the blinds in a extended position
void engage(A4988& stepper);
//spins the motor in the closing direction until blinds are closed;
void disengage(A4988& stepper);


void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    toggleLED(ledState);



  }

  
}



void toggleLED(int& ledState){
  if(ledState == HIGH){
    ledState = LOW;
    digitalWrite(ledPin,LOW);
  }else{
    ledState = HIGH;
    digitalWrite(ledPin,HIGH);
  }
  delay(500);
  return;
}

void toggleBlinds(A4988& stepper,int& blindState){
  if(blindState == HIGH){
    blindState =LOW;
    disengage(stepper);
  }else{
    blindState = HIGH;
    engage(stepper);
  }
  delay(2000);
  return;
}
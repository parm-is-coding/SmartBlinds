#include <Arduino.h>
#include "A4988.h"
//pin macros
#define buttonPin 4
#define ledPin 13
//motor pins
// #define MOTOR_STEPS 200
// #define MICROSTEPS 1
// #define RPM 120

#define DIR 2
#define STEP 3
// #define MS1 9 
// #define MS2 10
// #define MS3 11
// put variable declarations here:
int buttonState = LOW;
int ledState = LOW;
//A4988 stepper(MOTOR_STEPS,DIR,STEP);
// put function declarations here:

//engage or disengage blinds based on buttonState
void toggleBlinds(A4988& stepper,int& blindState);
//toggles the led on the board on or off based on the press of a push button
void toggleLED(int& ledState);
//spins the motor enough times that it sets the blinds in a extended position
void engage(A4988& stepper);
//spins the motor in the closing direction until blinds are closed;
void disengage(A4988& stepper);
void rotateMotor360();

void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(DIR,OUTPUT);
  pinMode(STEP,OUTPUT);
  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    rotateMotor360();
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

void rotateMotor360(){
  digitalWrite(DIR,HIGH);
  for(int x =0; x < 200; x++){
    digitalWrite(STEP,HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP,LOW);
    delayMicroseconds(500);
  }
  delay(1000);

}

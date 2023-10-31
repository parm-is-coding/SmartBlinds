#include <Arduino.h>
#include "A4988.h"
// put variable declarations here:
const int buttonPin = 2;
int buttonState = LOW;
A4988 stepper();
// put function declarations here:
int toggleBlinds(A4988 stepper,int buttonState);

  // put your setup code here, to run once:
void setup() {
  pinMode(buttonPin,INPUT);

}

  // put your main code here, to run repeatedly:
void loop() {
  buttonState = digitalRead(buttonPin);
  //toggleBlinds(stepper, buttonState);

}

// put function definitions here:
int toggleBlinds(A4988 stepper,int buttonState){
  if(buttonState == HIGH){
    
    delay(10000);
  }
  return 1;
}
#include <Arduino.h>
#include "A4988.h"
#define buttonPin 4
#define ledPin 13
// put variable declarations here:
int buttonState = LOW;
int ledState = LOW;
//A4988 stepper();

// put function declarations here:

//int toggleBlinds(A4988 stepper,int buttonState);
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

// put function definitions here:
// int toggleBlinds(A4988 stepper,int buttonState){
//   if(buttonState == HIGH){
//     delay(10000);
//   }
//   return 1;
// }


void toggleLED(int buttonState,int& ledState){
  if(buttonState == HIGH){
    if(ledState == HIGH){
      ledState = LOW;
      digitalWrite(ledPin,LOW);
    }else{
      ledState = HIGH;
      digitalWrite(ledPin,HIGH);
    }
    delay(1000);
  }
  return;
}
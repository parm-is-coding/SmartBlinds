#include <Arduino.h>

//pin macros
#define buttonPin 4
#define ledPin 13
#define DIR 2
#define STEP 3

// put variable declarations here:
int buttonState = LOW;
int ledState = LOW;
// put function declarations here:

//engage or disengage blinds based on buttonState
void toggleBlinds(int& blindState);
//toggles the led on the board on or off based on the press of a push button
void toggleLED(int& ledState);
//spins the motor enough times that it sets the blinds in a extended position
void engage();
//spins the motor in the closing direction until blinds are closed;
void disengage();
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


//toggles the led on the arduino uno
//used to test push button functionality
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
//on click with toggle the blinds connected to the motor in the final state of the project
void toggleBlinds(int& blindState){
  if(blindState == HIGH){
    blindState =LOW;
    disengage();
  }else{
    blindState = HIGH;
    engage();
  }
  delay(2000);
  return;
}
//causes the motor to rotate 360 degrees 
//use this logic to define engage and disengage fns in toggle blinds
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

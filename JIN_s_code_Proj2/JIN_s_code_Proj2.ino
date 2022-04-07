/*
 AET Chang'e Story
 Team Name: The Jade Rabbits
 Team Members: Jose Nerio, Jessica Chen, and Anja Dahnke
 Description: button and servo program 
*/

//Servo code library
#include<Servo.h>;

//VARIABLES
Servo myservo;
const int buttonPin = 7;


void setup() {
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {
  
}

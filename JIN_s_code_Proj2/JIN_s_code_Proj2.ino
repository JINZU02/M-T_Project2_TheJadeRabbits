/*
AET Chang'e Story
Team Name: The Jade Rabbits
Team Members: Jose Nerio, Jessica Chen, and Anja Dahnke
Description: button and servo program
*/

//Servo code library
#include<Servo.h>;

//VARIABLES
Servo houYiServo;
Servo changeServo;
Servo arrowServo;

//if you want to change these pin numbers to make it organized, do so
const int bushPin = 4;
const int quiverPin = 8;
const int elixirPin = 5;
const int jadeRabbitPin = 12;
const int ledPin = 13;

void setup() {
 servos();
 pins();
 initialize();
}

void loop() {
 //if button is pressed, swivel servo 180 degrees
 if(digitalRead(bushPin) == LOW) {
   houYiServo.write(180);
   
   if(digitalRead(elixirPin) == HIGH) {
     moveChange();
   } 
   
   if(digitalRead(quiverPin) == HIGH) {
     moveArrow();
   }
   
   if(digitalRead(jadeRabbitPin) == LOW) {  //route 3
     rabbitMoon();
   } else {
    digitalWrite(ledPin, LOW);
   }

 }
}

void servos() {  //change these numbers if necessary for organization
 houYiServo.attach(2);  //using .attach to initialize servo to pin 11
 changeServo.attach(11);
 arrowServo.attach(6);
}

void pins() {
 pinMode(bushPin, INPUT);
 pinMode(quiverPin, INPUT);
 pinMode(elixirPin, INPUT);
 pinMode(jadeRabbitPin, INPUT);
}

void initialize() {
  houYiServo.write(0);
 changeServo.write(70);
 arrowServo.write(120);
}

void moveChange() {
 changeServo.write(20);
}

void moveArrow() {
 arrowServo.write(40);
}


void rabbitMoon() {
 digitalWrite(ledPin, HIGH);
}

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
float angle = 0;

//CONSTANTS
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

 if(digitalRead(bushPin) == LOW) {  //have to move the bush in order to start the story (also to move Hou Yi)
   houYiServo.write(180);
   
   if(digitalRead(elixirPin) == HIGH) {
     moveChange();
   } 
   
   if(digitalRead(quiverPin) == HIGH) {
     moveArrow();
   }
   
   if(digitalRead(jadeRabbitPin) == LOW) {
     rabbitMoon();
   } else {
    digitalWrite(ledPin, LOW);
   }

 }
}

//connecting servos to pins using .attach
void servos() {
 houYiServo.attach(2);
 changeServo.attach(11);
 arrowServo.attach(6);
}

void pins() {
 pinMode(bushPin, INPUT);
 pinMode(quiverPin, INPUT);
 pinMode(elixirPin, INPUT);
 pinMode(jadeRabbitPin, INPUT);
 pinMode(ledPin, OUTPUT);
}

//initializing servos to base angle
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

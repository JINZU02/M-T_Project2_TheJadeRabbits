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
const int bushPin = 13;
const int quiverPin = 12;
const int elixirPin = 8;
const int jadeRabbitPin = 7;
const int ledPin = 2;



void setup() {
  servos();
  pins();
}


void loop() {
  //if button is pressed, swivel servo 180 degrees
  if(digitalRead(bushPin) == LOW) {
    houYiServo.write(180);

    //part 1
    if(digitalRead(elixirPin) == HIGH && digitalRead(quiverPin) == LOW) {  //route 1 & 3
      scene1();
    } else if(digitalRead(elixirPin == LOW && digitalRead(quiverPin) == HIGH) {  //route 2 (arrow hits chang'e; end of story)
      scene1.2();
    }

    //part 2
    if(digitalRead(quiverPin) == HIGH && digitalRead(elixirPin) == HIGH) {  //route 1
      scene2();
    }

    //part 3
    if(digitalRead(quiverPin) == HIGH && digitalRead(elixirPin) == HIGH && digitalRead(jadeRabbit) == HIGH) {  //route 3
      scene3(); 
    }
  }


  
}



void servos() {  //change these numbers if necessary for organization
  houYiServo.attach(11);  //using .attach to initialize servo to pin 11
  changeServo.attach(10);
  arrowServo.attach(9);
}

void pins() {
  pinMode(bushPin, INPUT);
  pinMode(quiverPin, INPUT);
  pinMode(elixirPin, INPUT);
  pinMode(jadeRabbitPin, INPUT);
}


void scene1() {
  changeServo.write(90);
  arrowServo.write(0);
}

void scene1.2() {
  arrowServo.write(180);
  changeServo.write(0);
}

void scene2() {
  arrowServo.write(180);
}

void scene3() {
  digitalWrite(ledPin, HIGH);
}

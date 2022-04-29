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
int mapSpeed;

//CONSTANTS
const int bushPin = 13;
const int quiverPin = 8;
const int elixirPin = 12;
const int jadeRabbitPin = 7;
const int ledPin = 2;

void setup() {
  servos();
  pins();
  initialize();
}

void loop() {

  if (digitalRead(bushPin) == LOW) { //have to move the bush in order to start the story (also to move Hou Yi)
    houYiServo.write(180);

    if (digitalRead(elixirPin) == HIGH) {
      moveChange();
    }

    if (digitalRead(quiverPin) == HIGH) {
      moveArrow();
    }

    if (digitalRead(jadeRabbitPin) == LOW) {
      rabbitMoon();
    } else {
      digitalWrite(ledPin, LOW);
    }

  }
}

//connecting servos to pins using .attach
void servos() {
  houYiServo.attach(11);
  changeServo.attach(9);
  arrowServo.attach(10);
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
  //changeServo.write(20);

  moveTo(20, 15);
}

int pos1 = 70;
int pos = 0;

void moveTo(int position, int speed) {
  mapSpeed = map(speed, 0, 30, 30, 0);

  if (position > pos) {
    for (pos = pos1; pos >= position; pos -= 1) {  //move Chang'e at a slower pace
      changeServo.write(pos);
      pos1 = pos;
      delay(mapSpeed);
    }
  }

}

void moveArrow() {
  //arrowServo.write(40);


  //move arrow back and forth (stops when you remove the quiver)
  for (int pos = 40; pos <= 120; pos += 5) {
    arrowServo.write(pos);
    delay(15);
  }
  for (int pos = 120; pos >= 40; pos -= 1) {
    arrowServo.write(pos);
    delay(15);
  }

}


void rabbitMoon() {
  digitalWrite(ledPin, HIGH);
}

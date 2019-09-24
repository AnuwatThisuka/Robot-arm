#include <Arduino.h>
#include <AccelStepper.h>
#include <Servo.h>
#include <MultiStepper.h>
//driver for the axis X
#define PUL1_PIN 54
#define DIR1_PIN 55
#define ENA1_PIN 38
//driver for the axis y
#define PUL2_PIN 60
#define DIR2_PIN 61
#define ENA2_PIN 56
//driver for the axis z
#define PUL3_PIN 46
#define DIR3_PIN 48
#define ENA3_PIN 62
//driver for the axis e
#define PUL4_PIN 26
#define DIR4_PIN 28
#define ENA4_PIN 24
//driver for the axis e1
#define PUL5_PIN 36
#define DIR5_PIN 34
#define ENA5_PIN 30
//Servos motor
#define SERVOS1   4
#define SERVOS2   5
#define SERVOS3   6
#define SERVOS4  11

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;


AccelStepper motor_1(1,PUL1_PIN,DIR1_PIN);
AccelStepper motor_2(1,PUL3_PIN,DIR3_PIN);
AccelStepper motor_3(1,PUL4_PIN,DIR4_PIN);
AccelStepper motor_4(1,PUL5_PIN,DIR5_PIN);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

MultiStepper steppers;
MultiStepper steppers1;
MultiStepper steppers2;
MultiStepper steppers3;

//Servo ขึ้นลง สีเหลือง
//Servo ซ้ายขวา สีน้ำเงิน
//Servo 

void setup()
{
  Serial.begin(9600);
  motor_1.setEnablePin(ENA1_PIN);
  motor_1.setPinsInverted(false, false, true);
  motor_1.setMaxSpeed(160);
  motor_1.setAcceleration(100);
  motor_1.enableOutputs();

  motor_2.setEnablePin(ENA3_PIN);
  motor_2.setPinsInverted(false, false, true);
  motor_2.setMaxSpeed(80);
  motor_2.setAcceleration(100);
  motor_2.enableOutputs();

  motor_3.setEnablePin(ENA4_PIN);
  motor_3.setPinsInverted(false, false, true);
  motor_3.setMaxSpeed(250);
  motor_3.setAcceleration(100);
  motor_3.enableOutputs();

  motor_4.setEnablePin(ENA5_PIN);
  motor_4.setPinsInverted(false, false, true);
  motor_4.setMaxSpeed(160);
  motor_4.setAcceleration(150);
  motor_4.enableOutputs();

  //Servo 
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(11);

  //Multisteppers
  steppers.addStepper(motor_2);
  steppers.addStepper(motor_3);

  steppers1.addStepper(motor_1);
  steppers1.addStepper(motor_3);

  steppers2.addStepper(motor_2);
  steppers2.addStepper(motor_3);
  steppers2.addStepper(motor_1);
  
  steppers3.addStepper(motor_1);
  steppers3.addStepper(motor_2);
  steppers3.addStepper(motor_3);

}

void Multimotors1(){

  long positions[2];

  positions[0] = 200;
  positions[1] = 1100;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  delay(1000);
}

void Multimotors2(){

  long positions[2];

  positions[0] =  400;
  positions[1] = 500;
  steppers1.moveTo(positions);
  steppers1.runSpeedToPosition();
  delay(1000);
}

void Multimotors3(){

  long positions[3];

  positions[0] =  200;
  positions[1] =  1100;
  positions[2] =  0;
  steppers2.moveTo(positions);
  steppers2.runSpeedToPosition();
  delay(1000);
}

void Multimotors4(){

long positions[2];

  positions[0] = -400;
  positions[1] = 500;
  steppers1.moveTo(positions);
  steppers1.runSpeedToPosition();
  delay(1000);
}

void Home(){

long positions[3];

  positions[0] = 0;
  positions[1] = 0;
  positions[2] = 0;
  steppers3.moveTo(positions);
  steppers3.runSpeedToPosition();
  delay(1000);
}
void Servosmotor(){                    //มือจับ จับ
   servo1.write(-40);
   delay(200);
}
void Servosmotor1(){                    //มือจับ ปล่อย
   servo1.write(40);
   delay(200);
}
void ServoRL(){
  servo4.write(40);
   delay(200);
}
void ServoUpDown(){
  servo2.write(60);
   delay(200);
}
void TESTxxx(){
  motor_2.runToNewPosition(-80);
  delay(500); 
  Multimotors1();
  delay(500);
  Multimotors2();
  delay(500);
  Servosmotor();
  delay(500);
  Multimotors3();
  delay(500);
  Multimotors4();
  delay(500);
  Servosmotor1();
  delay(500);
  Home();
  delay(1000);
  Multimotors1();
  delay(500);
  Multimotors4();
  delay(500);
  Servosmotor();
  delay(500);
  Multimotors3();
  delay(500);
  Multimotors2();
  delay(500);
  Servosmotor1();
  delay(500);
  Home();
  delay(1000);
}

void loop(){
  motor_2.runToNewPosition(-80);
  delay(500); 
  Multimotors1();
  delay(500);
  Multimotors2();
  delay(500);
  Servosmotor();
  delay(500);
  Multimotors3();
  delay(500);
  Multimotors4();
  delay(500);
  Servosmotor1();
  delay(500);
  Home();
  delay(1000);
  Multimotors1();
  delay(500);
  Multimotors4();
  delay(500);
  Servosmotor();
  delay(500);
  Multimotors3();
  delay(500);
  Multimotors2();
  delay(500);
  Servosmotor1();
  delay(500);
  Home();
  delay(1000);
}

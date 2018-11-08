#include "Sonar.h"
#include "Arduino.h"

Sonar::Sonar(int pinEcho, int pinTrig){
  this->pinEcho = pinEcho;
  this->pinTrig = pinTrig;
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
}

int Sonar::getValue(){
  return 0;
};

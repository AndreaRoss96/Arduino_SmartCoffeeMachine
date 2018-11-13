#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
  pinMode(pin, INPUT); 
}

float Potentiometer::getValue(){
  return analogRead(pin);
};

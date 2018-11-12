#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
  this->pin = pin;
}

float Potentiometer::getValue(){
  return analogRead(pin);
};

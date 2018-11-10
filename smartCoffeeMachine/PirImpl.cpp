#include "PirImpl.h"
#include "Arduino.h"

PirImpl::PirImpl(int pin){
  this->pin = pin;
  pinMode(pin,INPUT);
}

float PirImpl::getValue(){
  return digitalRead(pin);

};

#include "PirImpl.h"
#include "Arduino.h"

PirImpl::PirImpl(int pin){
  this->pin = pin;
  pinMode(pin,INPUT);
}

int PirImpl::getValue(){
  return digitalRead(pin);
};

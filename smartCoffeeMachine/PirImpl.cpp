#include "PirImpl.h"

PirImpl::PirImpl(int pin){
  this->pin = pin;
}

float PirImpl::getValue(){
  return digitalRead(pin);
}

int PirImpl::getPin(){
    return pin;
};

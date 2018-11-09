#ifndef __PIRIMPL__
#define __PIRIMPL__

#include "Sensor.h"

class PirImpl: public Sensor{
public:
  PirImpl(int pin);
  float getValue();

private:
  int pin;
};

#endif

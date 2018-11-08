#ifndef __PIRIMPL__
#define __PIRIMPL__

#include "Sensor.h"

class PirImpl: public Sensor{
public:
  PirImpl(int pin);
  int getValue();

private:
  int pin;
};

#endif

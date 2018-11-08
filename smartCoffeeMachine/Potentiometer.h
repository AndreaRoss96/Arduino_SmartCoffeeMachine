#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__

#include "Sensor.h"

class Potentiometer: public Sensor{
public:
  Potentiometer(int pin);
  int getValue();

private:
  int pin;
};

#endif

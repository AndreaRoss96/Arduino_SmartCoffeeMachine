#ifndef __THREELEDSHOW__
#define __THREELEDSHOW__

#include "Led.h"
#include "GlobalClass.h"
#include "Arduino.h"

class ThreeLedShow {

private:
  int pin[3];
  Light* led[3];
  float myPeriod;

public:
  ThreeLedShow(int pin0, int pin1, int pin2);
  void startShow();   //turn on all leds in DT3 seconds
  void resetLed();    //turn off all three leds
};

#endif

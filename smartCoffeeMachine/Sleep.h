
#ifndef __SLEEP__
#define __SLEEP__

#include "Phase.h"
#include "PirImpl.h"
#include "Arduino.h"
#include <avr/sleep.h>

class Sleep: public Phase {
public:
  Sleep(PirImpl& pir);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
 // PirImpl& pir;
  int pin;
  static void wakeUp();
};

#endif

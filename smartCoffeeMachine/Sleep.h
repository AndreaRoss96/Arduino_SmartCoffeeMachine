#ifndef __SLEEP__
#define __SLEEP__

#include "Phase.h"
#include <avr/sleep.h>

class Sleep: public Phase {
public:
  Sleep(int pinToIntterupt);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  int pin;
  static void wakeUp();
};

#endif

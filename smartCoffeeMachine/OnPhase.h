#ifndef __ONPHASE__
#define __ONPHASE__

#include "Phase.h"
#include "PirImpl.h"
#include "Sonar.h"

class OnPhase: public Phase {
public:
  OnPhase(PirImpl& pir, Sonar& sonar);
  bool updateAndCheckTime(int basePeriod);
private:
  PirImpl& pir;
  Sonar& sonar;
  int myPeriodAscent;
  int myperiodDiscent;
  int timeElapsed;
};

#endif

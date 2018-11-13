#ifndef __ONPHASE__
#define __ONPHASE__

#include "Phase.h"
#include "PirImpl.h"
#include "Sonar.h"

class OnPhase: public Phase {
public:
  OnPhase(PirImpl* pir, Sonar* sonar);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  PirImpl* pir;
  Sonar* sonar;
  int timeElapsed;
  boolean movement;     //true se c'è del moviemnto, false altrimenti
  boolean isNear;       //true se qualcuno è nelle vicinanze, false altrimenti
};

#endif

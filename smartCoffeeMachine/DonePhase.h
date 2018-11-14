#ifndef __DONEPHASE__
#define __DONEPHASE__

#include "Phase.h"
#include "Sonar.h"

class DonePhase: public Phase {
public:
  DonePhase(Sonar* sonar);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  Sonar* sonar;
  int timeElapsed;
};

#endif

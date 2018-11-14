#ifndef __MAINTENANCE__
#define __MAINTENANCE__

#include "Phase.h"

class Maintenance: public Phase {
public:
  Maintenance();
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  int timeElapsed;
};

#endif

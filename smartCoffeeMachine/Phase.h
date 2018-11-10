#ifndef __PHASE__
#define __PHASE__

#include "EnumPhase.h"

class Phase {
public:
  virtual bool updateAndCheckTime(int basePeriod);
  virtual void tick() = 0;
private:
  EnumPhase myPhase;
};

#endif

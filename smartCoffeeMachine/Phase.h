#ifndef __PHASE__
#define __PHASE__

#include "GlobalClass.h"

class Phase {
public:
  virtual bool updateAndCheckTime(int basePeriod) = 0;
  virtual void tick() = 0;
protected:
  EnumPhase myPhase;
};

#endif

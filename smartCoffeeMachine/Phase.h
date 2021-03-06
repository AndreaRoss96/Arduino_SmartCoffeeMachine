#ifndef __PHASE__
#define __PHASE__

#define GLOBAL_CLASS GlobalClass::getInstance()

#include "GlobalClass.h"
#include "Arduino.h"
#include "MsgService.h"

class Phase {
public:
  virtual bool updateAndCheckTime(int basePeriod) = 0;
  virtual void tick() = 0;
};

#endif

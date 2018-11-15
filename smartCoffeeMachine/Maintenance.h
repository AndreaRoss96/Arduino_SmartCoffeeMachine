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
  boolean printed;                //se true, significa che ha già inviato le informazioni a java, altrimenti false
};

#endif

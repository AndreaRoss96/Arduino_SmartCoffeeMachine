#ifndef __ONPHASE__
#define __ONPHASE__

#include "Phase.h"

class OnPhase: public Phase {
public:
  OnPhase(Sensor pir, Sonar sonar);
  void update();  // modificare void con Filo
private:
  Sensor pir;
  Sonar sonar;
};

#endif

#ifndef __SLEEP__
#define __SLEEP__

#include "Phase.h"
#include "PirImpl.h"

class Sleep: public Phase {
public:
  Sleep(PirImpl& pir);
  void update();
private:
  PirImpl& pir;
};

#endif
// cancellare il file

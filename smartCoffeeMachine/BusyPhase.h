#ifndef __BUSYPHASE__
#define __BUSYPHASE__

#include "Phase.h"
#include "Led.h"

class BusyPhase: public Phase {
public:
  BusyPhase(Led* led1,Led* led2,Led* led3);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  int timeElapsed;
  Led* led1;
  Led* led2;
  Led* led3;
  bool take;
  bool printed;             //true se ha insviato il messaggio, false altrimenti
};

#endif

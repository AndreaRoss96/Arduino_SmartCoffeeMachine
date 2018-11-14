#ifndef __READYPHASE__
#define __READYPHASE__

#include "Phase.h"
#include "Potentiometer.h"
#include "Sonar.h"
#include "ButtonImpl.h"
#include "MsgService.h"

class ReadyPhase: public Phase {
public:
  ReadyPhase(Sonar* sonar, Potentiometer* potentiometer, ButtonImpl* button);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  Sonar* sonar;
  Potentiometer* potentiometer;
  ButtonImpl* button;
  int timeElapsed;
  int lastKnownSugar;
  boolean started;
};

#endif

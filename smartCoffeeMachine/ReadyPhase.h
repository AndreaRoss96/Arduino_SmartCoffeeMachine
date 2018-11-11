#ifndef __READYPHASE__
#define __READYPHASE__

#include "Phase.h"
#include "Potentiometer.h"
#include "Sonar.h"
#include "ButtonImpl.h"

class ReadyPhase: public Phase {
public:
  ReadyPhase(Sonar& sonar, Potentiometer& sonar, ButtonImpl& button);
  bool updateAndCheckTime(int basePeriod);
  void tick();
private:
  Sonar& sonar;
  Potentiometer& sonar;
  ButtonImpl& button;
  int myPeriod;
  int timeElapsed;
};

#endif

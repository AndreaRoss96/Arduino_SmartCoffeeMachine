#include "OnPhase.h"
#include "Arduino.h"
//ricordarsi di distinguere ON_ASCENT e ON_DISCENT che hanno tempi diversi
OnPhase::OnPhase(PirImpl& pir, Sonar& sonar){
  this -> pir = pir;
  this -> sonar = sonar;
  this -> myPeriodAscent = GlobalClass::getInstance()->getDT1();
  this -> myperiodDiscent = GlobalClass::getInstance()->getDT2B();
  myPhase = EnumPhase::ON;
}

bool OnPhase::updateAndCheckTime(int basePeriod){
  if(GlobalClass::getInstance()->getActualPhase() == EnumPhase::ON_ASCENT || GlobalClass::getInstance()->getActualPhase() == EnumPhase::ON_DISCENT){ // se la fase attuale e' ON qualsiasi
    timeElapsed += basePeriod;
    if(timeElapsed >= GlobalClass::getInstance()->getActualPhase() == EnumPhase::ON_ASCENT ? myPeriodAscent : myperiodDiscent){ //se la fase attuale e' onAScent utilizza dt1 altrimenti dt2b
      timeElapsed = 0;
      return true;
    }else{
      return false;
    }
  } else{
  return false;
  }
};

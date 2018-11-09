#include "Sleep.h"
#include "Arduino.h"

Sleep::Sleep(PirImpl& pir){
  this -> pir = pir;
};

EnumPhase Sleep::update(){
  EnumPhase p;
  p.allPhases = EnumPhase::ON;
  return p;
};

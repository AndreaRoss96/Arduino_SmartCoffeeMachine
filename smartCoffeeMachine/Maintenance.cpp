#include "Maintenance.h"

Maintenance::Maintenance(){
  this->timeElapsed = 0;
}

bool Maintenance::updateAndCheckTime(int basePeriod){
  if(GLOBAL_CLASS.getActualPhase() == EnumPhase::MAINTENANCE){     //se non è la sua fase restituisce false
    timeElapsed += basePeriod;
    return true;
  }else{
    return false;
  }
}

void Maintenance::tick(){
  if(GLOBAL_CLASS.getNc() != 0){
    GLOBAL_CLASS.setActualPhase(EnumPhase::SLEEP);
    timeElapsed = 0;
  }
  Serial.println("Ho bisogno di capsuleeeeeee");
}

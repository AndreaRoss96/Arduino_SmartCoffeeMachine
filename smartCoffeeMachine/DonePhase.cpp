#include "DonePhase.h"

DonePhase::DonePhase(Sonar* sonar){
  this->timeElapsed = 0;
  this -> sonar = sonar;
}

bool DonePhase::updateAndCheckTime(int basePeriod){
  if(GLOBAL_CLASS.getActualPhase() == EnumPhase::DONE){     //se non è la sua fase restituisce false
    timeElapsed += basePeriod;
    return true;
  }else{
    return false;
  }
}

void DonePhase::tick(){
  if(GLOBAL_CLASS.getNc() == 0){
    GLOBAL_CLASS.setActualPhase(EnumPhase::MAINTENANCE);
  } else{
    if(timeElapsed > GLOBAL_CLASS.getDT4()){                    //torna a ready anche se la "tazzina" non viene presa, dopo DT4
      timeElapsed = 0;
      GLOBAL_CLASS.setActualPhase(EnumPhase::READY);
    } else if (sonar -> getValue() <= GLOBAL_CLASS.getDist2()){ //ritorna subito a ready se viene presa la "tazzina" di caffé
      timeElapsed = 0;
      GLOBAL_CLASS.setActualPhase(EnumPhase::READY);
    }
  }
}

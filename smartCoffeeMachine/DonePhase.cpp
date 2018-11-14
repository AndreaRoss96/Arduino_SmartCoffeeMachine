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
    if(timeElapsed > GLOBAL_CLASS.getDT4()){
      timeElapsed = 0;
      GLOBAL_CLASS.setActualPhase(EnumPhase::READY);
    } else if (sonar -> getValue() <= GLOBAL_CLASS.getDist2()){
      Serial.print("ho preso il caffe'");
      timeElapsed = 0;
      GLOBAL_CLASS.setActualPhase(EnumPhase::READY);
    }
  }
}

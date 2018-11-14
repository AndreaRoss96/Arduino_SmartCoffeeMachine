#include "ReadyPhase.h"

ReadyPhase::ReadyPhase(Sonar* sonar, Potentiometer* potentiometer, ButtonImpl* button){
  this->sonar = sonar;
  this->potentiometer = potentiometer;
  this->button = button;

  this->lastKnownSugar = map(potentiometer->getValue(),0,1023,0,5);   //ultimo livello di zucchero misurato
  this->timeElapsed = 0;
}

bool ReadyPhase::updateAndCheckTime(int basePeriod){
  if(GLOBAL_CLASS.getActualPhase() == EnumPhase::READY){     //se non è la sua fase restituisce false
    timeElapsed += basePeriod;
    return true;
  }else{
    return false;
  }
}

void ReadyPhase::tick(){
    if(timeElapsed > GLOBAL_CLASS.getDT2A()){                    //se è passato troppo tempo cambia fase
        GLOBAL_CLASS.setActualPhase(EnumPhase::ON);
        Serial.println("Torno in ON");
        timeElapsed = 0;
    } else {
      if(sonar->getValue() <= GLOBAL_CLASS.getDist1()){ // se è vero rimane in ReadyPhase
        timeElapsed = 0;
      }
      int tmp = map(potentiometer->getValue(),0,1023,0,5);
      if(lastKnownSugar != tmp){
        lastKnownSugar = tmp;
      }
      if(button->isPressed()){
        GLOBAL_CLASS.setActualPhase(EnumPhase::BUSY);
        timeElapsed = 0;
      }
    }
}

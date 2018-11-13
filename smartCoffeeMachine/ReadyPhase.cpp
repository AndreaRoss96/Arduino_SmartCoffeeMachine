#include "ReadyPhase.h"

ReadyPhase::ReadyPhase(Sonar* sonar, Potentiometer* potentiometer, ButtonImpl* button){
  this->sonar = sonar;
  this->potentiometer = potentiometer;
  this->button = button;
  this->myPhase = EnumPhase::READY;
  this->myPeriod = GLOBAL_CLASS.getDT2A();

  this->myDistance = GLOBAL_CLASS.getDist1();
  this->lastKnownSugar = map(potentiometer->getValue(),0,1023,0,5);   //ultimo livello di zucchero misurato
  this->timeElapsed = 0;
}

bool ReadyPhase::updateAndCheckTime(int basePeriod){
  if(GLOBAL_CLASS.getActualPhase() == myPhase){     //se non è la sua fase restituisce false
    timeElapsed += basePeriod;
    return true;
  }else{
    return false;
  }
}

void ReadyPhase::tick(){
    if(timeElapsed > myPeriod){                    //se è passato troppo tempo cambia fase
        GLOBAL_CLASS.setActualPhase(EnumPhase::ON);
        Serial.println("Torno in ON");
        Serial.print("Valore sonar: ");
        Serial.println(sonar->getValue());
        timeElapsed = 0;
    } else {
      if(sonar->getValue() <= myDistance){ // se è vero rimane in ReadyPhase
        timeElapsed = 0;
      }
      if(lastKnownSugar != map(potentiometer->getValue(),0,1023,0,5)){
        lastKnownSugar = map(potentiometer->getValue(),0,1023,0,5);
        Serial.println(lastKnownSugar);
        Serial.flush();
      }
      if(button->isPressed()){
        GLOBAL_CLASS.setActualPhase(EnumPhase::BUSY);
        Serial.println("Sono andato in busy");
        timeElapsed = 0;
      }
    }
}

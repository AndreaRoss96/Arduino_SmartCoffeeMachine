#include "BusyPhase.h"

BusyPhase::BusyPhase(Led* led1,Led* led2,Led* led3){
  this->timeElapsed = 0;
  this -> led1 = led1;
  this -> led2 = led2;
  this -> led3 = led3;
}

bool BusyPhase::updateAndCheckTime(int basePeriod){
  if(GLOBAL_CLASS.getActualPhase() == EnumPhase::BUSY){     //se non è la sua fase restituisce false
    timeElapsed += basePeriod;
    return true;
  }else{
    return false;
  }
}

void BusyPhase::tick(){
  if(timeElapsed > 3000){                       // se il tempo per la fase di busy e' finito passa alla fase di done e spegni tutti i led.
    GLOBAL_CLASS.setActualPhase(EnumPhase::DONE);
    Serial.println("Vado in DONE")
    led1 -> switchOff();
    led2 -> switchOff();
    led3 -> switchOff();
  } else {
    if(timeElapsed <= 1000 && timeElapsed > 0){     // accensione dei led in maniera progressiva in 3 secondi. uno ogni 1000 millisecondi
      led1 -> switchOn();
    }else if (timeElapsed <= 2000 && timeElapsed > 1000){
      led2 -> switchOn();
    }else if(timeElapsed <= 3000 && timeElapsed > 2000){
      led3 -> switchOn();
    }
  }
}

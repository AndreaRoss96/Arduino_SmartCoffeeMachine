#include "BusyPhase.h"

BusyPhase::BusyPhase(Led* led1,Led* led2,Led* led3){
  this->timeElapsed = 0;
  this -> led1 = led1;
  this -> led2 = led2;
  this -> led3 = led3;
  this -> take = false;
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
  if(timeElapsed > GLOBAL_CLASS.getDT3()){                       // se il tempo per la fase di busy e' finito passa alla fase di done e spegni tutti i led.
    take = false;
    timeElapsed = 0;
    Serial.println("Vado in DONE");
    led1 -> switchOff();
    led2 -> switchOff();
    led3 -> switchOff();
    GLOBAL_CLASS.setActualPhase(EnumPhase::DONE);
  } else {
    if(timeElapsed <= GLOBAL_CLASS.getTimeRangeLed() && timeElapsed > 0){     // accensione dei led in maniera progressiva in 3 secondi. uno ogni 1000 millisecondi
      if(!take){
        GLOBAL_CLASS.decNCoffe();
        Serial.println(GLOBAL_CLASS.getNc());
      }
      take = true;
      led1 -> switchOn();                                                     // verifica se il tempo trascorso e' minore o uguale a 5 secondi diviso il numero di led (questo calcolo equivale a getTimeRangeLed)
    }else if (timeElapsed <= GLOBAL_CLASS.getTimeRangeLed()*2 && timeElapsed > GLOBAL_CLASS.getTimeRangeLed()){
      led2 -> switchOn();
    }else if(timeElapsed <= GLOBAL_CLASS.getTimeRangeLed()*3 && timeElapsed > GLOBAL_CLASS.getTimeRangeLed()*2){
      led3 -> switchOn();
    }
  }
}

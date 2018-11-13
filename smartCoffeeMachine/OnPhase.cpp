#include "OnPhase.h"

OnPhase::OnPhase(PirImpl* pir, Sonar* sonar) {
  this -> pir = pir;
  this -> sonar = sonar;
  this -> myPeriodAscent = GLOBAL_CLASS.getDT1(); //si possono togliere
  this -> myperiodDiscent = GLOBAL_CLASS.getDT2B();
  myPhase = EnumPhase::ON;
  movement = false;
  isNear = false;
}

bool OnPhase::updateAndCheckTime(int basePeriod){
    if(GLOBAL_CLASS.getActualPhase() == myPhase){
        timeElapsed += basePeriod;
        return true; //quindi esegue tick() (vd scheduler)
  } else {
      return false;
  }
}

void OnPhase::tick() {
    Serial.println(sonar->getValue());
    Serial.print(GLOBAL_CLASS.getActualPhase() == EnumPhase::ON ? "SONO IN ON" : "FigliDiPuttana");
    if(sonar->getValue() <= GLOBAL_CLASS.getDist1()){               //controllo se c'è qualcuno vicino
        if(isNear){                                                 //se c'era qualcuno vicion anche prima
        Serial.println(timeElapsed);
            if(timeElapsed >= GLOBAL_CLASS.getDT1()) {           //controllo se il tempo passato è soddisfacente
                GLOBAL_CLASS.setActualPhase(EnumPhase::READY);      //per passare a ready
                Serial.println("Setto a ready!");
                Serial.flush();
            }
        } else {                                                    //altrimenti è la prima volta che ho qualcuno vicino
            isNear = true;
            timeElapsed = 0;
        }
    } else {                                                        //se non c'è nessuno vicino controllo che almeno ci sia del movimento
        isNear = false;
        if(!pir->getValue()){                                       //mi assicuro che non ci sia del movimento
            if(!movement){                                          //controllo se non c'era neanche prima
                if (timeElapsed >= GLOBAL_CLASS.getDT2B()) {          //controllo se il tempo passato è soddisfacente
                    GLOBAL_CLASS.setActualPhase(EnumPhase::SLEEP);  //per passare alla fase di sleep
                }
            } else {                                                //se prima c'era qualcuno e adesso non c'è più nessuno
                movement = false;
                timeElapsed = 0;                                    //resetto il timer
            }
        } else {
            movement = true;                                        //rilevo del movimento, quindi ne tengo memoria
        }
    }
};

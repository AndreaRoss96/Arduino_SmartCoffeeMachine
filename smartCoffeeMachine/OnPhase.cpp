#include "OnPhase.h"
//ricordarsi di distinguere ON_ASCENT e ON_DISCENT che hanno tempi diversi
//time_t start_t, end_t;
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
    Serial.println("Check di onPhase");
//  if(GLOBAL_CLASS.getActualPhase() == EnumPhase::ON_ASCENT || GLOBAL_CLASS.getActualPhase() == EnumPhase::ON_DISCENT){ // se la fase attuale e' ON qualsiasi
    if(GLOBAL_CLASS.getActualPhase() == myPhase){
        timeElapsed += basePeriod;
        return true;
    // if(timeElapsed <=  myPeriodAscent){ //se la fase attuale e' onAscent utilizza dt1 altrimenti dt2b
    //     return true; //quindi fa il tick (vd. scheduler)
    // } else { //il tempo è terminato quindi vuol dire che per dt secondi ho rilevato qualcuno a dist < 30 cm
    //     GLOBAL_CLASS.setActualPhase(EnumPhase::READY); // vado in ready
    //     timeElapsed = 0;
    //     return false;
    // }
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
            if(timeElapsed >= GLOBAL_CLASS.getDT1())                //controllo se il tempo passato è soddisfacente
                GLOBAL_CLASS.setActualPhase(EnumPhase::READY);      //per passare a ready
                Serial.println("Setto a ready!");
                Serial.flush();
        } else {                                                    //altrimenti è la prima volta che ho qualcuno vicino
            isNear = true;
            timeElapsed = 0;
        }
    } else {                                                        //se non c'è nessuno vicino controllo che almeno ci sia del movimento
        isNear = false;
        if(!pir->getValue()){                                       //mi assicuro che non ci sia del movimento
            if(!movement){                                          //controllo se non c'era neanche prima
                if (timeElapsed >= GLOBAL_CLASS.getDT2B())          //controllo se il tempo passato è soddisfacente
                    GLOBAL_CLASS.setActualPhase(EnumPhase::SLEEP);  //per passare alla fase di sleep
            } else {                                                //se prima c'era qualcuno e adesso non c'è più nessuno
                movement = false;
                timeElapsed = 0;                                    //resetto il timer
            }
        } else {
            movement = true;                                        //rilevo del movimento, quindi ne tengo memoria
        }
    }
};

    /*
  if(start_t == NULL && sonar.getValue() <= GLOBAL_CLASS.getDist1()){    // se il tempo non e' stato preso e la distanza e' minore di 30 cm prendi il tempo
    time(&start_t);
  }else if(start_t != NULL && sonar.getValue() <= GLOBAL_CLASS.getDist1()){  // se il tempo e' stato preso precedentemente e la distanza e' minore di 30 cm fai la differenza dei tempi
    time(&end_t);
    if(difftime(end_t,start_t)*1000 >= (double)GLOBAL_CLASS.getDT1()){
      GLOBAL_CLASS.setActualPhase(EnumPhase::READY); //stampa a schermo welcome (JAVA)
    }
}else if(sonar.getValue() > GLOBAL_CLASS.getDist1()){
    start_t = end_t = NULL;
  }
  */

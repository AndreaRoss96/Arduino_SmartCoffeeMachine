#include "OnPhase.h"
#include "Arduino.h"
//ricordarsi di distinguere ON_ASCENT e ON_DISCENT che hanno tempi diversi
//time_t start_t, end_t;
OnPhase::OnPhase(PirImpl* pir, Sonar* sonar)
{
  // this -> pir = pir;
  // this -> sonar = sonar;
  this -> myPeriodAscent = GlobalClass::getInstance()->getDT1();
  this -> myperiodDiscent = GlobalClass::getInstance()->getDT2B();
  myPhase = EnumPhase::ON;
}

bool OnPhase::updateAndCheckTime(int basePeriod){
  if(GlobalClass::getInstance()->getActualPhase() == EnumPhase::ON_ASCENT || GlobalClass::getInstance()->getActualPhase() == EnumPhase::ON_DISCENT){ // se la fase attuale e' ON qualsiasi
    timeElapsed += basePeriod;
    if(timeElapsed <= (GlobalClass::getInstance()->getActualPhase() == EnumPhase::ON_ASCENT ? myPeriodAscent : myperiodDiscent)){ //se la fase attuale e' onAscent utilizza dt1 altrimenti dt2b
        return true;
    }else{ //il tempo è terminato quindi vuol dire che per dt secondi ho rilevato qualcuno a dist < 30 cm
        GlobalClass::getInstance()->setActualPhase(EnumPhase::READY); // vado in ready
        return false;
    }
  } else {
      return false;
  }
}

void OnPhase::tick(){
    if(sonar.getValue() > GlobalClass::getInstance()->getDist1()) { //se non rilevo nessuno sotto i 30 cm torno in SLEEP
        GlobalClass::getInstance()->setActualPhase(EnumPhase::SLEEP);
    }

    /*
  if(start_t == NULL && sonar.getValue() <= GlobalClass::getInstance()->getDist1()){    // se il tempo non e' stato preso e la distanza e' minore di 30 cm prendi il tempo
    time(&start_t);
  }else if(start_t != NULL && sonar.getValue() <= GlobalClass::getInstance()->getDist1()){  // se il tempo e' stato preso precedentemente e la distanza e' minore di 30 cm fai la differenza dei tempi
    time(&end_t);
    if(difftime(end_t,start_t)*1000 >= (double)GlobalClass::getInstance()->getDT1()){
      GlobalClass::getInstance()->setActualPhase(EnumPhase::READY); //stampa a schermo welcome (JAVA)
    }
  }else if(sonar.getValue() > GlobalClass::getInstance()->getDist1()){
    start_t = end_t = NULL;
  }
  */
};

#define TIME_TO_SHOW_MESSAGE 10

#include "Maintenance.h"

Maintenance::Maintenance(){
  this->timeElapsed = 0;
  this->printed = false;
}

bool Maintenance::updateAndCheckTime(int basePeriod){
  return GLOBAL_CLASS.getActualPhase() == EnumPhase::MAINTENANCE;     //se non è la sua fase restituisce false
}

void Maintenance::tick(){
  if(GLOBAL_CLASS.getNc() != 0) {
    if (timeElapsed == TIME_TO_SHOW_MESSAGE) {
        GLOBAL_CLASS.setActualPhase(EnumPhase::SLEEP);
    } else {
        timeElapsed++;
    }
    printed = !printed;
} else {
      if(!printed) {
        MsgService.sendMsg("10");
        printed = !printed;
      }
      Msg * msg = MsgService.receiveMsg();                     //riceve il messaggio da java
      String tmp = msg->getContent();
      if(tmp.substring(0,6) == "refill"){
          GLOBAL_CLASS.refillCoffee(msg->getContent().substring(6,7).toInt());    //fa il parse della stringa che gli viene ritornata e refilla la macchinetta
      }
    }
}

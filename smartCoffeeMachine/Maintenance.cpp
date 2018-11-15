#include "Maintenance.h"

using namespace std;

using namespace std;
#include <string.h>

Maintenance::Maintenance(){
  this->timeElapsed = 0;
  this->printed = false;
}

bool Maintenance::updateAndCheckTime(int basePeriod){
  if(GLOBAL_CLASS.getActualPhase() == EnumPhase::MAINTENANCE){     //se non è la sua fase restituisce false
    timeElapsed += basePeriod;
    return true;
  }else{
    return false;
  }
}

void Maintenance::tick(){
  if(GLOBAL_CLASS.getNc() != 0) {
    GLOBAL_CLASS.setActualPhase(EnumPhase::SLEEP);
    timeElapsed = 0;
    printed = !printed;
  }
  if(!printed) {
    MsgService.sendMsg("10");
     printed = !printed;
  }
  if(MsgService.isMsgAvailable()) {
    Msg * msg = MsgService.receiveMsg();                        //riceve il messaggio da java
    GLOBAL_CLASS.refillCoffee(msg->getContent().toInt());    //fa il parse della stringa che gli viene ritornata e refilla la macchinetta
  }
}

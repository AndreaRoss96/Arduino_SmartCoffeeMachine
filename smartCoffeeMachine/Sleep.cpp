#include "Sleep.h"

Sleep::Sleep(PirImpl& pir){
  this -> pin = pir.getPin();

}

bool Sleep::updateAndCheckTime(int basePeriod) {
    return GlobalClass::getInstance()->getActualPhase() == EnumPhase::SLEEP;
}

void Sleep::tick(){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); //setta la modalità di sleep
    sleep_enable(); //abilita le sleep
    attachInterrupt(digitalPinToInterrupt(pin), wakeUp, CHANGE); //quando il pin rileva un movimento sveglia il dispositivo
    sleep_mode(); //VA A DROMIRE

    sleep_disable(); //disabilita la sleep
    detachInterrupt(digitalPinToInterrupt(pin));
    
    GlobalClass::getInstance()->setActualPhase(EnumPhase::ON); //passa alla fase on
}

void Sleep::wakeUp() {

};

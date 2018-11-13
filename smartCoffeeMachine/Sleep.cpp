#include "Sleep.h"

Sleep::Sleep(int pinToIntterupt){
  this->pin = pinToIntterupt;
  pinMode(pin,INPUT);
}

bool Sleep::updateAndCheckTime(int basePeriod) {
    return GLOBAL_CLASS.getActualPhase() == EnumPhase::SLEEP;
}

void Sleep::tick(){
    Serial.println("GOING IN POWER DOWN IN 0s ...");
    Serial.flush();

    attachInterrupt(digitalPinToInterrupt(pin), wakeUp, CHANGE); //quando il pin rileva un movimento sveglia il dispositivo

    //set_sleep_mode(SLEEP_MODE_PWR_DOWN); //setta la modalità di sleep
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable(); //abilita le sleep

    sleep_cpu();//VA A DROMIRE

    Serial.println("ueic ap");
    Serial.flush();

    sleep_disable(); //disabilita la sleep
    detachInterrupt(digitalPinToInterrupt(pin));

    Serial.println("ueic ap");
    Serial.flush();

    GLOBAL_CLASS.setActualPhase(EnumPhase::ON); //passa alla fase on
}

void Sleep::wakeUp() {
    Serial.println("Interrupttt");
        Serial.flush();
};

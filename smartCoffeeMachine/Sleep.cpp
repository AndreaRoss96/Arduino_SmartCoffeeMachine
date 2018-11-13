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

    attachInterrupt(digitalPinToInterrupt(pin), wakeUp, RISING); //quando il pin rileva un movimento sveglia il dispositivo

    set_sleep_mode(SLEEP_MODE_PWR_DOWN); //setta la modalità di sleep
    sleep_enable(); //abilita le sleep

    sleep_mode();//VA A DROMIRE

    Serial.println("ueic ap");
    Serial.flush();

    sleep_disable(); //disabilita la sleep
    detachInterrupt(digitalPinToInterrupt(pin));

    GLOBAL_CLASS.setActualPhase(EnumPhase::ON); //passa alla fase on
}

void Sleep::wakeUp() {
    Serial.println("Interrupt");
        Serial.flush();
};

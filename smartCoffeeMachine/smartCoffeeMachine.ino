#include "Sleep.h"
#include "ReadyPhase.h"
#include "Sonar.h"
#include "OnPhase.h"
#include "Scheduler.h"
#include "ButtonImpl.h"
#include "Potentiometer.h"
#include "MsgService.h"

Scheduler scheduler;

void setup() {
    Serial.begin(9600);
    Serial.flush();
    MsgService.init();
//inizializzazione dei componenti
    PirImpl* pir = new PirImpl(2);
    Sonar* sonar = new Sonar(8, 9);
    Potentiometer* potentiometer = new Potentiometer(A5);
    ButtonImpl* button = new ButtonImpl(4);
//Creazione delle fasi
    Phase* sleep = new Sleep(2);
    Phase* on = new OnPhase(pir, sonar);
    Phase* ready = new ReadyPhase(sonar, potentiometer, button);

    scheduler.init(100); //viene chiamato lo scheduler 100 volte/s
    scheduler.addPhase(sleep);
    scheduler.addPhase(on);
    scheduler.addPhase(ready);
}

void loop(){
    scheduler.schedule();
}

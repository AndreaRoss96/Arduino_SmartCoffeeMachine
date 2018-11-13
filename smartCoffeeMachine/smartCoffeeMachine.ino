#include "Sleep.h"
#include "ReadyPhase.h"
#include "Sonar.h"
#include "OnPhase.h"
#include "Scheduler.h"
#include "ButtonImpl.h"
#include "Potentiometer.h"

Scheduler scheduler;

void setup() {
    Serial.begin(9600);
    Serial.flush();
//inizializzazione dei componenti
    PirImpl* pir = new PirImpl(2);
    Sonar* sonar = new Sonar(8, 9);
    Potentiometer* potentiometer = new Potentiometer(6);
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

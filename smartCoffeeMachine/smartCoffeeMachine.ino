#include "Sleep.h"
#include "Sonar.h"
#include "OnPhase.h"
#include "Scheduler.h"

Scheduler scheduler;

void setup() {
    Serial.begin(9600);
    Serial.println("Partito");
    Serial.flush();

    PirImpl* pir = new PirImpl(2);
    Sonar* sonar = new Sonar(8, 9);

    Phase* sleep = new Sleep(2);
    Phase* on = new OnPhase(pir, sonar);

    scheduler.init(1000); //viene chiamato lo scheduler 100 volte/s
    scheduler.addPhase(sleep);
    scheduler.addPhase(on);
    Serial.println("Rosso garantisce che fino a qui arriva");
}

void loop(){
    scheduler.schedule();
}

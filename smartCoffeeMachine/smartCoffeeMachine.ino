#include "Sleep.h"
#include "Sonar.h"
#include "OnPhase.h"
#include "Scheduler.h"

Scheduler* scheduler;

void setup() {
  PirImpl* pir = new PirImpl(2);
  Sonar* sonar = new Sonar(8, 9);

  Phase* sleep = new Sleep(pir);
  Phase* on = new OnPhase(pir, sonar);

  scheduler->init(1000); //viene chiamato lo scheduler 100 volte/s
  scheduler->addPhase(sleep);
  scheduler->addPhase(on);

  Serial.begin(9600);
  Serial.println("stronzo");
}

void loop(){
    Serial.println("cani neri");
    scheduler->schedule();
}

#define BAUD 9600

#include "Sleep.h"
#include "ReadyPhase.h"
#include "Sonar.h"
#include "OnPhase.h"
#include "Scheduler.h"
#include "ButtonImpl.h"
#include "Potentiometer.h"
#include "BusyPhase.h"
#include "Led.h"
#include "MsgService.h"

Scheduler scheduler;
void setup() {
  Serial.begin(BAUD);
  Serial.flush();
  MsgService.init(BAUD);
  //inizializzazione dei componenti
  Led* led1 = new Led(5);
  Led* led2 = new Led(6);
  Led* led3 = new Led(7);
  PirImpl* pir = new PirImpl(2);
  Sonar* sonar = new Sonar(8, 9);
  Potentiometer* potentiometer = new Potentiometer(A5);
  ButtonImpl* button = new ButtonImpl(4);
  //Creazione delle fasi
  Phase* sleep = new Sleep(2);
  Phase* on = new OnPhase(pir, sonar);
  Phase* ready = new ReadyPhase(sonar, potentiometer, button);
  Phase* busy = new BusyPhase(led1,led2,led3);

  scheduler.init(100); //viene chiamato lo scheduler 100 volte/s
  scheduler.addPhase(sleep);
  scheduler.addPhase(on);
  scheduler.addPhase(ready);
  scheduler.addPhase(busy);
}

void loop(){
  scheduler.schedule();
}

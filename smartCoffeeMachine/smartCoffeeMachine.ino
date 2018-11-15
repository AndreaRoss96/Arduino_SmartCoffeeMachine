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
#include "DonePhase.h"
#include "Maintenance.h"

Scheduler scheduler;
void setup() {
  Serial.begin(BAUD);
  MsgService.init();
  Serial.flush();
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
  Phase* done = new DonePhase(sonar);
  Phase* maintenance = new Maintenance();
  //inizializzazione e costruzione dello scheduler
  scheduler.init(100); //viene richiamato lo scheduler ogni 100ms
  scheduler.addPhase(sleep);
  scheduler.addPhase(on);
  scheduler.addPhase(ready);
  scheduler.addPhase(busy);
  scheduler.addPhase(done);
  scheduler.addPhase(maintenance);
}

void loop(){
  scheduler.schedule();
}

/***********************************************************
            PROTOCOLLO DEI MESSAGGI:
1 - "Welcome!" - READY
2...7 - Livello di zucchero - READY
8 - "Making coffee" - BUSY
9 - "The coffe is ready" - DONE
10 - "No more coffe" - MAINTENANCE
***********************************************************/

#include "ThreeLedShow.h"

ThreeLedShow::ThreeLedShow(int pin0, int pin1, int pin2) {
    this->pin[0] = pin0;
    this->pin[1] = pin1;
    this->pin[2] = pin2;
    for (int i = 0; i < 3; i++){
      led[i] = new Led(pin[i]);
    }
    this->myPeriod = GlobalClass::getInstance()->getDT3() / 3;
}

void ThreeLedShow::startShow() {
    for(int i = 0; i < 3; i++) {
        led[i]->switchOn();
        delay(myPeriod); //genera problemi? è possibile che, dato che modifichiamo il timer di arduino, il delay gli dia fastidio
                        //in alternativa utilizzare delayMicroseconds all'interno di un for{} per trasformare i microsecondi in secondi
    }
}

void ThreeLedShow::resetLed() {
    for(int i = 0; i < 3; i++)
        led[i]->switchOff();
};

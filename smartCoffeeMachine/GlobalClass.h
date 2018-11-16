#define DIST1 0.3
#define DIST2 0.1
#define DT1 1000
#define DT2A 5000
#define DT2B 5000
#define DT3 3000
#define DT4 5000
#define NUM_LED 3
#define NUM_CAFFE 3

#include "EnumPhase.h"
#include "Arduino.h"

class GlobalClass { //SINGLETON
  EnumPhase actualPhase = EnumPhase::SLEEP;
  int nc = NUM_CAFFE;

  private:
      GlobalClass() {}
  public:
    /*
    return
      The instance of the globalClass
    */
    static GlobalClass& getInstance() {
        static GlobalClass gbInstance;
        return gbInstance;
    }

    /*
    Set the actual Phase
    */
    void setActualPhase(EnumPhase phase) {
      this->actualPhase = phase;
    }

    /*
    return
      the actual phase
    */
    EnumPhase getActualPhase() {
      return actualPhase;
    }

    /*
    return
      engagement distance
      */
    float getDist1(){
      return DIST1;
    }

    /**
    return
      Distance to take coffee
    */
    float getDist2() {
      return DIST2;
    }

    /*
    return
      Minimum engagement time
    */
    int getDT1() {
      return DT1;
    }

    /*
    return
      Maximum time with no engagement
    */
    int getDT2A() {
      return DT2A;
    }

    /*
    return
      Maximum time with no presence
    */
    int getDT2B() {
      return DT2B;
    }

    /*
    return
      Coffe making process duration
    */
    int getDT3() {
      return DT3;
    }

    /*
    return
      Maximum time to remove coffee
    */
    int getDT4() {
      return DT4;
    }
    /*
    return
      number of leds
    */
    int getNumLed(){
      return NUM_LED;
    }
    /*
    return
      time range of a single led
    */
    int getTimeRangeLed(){
      return GLOBAL_CLASS.getDT3()/GLOBAL_CLASS.getNumLed();
    }
    /*
    return
      number of coffes remain
    */
    int getNc(){
      return nc;
    }
    /*
      decrease number of coffes
    */
    void decNCoffe(){
      nc --;
    }

    void refillCoffee(int coffeeQuantity) {
        nc = coffeeQuantity;
    }
};

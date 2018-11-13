#define DIST1 0.3
#define DIST2 0.1
#define DT1 1000
#define DT2A 5000
#define DT2B 5000
#define DT3 5000
#define DT4 5000

#include "EnumPhase.h"
#include "Arduino.h"

class GlobalClass { //SINGLETON
  EnumPhase actualPhase = EnumPhase::SLEEP;

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
};

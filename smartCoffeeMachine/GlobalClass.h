#define DIST1 0.3
#define DIST2 0.1
#define DT1 1000
#define DT2A 5000
#define DT2B 5000
#define DT3 5000
#define DT4 5000

#include "EnumPhase.h"

class GlobalClass {
  EnumPhase actualPhase;

  public:
    static GlobalClass& getInstance() {
        static GlobalClass instance;
        return instance;
    }

  private:
      GlobalClass() {}
  public:
    void setActualPhase(EnumPhase phase) {
      this->actualPhase = phase;
    }

    EnumPhase getActualPhase() {
      return actualPhase;
    }

    float getDist1(){
      return DIST1;
    }

    float getDist2() {
      return DIST2;
    }

    int getDT1() {
      return DT1;
    }

    int getDT2A() {
      return DT2A;
    }

    int getDT2B() {
      return DT2B;
    }

    int getDT3() {
      return DT3;
    }

    int getDT4() {
      return DT4;
    }
};

// GlobalClass::getInstance()->function();

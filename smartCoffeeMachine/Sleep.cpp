#include "Sleep.h"
#include "Arduino.h"

Sleep::Sleep(PirImpl& pir){
  this -> pir = pir;
};
// cancellare il file

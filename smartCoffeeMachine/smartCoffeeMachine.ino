#include "PirImpl.h"

int ledPin = 13;
PirImpl* s;
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

void setup() {
  s = new PirImpl(2);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  Serial.begin(9600);
  Serial.println("stronzo");
}

void loop(){
  val = s->getValue();  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  delay(10);
}

#include "Sonar.h"
Sonar* s;
void setup() {
  s = new Sonar(8,7);
  Serial.begin(9600);
  Serial.println("stronzo");
}

void loop() {
  Serial.println(s->getValue());
  delay(1000);
}

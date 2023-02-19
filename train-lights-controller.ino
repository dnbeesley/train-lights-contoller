#include <Arduino.h>
#include <Wire.h>
#define DELAY_INTERVAL 500

uint8_t state = 0;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Wire.begin(0x54);
  Wire.onReceive(setState);
}

void loop() {
  digitalWrite(0, state & 0x01);
  digitalWrite(1, state & 0x04);
  digitalWrite(2, state & 0x10);
  digitalWrite(3, state & 0x40);
  delay(DELAY_INTERVAL);

  digitalWrite(0, state & 0x02);
  digitalWrite(1, state & 0x08);
  digitalWrite(2, state & 0x20);
  digitalWrite(3, state & 0x80);
  delay(DELAY_INTERVAL);
}

void setState(int a) {
  int c = Wire.read();
  if(c >= 0) {
    state = c;
  }
}

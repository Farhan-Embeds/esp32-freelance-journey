#include <Arduino.h>

#define LED 2

const unsigned long BLINK_INTERVAL_MS = 500;
const unsigned long UPTIME_INTERVAL_MS = 1000;

unsigned long lastBlink = 0;
unsigned long lastUptime = 0;
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - lastBlink >= BLINK_INTERVAL_MS) {
    lastBlink = now;
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }

  if (now - lastUptime >= UPTIME_INTERVAL_MS) {
    lastUptime = now;
    Serial.printf("Uptime: %lu s\n", now / 1000);
  }
}
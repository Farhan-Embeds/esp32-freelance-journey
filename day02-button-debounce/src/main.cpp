#include <Arduino.h>

const int buttonPin = 0;   // onboard BOOT button (active LOW)
const int ledPin = 2;      // onboard LED

const unsigned long DEBOUNCE_MS = 30;

int lastReading = HIGH;          // last raw reading
int stableState = HIGH;          // debounced state
unsigned long lastChangeTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);  // idle HIGH, pressed = LOW
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.println("LED is off");
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Raw reading changed (press, release, or bounce): restart the timer
  if (reading != lastReading) {
    lastChangeTime = millis();
    lastReading = reading;
  }

  // Reading has stayed the same longer than the debounce time
  if (millis() - lastChangeTime >= DEBOUNCE_MS && reading != stableState) {
    stableState = reading;

    if (stableState == LOW) {          // button pressed
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is on");
    } else {                           // button released
      digitalWrite(ledPin, LOW);
      Serial.println("LED is off");
    }
  }
}
/*
 * Non-blocking onboard LED experiment, no external electrical connections.
 * Send 'f' for 150 ms or 's' for 500 ms in Serial Monitor at 9600 baud.
 */
#include "timing.h"

const uint8_t kLedPin = LED_BUILTIN;
uint32_t lastToggle = 0;
uint32_t intervalMs = 500;
bool ledOn = false;

void setup() {
  pinMode(kLedPin, OUTPUT);
  digitalWrite(kLedPin, LOW);
  Serial.begin(9600);
  lastToggle = millis();
}

void loop() {
  const uint32_t now = millis();
  if (blink_is_due(now, lastToggle, intervalMs)) {
    lastToggle = now;
    ledOn = !ledOn;
    digitalWrite(kLedPin, ledOn ? HIGH : LOW);
  }

  // Parse one-byte commands; unexpected characters leave timing unchanged.
  while (Serial.available() > 0) {
    const char command = static_cast<char>(Serial.read());
    if (command == 'f') {
      intervalMs = 150;
      lastToggle = now;
    } else if (command == 's') {
      intervalMs = 500;
      lastToggle = now;
    }
  }
}

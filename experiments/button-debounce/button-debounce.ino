// Button between D2 and GND; INPUT_PULLUP provides the internal resistor.
// The debounce state machine is implemented in portable, testable C.
#include "debounce.h"

#ifndef LED_BUILTIN
#error "This board does not define LED_BUILTIN."
#endif

constexpr uint8_t BUTTON_PIN = 2;
constexpr uint32_t DEBOUNCE_MS = 35;
DebounceState buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  debounce_init(&buttonState, digitalRead(BUTTON_PIN) == HIGH, (uint32_t)millis());
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  const uint8_t rawHigh = digitalRead(BUTTON_PIN) == HIGH;
  const uint8_t stableHigh = debounce_update(&buttonState, rawHigh, (uint32_t)millis(), DEBOUNCE_MS);
  digitalWrite(LED_BUILTIN, stableHigh ? LOW : HIGH);
}

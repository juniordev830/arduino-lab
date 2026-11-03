// Debounced button input using the board's internal pull-up resistor.
// Wiring: momentary button between D2 and GND; no external resistor is required.

#ifndef LED_BUILTIN
#error "This board does not define LED_BUILTIN."
#endif

constexpr uint8_t BUTTON_PIN = 2;
constexpr unsigned long DEBOUNCE_MS = 35;

bool stableReading = HIGH;
bool lastReading = HIGH;
unsigned long lastChangeAt = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  const bool reading = digitalRead(BUTTON_PIN);
  if (reading != lastReading) {
    lastChangeAt = millis();
    lastReading = reading;
  }

  if (millis() - lastChangeAt >= DEBOUNCE_MS && reading != stableReading) {
    stableReading = reading;
    digitalWrite(LED_BUILTIN, stableReading == LOW ? HIGH : LOW);
  }
}

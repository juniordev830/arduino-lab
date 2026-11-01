// Safe starter experiment: blink the board built-in LED only.
// No external wiring is required. Verify LED_BUILTIN exists for your board.

#ifndef LED_BUILTIN
#error "This board does not define LED_BUILTIN; select a compatible board or configure the pin explicitly."
#endif

constexpr unsigned long BLINK_INTERVAL_MS = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(BLINK_INTERVAL_MS);
  digitalWrite(LED_BUILTIN, LOW);
  delay(BLINK_INTERVAL_MS);
}

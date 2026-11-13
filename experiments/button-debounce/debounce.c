#include "debounce.h"

void debounce_init(DebounceState *state, uint8_t initial_high, uint32_t now_ms) {
    const uint8_t level = initial_high ? 1u : 0u;
    state->stable_high = level;
    state->last_raw_high = level;
    state->last_change_ms = now_ms;
}

uint8_t debounce_update(DebounceState *state, uint8_t raw_high,
                        uint32_t now_ms, uint32_t debounce_ms) {
    const uint8_t level = raw_high ? 1u : 0u;
    if (level != state->last_raw_high) {
        state->last_raw_high = level;
        state->last_change_ms = now_ms;
    }

    /* Unsigned subtraction keeps working when millis() wraps around. */
    if ((uint32_t)(now_ms - state->last_change_ms) >= debounce_ms) {
        state->stable_high = level;
    }
    return state->stable_high;
}

#ifndef GX_DEBOUNCE_H
#define GX_DEBOUNCE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t stable_high;
    uint8_t last_raw_high;
    uint32_t last_change_ms;
} DebounceState;

/* HIGH = button released for INPUT_PULLUP. */
void debounce_init(DebounceState *state, uint8_t initial_high, uint32_t now_ms);
uint8_t debounce_update(DebounceState *state, uint8_t raw_high,
                        uint32_t now_ms, uint32_t debounce_ms);

#ifdef __cplusplus
}
#endif
#endif

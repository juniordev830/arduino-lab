#ifndef SERIAL_BLINK_TIMING_H
#define SERIAL_BLINK_TIMING_H

#include <stdint.h>

/* Unsigned subtraction handles the 32-bit millis() counter wrapping. */
static inline bool blink_is_due(uint32_t now, uint32_t last, uint32_t interval_ms) {
    return interval_ms > 0 && (uint32_t)(now - last) >= interval_ms;
}

#endif

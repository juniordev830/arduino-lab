#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#include "../experiments/button-debounce/debounce.h"

/*
 * Hardware-free input simulator.
 * Each line must contain a millis() timestamp and a raw digital level:
 *   15 0   (button pressed with INPUT_PULLUP)
 *   65 1   (button released)
 */
int main(void) {
    DebounceState state;
    debounce_init(&state, 1u, 0u);
    uint8_t previous = 1u;
    char line[128];
    unsigned line_number = 0;

    while (fgets(line, sizeof line, stdin) != NULL) {
        unsigned long long timestamp;
        unsigned level;
        char extra;
        ++line_number;

        if (sscanf(line, " %llu %u %c", &timestamp, &level, &extra) != 2 ||
            timestamp > UINT32_MAX || level > 1u) {
            fprintf(stderr, "Invalid sample at line %u (use: millis 0|1)\n", line_number);
            return 2;
        }

        uint8_t stable = debounce_update(
            &state, (uint8_t)level, (uint32_t)timestamp, 35u
        );
        if (stable != previous) {
            printf("%" PRIu32 " %s\n", (uint32_t)timestamp,
                   stable == 0u ? "PRESSED" : "RELEASED");
            previous = stable;
        }
    }

    if (ferror(stdin)) {
        fputs("Error reading samples\n", stderr);
        return 1;
    }
    return 0;
}

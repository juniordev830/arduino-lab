#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../experiments/button-debounce/debounce.h"

/*
 * Replay raw INPUT_PULLUP readings without an Arduino board.
 * Usage: ./debounce_sim [--threshold-ms 35]
 * Input: timestamp-ms 0|1 (one sample per line).
 */
static int read_u32(const char *text, uint32_t *value) {
    if (text[0] == '\0') return 0;
    for (const char *p = text; *p != '\0'; ++p) {
        if (*p < '0' || *p > '9') return 0;
    }
    errno = 0;
    char *end = NULL;
    unsigned long long n = strtoull(text, &end, 10);
    if (errno == ERANGE || end == text || *end != '\0' || n > UINT32_MAX) return 0;
    *value = (uint32_t)n;
    return 1;
}

int main(int argc, char **argv) {
    uint32_t threshold_ms = 35u;
    if (argc != 1) {
        if (argc != 3 || strcmp(argv[1], "--threshold-ms") != 0 ||
            !read_u32(argv[2], &threshold_ms) ||
            threshold_ms < 1u || threshold_ms > 10000u) {
            fputs("Usage: debounce_sim [--threshold-ms 1..10000]\n", stderr);
            return 2;
        }
    }

    DebounceState state;
    debounce_init(&state, 1u, 0u);
    uint8_t previous_level = 1u;
    uint32_t previous_ms = 0u;
    int saw_sample = 0;
    char line[256];
    unsigned line_number = 0u;

    while (fgets(line, sizeof line, stdin) != NULL) {
        char timestamp_text[64], level_text[16], extra;
        uint32_t timestamp_ms, raw_level;
        ++line_number;
        if (strchr(line, '\n') == NULL && !feof(stdin)) {
            fprintf(stderr, "Line %u is too long\n", line_number);
            return 2;
        }
        if (sscanf(line, " %63s %15s %c", timestamp_text, level_text, &extra) != 2 ||
            !read_u32(timestamp_text, &timestamp_ms) ||
            !read_u32(level_text, &raw_level) || raw_level > 1u) {
            fprintf(stderr, "Invalid sample at line %u (use: millis 0|1)\n", line_number);
            return 2;
        }

        /* Unsigned delta supports millis() wraparound; reject backward samples. */
        if (saw_sample && (uint32_t)(timestamp_ms - previous_ms) > UINT32_MAX / 2u) {
            fprintf(stderr, "Timestamps out of order at line %u\n", line_number);
            return 2;
        }
        saw_sample = 1;
        previous_ms = timestamp_ms;

        uint8_t stable = debounce_update(
            &state, (uint8_t)raw_level, timestamp_ms, threshold_ms
        );
        if (stable != previous_level) {
            printf("%" PRIu32 " %s\n", timestamp_ms,
                   stable == 0u ? "PRESSED" : "RELEASED");
            previous_level = stable;
        }
    }

    if (ferror(stdin)) {
        fputs("Failed to read samples\n", stderr);
        return 1;
    }
    return 0;
}

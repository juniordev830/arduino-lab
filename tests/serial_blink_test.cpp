#include <cassert>
#include <cstdint>
#include "../experiments/serial-blink/timing.h"

int main() {
    assert(!blink_is_due(10u, 0u, 150u));
    assert(blink_is_due(150u, 0u, 150u));
    assert(blink_is_due(151u, 0u, 150u));
    assert(!blink_is_due(10u, 0u, 0u));
    // millis wraps after UINT32_MAX, but elapsed time remains correct.
    assert(!blink_is_due(10u, 4294967290u, 20u)); // 16 ms
    assert(blink_is_due(20u, 4294967290u, 20u));  // 26 ms
    return 0;
}

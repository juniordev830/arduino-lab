#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "../experiments/button-debounce/debounce.h"

static void test_bounce_and_release(void) {
    DebounceState button;
    debounce_init(&button, 1, 0);
    assert(debounce_update(&button, 0, 5, 35) == 1);
    assert(debounce_update(&button, 1, 10, 35) == 1);
    assert(debounce_update(&button, 0, 15, 35) == 1);
    assert(debounce_update(&button, 0, 49, 35) == 1);
    assert(debounce_update(&button, 0, 50, 35) == 0);
    assert(debounce_update(&button, 1, 55, 35) == 0);
    assert(debounce_update(&button, 1, 89, 35) == 0);
    assert(debounce_update(&button, 1, 90, 35) == 1);
}

static void test_millis_rollover(void) {
    DebounceState button;
    debounce_init(&button, 1, UINT32_MAX - 20u);
    assert(debounce_update(&button, 0, UINT32_MAX - 10u, 35) == 1);
    assert(debounce_update(&button, 0, 10u, 35) == 1);
    assert(debounce_update(&button, 0, 25u, 35) == 0);
}

int main(void) {
    test_bounce_and_release();
    test_millis_rollover();
    puts("C debounce tests passed");
    return 0;
}

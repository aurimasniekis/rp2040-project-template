#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

#include <stdio.h>
#include "pico/stdlib.h"


int main() {
    stdio_init_all();
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    printf("Setup Done");

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }
#endif
}

#pragma clang diagnostic pop

#include "gpio.h"

static void delay(volatile uint32_t cycles) {
    while (cycles--) {
    }
}

int main(void) {
    while (1) {
        delay(100000U);
    }
}

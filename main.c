#include "gpio.h"

static void delay(volatile uint32_t cycles) {
    while (cycles--) {
    }
}

int main(void) {
    gpio_config_t led = {
        .port = GPIOA,
        .pin = 5U,
        .mode = GPIO_MODE_OUTPUT,
        .output_type = GPIO_OUTPUT_PUSHPULL,
        .pull = GPIO_PULL_NONE,
        .speed = GPIO_SPEED_LOW,
        .alternate = 0U,
    };

    gpio_init(&led);

    while (1) {
        gpio_toggle(led.port, led.pin);
        delay(100000U);
    }
}

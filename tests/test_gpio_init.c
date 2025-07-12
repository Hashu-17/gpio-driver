#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    RCC->AHB1ENR = 0;
    GPIOA->MODER = 0;

    gpio_config_t cfg = {
        .port = GPIOA,
        .pin = 3U,
        .mode = GPIO_MODE_OUTPUT,
        .output_type = GPIO_OUTPUT_PUSHPULL,
        .pull = GPIO_PULL_NONE,
        .speed = GPIO_SPEED_LOW,
        .alternate = 0U,
    };

    gpio_init(&cfg);

    TEST_ASSERT((RCC->AHB1ENR & RCC_AHB1ENR_GPIOAEN) != 0U);
    TEST_ASSERT(((GPIOA->MODER >> (cfg.pin * 2U)) & 0x3U) == GPIO_MODE_OUTPUT);
    return 0;
}

#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    gpio_pin_t pin = { GPIOA, 1U };
    gpio_config_t cfg = gpio_pin_config_defaults(pin);

    TEST_ASSERT(cfg.mode == GPIO_MODE_INPUT);
    TEST_ASSERT(cfg.pin == 1U);
    return 0;
}

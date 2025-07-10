#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    gpio_speed_t speed = GPIO_SPEED_LOW;
    (void)speed;
    TEST_ASSERT(GPIO_SPEED_LOW == 0);
    return 0;
}

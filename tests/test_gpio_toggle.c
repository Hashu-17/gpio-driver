#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    GPIOA->ODR = 0;

    gpio_toggle(GPIOA, 1U);
    TEST_ASSERT((GPIOA->ODR & (1U << 1U)) != 0U);

    gpio_toggle(GPIOA, 1U);
    TEST_ASSERT((GPIOA->ODR & (1U << 1U)) == 0U);
    return 0;
}

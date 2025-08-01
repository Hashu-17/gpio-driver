#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    GPIOA->AFRL = 0;
    gpio_set_af(GPIOA, 3U, 5U);
    TEST_ASSERT(((GPIOA->AFRL >> (3U * 4U)) & 0xFU) == 5U);
    return 0;
}

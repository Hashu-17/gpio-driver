#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    GPIOA->PUPDR = 0;
    gpio_set_pull(GPIOA, 2U, GPIO_PULL_UP);
    TEST_ASSERT(((GPIOA->PUPDR >> (2U * 2U)) & 0x3U) == GPIO_PULL_UP);
    return 0;
}

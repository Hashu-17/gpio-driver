#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    gpio_output_type_t otype = GPIO_OUTPUT_PUSHPULL;
    (void)otype;
    TEST_ASSERT(GPIO_OUTPUT_PUSHPULL == 0);
    return 0;
}

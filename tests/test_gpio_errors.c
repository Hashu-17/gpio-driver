#include "gpio.h"
#include "test_helpers.h"

int main(void) {
    gpio_status_t status = gpio_init(NULL);
    TEST_ASSERT(status == GPIO_STATUS_BAD_ARG);
    return 0;
}

#include "gpio.h"

void gpio_init(GPIO_TypeDef *port, uint8_t pin, gpio_mode_t mode) {
    if (port == NULL) {
        return;
    }
    port->MODER &= ~(0x3U << (pin * 2U));
    port->MODER |= ((uint32_t)mode << (pin * 2U));
}

void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value) {
    if (port == NULL) {
        return;
    }
    if (value)
        port->ODR |= (1U << pin);
    else
        port->ODR &= ~(1U << pin);
}

bool gpio_read(GPIO_TypeDef *port, uint8_t pin) {
    if (port == NULL) {
        return false;
    }
    return ((port->IDR >> pin) & 0x1U) != 0U;
}

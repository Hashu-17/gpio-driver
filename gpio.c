#include "gpio.h"

void gpio_init(const gpio_config_t *cfg) {
    if (cfg == NULL || cfg->port == NULL) {
        return;
    }
    cfg->port->MODER &= ~(0x3U << (cfg->pin * 2U));
    cfg->port->MODER |= ((uint32_t)cfg->mode << (cfg->pin * 2U));
    cfg->port->OSPEEDR &= ~(0x3U << (cfg->pin * 2U));
    cfg->port->OSPEEDR |= ((uint32_t)cfg->speed << (cfg->pin * 2U));
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

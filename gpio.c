#include "gpio.h"

void gpio_port_enable(GPIO_TypeDef *port) {
    if (port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

void gpio_init(gpio_config_t *cfg) {
    if (cfg == NULL) {
        return;
    }
    gpio_port_enable(cfg->port);
    cfg->port->MODER &= ~(0x3U << (cfg->pin * 2U));
    cfg->port->MODER |= ((uint32_t)cfg->mode << (cfg->pin * 2U));
}

void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value) {
    if (value)
        port->ODR |= (1U << pin);
    else
        port->ODR &= ~(1U << pin);
}

bool gpio_read(GPIO_TypeDef *port, uint8_t pin) {
    return ((port->IDR >> pin) & 0x1U) != 0U;
}

void gpio_pin_init(gpio_pin_t *pin, gpio_mode_t mode) {
    if (pin == NULL) {
        return;
    }
    gpio_config_t cfg = {
        .port = pin->port,
        .pin = pin->pin,
        .mode = mode,
    };
    gpio_init(&cfg);
}

#include "gpio.h"

void gpio_init(gpio_config_t *cfg) {
    if (cfg->port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (cfg->port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (cfg->port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    cfg->port->MODER &= ~(0x3 << (cfg->pin * 2));
    cfg->port->MODER |= (cfg->mode << (cfg->pin * 2));
}

void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value) {
    if (value)
        port->ODR |= (1 << pin);
    else
        port->ODR &= ~(1 << pin);
}

bool gpio_read(GPIO_TypeDef *port, uint8_t pin) {
    return (port->IDR >> pin) & 0x1;
}

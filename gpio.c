#include "gpio.h"

static bool gpio_is_valid(GPIO_TypeDef *port, uint8_t pin) {
    return port != NULL && pin < 16U;
}

void gpio_port_enable(GPIO_TypeDef *port) {
    if (port == NULL) {
        return;
    }
    if (port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

void gpio_init(gpio_config_t *cfg) {
    if (cfg == NULL) {
        return;
    }
    if (!gpio_is_valid(cfg->port, cfg->pin)) {
        return;
    }
    gpio_port_enable(cfg->port);
    cfg->port->MODER &= ~(0x3U << (cfg->pin * 2U));
    cfg->port->MODER |= ((uint32_t)cfg->mode << (cfg->pin * 2U));
}

void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    if (value)
        port->ODR |= (1U << pin);
    else
        port->ODR &= ~(1U << pin);
}

void gpio_toggle(GPIO_TypeDef *port, uint8_t pin) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    port->ODR ^= (1U << pin);
}

bool gpio_read(GPIO_TypeDef *port, uint8_t pin) {
    if (!gpio_is_valid(port, pin)) {
        return false;
    }
    return ((port->IDR >> pin) & 0x1U) != 0U;
}

void gpio_pin_write(gpio_pin_t *pin, bool value) {
    if (pin == NULL) {
        return;
    }
    gpio_write(pin->port, pin->pin, value);
}

bool gpio_pin_read(gpio_pin_t *pin) {
    if (pin == NULL) {
        return false;
    }
    return gpio_read(pin->port, pin->pin);
}

void gpio_pin_toggle(gpio_pin_t *pin) {
    if (pin == NULL) {
        return;
    }
    gpio_toggle(pin->port, pin->pin);
}

void gpio_pin_init(gpio_pin_t *pin, gpio_mode_t mode) {
    if (pin == NULL) {
        return;
    }
    gpio_config_t cfg = {
        .port = pin->port,
        .pin = pin->pin,
        .mode = mode,
        .output_type = GPIO_OUTPUT_PUSHPULL,
        .pull = GPIO_PULL_NONE,
        .speed = GPIO_SPEED_LOW,
        .alternate = 0U,
    };
    gpio_init(&cfg);
}

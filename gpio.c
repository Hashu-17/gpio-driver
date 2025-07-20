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

void gpio_set_mode(GPIO_TypeDef *port, uint8_t pin, gpio_mode_t mode) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    port->MODER &= ~(0x3U << (pin * 2U));
    port->MODER |= ((uint32_t)mode << (pin * 2U));
}

void gpio_set_output_type(GPIO_TypeDef *port, uint8_t pin, gpio_output_type_t otype) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    if (otype == GPIO_OUTPUT_OPENDRAIN)
        port->OTYPER |= (1U << pin);
    else
        port->OTYPER &= ~(1U << pin);
}

void gpio_set_pull(GPIO_TypeDef *port, uint8_t pin, gpio_pull_t pull) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    port->PUPDR &= ~(0x3U << (pin * 2U));
    port->PUPDR |= ((uint32_t)pull << (pin * 2U));
}

void gpio_set_speed(GPIO_TypeDef *port, uint8_t pin, gpio_speed_t speed) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    port->OSPEEDR &= ~(0x3U << (pin * 2U));
    port->OSPEEDR |= ((uint32_t)speed << (pin * 2U));
}

void gpio_set_af(GPIO_TypeDef *port, uint8_t pin, uint8_t af) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    if (pin < 8U) {
        port->AFRL &= ~(0xFU << (pin * 4U));
        port->AFRL |= ((uint32_t)af << (pin * 4U));
    } else {
        uint8_t shift = (uint8_t)(pin - 8U);
        port->AFRH &= ~(0xFU << (shift * 4U));
        port->AFRH |= ((uint32_t)af << (shift * 4U));
    }
}

void gpio_init(gpio_config_t *cfg) {
    if (cfg == NULL) {
        return;
    }
    if (!gpio_is_valid(cfg->port, cfg->pin)) {
        return;
    }
    gpio_port_enable(cfg->port);
    gpio_set_mode(cfg->port, cfg->pin, cfg->mode);
    gpio_set_output_type(cfg->port, cfg->pin, cfg->output_type);
    gpio_set_pull(cfg->port, cfg->pin, cfg->pull);
    gpio_set_speed(cfg->port, cfg->pin, cfg->speed);
    if (cfg->mode == GPIO_MODE_ALT) {
        gpio_set_af(cfg->port, cfg->pin, cfg->alternate);
    }
}

void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    if (value)
        port->BSRR = (1U << (uint32_t)pin);
    else
        port->BSRR = (1U << ((uint32_t)pin + 16U));
}

void gpio_toggle(GPIO_TypeDef *port, uint8_t pin) {
    if (!gpio_is_valid(port, pin)) {
        return;
    }
    port->ODR ^= (1U << (uint32_t)pin);
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

gpio_config_t gpio_pin_config_defaults(gpio_pin_t pin) {
    gpio_config_t cfg = {
        .port = pin.port,
        .pin = pin.pin,
        .mode = GPIO_MODE_INPUT,
        .output_type = GPIO_OUTPUT_PUSHPULL,
        .pull = GPIO_PULL_NONE,
        .speed = GPIO_SPEED_LOW,
        .alternate = 0U,
    };
    return cfg;
}

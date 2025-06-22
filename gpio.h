#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32l4xx.h"

typedef enum {
    GPIO_MODE_INPUT = 0x00,
    GPIO_MODE_OUTPUT = 0x01,
    GPIO_MODE_ALT = 0x02,
    GPIO_MODE_ANALOG = 0x03
} gpio_mode_t;

typedef enum {
    GPIO_SPEED_LOW = 0x00,
    GPIO_SPEED_MEDIUM = 0x01,
    GPIO_SPEED_HIGH = 0x02,
    GPIO_SPEED_VERY_HIGH = 0x03
} gpio_speed_t;

typedef struct {
    GPIO_TypeDef *port;
    uint8_t pin;
} gpio_pin_t;

typedef struct {
    GPIO_TypeDef *port;
    uint8_t pin;
    gpio_mode_t mode;
} gpio_config_t;

void gpio_port_enable(GPIO_TypeDef *port);
void gpio_init(gpio_config_t *cfg);
void gpio_pin_init(gpio_pin_t *pin, gpio_mode_t mode);
void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value);
bool gpio_read(GPIO_TypeDef *port, uint8_t pin);

#endif

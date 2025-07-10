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
    GPIO_OUTPUT_PUSHPULL = 0x00,
    GPIO_OUTPUT_OPENDRAIN = 0x01
} gpio_output_type_t;

typedef enum {
    GPIO_PULL_NONE = 0x00,
    GPIO_PULL_UP = 0x01,
    GPIO_PULL_DOWN = 0x02
} gpio_pull_t;

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
    gpio_output_type_t output_type;
    gpio_pull_t pull;
    gpio_speed_t speed;
    uint8_t alternate;
} gpio_config_t;

void gpio_port_enable(GPIO_TypeDef *port);
void gpio_init(gpio_config_t *cfg);
void gpio_pin_init(gpio_pin_t *pin, gpio_mode_t mode);
void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value);
bool gpio_read(GPIO_TypeDef *port, uint8_t pin);
void gpio_toggle(GPIO_TypeDef *port, uint8_t pin);
void gpio_pin_write(gpio_pin_t *pin, bool value);
bool gpio_pin_read(gpio_pin_t *pin);
void gpio_pin_toggle(gpio_pin_t *pin);

#endif

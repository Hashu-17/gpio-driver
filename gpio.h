#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32l4xx.h"

#define GPIO_PIN_COUNT 16U

#define GPIO_PIN_MASK(pin) (1U << (pin))

typedef enum {
    GPIO_STATUS_OK = 0,
    GPIO_STATUS_BAD_ARG = 1,
    GPIO_STATUS_BAD_PIN = 2
} gpio_status_t;

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

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin_mask;
    gpio_mode_t mode;
    gpio_output_type_t output_type;
    gpio_pull_t pull;
    gpio_speed_t speed;
    uint8_t alternate;
} gpio_port_config_t;

#define GPIO_RMW32(reg, mask, value) \
    ((reg) = ((reg) & ~(mask)) | ((value) & (mask)))

void gpio_port_enable(GPIO_TypeDef *port);
gpio_status_t gpio_init(const gpio_config_t *cfg);
gpio_status_t gpio_pin_init(const gpio_pin_t *pin, gpio_mode_t mode);
void gpio_set_mode(GPIO_TypeDef *port, uint8_t pin, gpio_mode_t mode);
void gpio_set_output_type(GPIO_TypeDef *port, uint8_t pin, gpio_output_type_t otype);
void gpio_set_pull(GPIO_TypeDef *port, uint8_t pin, gpio_pull_t pull);
void gpio_set_speed(GPIO_TypeDef *port, uint8_t pin, gpio_speed_t speed);
void gpio_set_af(GPIO_TypeDef *port, uint8_t pin, uint8_t af);
void gpio_write(GPIO_TypeDef *port, uint8_t pin, bool value);
bool gpio_read(GPIO_TypeDef *port, uint8_t pin);
void gpio_toggle(GPIO_TypeDef *port, uint8_t pin);
void gpio_pin_write(const gpio_pin_t *pin, bool value);
bool gpio_pin_read(const gpio_pin_t *pin);
void gpio_pin_toggle(const gpio_pin_t *pin);
void gpio_pin_write_mask(GPIO_TypeDef *port, uint16_t set_mask, uint16_t reset_mask);
void gpio_write_port(GPIO_TypeDef *port, uint16_t value);
uint16_t gpio_read_port(GPIO_TypeDef *port);
void gpio_port_apply(const gpio_port_config_t *cfg);
void gpio_port_set_pull(GPIO_TypeDef *port, uint16_t pin_mask, gpio_pull_t pull);
void gpio_port_set_speed(GPIO_TypeDef *port, uint16_t pin_mask, gpio_speed_t speed);
gpio_config_t gpio_pin_config_defaults(gpio_pin_t pin);

static inline gpio_pin_t gpio_pin(GPIO_TypeDef *port, uint8_t pin) {
    gpio_pin_t out = { port, pin };
    return out;
}

#endif

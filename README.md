# gpio-driver

## Build

Run `make` to build the example.

## Tests

Run `scripts/run_tests.sh` to build and execute tests.

## Example

```c
gpio_pin_t led = GPIO_PIN(GPIOA, 5U);
gpio_config_t cfg = gpio_pin_config_defaults(led);
cfg.mode = GPIO_MODE_OUTPUT;
gpio_init(&cfg);
gpio_pin_toggle(&led);
```

## Port Config

```c
gpio_port_config_t cfg = {
    .port = GPIOA,
    .pin_mask = 0x00FFU,
    .mode = GPIO_MODE_OUTPUT,
    .output_type = GPIO_OUTPUT_PUSHPULL,
    .pull = GPIO_PULL_NONE,
    .speed = GPIO_SPEED_LOW,
    .alternate = 0U,
};
gpio_port_apply(&cfg);
```


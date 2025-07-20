CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -DGPIO_TEST -I..
TESTS = test_gpio_init test_gpio_toggle test_gpio_pull test_gpio_af test_gpio_defaults

all: $(TESTS)

test_gpio_init: test_gpio_init.c mock_stm32l4xx.c ../gpio.c
	$(CC) $(CFLAGS) -o $@ $^

test_gpio_toggle: test_gpio_toggle.c mock_stm32l4xx.c ../gpio.c
	$(CC) $(CFLAGS) -o $@ $^

test_gpio_pull: test_gpio_pull.c mock_stm32l4xx.c ../gpio.c
	$(CC) $(CFLAGS) -o $@ $^

test_gpio_af: test_gpio_af.c mock_stm32l4xx.c ../gpio.c
	$(CC) $(CFLAGS) -o $@ $^

test_gpio_defaults: test_gpio_defaults.c mock_stm32l4xx.c ../gpio.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TESTS)

run: all
	@for t in $(TESTS); do ./$$t; done

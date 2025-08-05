CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Os
SRC = main.c gpio.c
TARGET = gpio_demo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

CC ?= gcc
CFLAGS ?= -std=c11
SRC = main.c gpio.c
TARGET = gpio_demo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

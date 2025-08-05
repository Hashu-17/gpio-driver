CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Os
SRC = main.c gpio.c
TARGET = gpio_demo

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

debug: CFLAGS += -g -O0
debug: clean $(TARGET)

release: CFLAGS += -O2
release: clean $(TARGET)

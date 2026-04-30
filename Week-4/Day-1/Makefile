CC = gcc
CFLAGS = -Wall -Wextra -O2 -s

TARGET = 1
SRCS = main.c operations.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean

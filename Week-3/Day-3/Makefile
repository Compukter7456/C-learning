CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined

TARGET = 3
SRCS = 3.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean

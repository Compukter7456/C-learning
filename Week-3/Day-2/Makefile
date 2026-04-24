CC = gcc
CFLAGS = -Wall -Wextra -O2 -s

TARGET = compiled
SRCS = 2.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean

# .PHONY tells make that "clean" is a command, not a file to create
# Without .PHONY, make treats "clean" as a file target
# If file "clean" exists on disk, make skips the command
#include <stdio.h>

struct MyStruct {
    size_t spacesAmmount;
    size_t symbolsAmmount;
    size_t errorCode;
};

// Safely read symbols from stdin, save to buffer and output ammount of spaces and elements in buffer
struct MyStruct readBuffer(char buffer[], size_t bufferSize) {
   struct MyStruct values = {0, 0, 0};

    if (fgets(buffer, bufferSize, stdin) == NULL) {
        values.errorCode = -1;
        return values;
    }

    for (size_t i = 0; i < bufferSize; ++i) {
        if (buffer[i] == ' ') {
            values.spacesAmmount++;
        }

        if (buffer[i] == '\0') {
            break;
        }
        values.symbolsAmmount++;
    }

    return values;
}


int main(void) {
    struct MyStruct values = {0, 0, 0};
    char buffer[101];

    printf("Hello, enter up to 100 any symbols: ");
    values = readBuffer(buffer, sizeof(buffer));

    if (values.errorCode == -1) {
        printf("Error reading buffer\n");
        return -1;
    }

    printf("You've entered %zu spaces\n", values.spacesAmmount);
    printf("You've entered %zu symbols\n", values.symbolsAmmount);

    return 0;
}

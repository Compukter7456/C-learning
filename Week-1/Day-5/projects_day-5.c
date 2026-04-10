#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MyStruct {
    size_t spacesAmmount;
    size_t symbolsAmmount;
    int errorCode;
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

int calculateSqrt(int number) {
    int i = 0;

    if (number < 0) {
        return -1;
    }

    while ((i + 1) <= number / (i + 1)) {
        i++;
    }
    return i;
}

int main(void) {
    struct MyStruct values = {0, 0, 0};
    char buffer[101];
    int randomNum = 0;
    srand(time(NULL));

    printf("Hello, enter up to 100 any symbols: ");
    values = readBuffer(buffer, sizeof(buffer));

    if (values.errorCode == -1) {
        printf("Error reading buffer\n");
        return -1;
    }

    printf("You've entered %zu spaces\n", values.spacesAmmount);
    printf("You've entered %zu symbols\n", values.symbolsAmmount);

    for (int i = 0; i < 100; ++i) {
        // Random number in range [100; 1000]
        randomNum = rand() % (1000 - 100 + 1) + 100;
        printf("Sqrt of %d is %d\n", randomNum, calculateSqrt(randomNum));
    }

    return 0;
}

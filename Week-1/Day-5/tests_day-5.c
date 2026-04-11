#include <stdio.h>

int readInt(long long *out) {
    char buffer[128];
    char extra[8];

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 0; // Fgets failed
    }

    if (sscanf(buffer, "%lld %c", out, extra) != 1) {
        return 0; // User entered more than just a number
    }
    return 1;
}


int main(void) {
    long long int number;

    printf("Hello, enter any number: ");
    if (readInt(&number)) {
        printf("You've entered %lld\n", number);
    }
    else {
        printf("Wrong input\n");
    }

    return 0;
}

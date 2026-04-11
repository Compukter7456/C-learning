#include <stdio.h>

int readLongLongInt(long long *out) {
    char buffer[128];
    char extra;
    long long temp;

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        return 0; // Fgets failed
    }

    if (sscanf(buffer, " %lld %c", &temp, &extra) != 1) {
        return 0; // User entered invalid data
    }
    *out = temp;

    return 1;
}


int main(void) {
    long long int number;

    printf("Hello, enter any number: ");
    if (readLongLongInt(&number)) {
        printf("You've entered %lld\n", number);
    }
    else {
        printf("Wrong input\n");
    }

    return 0;
}

 #include <stdio.h>

// Use getchar() to get data from stdin.
// If stdin has no data - getchar() returns EOF.
// If stdinData has any data - delete it by 
void cleanStdin(void) {
    int stdinData = getchar();
    if (stdinData != EOF) {
        while ((stdinData = getchar()) != EOF);
    }

}

// Read an integer. Write all numbers from 0 to n, which can be divided by 3 or by 5, but not both
void taskOne(void) {
    long long number = 0;

    printf("Enter any whole number: ");
    if (scanf("%lld", &number) != 1) {
        printf("Invalid input\n");
        cleanStdin();
    }

    if (number > 0) {
        for (long long i = 1; i <= number; ++i) {
            if (i % 5 == 0 && i % 3 != 0) {
                printf("%lld is divisible by 5\n", i);
            } else if (i % 3 == 0) {
                printf("%lld is divisible by 3\n", i);
            }
        }
    }

    else if (number < 0) {
        for (long long i = -1; i >= number; --i) {
            if (i % 5 == 0 && i % 3 != 0) {
                printf("%lld is divisible by 5\n", i);
            } else if (i % 3 == 0) {
                printf("%lld is divisible by 3\n", i);
            }
        }
    }
    else {
        printf("Number cannot be zero\n");
    }
}


int isDigit(int number) {
    return (number >= '0' && number <= '9');
}

int isAlpha(char symbol) {
    return (symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122);
}

void printASCIITable(void) {
    for (int i = 0; i < 256; ++i) {
        printf("ASCII value of %d is: %c\n", i, i);
    }
}

int isPrime(int number) {

    if (number <= 1) {
        return 0;
    }

    for (int i = 2; i*i <= number; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
//    taskOne();
//    (isAlpha('D')) ? printf("D is alpha\n") : (void)0;
//    printASCIITable();

    for (int i = -10; i <= 100; ++i) {
        printf("%d is %s", i, (isPrime(i)) ? "prime\n" : "not prime\n");
    }
}

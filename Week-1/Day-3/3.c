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
void firstTask(void) {
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

// If number can be divided on [2; i], where i is square root, it is not prime
// [-inf; 1] is not prime numbers
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

void logicalOperators(void) {
    int a = 5, b = 10, c = 0;

    // && - logical AND
    if (a > 0 && b > 0) {
        printf("1) Both a and b are positive (a > 0 && b > 0) \n");
    }

    // || - logical OR
    if (a < 0 || b > 0) {
        printf("2) At least one condition is true (a < 0 || b > 0)\n");
    }

    // ! - logical NOT
    if (!c) {
        printf("3) c is zero, so !c is true (!c)\n");
    }

    // Combining operators
    if ((a > 0 && b > 0) || c != 0) {
        printf("4) Combination returned true: (a > 0 && b > 0) || c != 0\n");
    }

    //  Short-circuiting example
    // (number != 0 && 4 / number == 4). If first condition is false, compiler sees that the following calculations is pointless, so it skips them
    printf("5) Short-circuiting demonstration:\n");
    if (c != 0 && (b / c) > 1) {
        printf("This won't be printed due to short-circuiting\n");
    } else {
        printf("Short-circuit prevented division by zero\n");
    }
}

// Ask user to enter numbers while input number != 0, than output sum of entered numbers
void secondTask(void) {
    char userArray[64];
    double number = 0, sum = 0;

    while (1) {
        printf("Hello, enter any number (0 to exit): ");

        // If fgets returns error or EOF - exit
        if (!fgets(userArray, sizeof(userArray), stdin)) {
            break;
        }

        // sscanf reads data from a string according to the specified format
        // If the input matches the format, the value is stored in the given variable
        // Parsing stops when the input no longer matches the format
        // If user enters wrong data type - sscanf returns 0
        if (sscanf(userArray, "%lf", &number) != 1) {
            printf("Invalid input\n");
            continue;
        }

        if (number == 0) {
            break;
        }

        sum += number;
    }

    printf("Sum of your numbers is: %lf\n", sum);
}

int main(void) {
//    for (int i = -10; i <= 100; ++i) {
//        printf("%d is %s", i, (isPrime(i)) ? "prime\n" : "not prime\n");
//    }
    secondTask();

}

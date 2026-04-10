#include <stdio.h>

// Using 'void' in function's parameter list ensures the function takes no arguments
// The compiler will report an error if any arguments are passed
void calculator(void) {
    char buffer[128];
    double a, b;
    char op;

    while (1) {
        printf("Enter first number: ");
        if (!fgets(buffer, sizeof(buffer), stdin) ||
            sscanf(buffer, "%lf", &a) != 1) {
            printf("Invalid input\n");
            continue;
        }

        printf("Enter second number: ");
        if (!fgets(buffer, sizeof(buffer), stdin) ||
            sscanf(buffer, "%lf", &b) != 1) {
            printf("Invalid input\n");
            continue;
        }

        printf("Enter operator (+, -, /, *): ");
        if (!fgets(buffer, sizeof(buffer), stdin) ||
            sscanf(buffer, " %c", &op) != 1) {
            printf("Invalid input\n");
            continue;
        }

        switch (op) {
            case '+':
                printf("%lf + %lf = %lf\n", a, b, a + b);
                break;

            case '-':
                printf("%lf - %lf = %lf\n", a, b, a - b);
                break;

            case '*':
                printf("%lf * %lf = %lf\n", a, b, a * b);
                break;

            case '/':
                if (b == 0) {
                    printf("Cannot divide by 0\n");
                    continue;
                }
                printf("%lf / %lf = %lf\n", a, b, a / b);
                break;

            default:
                printf("Invalid operator\n");
                continue;
        }

        break;
    }
}

// A variable declared inside a function is only visible within that function
// A variable declared outside all functions is global and accessible from any function

int globalNumber = 3546;

void firstFunction(void) {
    int number = 65433;

    printf("Local number is %d\n", number);
    printf("Global number is %d\n", globalNumber);
}

void secondFunction(void) {
    int number = 5787568;

    printf("Local number is %d\n", number);
    printf("Global number is %d\n", globalNumber);
}

int main(void) {
    firstFunction();
    secondFunction();
    return 0;
}

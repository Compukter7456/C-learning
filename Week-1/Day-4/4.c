#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_BOUND 110
#define LOWER_BOUND 10

// Generate 100 random numbers in range [10; 110] and calculate sum of even ones
void firstTask(void) {
    short int sum = 0, randomNumber = 0;
    // Set rand PRNG seed to current time
    srand(time(NULL));

    for (int i = 0; i < 100; ++i) {
        randomNumber = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
        printf("Random number in range [10; 110] is: %d\n", randomNumber);

        if (!(randomNumber % 2)) {
            sum += randomNumber;
        }
    }
    printf("Sum of all even numbers is: %d\n", sum);
}

// Generate random numbers in range [1; 50] untill 25 is generated, than prints ammount all generated numbers
void secondTask(void) {
    int generatedNumbers = 0, randomNumber = 0;

    srand(time(NULL));

    while (randomNumber != 25) {
        randomNumber = rand() % (50 - 1 + 1) + 1;
        printf("Random number in range [1; 50] is: %d\n", randomNumber);
        generatedNumbers++;
    }

    printf("Loop \"while\" has generated %d random numbers\n", generatedNumbers);

}

// Generate random number in range [0; 10], ask user for number to ques. If user quessed - exit and print total tries, if not - give a hint
void thirdTask(void) {
    int numberToGuess = 0, userGuess = 0, totalTries = 0;
    char buffer[64];

    srand(time(NULL));
    numberToGuess = rand() % 10;

    do {
        printf("Hello, guess a number within 0 and 10: ");
        fgets(buffer, sizeof(userGuess), stdin);

        if ((sscanf(buffer, "%d", &userGuess) != 1)) {
            printf("Invalid input\n");
            continue;
        }

        if (userGuess != numberToGuess) {
            printf("Unluck. Number is %s", (userGuess > numberToGuess) ? "smaller\n" : "bigger\n");
        }
        totalTries++;

    } while (userGuess != numberToGuess);

    printf("Congrats! You've guessed number in %d tries\n", totalTries);
}

// Generate 20 random numbers in the range [-50, 50], print them, and calculate the sum of numbers that are positive and divisible by 3
void fourthTask(void) {
    int sum = 0, randomNumber = 0;

    for (int i = 0; i < 20; ++i) {
        srand(time(NULL));
        randomNumber = rand() % (50 + 50 + 1) - 50;

        if (randomNumber > 0 && randomNumber % 3 == 0) {
            sum += randomNumber;
            printf("%d is positive and divisible by 3\n", randomNumber);
        }
    }

    printf("Sum of generated and filtered numbers is: %d\n", sum);
}

int main() {

//    firstTask();
//    secondTask();
//    thirdTask();
    fourthTask();
    return 0;
}

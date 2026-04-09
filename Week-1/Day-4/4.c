#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_BOUND 110
#define LOWER_BOUND 10

// Generate random number in range [x; y]:
// randomNumber = rand() % (y - x + 1) + x
// Random number in range [-10; 10]: randomNumber = rand() % (10 + 10 + 1) - 10

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

    numberToGuess = rand() % 11;

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

// Generate 20 random numbers in range [-50, 50], print them, and calculate the sum of numbers that are positive and divisible by 3
void fourthTask(void) {
    int sum = 0, randomNumber = 0;

    for (int i = 0; i < 20; ++i) {
        randomNumber = rand() % (50 + 50 + 1) - 50;

        if (randomNumber > 0 && randomNumber % 3 == 0) {
            sum += randomNumber;
            printf("%d is positive and divisible by 3\n", randomNumber);
        }
    }

    printf("Sum of generated and filtered numbers is: %d\n", sum);
}

// Fill an array with 15 random numbers in range [0; 100], find and output smallest and biggest numbers, calculate sum of all numbers in array
void fifthTask(void) {
    int array[15];
    short int iterationNumber = 0, theSmallestNumber = 100, theBiggestNumber = 0, sum = 0;

    // Fill array with random numbers
    while (iterationNumber != 15) {
        array[iterationNumber] = rand() % 101;
        printf("%d'th array element is: %d\n", iterationNumber, array[iterationNumber]);
        iterationNumber++;
    }

    iterationNumber = 0;
    // Find the smallest and the biggest number and calculate sum of all numbers in array
    while (iterationNumber != 15) {
        if (array[iterationNumber] < theSmallestNumber) {
            theSmallestNumber = array[iterationNumber];
        }

        if (array[iterationNumber] > theBiggestNumber) {
            theBiggestNumber = array[iterationNumber];
        }

        sum += array[iterationNumber];
        iterationNumber++;
    }

    printf("The smallest number in array is: %d\n", theSmallestNumber);
    printf("The biggest number in arrany is: %d\n", theBiggestNumber);
    printf("Sum of all numbers is: %d\n", sum);
}

int main() {

    srand(time(NULL));

//    firstTask();
//    secondTask();
//    thirdTask();
//    fourthTask();
    fifthTask();
    return 0;
}

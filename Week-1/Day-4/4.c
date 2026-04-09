#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_BOUND 110
#define LOWER_BOUND 10

// Generate 100 random numbers within [10; 110] and calculate sum of even ones
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

// Generate random numbers withit [1; 50] untill 25 is generated, print ammount all generated numbers
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

int main() {

//    firstTask();
//    secondTask();


    return 0;
}

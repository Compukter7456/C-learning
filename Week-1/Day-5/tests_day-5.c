#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct arrayStats {
    long long sum;
    double avg;
    int min;
    int max;
    int evenCount;
    int oddCount;
    int countDiv3Not5;
};

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

// Fill an array with random numbers in set range
void fillIntArray(int array[], size_t arraySize, int min, int max) {
    for (size_t i = 0; i < (arraySize / sizeof(array[0])); ++i) {
        array[i] = rand() % (max - min + 1) + min;
    }

}

// Analyze numbers in array
struct arrayStats analyzeArray(const int array[], size_t arraySize) {
    struct arrayStats data = {0, 0.0, array[0], array[0], 0, 0, 0};

    for (size_t  i = 0; i < (arraySize / sizeof(array[0])); ++i) {
        data.sum += array[i];

        if (data.min > array[i]) {
            data.min = array[i];
        }

        if (data.max < array[i]) {
            data.max = array[i];
        }

        if (array[i] % 2 == 0) {
            data.evenCount++;
        }

        else if (array[i] % 2 != 0) {
            data.oddCount++;
        }

        if (array[i] % 3 == 0 && array[i] % 5 != 0) {
            data.countDiv3Not5++;
        }
    }

    data.avg = (double)data.sum / (arraySize / sizeof(int));

    return data;
}

void printHistogram(const int array[], size_t arraySize) {
    int one = 0, two = 0, three = 0, four = 0, five = 0;

    for (size_t i = 0; i < (arraySize / sizeof(array[0])); i++) {
        if (array[i] >= -100 && array[i] <= -50) {
            one++;
        }

        else if (array[i] >= -49 && array[i] <= 0) {
            two++;
        }

        else if (array[i] >= 1 && array[i] <= 50) {
            three++;
        }

        else if (array[i] >= 51 && array[i] <= 100) {
            four++;
        }

        else {
            five++;
        }

    }

    printf("Histogram of the list: \n");
    printf("[-100; -50]: %d numbers\n", one);
    printf("[ -49;  0 ]: %d numbers\n", two);
    printf("[  1 ;  50]: %d numbers\n", three);
    printf("[ 51 ; 100]: %d numbers\n", four);
    printf("[Undefined array]: %d numbers\n", five);
}

int main(void) {
    long long int number;
    int randomNumbersArray[100];
    struct arrayStats data = {0, 0.0, 0, 0, 0, 0, 0};

    srand(time(NULL));

    printf("Hello, enter any number: ");
    if (readLongLongInt(&number)) {
        printf("You've entered %lld\n", number);
    }
    else {
        printf("Wrong input\n");
    }

    printf("\n\nGenerating list of random numbers...\n");
    fillIntArray(randomNumbersArray, sizeof(randomNumbersArray), -100, 100);
    printHistogram(randomNumbersArray, sizeof(randomNumbersArray));

    data = analyzeArray(randomNumbersArray, sizeof(randomNumbersArray));

    printf("Sum of all numbers in the list: %lld\n", data.sum);
    printf("Average number in the generated list: %lf\n", data.avg);
    printf("The smallest number in the list: %d\n", data.min);
    printf("The biggest number in the list: %d\n", data.max);
    printf("Number of even numbers in the list: %d\n", data.evenCount);
    printf("Number of odd numbers in the list: %d\n", data.oddCount);
    printf("Number of numbers which divides by 3 and not by 5 in the list: %d\n", data.countDiv3Not5);

    return 0;
}

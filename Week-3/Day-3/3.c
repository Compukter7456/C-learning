#include <stdlib.h>
#include <stdio.h>

void memory_leak(void) {
    int *array = malloc(sizeof(int) * 20);

    for (size_t i = 0; i < 20; i++) {
        array[i] = i * 10;
    }
}

void use_after_free(void) {
    int *array = malloc(sizeof(int) * 20);

    free(array);

    for (size_t i = 0; i < 20; i++) {
        array[i] = i * 10;
    }
}

void out_of_bounds(void) {
    int *array = malloc(sizeof(int) * 20);

    for (size_t i = 0; i < 20; i++) {
        array[i+10] = i * 10;
    }

    free(array);
}

int main(void) {
    memory_leak();
    use_after_free();
    out_of_bounds();
}

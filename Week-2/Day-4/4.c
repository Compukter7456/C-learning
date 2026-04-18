#include <stdio.h>
#include <stdlib.h>

void malloc_example(void) {
    size_t array_elements = 10;
    // malloc() is used to allocate block of memory on the heap on runtime
    // Allocated memory is not deallocated on their own, so we must free it using free() function
    int* numbers = (int*)malloc(sizeof(int) * array_elements); // Allocate memory for 10 integers
    // Allocated memory is uninitialized and conains garbage

    // If there is not enough memory available, malloc() returns NULL
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Size of allocated memory for %zu integers: %zu bytes\n", array_elements, sizeof(int) * array_elements);
    // Fill the allocated memory with some numbers
    for (size_t i = 0; i < array_elements; i++) {
        *(numbers + i) = (i + 1) * array_elements;
    }

    for (size_t i = 0; i < array_elements; i++) {
        printf("%zu'th number stored in dynamically allocated memory: %d\n", i, *(numbers + i));
        printf("Memory address of %zu'th number: %p\n", i, (int*)(numbers + i));
    }

    free(numbers);
}

void calloc_example(void) {
    size_t array_elements = 10;

    // calloc() is similar to malloc(). It allocates block of memory on the heap on runtime BUT fills it with zeros
    // Allocated memory is not deallocated on their own, so we must free it using free() function
    int* numbers = (int*)malloc(sizeof(int) * 10);

    if (numbers == NULL) {
        printf("Memory allocation failed");
    }

    for (size_t i = 0; i < array_elements; i++) {
        printf("%zu'th element's value stored in dynamically allocated memory: %d\n", i, *(numbers + i));
        printf("%zu'th element's memory address: %p\n", array_elements, (int*)(numbers + i));
    } 
    
    // VERY important
    free(numbers);
}

void realloc_example(void) {
    return;
}

int main(void) {
    malloc_example();
    calloc_example();

    return 0;
}
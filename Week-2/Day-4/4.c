#include <stdio.h>
#include <stdlib.h>

void malloc_example(void) {
    size_t array_elements = 10;

    printf("\nmalloc() usage example\n");
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

    // It is VERY important to free allocated memory
    free(numbers);
}

void calloc_example(void) {
    size_t array_elements = 10;

    printf("\ncalloc() usage example\n");
    // calloc() is similar to malloc(). It allocates block of memory on the heap on runtime BUT fills it with zeros
    // Allocated memory is not deallocated on their own, so we must free it using free() function
    int* numbers = (int*)calloc(array_elements, sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
    }

    for (size_t i = 0; i < array_elements; i++) {
        printf("%zu'th element's value stored in dynamically allocated memory: %d\n", i, *(numbers + i));
        printf("%zu'th element's memory address: %p\n", array_elements, (int*)(numbers + i));
    } 
    
    // It is VERY important to free allocated memory
    free(numbers);
}

void realloc_example(void) {
    size_t array_elements = 10;
    
    printf("\nrealloc() usage example\n");
    // realloc() is used to resize previously allocated memory block without needing to free the old memory and allocate a new block

    int* numbers = (int*)malloc(sizeof(int) * array_elements);

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Size of allocated memory for %zu integers: %zu bytes\n", array_elements, sizeof(int) * array_elements);

    for (size_t i = 0; i < array_elements; i++) {
        *(numbers + i) = (i + 1) * array_elements;
    }

    printf("Pointer's memory address to the allocated memory: %p\n", numbers);

    for (size_t i = 0; i < array_elements; i++) {
        printf("%zu'th element's value stored in dynamically allocated memory: %d\n", i, *(numbers + i));
        printf("%zu'th element's memory address: %p\n", i, (int*)(numbers + i));
    }

    // Expand numbers memory block by 10 elements
    // Use another pointer for realloc. Because if realloc fails, it returns NULL
    // This will overwrite the original pointer and cause a memory leak

    int* bigger_numbers = (int*)realloc(numbers, sizeof(int) * (array_elements + 10));

    if (bigger_numbers == NULL) {
        printf("Memory allocation failed\n");
        free(numbers);
        return;
    }

    printf("Pointer's memory address to the reallocated memory: %p\n", bigger_numbers);

    for (size_t i = 0; i < array_elements + 10; i++) {
        printf("%zu'th element's value stored in dynamically allocated memory: %d\n", i, *(bigger_numbers + i));
        printf("%zu'th element's memory address: %p\n", i, (int*)(bigger_numbers + i));
    }

    free(bigger_numbers);
}

int* malloc_i_numbers(size_t elements) {
    if (elements <= 0) {
        return NULL;
    }

    int* numbers_array = (int*)malloc(sizeof(int) * elements);

    return numbers_array;
}

int main(void) {
    char buff[100];
    size_t ammount = 0;
    // malloc_example();
    // calloc_example();
    // realloc_example();


    printf("Hello, enter ammount of integers you wantto allocate memory for: ");
    if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%zu", &ammount) != 1) {
        printf("Invalid input\n");
        return -1;
    }

    int* allocated_memory = malloc_i_numbers(ammount);
    if (allocated_memory == NULL) {
        printf("Failed to allocate memory block for %zu integers\n", ammount);
        return -1;
    }

    printf("Allocated memory block for %zu integers. It's address: %p\n", ammount, allocated_memory);
    free(allocated_memory);

    return 0;
}
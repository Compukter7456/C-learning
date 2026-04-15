#include <stdio.h>
#include <string.h>

int is_alpha(const char data) {
    if (('A' <= data && data <= 'Z') || ('a' <= data && data <= 'z')) {
        return 1;
    }
    return 0;
}

void swap_integers(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int reverse_array(int* array, size_t array_size) {
    int* end = array + array_size - 1;

    if (array == end) {
        return 0;
    }

    for (size_t i = 0; i < array_size / 2; i++) {
        swap_integers(array + i, end - i);
    }

    return 1;
}

int count_words(const char* array, size_t array_size) {
    const char* end = array + array_size - 1;
    int is_word = 0;
    int words = 0;

    if (array == end) {
        return 0;
    }

    while (array <= end) {
        if(is_alpha(*array) && array != end && (*(array+1) != ',' && *(array+1) != '.' && *(array+1) != ' ' && *(array+1) != '\n' && *(array+1) != '\t')) {
            is_word = 1;
            array++;
        }

        else if(is_word) {
            words++;
            is_word = 0;
        }
        
        else {
            array++;
        }
    }

    if (is_word) {
        words++;
    }

    return words;
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    if (!reverse_array(array, array_size)) {
        printf("Error reversing the array\n");
        return 1;
    }

    printf("Reversed array: ");
    for (size_t i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    const char* test_string = "Hello, Worlddew. Here is s0me strs";
    printf("Number of strings in \"%s\" array: %d\n", test_string, count_words(test_string, strlen(test_string)));
    return 0;

}
#include <stdio.h>

struct string_stats {
    int digits;
    int letters;
    int spaces;
    size_t length;
    int other;
};

struct array_stats {
    int ints;
    int strings;

    long long int_sum;

    int letters;
    int digits;
    int spaces;
    int others;
};

int is_alpha(const char data) {
    if (('A' <= data && data <= 'Z') || ('a' <= data && data <= 'z')) {
        return 1;
    }
    return 0;
}

int is_digit(const char data) {
    if ('0' <= data && data <= '9') {
        return 1;
    }
    return 0;
}

void swap_integers(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int is_integer(const char *data, size_t data_size) {
    for (size_t i = 0; i < data_size && (data[i] != ' ' || data[i] != '\n' || data[i] != '\0'); ++i) {
        if (!is_digit(data[i])) {
            return 0;
        }
    }
    return 1;
}

void print_array_stats(struct string_stats array_stats) {
    printf("Array stats: \n");
    printf("Letters: %d\n", array_stats.letters);
    printf("Digits: %d\n", array_stats.digits);
    printf("Spaces: %d\n", array_stats.spaces);
    printf("Other data: %d\n", array_stats.other);
    printf("Total array size (in bytes): %zu\n", array_stats.length);
}


struct string_stats analyze_array_data(const char *array, size_t array_size) {
    struct string_stats array_stats = {0, 0, 0, array_size, 0};
    const char *array_pointer = array;
    const char *array_end = array + array_size;

    while (array_pointer < array_end) {
        if (*array_pointer == ' ') {
            array_stats.spaces++;
        }

        else if (is_alpha(*array_pointer)) {
            array_stats.letters++;
        }

        else if (is_digit(*array_pointer)) {
            array_stats.digits++;
        }

        else {
            array_stats.other++;
        }

        array_pointer++;
    }

    return array_stats;
}

int analyze_array_advanced(int *array, size_t array_size) {
    return 0;
}

int main(void) {
    char buffer[256];
    size_t data_size = 0;
    struct string_stats array_stats = {0, 0, 0, 0, 0};

    printf("Hello, enter any data: ");


    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Error writing to buffer\n");
        return 1;
    }

    for (; data_size < sizeof(buffer) && buffer[data_size] != '\0'; ++data_size);

    array_stats = analyze_array_data(buffer, data_size);
    print_array_stats(array_stats);

    return 0;
}

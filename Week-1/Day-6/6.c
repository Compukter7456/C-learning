#include <stdio.h>

struct array_stats {
    long long int_sum;

    int letters;
    int digits;
    int spaces;

    int ints;
    int strings;

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

int is_integer(const char *data, size_t data_size) {
    if (*data == ' ' || *data == '\n' || *data == '\0') {
        return 0;
    }

    for (size_t i = 0; i < data_size && (*data != ' ' && *data != '\n' && *data != '\0'); ++i) {
        if (*data == '-' || *data == '+') {
            data++;
            continue;
        }

        if (!is_digit(*data)) {
            return 0;
        }
        data++;
    }
    return 1;
}

int is_string(const char *data, size_t data_size) {
    for (size_t i = 0; i < data_size && (data[i] != ' ' && data[i] != '\n' && data[i] != '\0'); ++i) {
        if (!is_alpha(data[i]) || (data[i] != ' ' && data[i] != '\n' && data[i] != '\0')) {
            return 0;
        }
    }
    return 1;
}

void swap_integers(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void print_array_stats(struct array_stats array_stats) {
    printf("Array stats: \n");
    printf("Letters: %d\n", array_stats.letters);
    printf("Digits: %d\n", array_stats.digits);
    printf("Spaces: %d\n", array_stats.spaces);
    printf("Strings: %d\n", array_stats.strings);
    printf("Integers: %d\n", array_stats.ints);
    printf("Sum of all integers: %lld\n", array_stats.int_sum);
    printf("Other data: %d\n", array_stats.others);
}


struct array_stats analyze_array(const char *array, size_t array_size) {
    struct array_stats array_stats = {0, 0, 0, 0, 0, 0, 0};

    const char *array_pointer = array;
    int temp_int = 0;

    while (array_pointer < array + array_size) {
        if (is_alpha(*array_pointer)) {
            array_stats.letters++;
        }

        else if (is_digit(*array_pointer)) {
            array_stats.digits++;
        }

        else if (*array_pointer == ' ') {
            array_stats.spaces++;
        }

        else {
            array_stats.others++;
        }

        if (is_integer(array_pointer, array_size)) {
            for (const char *pointer = array_pointer; pointer < array + array_size && (*pointer != ' ' && *pointer != '\n' && *pointer != '\0'); ++pointer) {
                temp_int = temp_int * 10 + *pointer;
            }

            array_stats.ints++;
            array_stats.int_sum += temp_int;
        }

        else if (is_string(array_pointer, array_size)) {
            array_stats.strings++;
        }

        array_pointer++;
    }

    return array_stats;
}

int main(void) {
    struct array_stats array_stats = {0, 0, 0, 0, 0, 0, 0};
    char buffer[256];

    size_t buffer_size = 0;

    printf("Hello, enter any data: ");

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Error writing to buffer\n");
        return 1;
    }

    while (buffer[buffer_size] != '\0') {
        buffer_size++;
    }
    
    array_stats = analyze_array(buffer, buffer_size);
    print_array_stats(array_stats);

    return 0;
}

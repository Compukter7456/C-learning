#include <stdio.h>

struct array_stats {
    int digits_sum;

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

int is_integer(const char* data, size_t data_size) {
    const char* end = data + data_size;

    if (data == end) {
        return 0;
    }

    if (*data == '-' || *data == '+') {
        data++;

        if (data == end) {
            return 0;
        }
    }

    if (!is_digit(*data)) {
        return 0;
    }

    while (data < end && *data != ' ' && *data != '\n' && *data != '\0') {
        if (!is_digit(*data)) {
            return 0;
        }
        data++;
    }

    return 1;
}

int is_string(const char *data, size_t data_size) {
    const char* end = data + data_size;

    if (data == end) {
        return 0;
    }

    if (!is_alpha(*data)) {
        return 0;
    }

    while (data < end && *data != ' ' && *data != '\n' && *data != '\0') {
        if (!is_alpha(*data)) {
            return 0;
        }
        data++;
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
    printf("Sum of all digits: %d\n", array_stats.digits_sum);
    printf("Other data: %d\n", array_stats.others);
}


struct array_stats analyze_array(const char *array, size_t array_size) {
    struct array_stats array_stats = {0, 0, 0, 0, 0, 0, 0};

    const char* end = array + array_size;

    while (array < end) {
        if (is_alpha(*array)) {
            array_stats.letters++;
        }

        else if (is_digit(*array)) {
            array_stats.digits++;
            array_stats.digits_sum += (*array - '0');
        }

        else if (*array == ' ') {
            array_stats.spaces++;
        }

        else {
            array_stats.others++;
        }

        array++;
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

    while (buffer[buffer_size] != '\0' && buffer_size < sizeof(buffer)) {
        buffer_size++;
    }
    
    array_stats = analyze_array(buffer, buffer_size);
    print_array_stats(array_stats);

    return 0;
}

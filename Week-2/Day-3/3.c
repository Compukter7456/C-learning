#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *str) {
    size_t length = 0;

    if (str == NULL) {
        return 0;
    }

    while (*str != '\0') {
        length++;
        str++;      
    }
    return length;
}

int my_strcpy(const char* source, char* dest, size_t source_size, size_t dest_size) {
    if (source == NULL || dest == NULL || source_size > dest_size) {
        return -1;
    }

    while (*source != '\0') {
        *dest++ = *source++;
    }

    *dest = '\0';
    return 0;
} 

void strlen_demo(void) {
    // strlen() calculates the length of a string, excluding the null terminator
    // strlen() returns size_t result
    char string[] = "Hello from linux!";
    printf("Calculated length of the string via strlen(): %zu\n", strlen(string));
    printf("Calculated length of the string via my_strlen(): %zu\n", my_strlen(string));
}

void strcpy_demo(void) {
    // strcpy() copies string from source to destination, including the null terminator
    // strcpy() does not perform bounds checking, so the destination buffer must be large enough to hold the source string and the null terminator
    char source[] = "Hello from linux!";
    // Ensure the destination buffer is large enough to fit the source string
    char destination[20];

    strcpy(destination, source);
    printf("Copied string: %s\n", destination);

    char my_source[] = "Hello from C";
    char my_destination[20];

    my_strcpy(my_source, my_destination, sizeof(my_source), sizeof(my_destination));
    printf("Copied string using my_strcpy: %s\n", my_destination);
    printf("Size of source string: %zu\n", sizeof(my_source));
    printf("Length of source string: %zu\n", my_strlen(my_destination));
    printf("Size of destination buffer: %zu\n", sizeof(my_destination));
    printf("Length of destination string: %zu\n", my_strlen(my_destination));
}

int main() {
    strlen_demo();
    strcpy_demo();
    return 0;
}
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

    size_t i = 0;

    while (i < source_size && *source != '\0') {
        *(dest + i) = *(source + i);
        i++;
    }

    *(dest + i) = '\0';
    
    return 0;
} 

int my_strcmp(const char *str1, const char *str2, size_t str1_size, size_t str2_size) {
    if (str1 == NULL || str2 == NULL || str1_size == 0 || str2_size == 0) {
        return -1;
    }

    size_t i = 0;

    while (i < str1_size && i < str2_size && *(str1 + i) != '\0' && *(str2 + i) != '\0') {
        if (*(str1 + i) != *(str2 + i)) {
            return *(str1 + i) - *(str2 + i);
        }
        i++;
    }

    return *(str1 + i) - *(str2 + i);
}

char* my_strcat(char* dest, const char* src, size_t dest_size){
    if (dest == NULL || src == NULL || dest_size == 0) {
        return NULL;
    }

    size_t i = 0;
    size_t dest_net = my_strlen(dest);

    while (i < dest_size - dest_net - 1 && *(src + i) != '\0') {
        *(dest + dest_net + i) = *(src + i);
        i++;
    }

    *(dest + dest_net + i) = '\0';

    return dest;
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

void strcmp_demo(void) {
    // strcmp() takes const char *str1, const char *str2 arguments and compares their ASCII values till the null terminator
    // strcmp() rteturns 0 if strings are equal and a positive or negative value based on the ASCII difference of the first non-matching character if they are not equal
    const char* str1 = "First";
    const char* str2 = "first";
    const char* str3 = "Third";

    printf("Comparing '%s' and '%s': %d\n", str1, str1, my_strcmp(str1, str1, strlen(str1), strlen(str1)));
    printf("Comparing '%s' and '%s': %d\n", str1, str2, my_strcmp(str1, str2, strlen(str1), strlen(str2)));
    printf("Comparing '%s' and '%s': %d\n", str1, str3, my_strcmp(str1, str3, strlen(str1), strlen(str3)));
    printf("Comparing '%s' and '%s': %d\n", str2, str3, my_strcmp(str2, str3, strlen(str2), strlen(str3)));
}

void strcat_demo(void) {
    // strcat() takes char* dest and const char* src and adds src string to the end of the dest string, including '\0'
    // strcat() does not check bounds checking, so the destination buffer must be large enough to hold the resulting string'
    char array[64];

    strcat(array, "Hello");
    strcat(array, " from");
    strcat(array, " C");
    printf("Concatenated string using strcat(): %s\n", array);

    char my_array[64] = "Hello";
    my_strcat(my_array, " from", sizeof(my_array));
    my_strcat(my_array, " C", sizeof(my_array));
    printf("Concatenated string using my_strcat(): %s\n", my_array);
}

int main() {
    // strlen_demo();
    // strcpy_demo();
    // strcmp_demo();
    strcat_demo();

    return 0;
}
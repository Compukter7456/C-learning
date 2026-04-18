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

void strlen_demo(void) {
    // strlen() calculates the length of a string, excluding the null terminator
    // strlen() returns size_t result
    char string[] = "Hello from linux!";
    printf("Calculated length of the string via strlen(): %zu\n", strlen(string));
    printf("Calculated length of the string via my_strlen(): %zu\n", my_strlen(string));
}

int main() {
    strlen_demo();
    return 0;
}
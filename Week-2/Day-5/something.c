#include <stdio.h>
#include <stdlib.h>

char* copy_str(char* source) {
    if (source == NULL) {
        return NULL;
    }

    size_t arr_size = 1;

    for (size_t i = 0; *(source + i) != '\0'; i++) {
        arr_size++;
    }

    char* copied_list = (char*)malloc(arr_size);

    for (size_t i = 0; i < arr_size; i++) {
        *(copied_list + i) = *(source + i);
    }

    return copied_list;
}

int main (void) {
    char buffer[256];

    printf("Hello, enter some data: ");
    if(!fgets(buffer, sizeof(buffer), stdin)) {
        fprintf(stderr, "[Error] Error writing your input to the buffer\n");
        return -1;
    }

    char* dest = copy_str(buffer);

    if (dest == NULL) {
        fprintf(stderr, "[Error] Error allocating memory\n");
        return -1;
    }

    fprintf(stdout, "[Info] You've entered: %s", buffer);
    fprintf(stdout, "[Info] Original string's pointer: %p\n", buffer);
    fprintf(stdout, "[Info] Copied string's memory address in heap: %p\n", dest);
    fprintf(stdout, "[Info] Freeing allocated memory...\n");
    free(dest);
}
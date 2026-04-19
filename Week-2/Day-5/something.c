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

int copy_string_examlle (void) {
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

    return 0;
}

int dynamical_float_array(void){
    size_t array_elements = 5;
    size_t counter = 0;
    float* array = (float*)malloc(sizeof(float) * array_elements);
    char buffer[256];

    fprintf(stdout, "Hello, this program creates a dynamic list of floats. Enter any float, if the list becomes full, it will be resized\n");
    if (array == NULL) {
        fprintf(stderr, "[Error] Error allocating %zu bytes list for floats\n", sizeof(float) * array_elements);
        return -2;
    }
    fprintf(stdout, "[Info] Allocated %zu bytes memory block for %zu floats\n", sizeof(float) * array_elements, array_elements);

    while (1) {
        if (counter >= array_elements) {
            fprintf(stdout, "[Info] Array size limit reached. Resizing array to fit 10 more floats...\n");
            array_elements += 10;

            float* tmp = (float*)realloc(array, sizeof(float) * array_elements);

            if (tmp == NULL) {
                fprintf(stderr, "[Error] Error allocating %zu bytes list for floats\n", sizeof(float) * array_elements);
                free (array);
                return -2;
            }

            array = tmp;
        }

        fprintf(stdout, "Your float: ");
        
        if (!fgets(buffer, sizeof(buffer), stdin) || sscanf(buffer, "%f", array + counter) != 1) {
            fprintf(stdout, "[Warning] Incorrect input. Enter only float data or 0 to exit\n");
            continue;
        }
        if (*(array + counter) == 0.0f) {
            fprintf(stdout, "[Info] 0 detected, exiting...\n");
            break;
        }
        counter++;
    }

    fprintf(stdout, "You have entered %zu floats. Allocated memory's size is %zu bytes\n", counter, sizeof(float) * array_elements);
    fprintf(stdout, "[Info] Freeing %zu bytes allocated memory...\n", sizeof(float) * array_elements);
    free(array);

    return 0;
}

int main(void) {
    dynamical_float_array();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* save_argv(char* name) {
    if (name == NULL) {
        return NULL;
    }

    size_t name_length = strlen(name) + 1;

    char* string = malloc(name_length);
    if (string == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < name_length; i++) {
        string[i] = name[i];
    }

    return string;
}

int main(int argc, char *argv[]) {
    char *name = NULL;
    char *age = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--name") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[Error] --name needs a value\n");
                return -1;
            }
            else if (name != NULL) {
                fprintf(stderr, "[Error] --name is already set\n");
                return -1;
            }

            name = save_argv(argv[i+1]);
            if (name == NULL) {
                fprintf(stderr, "[Error] Could not save name to heap memory\n");
                return -1;
            }
            i++;
        }

        else if (strcmp(argv[i], "--age") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[Error] --age needs a value\n");
                return -1;
            }
            else if (age != NULL) {
                fprintf(stderr, "[Error] --age is already set\n");
                return -1;
            } 

            age = save_argv(argv[i+1]);
            if (age == NULL) {
                fprintf(stderr, "[Error] Could not save age to heap memory\n");
                return -1;
            }
            i++;
        }

        else {
            fprintf(stderr, "[Error] Unknown flag: %s\n", argv[i]);
            return -1;
        }
    }
    
    if (name == NULL || age == NULL) {
        fprintf(stderr, "Usage: %s --name Bob --age 17\n", argv[0]);
        return -1;
    }

    fprintf(stdout, "argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s, memory address: %p\n", i, argv[i], argv[i]);
    }

    fprintf(stdout,
        "Your name: %s\n"
        "Your age: %s\n"
        "Name is saved in heap memory, address: %p\n"
        "Age is saved in heap memory, address: %p\n",
        name, age, (void*)name, (void*)age);

    free(name);
    free(age);

    return 0;
}
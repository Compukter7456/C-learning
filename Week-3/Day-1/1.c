#include <stdio.h>
#include <unistd.h> // sleep()

#define WORKING_FILE "test.txt"
#define BUFFER_SIZE 32

int create_file(void) {
    FILE *file = fopen(WORKING_FILE, "w");

    if (file == NULL) {
        fprintf(stderr, "[Error] Cannot open file\n");
        return -1;
    }

    fprintf(stdout, "[Info] Writing data to %s. FILE's address: %p\n", WORKING_FILE, file);
    fprintf(file, 
        "NAME    AGE   CITY\n"
        "abc     12    Chicago\n"
        "def     25    Colego\n"
        "ghi     65    Cleveland\n"
    );

    fclose(file);
    return 0;
}

int fscanf_demo(void) {
    FILE *file = fopen(WORKING_FILE, "r");

    if (file == NULL) {
        fprintf(stderr, "[Error] There is no such file %s\n", WORKING_FILE);
        return -1;
    }

    char name[BUFFER_SIZE];
    char age[BUFFER_SIZE];
    char city[BUFFER_SIZE];

    fprintf(stdout, "[Info] Reading file %s...\n", WORKING_FILE);

    while (fscanf(file, "%31s %31s %31s", name, age, city) == 3) {
        printf("%s %s %s\n", name, age, city);
    }

    fclose(file);
    return 0;
}

int fgets_demo(void) {
    FILE *file = fopen(WORKING_FILE, "r");

    if (file == NULL) {
        fprintf(stderr, "[Error] There is no such file %s\n", WORKING_FILE);
        return -1;
    }

    char buff[BUFFER_SIZE];

    for (size_t i = 0; fgets(buff, sizeof(buff), file) != NULL; i++) {
        sleep(1);
        fprintf(stdout, "%zu's line in file: %s", i+1, buff);
    }

    fclose(file);
    return 0;
}

int main(void) {
    create_file();
    fscanf_demo();
    fgets_demo();
    return 0;
}
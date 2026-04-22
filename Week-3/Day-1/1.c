#include <stdio.h>
#include <unistd.h> // sleep

#define WORKINGFILE "test.txt"
#define BUFFERSIZE 32

int file_descriptors(void) {
    
    // FILE is glibc struct which contains info about file with which we are working
    FILE *file = fopen(WORKINGFILE, "w"); // file1 contains memory address of struct FILE that works with test1.txt
    // /proc/PID/fd/3 is file descriptor of test1.txt
    // If we delete/unlink file (but program has open fd) - file will be accessible via that fd

    if (file == NULL) {
        fprintf(stderr, "[Error] Cannot open file\n");
        return -1;
    }

    // fprintf allows to write data into set stream, like stdin, stdout, stderr, files, etc
    // printf("Hello\n"); is fprintf(stdout, "Hello\n");
    fprintf(stdout, "[Info] Writing \"Hello from C\" to %s. Address of FILE: %p\n", WORKINGFILE, file);
    fprintf(file, "NAME    AGE   CITY\nabc     12    Chicago\ndef     25    Colego\nghi     65    Cleveland\n");

    fclose(file);

    return 0;
}

int fscanf_demo(void) {
    FILE *file = fopen(WORKINGFILE, "r");

    if (file == NULL) {
        fprintf(stderr, "[Error] There is no such file %s\n", WORKINGFILE);
        return -1;
    }

    char a[BUFFERSIZE], b[BUFFERSIZE], c[BUFFERSIZE];

    fprintf(stdout, "[Info] Reading file %s...\n", WORKINGFILE);

    while (fscanf(file, "%31s %31s %31s", a, b, c) == 3) {
        printf("%s %s %s\n", a, b, c);
    }

    fclose(file);
    return 0;
}

int main(void) {
    file_descriptors();
    fscanf_demo();
    return 0;
}
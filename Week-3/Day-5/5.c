#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h> // for memfd

#define BUFF_SIZE 128

int main(void) {
    int fd = memfd_create("temp", 0);

    if (fd == -1) {
        fprintf(stderr, "[Error] Could not create memfd file\n");
        return -1;
    }

    // By default memfd_create creates file in ram (it has volatile storage) with 0 bytes size
    if (ftruncate(fd, BUFF_SIZE) == -1) { // ftruncate() changes fd's size to n bytes
        fprintf(stderr, "[Error] Ftruncate failed\n");
        close(fd);
        return -1;
    } 

    char *buff = "Some secret payload data. Password is: thiswillbeencrypted";
    if (write(fd, buff, strlen(buff)) == -1) {
        fprintf(stderr, "[Error] Could not write data to memfd file\n");
        close(fd);
        return -1;
    }

    char *array = calloc(BUFF_SIZE, 1);
    if (array == NULL) {
        fprintf(stderr, "[Error] Could not allocate %d bytes\n", BUFF_SIZE);
        close(fd);
        return -1;
    }
    lseek(fd, 0, SEEK_SET); // Reset fd's position indicator

    if (read(fd, array, strlen(buff)) < (ssize_t)strlen(buff)) {
        fprintf(stdout, "[Warning] Read less data than expected\n");
    }

    fprintf(stdout, "Stored data in memfd: %s\n", array);

    sleep(30); // Look at /proc/PID/fd/3. You wil see: 3 -> '/memfd:temp (deleted)'
    free(array);
    close(fd);

    return 0;
}
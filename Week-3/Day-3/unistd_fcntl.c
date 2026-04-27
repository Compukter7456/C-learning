#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define WORKING_FILE "temp.txt"


int main(void) {
    int fd = open(WORKING_FILE, O_CREAT | O_RDWR, 0600);

    if (fd == -1) {
        fprintf(stderr, "[Error] Could not create file %s\n", WORKING_FILE);
        return -1;
    }
    fprintf(stdout, "[Info] Created file %s and unlinked from diretory, file remains open in fd\n", WORKING_FILE);
    unlink(WORKING_FILE);

    char *data = "S0mESecRetP@sSwOrD";

    if (write(fd, data, strlen(data)) == -1) {
        printf("[Error] Could not write data to file or meet EOF\n");
        close(fd);
        return -1;
    }
    fsync(fd); // Sync fd. Write data from ram to the disc
    fprintf(stdout, "[Info] Written data to %s\n", WORKING_FILE);

    char *buff = calloc(strlen(data) + 1, 1);
    if (buff == NULL) {
        fprintf(stderr, "[Error] Could not allocate %zd bytes\n", strlen(data));
        close(fd);
        return -1;
    }

    lseek(fd, 0, SEEK_SET);
    if (read(fd, buff, strlen(data)) == -1) {
        printf("[Error] Could not read data from file or meet EOF\n");
        close(fd);
        return -1;
    }
    
    fprintf(stdout, "File's content: %s\n", buff);
    fprintf(stdout, "[Info] Sleeping 999 seconds. Look at /proc/PID/fd/3\n");
    free(buff);

    sleep(999);
    close(fd);

    return 0;
}
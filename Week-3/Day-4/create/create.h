#ifndef CREATE_H
#define CREATE_H

#include <stddef.h>

#define CONTENTS_SIZE 256
struct list {

    struct task *tasks;
};

struct task {
    unsigned int id; 
    char status; // 0 - undone, 1 - done
    char task_contents[CONTENTS_SIZE];
};

int create_file(char *filename);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Singly linked list is a data structure. Each node contains address of the next node but doesn't know about previous one

int main(void) {
    struct Transaction *head = NULL;

    prepend(&head, 1, 136483, "Marko", ARR_SIZE, "Antonio", ARR_SIZE);
    prepend(&head, 2, 2843600, "Antonio", ARR_SIZE, "Francesco", ARR_SIZE);
    prepend(&head, 3, 30000, "Francesco", ARR_SIZE, "Layla", ARR_SIZE);
    prepend(&head, 4, 20000, "Francesco", ARR_SIZE, "Luca", ARR_SIZE);
    prepend(&head, 5, 500, "Luca", ARR_SIZE, "LR Motors", ARR_SIZE);

    print_list(head);
    free_list(head);
    return 0;
}
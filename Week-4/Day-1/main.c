#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Singly linked list is a data structure. Each node contains address of the next node but doesn't know about previous one

int main(void) {
    struct Transaction *head = NULL;

    prepend(&head, 1, 136483, "Marko", "Antonio");
    prepend(&head, 2, 2843600, "Antonio", "Francesco");
    prepend(&head, 3, 30000, "Francesco", "Layla");
    prepend(&head, 4, 20000, "Francesco", "Luca");
    prepend(&head, 5, 500, "Luca", "LR Motors");

    print_list(head);
    free_list(head);
    return 0;
}
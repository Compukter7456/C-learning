#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Singly linked list is a data structure. Each node contains address of the next node but doesn't know about previous one

int main(void) {
    printf("[Info] Creating single linked list...\n");
    struct Transaction *head = NULL;
    struct Transaction *element = NULL;

    printf("[Info] Appending single listing list...\n");
    prepend(&head, 1, 136483, "Marko", "Antonio");
    prepend(&head, 2, 2843600, "Antonio", "Francesco");
    prepend(&head, 3, 30000, "Francesco", "Layla");
    prepend(&head, 4, 20000, "Francesco", "Luca");
    prepend(&head, 5, 10000, "Luca", "LR Motors");

    printf("Created list: \n");
    print_list(head);

    printf("\n");
    printf("[Info] Calculating single linked list elements...\n");
    printf("List has %zu elements\n\n", list_length(head));

    element = list_search(head, 5);
    if (element == NULL) {
        printf("[Info] Element with id %d not found\n", 5);
    }
    else {
        printf("Element with %d: ", 5);
        print_list_element(element);
    }

    element = list_search(head, 1);
    if (element == NULL) {
        printf("[Info] Element with id %d not found\n", 1);
    }
    else {
        printf("Element with %d: ", 1);
        print_list_element(element);
    }

    element = list_search(head, 3);
    if (element == NULL) {
        printf("[Info] Element with id %d not found\n", 3);
    }
    else {
        printf("Element with %d: ", 3);
        print_list_element(element);
    }

    element = list_search(head, 6);
    if (element == NULL) {
        printf("[Info] Element with id %d not found\n", 6);
    }
    else {
        printf("Element with %d: ", 6);
        print_list_element(element);
    }

    printf("\n");
    printf("[Info] Deleting element with id %d\n", 1);
    list_element_delete(&head, 1);

    printf("[Info] Deleting element with id %d\n", 3);
    list_element_delete(&head, 3);

    printf("[Info] Deleting element with id %d\n", 5);
    list_element_delete(&head, 5);

    printf("\nModified list: \n");
    print_list(head);

    printf("[Info] Freeing list...\n");
    free_list(head);

    printf("Bye\n");

    return 0;
}
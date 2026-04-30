#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 64

// Singly linked list is a data structure. Each node contains address of the next node but doesn't know about previous one
struct Transaction {
    unsigned long int sum;
    char sender[ARR_SIZE];
    char recipient[ARR_SIZE];
    struct Transaction *next;
};

size_t my_strlen(const char *str) {
    size_t length = 0;

    while (*str != '\0') {
        length++;
        str++;      
    }

    return length;
}

struct Transaction *create_transaction(unsigned long int sum, char sender[ARR_SIZE], char recipient[ARR_SIZE]) {
    struct Transaction *new_transaction = (struct Transaction*)calloc(1, sizeof(struct Transaction));
    if (new_transaction == NULL) {
        fprintf(stderr, "[Error] Failed to create new transaction\n");
        return NULL;
    }

    new_transaction->sum = sum;
    for (size_t i = 0; i <= my_strlen(sender); i++) {
        new_transaction->sender[i] = sender[i];
    }
    for (size_t i = 0; i <= my_strlen(recipient); i++) {
        new_transaction->recipient[i] = recipient[i];
    }

    return new_transaction;
}

// Add element to the beginning of the list
void prepend(struct Transaction **head, unsigned long int sum, char *sender, char *recipient) {
    if (head == NULL) {
        return;
    }

    struct Transaction *new = create_transaction(sum, sender, recipient);
    if (new == NULL) {
        return;
    }

    new->next = *head;
    *head = new;
}

void print_list(struct Transaction *head) {
    if (head == NULL) {
        return;
    }

    struct Transaction *current = head;

    while(current != NULL) {
        printf("Transaction's memory address: %p\n", current);
        printf("Transaction sum: %lu\n", current->sum);
        printf("Sender: %s\n", current->sender);
        printf("Recipient: %s\n", current->recipient);
        printf("Next transaction's memory address: %p\n", current->next);
        printf("\n");
        current = current->next;
    }
}

void free_list(struct Transaction *head) {
    if (head == NULL) {
        return;
    }

    for (struct Transaction *tmp = head; head != NULL;) {
        tmp = head;
        head = head->next;
        free(tmp);
    } 
}

int main(void) {
    struct Transaction *head = NULL;

    prepend(&head, 136483, "Marko", "Antonio");
    prepend(&head, 2843600, "Antonio", "Francesco");
    prepend(&head, 30000, "Francesco", "Layla");
    prepend(&head, 20000, "Francesco", "Luca");
    prepend(&head, 500, "Luca", "LR Motors");

    print_list(head);
    free_list(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"


struct Transaction *create_transaction(const unsigned long int id, const unsigned long int sum, const char *sender, const size_t sender_length, const char *recipient, size_t recipient_length) {
    struct Transaction *new_transaction = (struct Transaction*)calloc(1, sizeof(struct Transaction));
    if (new_transaction == NULL) {
        fprintf(stderr, "[Error] Failed to create new transaction\n");
        return NULL;
    }

    new_transaction->id = id;
    new_transaction->sum = sum;
    snprintf(new_transaction->sender, ARR_SIZE, "%s", ARR_SIZE);
    snprintf(new_transaction->recipient, ARR_SIZE, "%s", ARR_SIZE);

    return new_transaction;
}

// Add element to the beginning of the list
void prepend(struct Transaction **head, const unsigned long int id, const unsigned long int sum, const char *sender, size_t sender_length, const char *recipient, size_t recipient_length) {
    if (head == NULL) {
        return;
    }

    
    struct Transaction *new = create_transaction(id, sum, sender, sender_length, recipient, recipient_length);
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
        printf("Transaction's memory address: %p\n", (void*)current);
        printf("Transaction's id: %lu\n", current->id);
        printf("Transaction sum: %lu\n", current->sum);
        printf("Sender: %s\n", current->sender);
        printf("Recipient: %s\n", current->recipient);
        printf("Next transaction's memory address: %p\n", (void*)current->next);
        printf("\n");
        current = current->next;
    }
}

void free_list(struct Transaction *head) {
    if (head == NULL) {
        return;
    }

    struct Transaction *tmp = head;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    } 
}

size_t list_length(const struct Transaction *head) {
    if (head == NULL) {
        return 0;
    }

    
    size_t elements = 0;

    for(struct Transaction *current = head; current != NULL; current = current->next) {
        elements++;
    }

    return elements;
}

struct Transaction *list_search(const struct Transaction *head, const unsigned long int id) {
    if (head == NULL) {
        return NULL;
    }

    struct Transaction *current = head;

    while (current != NULL) {
        if (current->id == id) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void list_element_delete (struct Transaction **head, const unsigned long int id) {
    if (head == NULL || *head == NULL) {
        return;
    }

    struct Transaction *current = *head;

    if ((*head)->id == id) {
        *head = current->next;
        free(current);
        return;
    }

    // Delete linked list's specific position element
    while (current->next != NULL) {
        if ((current->next)->id == id) {
            struct Transaction *tmp = current->next;

            current->next = (current->next)->next;
            free(tmp);
            return;
        }
        current = current->next;
    }
}
#ifndef OPERATIONS_H
#define OPERATIONS_H

#define ARR_SIZE 64

struct Transaction {
    unsigned long int id;
    unsigned long int sum;
    char sender[ARR_SIZE];
    char recipient[ARR_SIZE];
    struct Transaction *next;
};

struct Transaction *create_transaction(const unsigned long int id, const unsigned long int sum, const char *sender, const size_t sender_length, const char *recipient, size_t recipient_length);
void prepend(struct Transaction **head, const unsigned long int id, const unsigned long int sum, const char *sender, size_t sender_length, const char *recipient, size_t recipient_length);
void print_list(struct Transaction *head);
void free_list(struct Transaction *head);
size_t list_length(const struct Transaction *head);
struct Transaction *list_search(const struct Transaction *head, const unsigned long int id);
void list_element_delete (struct Transaction **head, const unsigned long int id);

#endif
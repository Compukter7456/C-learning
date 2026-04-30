#ifndef OPERATIONS_H
#define OPERATIONS_H

#define ARR_SIZE 64

struct Transaction {
    size_t id;
    unsigned long int sum;
    char sender[ARR_SIZE];
    char recipient[ARR_SIZE];
    struct Transaction *next;
};

struct Transaction *create_transaction(const size_t id, const unsigned long int sum, const char *sender, const char *recipient);
void prepend(struct Transaction **head, const size_t id, const unsigned long int sum, const char *sender, const char *recipient);
void print_list(struct Transaction *head);
void print_list_element(struct Transaction *element);
void free_list(struct Transaction *head);
size_t list_length(struct Transaction *head);
struct Transaction *list_search(struct Transaction *head, const size_t id);
void list_element_delete (struct Transaction **head, const size_t id);

#endif
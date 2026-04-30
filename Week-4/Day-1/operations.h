#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>

#define ARR_SIZE 64

struct Transaction {
    unsigned long int id;
    unsigned long int sum;
    char sender[ARR_SIZE];
    char recipient[ARR_SIZE];
    struct Transaction *next;
};

size_t my_strlen(const char *str);
struct Transaction *create_transaction(unsigned long int id, unsigned long int sum, const char *sender, const char *recipient);
void prepend(struct Transaction **head, unsigned long int id, unsigned long int sum, char *sender, char *recipient);
void print_list(struct Transaction *head);
void free_list(struct Transaction *head);
size_t list_length(struct Transaction *head);
struct Transaction *list_search(struct Transaction *head, unsigned long int id);
void list_element_delete (struct Transaction **head, unsigned long int id);

#endif
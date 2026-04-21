#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

#define GROWTH_STEP 5

int my_strcmp(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;
    }

    size_t i = 0;

    while (*(str1 + i) != '\0' && *(str2 + i) != '\0') {
        if (*(str1 + i) != *(str2 + i)) {
            return *(str1 + i) - *(str2 + i);
        }
        i++;
    }

    return *(str1 + i) - *(str2 + i);
}

struct contact_book* create_book(void) {
    struct contact_book *book = (struct contact_book*)malloc(sizeof(struct contact_book));

    if (book == NULL) {
        fprintf(stderr, "[Error] contact_book malloc failed\n");
        return NULL;
    }

    book->contacts = (struct contact*)malloc(sizeof(struct contact) * INITIAL_CAPACITY);
    if (book->contacts == NULL) {
        fprintf(stderr, "[Error] contacts malloc failed\n");
        free(book);
        return NULL;
    }

    book->count = 0;
    book->capacity = INITIAL_CAPACITY; 

    return book;
}

int add_contact(struct contact_book* book, struct contact* contact) {
    if (book == NULL || contact == NULL) {
        fprintf(stderr, "[Error] book or contact pointer is NULL\n");
        return -1;
    }

    if (book->count >= book->capacity) {
        struct contact* tmp = (struct contact*)realloc(book->contacts, sizeof(struct contact) * (book->count + GROWTH_STEP));
        
        if (tmp == NULL) {
            fprintf(stderr, "Error allocating %zu bytes for the bigger list of contacts\n", sizeof(struct contact) * (book->count + GROWTH_STEP));
            return -1;
        }

        book->capacity = book->count + GROWTH_STEP;
        book->contacts = tmp;

        fprintf(stdout, "[Info] Size limit exceeded, added %zu bytes to contacts array. New size: %zu\n", sizeof(struct contact) * GROWTH_STEP, sizeof(struct contact) * (book->count));

    }

    *(book->contacts + book->count) = *contact;
    book->count++;

    return 0;
}

struct contact* find_contact(struct contact_book* book, const char* name) {
    if (book == NULL || name == NULL) {
        fprintf(stderr, "[Error] book or name pointer is NULL\n");   
        return NULL;
    }

    for (size_t i = 0; i < book->count; i++) {

    }
}
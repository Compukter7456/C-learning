#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

#define CALLOC_STEP 5

struct contact_book *create_book(void) {
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

int add_contact(struct contact_book *book, struct contact *contact) {
    if (book == NULL || contact == NULL) {
        fprintf(stderr, "[Error] book or contact pointer is NULL\n");
        return -1;
    }

    if (book->count >= book->capacity / book->count) {
        struct contact* tmp = (struct contact*)realloc(book->contacts, sizeof(struct contact) * (book->count + CALLOC_STEP));

        if (tmp == NULL) {
            fprintf(stderr, "Error allocating %zu bytes for the bigger list of contacts\n", sizeof(struct contact) * (book->count + CALLOC_STEP));
            return -1;
        }

        if (tmp != book->contacts) {
            free(book->contacts);
            book->contacts = tmp;
        }

        fprintf(stdout, "[Info] Size limit exceeded, added %zu bytes to contacts array. New size: %zu\n", sizeof(struct contact) * CALLOC_STEP, sizeof(struct contact) * (book->count));
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"

#define GROWTH_STEP 5

int my_strcmp(const char *str1, const char *str2) {
    size_t i = 0;

    while (*(str1 + i) != '\0' && *(str2 + i) != '\0') {
        if (*(str1 + i) != *(str2 + i)) {
            return *(str1 + i) - *(str2 + i);
        }
        i++;
    }

    return *(str1 + i) - *(str2 + i);
}

size_t my_strlen(const char *str) {
    if (str == NULL) {
        return 0;
    }

    size_t length = 0;

    while (*str != '\0') {
        length++;
        str++;      
    }

    return length;
}

struct contact_book* create_book(void) {
    struct contact_book *book = (struct contact_book*)malloc(sizeof(struct contact_book));

    if (book == NULL) {
        fprintf(stderr, "[Error] contact_book malloc failed\n");
        return NULL;
    }

    book->contacts = malloc(sizeof(struct contact) * INITIAL_CAPACITY);
    if (book->contacts == NULL) {
        fprintf(stderr, "[Error] contacts malloc failed\n");
        free(book);
        return NULL;
    }

    book->count = 0;
    book->capacity = INITIAL_CAPACITY; 

    return book;
}

int add_contact(struct contact_book* book, const struct contact* contact_data) {
    if (book == NULL || contact_data == NULL) {
        fprintf(stderr, "[Error] book or contact pointer is NULL\n");
        return -1;
    }

    if (book->count >= book->capacity) {
        struct contact* tmp = realloc(book->contacts, sizeof(struct contact) * (book->count + GROWTH_STEP));
        
        if (tmp == NULL) {
            fprintf(stderr, "Error allocating %zu bytes for the bigger list of contacts\n", sizeof(struct contact) * (book->count + GROWTH_STEP));
            return -1;
        }

        book->capacity = book->count + GROWTH_STEP;
        book->contacts = tmp;

        fprintf(stdout, "[Info] Size limit exceeded, added %zu bytes to contacts array. New size: %zu\n", sizeof(struct contact) * GROWTH_STEP, sizeof(struct contact) * (book->count));

    }

    *(book->contacts + book->count) = *contact_data;
    book->count++;

    return 0;
}

struct contact* find_contact(const struct contact_book* book, const char* name) {
    if (book == NULL || name == NULL) {
        fprintf(stderr, "[Error] book or name pointer is NULL\n");   
        return NULL;
    }

    for (size_t i = 0; i < book->count; i++) {
        struct contact* contact = book->contacts + i;
        if (my_strcmp(name, contact->name) == 0) {
            return contact;
        }
    }

    return NULL;
}

void print_contacts(const struct contact_book* book) {
    if (book == NULL) {
        fprintf(stderr, "[Error] book pointer is NULL\n");
        return;
    }
    
    if (book->contacts == NULL) {
        fprintf(stderr, "[Error] contacts pointer is NULL\n");
        return;
    }

    if (book->count == 0) {
        fprintf(stdout, "[Info] Contact book is empty\n");
        return;
    }

    fprintf(stdout, "[Info] All contacts in contacts book:\n");
    for (size_t i = 0; i < book->count; i++) {
        struct contact* contact = book->contacts + i;

        fprintf(stdout, "\nContact #%zu:\n", i+1);
        fprintf(stdout, "Name: %s\n", contact->name);
        fprintf(stdout, "Phone: %s\n", contact->phone);
        fprintf(stdout, "Email: %s\n", contact->email);
    }
    fprintf(stdout, "[Info] Finished\n");
}

void free_book(struct contact_book* book) {
    if (book == NULL) {
        fprintf(stderr, "[Error] book pointer is NULL\n");
        return;
    }

    free(book->contacts);
    free(book);
}
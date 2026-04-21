#ifndef CONTACTS_H
#define CONTACTS_H


#include <stddef.h>

#define MAX_NAME    64
#define MAX_PHONE   16
#define MAX_EMAIL   64
#define INITIAL_CAPACITY 5

// Contact's record data
struct contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
};

// Array of contacts
struct contact_book {
    struct contact *contacts; // Pointer to the dynamicall array of pointers, storing addresses of contact's structs
    size_t count; // Ammount of contacts
    size_t capacity; // Size of dynamical array
};

// Create contacts book
// Return NULL on any error
struct contact_book *create_book(void);

// Add a new contact to the book
// Resize dynamical array in case no more space left in the array
// Return 0 on success, -1 on failure
int add_contact(struct contact_book *book, struct contact *contact);

// Search for contact by name, phone or email
// Return pointer to found struct in case of success
// Return pointer = NULL in case of failure
struct contact *find_contact(struct contact_book *book, char *name);

// Print all contacts in contact books
void print_contacts(struct contact_book *book);

// Free allocated memory
void free_book(struct contact_book *book);

#endif
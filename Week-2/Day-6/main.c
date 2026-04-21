#include <stdio.h>
#include "contacts.h"

int main(void) {
    char buff[64];
    struct contact_book* book;
    int choice = 0, is_initialized = 0;;

    fprintf(stdout, "Hello, this program implements simple contacts book\n");
    fprintf(stdout, "I have used .h file to separate code, structs to store data, malloc and realloc to create dynamical heap memory with growth ability\n");
    fprintf(stdout, "\n====== Menu ======\n");
    fprintf(stdout, "1. Create contacts book\n");
    fprintf(stdout, "2. Add contacts to the contacts book\n");
    fprintf(stdout, "3. Search contact in the contacts book\n");
    fprintf(stdout, "4. Print all contacts\n");
    fprintf(stdout, "5. Delete contacts book\n");
    fprintf(stdout, "0. Exit program\n");

    
    while (1) {
        fprintf(stdout, "Your choice: ");
        if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%d", &choice) != 1) {
            fprintf(stderr, "[Error] Invalid input\n");
            continue;
        }

        switch (choice) {
            case 0:
                if (is_initialized) {
                    fprintf(stdout, "[Info] Cleaning contacts book before exiting...\n");

                    free_book(book);
                }

                fprintf(stdout, "[Info] Exiting...\n");
                return 0;
        

            case 1: 
                if (is_initialized) {
                    fprintf(stdout, "[Warning] Contacts book is already created\n");
                    break;
                }

                fprintf(stdout, "[Info] Creating contacts book...\n");
                book = create_book();

                if (book == NULL) {
                    fprintf(stderr, "[Error] Failed to create book\n");
                    break;
                }
                
                fprintf(stdout, "[Info] Book's memory address: %p\n", book);
                is_initialized = 1;
                break;


            case 2:
                if (!is_initialized) {
                    fprintf(stderr, "[Error] You need to create the book first\n");
                    break;
                }
                    
                struct contact contact_data = {"", "", ""};

                fprintf(stdout, "Adding a new contact to the book\n");

                fprintf(stdout, "Enter contact's name: ");
                if (!fgets(contact_data.name, sizeof(contact_data.name), stdin)) {
                    fprintf(stderr, "[Error] Error writing name\n");
                    break;
                }

                fprintf(stdout, "Enter contact's email: ");
                if (!fgets(contact_data.email, sizeof(contact_data.email), stdin)) {
                    fprintf(stderr, "[Error] Error writing email\n");
                    break;
                }

                fprintf(stdout, "Enter contact's phone (max 32 symbols): ");
                if (!fgets(contact_data.phone, sizeof(contact_data.phone), stdin)) {
                    fprintf(stderr, "[Error] Error writing number\n");
                    break;
                }

                strip_newline(contact_data.name);
                strip_newline(contact_data.email);
                strip_newline(contact_data.phone);

                fprintf(stdout, "[Info] Successfully added your contact to the book\n");
                add_contact(book, &contact_data);
                break;


            case 3:
                if (!is_initialized) {
                    fprintf(stderr, "[Error] You need to create the book first\n");
                    break;
                }

                fprintf(stdout, "Searching contact by name. Enter name: ");
                    if (!fgets(buff, sizeof(buff), stdin)) {
                        fprintf(stderr, "[Error] Error writing name\n");
                        break;
                    }
                strip_newline(buff);

                struct contact* found_contact = find_contact(book, buff);

                if (found_contact == NULL) {
                    fprintf(stdout, "[Info] Could not find contact with name \"%s\" \n", buff);
                    break;
                }

                fprintf(stdout, "[Info] Found your contact at %p\n", found_contact);
                fprintf(stdout, "Name: %s\n", found_contact->name);
                fprintf(stdout, "Email: %s\n", found_contact->email);
                fprintf(stdout, "Phone number: %s\n", found_contact->phone);
                break;

                
            case 4:
                if (!is_initialized) {
                    fprintf(stderr, "[Error] You need to create the book first\n");
                    break;
                }
                
                print_contacts(book);
                break;

            case 5:
                if (!is_initialized) {
                    fprintf(stderr, "[Error] You need to create the book first\n");
                    break;
                }

                fprintf(stdout, "[Info] Deleting contacts book...\n");
                free_book(book);
                is_initialized = 0;

                break;

            default:
                fprintf(stdout, "[Warning] There is no such option %d\n", choice);
        }
    }
}
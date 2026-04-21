#include <stdio.h>
#include "contacts.h"

int main(void) {
    char buff[64];
    struct contact_book* book;
    int choice = 0, is_initalized = 0;;

    fprintf(stdout, "Hello, this program implements simple contacts book\n");
    fprintf(stdout, "I have used .h file to separate code, structs to store data, malloc and realloc to create dynamical heap memory with growth ability\n");
    fprintf(stdout, "\n====== Menu ======\n");
    fprintf(stdout, "1. Create contacts book\n");
    fprintf(stdout, "2. Add contacts to the contacts book\n");
    fprintf(stdout, "3. Search contact in the contacts book\n");
    fprintf(stdout, "4. Print all contacts\n");
    fprintf(stdout, "0. Exit program\n");

    
    while (1) {
        fprintf(stdout, "Your choice: ");
        if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%d", choice) != 1) {
            fprintf(stderr, "[Error] Invalid input\n");
        }

        switch (choice) {
            case 0:
                fprintf(stdout, "[Info] Exiting...\n");

                if (is_initalized) {
                    free_book(book);
                }

                return 0;
        
            case 1: 
                fprintf(stdout, "[Info] Creating contacts book...\n");
                book = create_book();

                if (book == NULL) {
                    fprintf(stderr, "[Error] Failed to create book\n");
                    break;
                }
                fprintf(stdout, "[Info] Book's memory address: %p\n", book);
                break;

            case 2:
                if (is_initalized) {
                    struct contact contact_data = {"", "", ""};

                    fprintf(stdout, "Adding a new contact to the book\n");

                    fprintf(stdout, "Enter contact's name: ");
                    if (!fgets(contact_data.name, sizeof(contact_data.name), stdin) != 1) {
                        fprintf(stderr, "[Error] Error writing name\n");
                        break;
                    }

                    fprintf(stdout, "Enter contact's email: ");
                    if (!fgets(contact_data.email, sizeof(contact_data.email), stdin) != 1) {
                        fprintf(stderr, "[Error] Error writing email\n");
                        break;
                    }

                    fprintf(stdout, "Enter contact's phone (max 32 symbols): ");
                    if (!fgets(contact_data.phone, sizeof(contact_data.phone), stdin) != 1) {
                        fprintf(stderr, "[Error] Error writing number\n");
                        break;
                    }

                    fprintf(stdout, "[Info] Successfully added your contact to the book\n");
                    add_contact(book, &contact_data);
                    break;
                }
                else {
                    fprintf(stderr, "[Error] Yout need to create the book first\n");
                    break;
                }

            case 3:
                if (is_initalized) {
                    print_contacts(book);
                    break;
                }
                
                fprintf(stderr, "[Error] Yout need to create the book first\n");
                break;
                
        }
    }
}
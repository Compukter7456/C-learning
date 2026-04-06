#include <stdio.h>

int outputNameScanf() {
    char name[20];

    printf("[OutputName] Hello user, enter your name: ");

    // Read and save data from stdin to list of chars name[20], stop on whitespace or '\n'.
    // Scanf does not save whitespace or '\n' to variable. They are leaved in stdin as junk.
    // User enters "Hello world". scanf writes {'H', 'e', 'l', 'l', 'o', '\0'} to name[20]. All written data is deleted from stdin
    // ' ', 'w', 'o', 'r', 'l', 'd', '\n' is staying in stdin as junk
    scanf("%s", name);

    // After scanf finishes reading stdin - getchar checks all remaining stdin. It reads each char, each read char is deleted from stdin.
    // When getchar sees '\n' - it deletes it and stopps. So this line cleans junk from stdin (including '\n').
    // But if stdin contains more '\n' than one - getchar will only clean data up to '\n' (incliding '\n').
    while (getchar() != '\n');

    // Output saved data via %s
    printf("Hi! %s\nYour name is printed with %%s operator.\n\n", name);

    printf("Hello ");
    // Iterate over all chars in list "char name[20]" and print each of them
    for (int i = 0; name[i] != '\0'; ++i) {
        printf("%c", name[i]);
    }
    printf("!\nYour name was printed using operator for\n");

    return 0;
}

int outputNameFgets() {
    char name[40];

    printf("\n\n[OutputName] Hello, enter your full name: ");

    // fgets is safer than scanf.
    // It saves all data from stdin, including whitespaces and '\n'.
    // It allows to set source of input data (stdin, stderr, etc).
    // It avoids buffer overflows by asking max input data.
    // If user enters 40 chars but fgets allows 20 chars - first 20 chars is saved. Rest is left in stdin.
    // fgets saves string, including '\n'. User enters "My Name//enter", name = {'M', 'y', ' ', 'N', 'a', 'm', 'e', '\n', '\0'}
    fgets(name, sizeof(name), stdin);

    // Iterate over each element in list. If element == '\n' - break cycle. 
    // Else if character == '\0' (iterator proceed the whole list) and no '\n' found
    // It means that fgets truncated user's input and stdin has junk data
    // If so - clean stdin
    for (int i = 0; i < sizeof(name); ++i) {
        if (name[i] == '\n') {
            break;
        }
        else if (name[i] == '\0') {
            while (getchar() != '\n');
        }
    }

    printf("Your full name is: %s\n", name);

    return 0;
}

int outputAllCharsWithJunk() {
    char name[20]; // All 20 chars is filled with junk.

    printf("\n\n[OutputJunk] Enter any string: ");
    fgets(name, sizeof(name), stdin);

    for (int i = 0; i < sizeof(name); ++i) {
        if (name[i] == '\n') {
            break;
        }
        else if (name[i] == '\0') {
            while (getchar() != '\n');
        }
    }


    // User's entered data overwrites junk in chars.
    // If user enters less than 20 chars - rest chars will still be filled with junk.

    for (int i = 0; i < sizeof(name); ++i) {
        printf("%d'th element of char list name has %d's ascii number. Value: %c\n", i, name[i], name[i]);
    }

    return 0;
}

int main() {
    outputNameScanf();
    outputAllCharsWithJunk();
    outputNameFgets();
}

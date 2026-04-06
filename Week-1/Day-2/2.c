#include <stdio.h>

void cleanStdin(char *list) {
    // Iterate over each element in list. If element == '\n' - break cycle. 
    // Else if character == '\0' (iterator proceed the whole list) and no '\n' found
    // It means that fgets truncated user's input and stdin has junk data
    // If so - clean stdin
    for (int i = 0; ; ++i) {
        if (list[i] == '\n') {
            break;
        }
        else if (list[i] == '\0') {
            int character;
            while ((character = getchar()) != '\n' && character != EOF);
            break;
        }
    }
}

void outputNameScanf() {
    char charsList[20];

    printf("[OutputName] Hello user, enter your name: ");

    // Read and save data from stdin to list of chars charsList[20], stop on whitespace or '\n'.
    // Scanf does not save whitespace or '\n' to variable. They are leaved in stdin as junk.
    // User enters "Hello world". scanf writes {'H', 'e', 'l', 'l', 'o', '\0'} to charsList[20]. All written data is deleted from stdin
    // ' ', 'w', 'o', 'r', 'l', 'd', '\n' is staying in stdin as junk
    scanf("%s", charsList);

    // After scanf finishes reading stdin - getchar checks all remaining stdin. It reads each char, each read char is deleted from stdin.
    // When getchar sees '\n' - it deletes it and stopps. So this line cleans junk from stdin (including '\n').
    // But if stdin contains more '\n' than one - getchar will only clean data up to '\n' (incliding '\n').
    while (getchar() != '\n');

    // Output saved data via %s
    printf("Hi! %s\nYour name is printed with %%s operator.\n\n", charsList);

    printf("Hello ");
    // Iterate over all chars in list "char charsList[20]" and print each of them
    for (int i = 0; charsList[i] != '\0'; ++i) {
        printf("%c", charsList[i]);
    }
    printf("!\nYour name was printed using operator for\n");
}

void outputNameFgets() {
    char charsList[40];

    printf("\n\n[OutputName] Hello, enter your full name: ");

    // fgets is safer than scanf.
    // It saves all data from stdin, including whitespaces and '\n'.
    // It allows to set source of input data (stdin, stderr, etc).
    // It avoids buffer overflows by asking max input data.
    // If user enters 40 chars but fgets allows 20 chars - first 20 chars is saved. Rest is left in stdin.
    // fgets saves string, including '\n'. User enters "My Name//enter", charsList = {'M', 'y', ' ', 'N', 'a', 'm', 'e', '\n', '\0'}
    // If char list is 40 bytes and user enters 39 bytes - fgets will write '\0' to 40'th byte, leaving '\n' in stdin  
    fgets(charsList, sizeof(charsList), stdin);
    cleanStdin(charsList);
    printf("Your full name is: %s\n", charsList);
}

void outputNamePutchar() {
    char charsList[40];

    printf("[OutputNamePutchar] Hello, enter your full name: ");
    fgets(charsList, sizeof(charsList), stdin);
    cleanStdin(charsList);

    // Print entered name via putchar
    // Putchar takes 1 byte int (unsigned char). [-1; 255]. Where -1 means EOF
    // Putchar functional is to print 1 char to stdout. It does not support anything else
    // Because of that putchar if faster than printf
    printf("Hello, ");
    for (int i = 0; charsList[i] != '\0' && charsList[i] != '\n'; ++i) {
        putchar(charsList[i]);
    }
    printf(", your name was printed using putchar!\n");
}

void outputAllCharsWithJunk() {
    char charsList[20]; // All 20 chars is filled with junk.

    printf("\n\n[OutputJunk] Enter any string: ");
    fgets(charsList, sizeof(charsList), stdin);
    cleanStdin(charsList);

    // User's entered data overwrites junk in chars.
    // If user enters less than 20 chars - rest chars will still be filled with junk.
    for (int i = 0; i < sizeof(charsList); ++i) {
        printf("%d'th element of char list name has %d's ascii number. Value: %c\n", i, charsList[i], charsList[i]);
    }
}

int main() {
    outputNameScanf();
    outputAllCharsWithJunk();
    outputNameFgets();
    outputNamePutchar();
}

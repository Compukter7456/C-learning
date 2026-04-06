#include <stdio.h>

int main() {

    // 1 byte, -128 to 127
    char regularChar = 'd';

    // 1 byte, 0 to 255 (for working with bytes)
    unsigned char unsignedChar = 255;

    // 2 bytes, -2**15 to 2**15-1
    short int shortInt = -23452;

    // 4 bytes, -2**31 to 2**31-1
    int regularInt = -234123;

    // 4 bytes, 0 to 2**32-1
    unsigned int unsignedInt = 3452535432;

    // 8 bytes, -2**63 to 2**63-1
    long long int longLongInt = -563764457645654;

    // 8 bytes, 0 to 2**64-1
    unsigned long long int unsignedLongLongInt = 3464536546457647ULL;

    // 4 bytes
    float regularFloat = 234.243465f;

    // 8 bytes
    double regularDouble = 54356346.234234;


    printf("Size of char on this system is: %zu. Char value: %c\n", sizeof(regularChar), regularChar);
    printf("Size of unsigned char on this system is: %zu. Unsigned char value: %d\n", sizeof(unsignedChar), unsignedChar);
    printf("Size of short int on this system is: %zu. Short int value: %hd\n", sizeof(shortInt), shortInt);
    printf("Size of integer on this system is: %zu. Integer value: %d\n", sizeof(regularInt), regularInt);
    printf("Size of unsigned int on this system is: %zu. Unsigned int value: %u\n", sizeof(unsignedInt), unsignedInt);
    printf("Size of long long int on this system is: %zu. Long long int value: %lld\n", sizeof(longLongInt), longLongInt);
    printf("Size of unsigned long long int on this system is: %zu. Unsigned long long int value: %llu\n", sizeof(unsignedLongLongInt), unsignedLongLongInt);
    printf("Size of float on this system is: %zu. Float value: %f\n", sizeof(regularFloat), regularFloat);
    printf("Size of double on this system is: %zu. Char value: %lf\n", sizeof(regularDouble), regularDouble);

    printf("-----------------------------------------------------------------------\n");

    printf("Float with 4 symbols after comma: %.4f\n", regularFloat);
    printf("Double with 5 symbols after comma: %.5lf\n", regularDouble);
}

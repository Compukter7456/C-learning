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
    float regularFloat = 234.24f;

    // 8 bytes
    double regularDouble = 54356346.234234;
}

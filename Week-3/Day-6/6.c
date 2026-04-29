#include <stdio.h>
#include <stdint.h> // For fixed size integers

int is_palindrome(int x) {
    if (x < 0) {
        return 0;
    }

    int half = 0;

    while (x > half) {
        half = half * 10 + x % 10;
        x /= 10;
    }

    return (x == half || x == half/10);
}

void print_byte_binary(unsigned char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
}

void fixed_size_integers(void) {
    // intX_t - types with fixed size. C guarantees that variables will have fixed size across different systems
    // uintX_t unsigned version of intX_t

    // Range formula for signed integers: [-2**(n-1); 2**(n-1) -1]
    int8_t signed_8  =  0x00; // 8 bits, [-128; 127]. 0x00 => 0000 0000
    int16_t signed_16 = 0x0000; // 16 bits [-2**15; 2**15 -1]
    int32_t signed_32 = 0x00000000; // 32 bits [-2**31; 2**31 -1]
    int64_t signed_64 = 0x0000000000000000; // 64 bits [-2**63; 2**63 -1]

    // Range formula for signed integers: [0; 2**n -1]
    uint8_t unsigned_8  =  0x00; // 8 bits, [0; 255]. 0x00 => 0000 0000
    uint16_t unsigned_16 = 0x0000; // 16 bits [-; 2**16 -1]
    uint32_t unsigned_32 = 0x00000000; // 32 bits [0; 2**32 -1]
    uint64_t unsigned_64 = 0x0000000000000000; // 64 bits [0; 2**64 -1]

    // uint8_t is comfortable in working with raw bytes
    // unsigned char is almost same as uint8_t, but is more portable and commonly used to work with bytes
}

void binary_operations(void) {
    const unsigned char array[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 
        0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
        0x0C, 0x0D, 0x0E, 0x0F, 
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
        0x16, 0x17, 0x18, 0x19
    };

    for (size_t i = 0; i < sizeof(array); i++) {
        print_byte_binary(array[i]);
        printf(" ");
    }
}

int main(void) {
    binary_operations();
}
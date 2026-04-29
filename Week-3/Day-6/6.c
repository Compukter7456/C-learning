#define _GNU_SOURCE // memfd_create()
#include <stdio.h> // printf() fprintf()
#include <stdlib.h> // calloc() free()
#include <unistd.h> // close(), read(), write(),
#include <sys/mman.h> // memfd_create()
#include <stdint.h> // For fixed size integers
#include <unistd.h>

#define BUFF_SIZE 128

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

ssize_t my_strlen(const char *str) {
    ssize_t length = 0;

    while (*str != '\0') {
        length++;
        str++;      
    }

    return length;
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
    printf("\n");

    // & --> AND
    unsigned char a = 0b10101010;
    unsigned char b = 0b01011011;
    unsigned char c = a & b; // 0b00001010;
    print_byte_binary(a);
    printf(" & ");
    print_byte_binary(b);
    printf(" = ");
    print_byte_binary(c);
    printf("\n");

    // | --> OR
    c = a | b; // 0b11111011;
    print_byte_binary(a);
    printf(" | ");
    print_byte_binary(b);
    printf(" = ");
    print_byte_binary(c);
    printf("\n");

    // ^ --> XOR
    c = a ^ b; // 11110001
    print_byte_binary(a);
    printf(" ^ ");
    print_byte_binary(b);
    printf(" = ");
    print_byte_binary(c);
    printf("\n");

    // ~ --> NOT, inversion
    c = ~a; // 01010101
    printf("~");
    print_byte_binary(a);
    printf(" = ");
    print_byte_binary(c);
    printf("\n");

    // << --> bitwise shift left
    c = a << 3; // shifts all bits to the left by 3 steps. x * x**n
    print_byte_binary(a);
    printf(" << 3");
    printf(" = ");
    print_byte_binary(c);
    printf("\n");

    // >> --> bitwise shift right
    c = a >> 3; // shifts all bits to the right by 3 steps. x / x**n
    print_byte_binary(a);
    printf(" >> 3");
    printf(" = ");
    print_byte_binary(c);
    printf("\n");

}

char *encrypt_decrypt(const char *array, size_t array_length, const unsigned char *xor_key, size_t xor_key_length) {
    if (array == NULL || xor_key == NULL || array_length == 0 || xor_key_length == 0) {
        return NULL;
    }

    char *buffer = calloc(array_length, sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < array_length; i++) {
        buffer[i] = array[i] ^ xor_key[i % xor_key_length];
    }

    return buffer;
}

int xor_encrypt_decrypt(void) {
    // XOR is a primitive symmetric cipher
    // First XOR round encrypts data, second round decrypts it
    const unsigned char xor_key[] = {0x43, 0xA2, 0x00, 0xBF, 0xD8};
    size_t key_len = sizeof(xor_key);

    int fd = memfd_create("decrypted_data", 0);
    if (fd == -1) {
        fprintf(stderr, "[Error] Could not create memfd file\n");
        return -1;
    }
    if (ftruncate(fd, BUFF_SIZE) == -1) {
        fprintf(stderr, "[Error] Ftruncate failed\n");
        close(fd);
        return -1;
    }

    char *buff = calloc(BUFF_SIZE, 1);
    if (buff == NULL) {
        fprintf(stderr, "[Error] Could not allocate %d bytes\n", BUFF_SIZE);
        close(fd);
        return -1;
    }
    printf("[Info] Allocated %d bytes in heap\n\n", BUFF_SIZE);

    printf("Hello, enter any data: ");
    if (!fgets(buff, BUFF_SIZE, stdin)) {
        fprintf(stderr, "[Error] Could not write data to buff\n");
        free(buff);
        close(fd);
        return -1;
    }
    ssize_t buff_len = my_strlen(buff);
    printf("[Success] Saved your string to buffer\n");

    printf("[Info] Encrypting your data with xor key...\n");
    char *tmp = encrypt_decrypt(buff, buff_len, xor_key, sizeof(xor_key));
    if (tmp == NULL) {
        fprintf(stderr, "[Error] Could not encrypt your data\n");
        free(buff);
        close(fd);
        return -1;
    }
    if (write(fd, tmp, buff_len) == -1) {
        fprintf(stderr, "[Error] Could not write data to memfd file\n");
        free(tmp);
        free(buff);
        close(fd);
        return -1;
    }
    free(tmp);
    lseek(fd, 0, SEEK_SET);
    printf("[Success] Encrypted your data with xor and written it to memfd\n");    

    printf("Encrypted data in memfd(hex): ");
    while (read(fd, buff, buff_len) > 0) {
        for (ssize_t i = 0; i < buff_len; i++) {
            printf("%02X ", (unsigned char)buff[i]);
        }
    }
    printf("\n");
    lseek(fd, 0, SEEK_SET);
    read(fd, buff, buff_len);

    printf("[Info] Reading memfd and decrypting data...\n");
    tmp = encrypt_decrypt(buff, buff_len, xor_key, sizeof(xor_key));
    printf("Decrypted data: %s", tmp);

    sleep(30); // analyze /proc/PID/fd/3 - you will see xor encrypted data
    free(tmp);
    free(buff);
    close(fd);

    return 0;
}

int main(void) {
    binary_operations();
    xor_encrypt_decrypt();
}
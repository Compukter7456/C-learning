#include <stdio.h>

void pointersBehaviour(void) {
    // Pointer is a variable that stores memory address of another variable
    // It allows to access and manipulate variable's value by it's memory address
    // We use * operator to declare a pointer and to get the value stored at the memory address
    
    // Create named memory area for an integer and save some number there
    int number = 456434;
    printf("Number's value: %d\n", number);
    printf("Size of the created variable: %zu bytes\n", sizeof(number));

    // Creates 8 bytes (4 bytes on x32 systems) variable and set number variable's memory address there
    // We can do both int* ptr and int *ptr, it doesn't matter, but int* ptr is easier to read
    int* number_pointer = &number;
    // This creates number_pointer variable. number_pointer returns memory address, *number_pointer returns data, stored at that memory address
    // & operator returns memory address of the variable. So &number returns memory address of number
    printf("Value stored at %p memory address: %d\n", number_pointer, *number_pointer);
    printf("Memory address of number's variable: %p\n", number_pointer); // %p is used to print memory addresses
    printf("Memory address of number_pointer's pointer: %p\n", &number_pointer); // &number_pointer returns memory address of number_pointer

    int** number_pointer_pointer = &number_pointer; 
    // This is pointer that points to a pointer, it stores memory address of number_pointer
    // We can do as much levels of pointers as we want 
    printf("Value stored at %p memory address: %p\n", number_pointer_pointer, *number_pointer_pointer);
    printf("Memory address of number_pointer_pointer's pointer: %p\n", &number_pointer_pointer);

}

 
int main(void) {
    pointersBehaviour();

}
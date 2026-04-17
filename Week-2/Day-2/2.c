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

 void datasets(void) {
    // C does not have built in string type. It is just an array of chars, that ends with a null terminator '\0'
    char hello_string[] = "Hello GitHub";
    // This creates fixed 13 bytes size array that looks like: {'H', 'e', 'l', 'l', 'o', ' ', 'G', 'i', 't', 'H', 'u', 'b', '\0'}
    // sizeof(string) will return 13 bytes
    printf("Size of '%s' string is %zu bytes\n", hello_string, sizeof(hello_string));

    // We can also set array's size
    char fixed_hello_string[20] = "Hello GitHub";
    // This creates fixed 13 bytes size array that looks like: {'H', 'e', 'l', 'l', 'o', ' ', 'G', 'i', 't', 'H', 'u', 'b', '\0', '0', '0', '0', '0', '0', '0', '0'}
    // 13 bytes contains our payload, the rest is zero initialized
    printf("Size of fixed '%s' string is %zu bytes\n", fixed_hello_string, sizeof(fixed_hello_string));

    // String is a contiguous sequence of chars, that ends with a null terminator '\0'

    // Array is similar to string. It just doesn't contain '\0' at the end
    // Array is a contiguous sequence of elements of the same type. It can be of any type
    // In string we can understand where it ends, because it has '\0' in the end. 
    // In array we don't have such marker, so we need to store size of the array in separate variable
    int numbers_array[] = {1, 2, 3, 4, 5};
    // This creates 20 bytes size array that looks like: {1, 2, 3, 4, 5}
    // sizeof(numbers_array) will return 20 bytes, because it contains 5 integers, and each integer is 4 bytes
    printf("Size of numbers array is %zu bytes\n", sizeof(numbers_array));
    // We can calculate number of elements in the array by dividing total size of the array by size of one element
    printf("Number of elements in numbers array is %zu\n", sizeof(numbers_array) / sizeof(numbers_array[0])); 
    // We store size of anything in size_t variable. It is an unsigned integer type that can store size of any object in bytes

    // We can create empty array with fixed size for future data storage
    // Each array's element will be initialized with garbage value, because we don't set any value for it
    int array[10]; 

    // To work with array's elements, we need to use loops
    for (size_t i = 0; i < sizeof(numbers_array) / sizeof(numbers_array[0]); i++) {
        printf("%zu's element of array with numbers: %d\n", i, numbers_array[i]);
    }

    // We can easily cause undefined behaviour by accessing array's element that is outside of array, it can be any data
    // This causes CWE like buffer overflow of out of bounds, etc
    char data[5] = "str";
    printf("7'th element of 6 chars array: %c\n", data[6]); // Out of bounds read, ub
    // data[6] = 'a';  it is undefined behavior, out of bounds write. Program will overwrite some data outside of the array
 }

 void pointers_with_datasets(void) {
    // Array is a contiguous sequence of elements of the same type
    // Each element is stored strictly one after another in memory. So we can calculate memory address of any element by adding offset to the memory address of the first element
    char array[] = "Hello GitHub";

    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%zu's array element's memory address: %p\n", i, &array[i]);
    }
    // We will see that each element is stored one after another in memory
    // We can use pointers to easily work with arrays

    char* array_pointer = &array[0]; // Create a pointer which stores memory address of the first element of the array
    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%zu's array element's value: %c\n", i, *(array_pointer + i));
    }
 
}

void array_of_strings(void) {
    // Array of strings is a 2d array - array of pointers which stores pointers to the first element of each string
    char* array_of_strings[] = {"Hello", "GitHub", "from", "C"};
    // This creates 32 bytes array of 4 pointers, each pointer stores memory address of the first element
    // array_of_strings stores memory address of the first pointer in created array
    char** array_pointer = array_of_strings;

    for (size_t i = 0; i < sizeof(array_of_strings) / sizeof(array_of_strings[0]); i++) {
        char* str = *(array_pointer + i);

        while (*str != '\0') {
            printf("%c", *str);
            str++;
        }
        printf("\n");
    }

    for (size_t i = 0; i < sizeof(array_of_strings) / sizeof(array_of_strings[0]); i++) {
        char* str = *(array_pointer + i);
        char* str_start = str;

        printf("Memory address of the %zu' array's pointer is: %p\n", i, str);
        while (*str != '\0') {
            printf("Memory address of the %zu's character is: %p, value: %c\n", str - str_start, str, *str);
            str++;
        }
        printf("\n");
    }
}

int main(void) {
    pointersBehaviour();
    datasets();
    pointers_with_datasets();
    array_of_strings();
}
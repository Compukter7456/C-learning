#include <stdio.h>

int main() {
    unsigned long long int aaa = 256ULL*256*256*256;
    printf("256**4 = %llu\n", aaa);
    printf("Int number range: %d %d\n", (aaa/2)-1, -(aaa/2)+1);
}

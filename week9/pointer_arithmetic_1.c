#include <stdio.h>

int main() {
    int vector[5] = {11, 13, 17, 23, 21};

    int* address = vector;

    printf("\nAddress[0] = %d\n", *address);
    printf("\nAddress[1] = %d\n", *(address + 1));
    printf("\nAddress[2] = %d\n", *(address + 2));

    return 0;
}
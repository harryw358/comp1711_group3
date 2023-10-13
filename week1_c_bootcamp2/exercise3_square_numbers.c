#include <stdio.h>

int main() {

    printf("The squares of the first 10 natural numbers are:\n");

    for (int i = 1; i <= 10; i++) {
        int square = i * i;
        printf("%d\n", square);
    }

    return 0;

}
#include <stdio.h>

int main () {

    printf("The first 10 odd numbers are:\n");

    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 1) {
            printf("%d\n", i);
        }
    }

    return 0;

}
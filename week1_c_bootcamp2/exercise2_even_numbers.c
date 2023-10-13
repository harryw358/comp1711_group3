#include <stdio.h>

int main() {

    int i = 20;

    printf("The even numbers from 20 to 0 are:\n");

    while (i > 0) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
        i--;
    }

    return 0;

}
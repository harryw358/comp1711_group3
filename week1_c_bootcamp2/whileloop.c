#include <stdio.h>

int main() {

    int a = 0;

    while (a < 5) {
        printf("a is equal to %d\n", a);
        a++;
    }

    printf("After the while loop is finished a is equal to %d", a);
    return 0;
}
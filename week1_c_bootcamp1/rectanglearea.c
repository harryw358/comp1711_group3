#include <stdio.h>

int main() {
    int length, width;

    printf("Enter the length: ");
    scanf("%d", &length);
    printf("Enter the width: ");
    scanf("%d", &width);

    int area = length * width;

    printf("The area of the rectangle is %d", area);
    return 0;
}
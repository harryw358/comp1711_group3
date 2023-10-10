#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    int sum = num1 + num2;

    printf("The sum of the 2 integers are %d", sum);
    return 0;
}
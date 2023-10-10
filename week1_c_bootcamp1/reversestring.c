#include <stdio.h>
#include <string.h>

int main() {
    char inputString[15];

    printf("Enter a string: ");
    scanf("%s", inputString);

    int length = strlen(inputString);
    for (int i = 0; i < length / 2; i++) {
        char temp = inputString[i];
        inputString[i] = inputString[length - i - 1];
        inputString[length - i - 1] = temp;
    }

    printf("The reversed string is %s", inputString);
    return 0;
}
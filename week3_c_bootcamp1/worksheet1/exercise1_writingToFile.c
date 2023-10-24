#include <stdio.h>

int main() {
    char filename[] = "squares.dat";
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {
        fprintf(file, "%d\n", i * i);
    }    

    fclose(file);
    return 0;
}
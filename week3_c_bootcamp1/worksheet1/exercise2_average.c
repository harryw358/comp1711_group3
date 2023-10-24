#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    float sum = 0;
    float line_count = 0;

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        line_count++;
        sum += atof(line_buffer);
    }

    float average = sum / line_count;
    printf("The average is %f", average);

    fclose(file);
    return 0;
}
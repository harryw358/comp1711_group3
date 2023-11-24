#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define ROWS 4
//#define COLS 5

void sum_of_marks(int student_marks[][5], int rows, int cols) {
    int currentMarkTotal = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            currentMarkTotal += student_marks[i][j];
        }
        printf("Student %d mark: %d\n", i + 1, currentMarkTotal);
        currentMarkTotal = 0;
    }
}

int main() { 
    int ROWS = 4, COLS = 5;
    srand(time(NULL));

    int student_marks[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; ++j) {
            student_marks[ROWS][COLS] = rand() % 26;
            printf("%d ", student_marks[ROWS][COLS]);
        }
        printf("\n");
    }

    sum_of_marks(student_marks, ROWS, COLS);

    return 0;
}
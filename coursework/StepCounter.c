#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

FITNESS_DATA fitnessData[600];

char getMenuChoice() {
    char choice;

    printf("A. Specify the filename to be imported\n");
    printf("B. Display the total number of records in the file\n");
    printf("C. Find the data and time of the timeslot with the fewest steps\n");
    printf("D. Find the date and time of timeslot with the largest number of steps\n");
    printf("E. Find the mean step count of all the records in the file\n");
    printf("F. Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n\n");
    printf("Make a choice: ");
    scanf("%c", &choice);

    return choice;
}

int main() {
    // stores the filename of the csv file to be used
    // opens the file in read mode, with error handling available
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open CSV file.");
        return 1;
    }

    // declares a new array of type FITNESS_DATA
    FITNESS_DATA data[300];

    // declares a bufferSize variable which is the max length of a csv record
    // declares a lineCount variable which is responsible for keeping track of the number of csv records
    int bufferSize = 100, lineCount = 0;
    char lineBuffer[bufferSize];
    while (fgets(lineBuffer, bufferSize, file) != NULL) {
        tokeniseRecord(lineBuffer, ",", date, time, steps);

        FITNESS_DATA newFitnessData;
        strcpy(newFitnessData.date, date);
        strcpy(newFitnessData.time, time);
        newFitnessData.steps = atoi(steps);

        data[lineCount] = newFitnessData;

        lineCount++;  
    }

    // closes the csv file
    fclose(file);

    char choice = getMenuChoice();

    switch (choice) {
        case 'A':
            printf("Input filename: ");
            scanf("%s", &filename);

            // opens the file in read mode with error handling
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                perror("Could not open file.");
                break;
            }
        break;
        case 'B':

        break;
        case 'C':

        break;
        case 'D':

        break;
        case 'E':

        break;
        case 'F':

        break;
        case 'Q':

        break;
    }

    return 0;
}
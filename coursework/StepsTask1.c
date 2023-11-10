#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Define any additional variables here

char date[11];
char time[6];
char steps[4];

// Complete the main function
int main() {

    // stores the filename of the csv file to be used
    char filename[] = "FitnessData_2023.csv";
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

        // Originally tried:
        //
        // data[lineCount].date = date;
        // data[lineCount].time = time;
        // data[lineCount].steps = atoi(steps);
        // 
        // Error: assignment to expression with array type
        //
        // To find a solution I typed the error into to Google and clicked on this link: 
        // https://stackoverflow.com/questions/37225244/error-assignment-to-expression-with-array-type-error-when-i-assign-a-struct-f
        // After reading replies to the original question, I got the idea to use the strcpy() function, and researched this using the link:
        // https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm
        // and understood that in C, arrays are not assignable, so I used the strcpy() function to copy the contents
        // of the arrays into the newFitnessData array fields

        lineCount++;  
    }

    // closes the csv file
    fclose(file);

    // prints the number of records in the csv file
    printf("Number of records in file: %d\n", lineCount);

    // prints the first 3 records from the data array
    for (int i = 0; i < 3; i++) {
        printf("%s/", data[i].date);
        printf("%s/", data[i].time);
        printf("%d\n", data[i].steps);
    }

    return 0;
}
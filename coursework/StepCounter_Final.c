#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

char date[11];
char time[6];
char steps[4];

// declares a new array of type FitnessData
FITNESS_DATA data[300];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

char getMenuChoice() {

    printf("A. Specify the filename to be imported\n");
    printf("B. Display the total number of records in the file\n");
    printf("C. Find the data and time of the timeslot with the fewest steps\n");
    printf("D. Find the date and time of timeslot with the largest number of steps\n");
    printf("E. Find the mean step count of all the records in the file\n");
    printf("F. Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q. Quit\n\n");
    
    printf("Make a choice: ");
    char choice = 'X';
    scanf("%c", &choice);

    return choice;
}

// Complete the main function
int main() {
   // declares a recordCount variable for keeping count of CSV records
   int recordCount = 0;

   char choice = getMenuChoice();

   while (choice != 'Q' && choice != 'q') {
    switch (choice) {
            case 'A':
            case 'a': {

                int bufferSize = 100;
                char line[bufferSize];
                char filename[bufferSize];

                // retrieves the filename from the user
                printf("Input filename: ");

                fgets(line, bufferSize, stdin);
                sscanf(line, " %s ", filename);        

                // opens the file in read mode, with error handling available
                FILE *file = fopen(filename, "r");
                if (file == NULL) {
                    perror("Could not open CSV file");
                    break;
                }

                // declares a bufferSize variable which is the max length of a CSV record
                char lineBuffer[bufferSize];
                while (fgets(lineBuffer, bufferSize, file) != NULL) {
                    tokeniseRecord(lineBuffer, ",", date, time, steps);

                    FITNESS_DATA newFitnessData;
                    strcpy(newFitnessData.date, date);
                    strcpy(newFitnessData.time, time);
                    newFitnessData.steps = atoi(steps);

                    data[recordCount] = newFitnessData;
                    recordCount++;
                }

                // closes the CSV file
                fclose(file);

                for (int i = 0; i < recordCount; i++) {
                    printf("%s\n", data[i].date);
                    printf("%s\n", data[i].time);
                    printf("%d\n\n", data[i].steps);
                }

                choice = getMenuChoice();
            }
            break;
            case 'B':
            case 'b': {
                printf("Total records: %d\n\n", recordCount);

                choice = getMenuChoice();
            }
            break;
            case 'C':
            case 'c': {
                FITNESS_DATA fewestSteps = data[0];
                for (int i = 0; i < recordCount; i++) {
                    if (data[i].steps < fewestSteps.steps) {
                        fewestSteps = data[i];
                    }
                }

                printf("Fewest steps: %s %s\n", fewestSteps.date, fewestSteps.time); 

                choice = getMenuChoice();
            }
            break;
            case 'D':
            case 'd': {
                FITNESS_DATA largestSteps = data[0];
                for (int i = 0; i < recordCount; i++) {
                    if (data[i].steps > largestSteps.steps) {
                        largestSteps = data[i];
                    }
                }

                printf("Largest steps: %s %s", largestSteps.date, largestSteps.time); 

                choice = getMenuChoice();
            }
            break;
            case 'E':
            case 'e': {
                int totalStepCount = 0;
                for (int i = 0; i < recordCount; i++) {
                    totalStepCount += data[i].steps;
                }

                float meanStepCount = totalStepCount / recordCount;
                printf("Mean step count:  %f", meanStepCount);

                choice = getMenuChoice();
            }
            break;
        }
   }

   return 0;
}
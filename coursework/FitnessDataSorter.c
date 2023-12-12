#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    FitnessData data[300];

    char date[11];
    char time[6];
    char steps[4];

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
        return 1;
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
    
}
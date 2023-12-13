#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    int recordCount = 0;

    char date[11];
    char time[6];
    int steps;

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
        tokeniseRecord(lineBuffer, ',', date, time, &steps);

        FitnessData newFitnessData;
        strcpy(newFitnessData.date, date);
        strcpy(newFitnessData.time, time);
        newFitnessData.steps = steps;

        data[recordCount] = newFitnessData;
        recordCount++;
    }

    // closes the CSV file
    fclose(file);

    // sorts the array
    // I based this on an idea from https://www.geeksforgeeks.org/bubble-sort/
    bool swapped = false;
    for (int i = 0; i < recordCount; i++) {
        swapped = false;
        for (int j = 1; j < recordCount - i; j++) {
            if (data[j].steps > data[j - 1].steps) {
                FitnessData temp = data[j];
                data[j - 1] = data[j];
                data[i] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    // checks that the array is sorted
    for (int i = 0; i < recordCount; i++) {
        printf("%s\n", data[i].date);
        printf("%s\n", data[i].time);
        printf("%d\n\n", data[i].steps);
    }

    return 0;
}
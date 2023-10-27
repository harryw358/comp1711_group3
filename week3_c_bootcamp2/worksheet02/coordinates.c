#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

int main() {
    Point coordinates [10] {
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
        {rand(), rand()},
    }
    for (i = 0; i < 10; i++) {
        printf("-------------\n");
        printf("X: %d\n", coordinates[i].x);
        printf("Y: %d\n", coordinates[i].y);
    }
    printf("-------------\n");
    return 0;
}
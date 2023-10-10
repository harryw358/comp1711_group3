#include <stdio.h>

int main() {
    float radius;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    float area = 3.14 * radius * radius;

    printf("The area of the circle is %f", area);
    return 0;
}
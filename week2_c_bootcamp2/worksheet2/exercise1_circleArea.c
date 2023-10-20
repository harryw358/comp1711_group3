#include <stdio.h>

float circleArea(float radius) {
    return 3.14 * radius * radius;
}

int main() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    
    float area = circleArea(radius);
    printf("The area of the circle with radius %f is %f", radius, area);

    return 0;
}
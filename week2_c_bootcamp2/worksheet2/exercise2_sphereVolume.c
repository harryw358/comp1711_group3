#include <stdio.h>

float sphereVolume(float radius) {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

int main() {
    float radius;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);

    float volume = sphereVolume(radius);
    printf("The volume of the sphere of radius %f is %f", radius, volume);

    return 0;
}
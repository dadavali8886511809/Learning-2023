// 2. Write a program to enter to Cartesian coordinate points and display the distance between them.


#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double calculateDistance(const struct Point *p1, const struct Point *p2) {
    double distance = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    return distance;
}

int main() {
    struct Point point1, point2;

    printf("Enter the coordinates of Point 1 (x y): ");
    scanf("%lf %lf", &(point1.x), &(point1.y));

    printf("Enter the coordinates of Point 2 (x y): ");
    scanf("%lf %lf", &(point2.x), &(point2.y));

    double distance = calculateDistance(&point1, &point2);
    
    printf("The distance between the two points is: %.2lf\n", distance);

    return 0;
}
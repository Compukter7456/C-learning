#include <stdio.h>

struct point {
    int x;
    int y;
};

// Newton's method of square root calculation
float calculate_sqrt(float number) {
    if (number <= 0) {
        return 0;
    }

    float result = number/3;

    for (int i = 0; i < 10; i++) {
        result = (result + number / result) / 2;
    }

    return result;
}

// Calculate dinstance between 2 points in 2d dimension
// Draw a triangle where p1 and p2 is some angles
// Distance is c. p1 and p2 is a and b. a**2 + b**2 = c**2
float calculate_distance(struct point p1, struct point p2) {
    float distance = 0;
    int a = 0, b = 0;

    a = p1.x - p2.x;
    b = p1.y - p2.y;

    distance = a*a + b*b;
    return calculate_sqrt(distance);
}

int main(void) {
    struct point p1 = {0, 0};
    struct point p2 = {0, 0};
    char buff[128];

    printf("Hello, enter x and y coordinates of the first point.\n");
    printf("x: ");
    if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%d", &p1.x) != 1) {
        printf("Invalid input\n");
        return -1;
    }
    printf("y: ");
    if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%d", &p1.y) != 1) {
        printf("Invalid input\n");
        return -1;
    }

    printf("Enter x and y coordinates of the second point.\n");
    printf("x: ");
    if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%d", &p2.x) != 1) {
        printf("Invalid input\n");
        return -1;
    }
    printf("y: ");
    if (!fgets(buff, sizeof(buff), stdin) || sscanf(buff, "%d", &p2.y) != 1) {
        printf("Invalid input\n");
        return -1;
    }

    printf("Distance between a(%d, %d) and b(%d, %d) is %f\n", p1.x, p1.y, p2.x, p2.y, calculate_distance(p1, p2));

}
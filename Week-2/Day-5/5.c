#include <stdio.h>

struct point {
    int x;
    int y;
};

struct student {
    char name[64];
    unsigned short int age;
    float grade;
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

int calculate_distance_between_points(void) {
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

    return 0;
}

struct student* find_best_student(struct student *students, size_t ammount) {
    if (ammount <= 0 || students == NULL) {
        return NULL;
    }

    float best_grade = 0;
    size_t i = 0;

    while (i < ammount) {
        struct student test = *(students + i);

        if (test.grade > best_grade) {
            best_grade = test.grade;
        }
        i++;
    }

    return students + i;
}

void print_students(struct student *students, size_t ammount) {
    if (ammount <= 0 || students == NULL) {
        return;
    }

    for (size_t i = 0; i < ammount; i++) {
        struct student student = *(students + i);
        printf("\n%zu'th student\n", i);
        printf("Name: %s, age: %hu, average grade: %f\n", student.name, student.age, student.grade);
    }
}

int main(void) {
    struct student group[5] = {
        {"Alice", 20, 95.5},
        {"Bob",   21, 87.0},
        {"Carol", 19, 91.3},
        {"Dave",  22, 78.5},
        {"Eve",   20, 88.0}
    };

    print_students(group, sizeof(group) / sizeof(group[0]));
    struct student* best_student = find_best_student(group, 5);

    printf("Student with the best grade is: %s", best_student->name);
    return 0;
}
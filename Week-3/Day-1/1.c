#include <stdio.h>
#include <unistd.h> // sleep()

#define WORKING_TEXT_FILE "test.txt"
#define WORKING_BINARY_FILE "test.bin"
#define BUFFER_SIZE 32

typedef struct student {
    size_t id;
    char name[12];
    float grade;
} Student;


void read_file(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "[Error] File is NULL\n");
        return;
    }

    for (int i = fgetc(file); i != EOF; i = fgetc(file)) {
        putchar(i);
    }
}

int create_file(void) {
    FILE *file = fopen(WORKING_TEXT_FILE, "w");

    if (file == NULL) {
        fprintf(stderr, "[Error] Could not open file\n");
        return -1;
    }

    fprintf(stdout, "[Info] Writing data to %s. FILE's address: %p\n", WORKING_TEXT_FILE, file);
    fprintf(file, 
        "NAME    AGE   CITY\n"
        "abc     12    Chicago\n"
        "def     25    Colego\n"
        "ghi     65    Cleveland\n"
    );

    fclose(file);
    return 0;
}

int fscanf_demo(void) {
    FILE *file = fopen(WORKING_TEXT_FILE, "r");

    if (file == NULL) {
        fprintf(stderr, "[Error] There is no such file %s\n", WORKING_TEXT_FILE);
        return -1;
    }

    char name[BUFFER_SIZE];
    char age[BUFFER_SIZE];
    char city[BUFFER_SIZE];

    fprintf(stdout, "[Info] Reading file %s...\n", WORKING_TEXT_FILE);

    while (fscanf(file, "%31s %31s %31s", name, age, city) == 3) {
        printf("%s %s %s\n", name, age, city);
    }

    fclose(file);
    return 0;
}

int fgets_demo(void) {
    FILE *file = fopen(WORKING_TEXT_FILE, "r");

    if (file == NULL) {
        fprintf(stderr, "[Error] There is no such file %s\n", WORKING_TEXT_FILE);
        return -1;
    }

    char buff[BUFFER_SIZE];

    for (size_t i = 0; fgets(buff, sizeof(buff), file) != NULL; i++) {
        fprintf(stdout, "%zu's line in file: %s", i+1, buff);
        sleep(1);
    }

    fclose(file);
    return 0;
}


int fputs_demo(void) {
    FILE *file = fopen(WORKING_TEXT_FILE, "r+");

    if (file == NULL) {
        fprintf(stderr, "[Error] Could not open %s\n", WORKING_TEXT_FILE);
        return -1;
    }

    const char* string = "Some string. Will be pasted with fputs()\n";
    
    // This will write string to the beginning of the working, overwriting the first two lines (because it contains \n)
    fprintf(stdout, "[Info] Writing \"%s\" to %s\n", string, WORKING_TEXT_FILE);
    if (fputs(string, file) == EOF) {
        fprintf(stderr, "[Error] Could not write string into file\n");
        fclose(file);
        return -1;
    }

    rewind(file); // Reloads file position indicator (places on the beginning) 
    read_file(file);

    fclose(file);
    return 0;
}


int fwrite_demo(void) {
    FILE *file = fopen(WORKING_BINARY_FILE, "wb");

    if (file == NULL) {
        fprintf(stderr, "[Error] Could not open %s\n", WORKING_BINARY_FILE);
        return -1;
    }

    Student s1 = {0, "Alex", 69.25};
    Student s2 = {1, "Layla", 83.75};
    Student s3 = {2, "Mathew", 79.5};

    Student students_arr[] = {s1, s2, s3};

    // Write 3 elements from student_arr with sizeof(struct student) to file
    size_t written = fwrite(students_arr, sizeof(Student), 3, file);

    fprintf(stdout, "[Info] Written %zu elements to %s\n", written, WORKING_BINARY_FILE);

    fclose(file);
    return 0;
}

/*
xxd -c 24 test.bin 
00000000: 0000 0000 0000 0000 416c 6578 0000 0000 0000 0000 0080 8a42  ........Alex...........B
00000018: 0100 0000 0000 0000 4c61 796c 6100 0000 0000 0000 0080 a742  ........Layla..........B
00000030: 0200 0000 0000 0000 4d61 7468 6577 0000 0000 0000 0000 9f42  ........Mathew.........B
*/

int fread_demo(void) {
    FILE *file = fopen(WORKING_BINARY_FILE, "rb");

    if (!file) {
        fprintf(stderr, "[Error] Could not open %s\n", WORKING_BINARY_FILE);
        return -1;
    }

    Student student;

    while (fread(&student, sizeof(student), 1, file) == 1) {
        fprintf(stdout, "Id: %zu, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }

    fclose(file);
    return 0;
}

int main(void) {
    /*create_file();
    fscanf_demo();
    fgets_demo();
    fputs_demo();*/
    fwrite_demo();
    fread_demo();
    return 0;
}
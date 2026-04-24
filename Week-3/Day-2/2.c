#include <stdio.h>
#include <unistd.h>

#define WORKING_TEXT_FILE "file.txt"

long int calculate_file_bytes(FILE *file) {
    if (file == NULL) {
        return -1;
    }

    long int bytes = 0;

    fseek(file, 0, SEEK_END);
    bytes = ftell(file);
    rewind(file);

    return bytes;
}

int file_position_operating(void) {
    FILE *file = fopen(WORKING_TEXT_FILE, "r+");

    if (file == NULL) {
        fprintf(stderr, "[Error] Could not open %s\n", WORKING_TEXT_FILE);
        return -1;
    }

    fprintf(stdout, "[Info] Working with %s file\n", WORKING_TEXT_FILE);
    fprintf(stdout, "Position indicator: %ld\n", ftell(file));

    fprintf(stdout, "[Info] Writing data to %s. FILE's address: %p\n", WORKING_TEXT_FILE, file);
    fprintf(file, 
        "Hello from C\n"
        "This data is written using fprintf()\n"
        "C is beautiful\n"
        "Linux >> Windows\n"
    );

    fprintf(stdout, "Current position indicator: %ld\n", ftell(file));
    rewind(file);
    fprintf(stdout, "[Info] Reloaded pointer. Current position indicator: %ld\n", ftell(file));

    // int fseek(FILE *file, long offset, int whence);
    // fseek() moves the file position indicator for the given stream.
    // Parameters:
    // FILE *file --> the file stream to operate on
    // long offser --> number of bytes to move (can be positive or negative)
    // int whence --> reference point for offset
    // Offsets:
    // SEEK_SET - beginning of the file
    // SEEK_CUR - current position
    // SEEK_END - end of the file
    fseek(file, 7, SEEK_SET);
    fprintf(stdout, "Moved position indicator by 7 bytes from the beginning. Current position: %ld\n", ftell(file));

    fseek(file, 23, SEEK_CUR);
    fprintf(stdout, "Moved position indicator by 23 bytes from the current position. Current position: %ld\n", ftell(file));

    fseek(file, -65, SEEK_END);
    fprintf(stdout, "Moved position indicator by -65 bytes from the end. Current position: %ld\n", ftell(file));

    fprintf(stdout, "Created file's size: %ld bytes\n", calculate_file_bytes(file));

    fclose(file);
    return 0;
}

int main(void) {
    file_position_operating();

    return 0;
}
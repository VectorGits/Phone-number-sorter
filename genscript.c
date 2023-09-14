#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_string() {
    char* str = (char*)malloc(12 * sizeof(char)); // 10 numbers + 1 "+" sign + 1 null terminator
    if (str == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    str[0] = '+';
    for (int i = 1; i <= 10; i++) {
        str[i] = '0' + (rand() % 10); // Generate random digit ('0' to '9')
    }
    str[11] = '\0'; // Null-terminate the string

    return str;
}

void create_strings_file(const char* filename, int num_strings) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < num_strings; i++) {
        char* string = generate_string();
        fputs(string, file);
        // fputc('\n', file);
        free(string); // Free the dynamically allocated memory
    }

    fclose(file);
}

// Example usage:
int main() {
    const char* output_file = "strings.txt";
    int num_strings = 100;

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    create_strings_file(output_file, num_strings);
    return 0;
}

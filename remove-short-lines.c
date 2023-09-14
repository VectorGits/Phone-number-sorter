#include <stdio.h>
#include <string.h>

void delete_short_lines(const char* input_file, const char* output_file) {
    FILE* input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE* output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        fclose(input_fp);
        return;
    }

    char line[1000]; // Adjust this buffer size as needed

    while (fgets(line, sizeof(line), input_fp) != NULL) {
        // Check if the line has at least 2 characters
        if (strlen(line) >= 2) {
            fputs(line, output_fp); // Write the line to the output file
        }
    }

    fclose(input_fp);
    fclose(output_fp);
}

// Example usage:
int main() {
    const char* input_file_path = "output4.txt";
    const char* output_file_path = "output5.txt";
    delete_short_lines(input_file_path, output_file_path);
    return 0;
}

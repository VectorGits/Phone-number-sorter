#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_plus_at_start_of_each_line(const char* input_file, const char* output_file) {
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

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_fp) != NULL) {
        if (buffer[0] != '+') {
            fputs("+", output_fp);
        }
        fputs(buffer, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
}

// Example usage:
int main() {
    const char* input_file_path = "output1.txt";
    const char* output_file_path = "output2.txt";
    add_plus_at_start_of_each_line(input_file_path, output_file_path);
    return 0;
}

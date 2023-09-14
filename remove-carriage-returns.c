#include <stdio.h>

void remove_carriage_returns(const char* input_file, const char* output_file) {
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

    int ch;

    while ((ch = fgetc(input_fp)) != EOF) {
        // Check if the character is not a carriage return (CR)
        if (ch != '\r') {
            fputc(ch, output_fp); // Write the character to the output file
        }
    }

    fclose(input_fp);
    fclose(output_fp);
}

// Example usage:
int main() {
    const char* input_file_path = "IT TRIBE MEETUP GROUP.txt";
    const char* output_file_path = "IT TRIBE MEETUP GROUP1.txt";
    remove_carriage_returns(input_file_path, output_file_path);
    return 0;
}

#include <stdio.h>

void add_carriage_return_before_plus(const char* input_file, const char* output_file) {
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

    int prevChar = EOF;
    int ch;

    while ((ch = fgetc(input_fp)) != EOF) {
        if (ch == '+' && prevChar != '\n') {
            fputc('\n', output_fp); // Add a carriage return before '+'
        }
        fputc(ch, output_fp); // Write the character to the output file
        prevChar = ch;
    }

    fclose(input_fp);
    fclose(output_fp);
}

// Example usage:
int main() {
    const char* input_file_path = "./files/LADDER BACK PRODUCTS OWNER.txt";
    const char* output_file_path = "./files/LADDER BACK PRODUCTS OWNER(1).txt";
    add_carriage_return_before_plus(input_file_path, output_file_path);
    return 0;
}

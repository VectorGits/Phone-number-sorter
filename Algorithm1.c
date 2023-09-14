#include <stdio.h>
#include "functions.h"

int main() {
    add_carriage_return_before_plus(input_file_path, output_file_path);
    remove_commas(input_file_path2, output_file_path2);
    remove_spaces_hyphens_parentheses(input_file_path, output_file_path);


    const char* input_file_path = "IT TRIBE MEETUP GROUP.txt";
    const char* output_file_path = "IT TRIBE MEETUP GROUP1.txt";
    add_carriage_return_before_plus(input_file_path, output_file_path);

    const char* input_file_path2 = "IT TRIBE MEETUP GROUP1.txt";
    const char* output_file_path2 = "IT TRIBE MEETUP GROUP2.txt";
    remove_commas(input_file_path2, output_file_path2);

    const char* input_file_path3 = "IT TRIBE MEETUP GROUP2.txt";
    const char* output_file_path3 = "IT TRIBE MEETUP GROUP3.txt";
    remove_spaces_hyphens_parentheses(input_file_path3, output_file_path3);

    // const char* input_file_path4 = "IT TRIBE MEETUP GROUP3.txt";
    // const char* output_file_path4 = "IT TRIBE MEETUP GROUP4.txt";
    // add_plus_at_start_of_each_line(input_file_path4, output_file_path4);
    return 0;
}

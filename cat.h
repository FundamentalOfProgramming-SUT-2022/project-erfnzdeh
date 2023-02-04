#include <stdio.h>
#include "functions.h"

typedef long long ll;
#define TRUE  1
#define FALSE 0

void print_message(char *message);
void cat(const char *rest_of_command) {
    char command_dash_dash_file[1000];
    char raw_path_input[1000];
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_file, raw_path_input);
    if (strcmp(command_dash_dash_file, "--file") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--file' after 'cat'!");
        return;
    }
    int strlen_raw_path_input = strlen(raw_path_input);
    int isQoutational = 0;
    if (raw_path_input[0] == '"') {
        if (raw_path_input[strlen_raw_path_input - 1] != '"') {
            print_message("[ERROR] invalid input. seems like you forgot to put '\"' at the end of the path.");
            return;
        } else {
            isQoutational = 1;
        }
    }

    int strlen_final;
    if (isQoutational) {
        strlen_final = strlen_raw_path_input - 3;
    } else {
        strlen_final = strlen_raw_path_input - 1;
    }
    char final_file_name[strlen_final];
    if (isQoutational) {
        for (int i = 0; i < strlen_final; ++i) {
        final_file_name[i] = raw_path_input[i + 2];
        final_file_name[i + 1] = '\0';
        }
    } else {
        for (int i = 0; i < strlen_final; ++i) {
            final_file_name[i] = raw_path_input[i + 1];
            final_file_name[i + 1] = '\0';
        }
    }

    /* MAIN */

    if (fopen(final_file_name, "r") == 0) {
        print_message("[ERROR] File does not exist.");
        return;
    } else {
        print_message("[DONE] File exists:");
        char ch;
        FILE *file;
        file = fopen(final_file_name, "r");
        ch = fgetc(file);
        int counter = 0;
        while (ch != EOF) {
            counter++;
            printf("%c", ch);
            ch = fgetc(file);
        }
        fclose(file);
        printf("\n");
    }
}
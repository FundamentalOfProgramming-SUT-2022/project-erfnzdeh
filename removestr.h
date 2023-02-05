#include <stdio.h>
#include "string.h"

typedef long long ll;
#define TRUE  1
#define FALSE 0

void print_message(char *message);

void removestr(const char *input_rest_of_command) {
    char GRAND_STRING[1000];
    char rest_of_command[1000];
    char command_dash_dash_file[1000];
    char command_file[1000];
    char command_trash_x[1000];
    char command_dash_dash_pos[1000];
    char command_pos[1000];
    char command_dash_dash_size[1000];
    int size;
    char b_or_f[1000];
    int line_num = 0;
    int start_position = 0;
    strcpy(rest_of_command, input_rest_of_command);
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_file, rest_of_command);
    if (rest_of_command[0] == '"') {
        rest_of_command[0] = 'X';
        for (int i = 0; i < 1000; ++i) {
            printf("%d", i);
            if (rest_of_command[i + 1] != '"') {
                command_file[i] = rest_of_command[i + 1];
                command_file[i + 1] = '\0';
                rest_of_command[i + 1] = 'X';
            } else {
                rest_of_command[i + 1] = 'X';
                break;
            }
        }
        sscanf(rest_of_command, "%s %[^\n]%*c", command_trash_x, rest_of_command);
    } else {
        sscanf(rest_of_command, "%s %[^\n]%*c", command_file, rest_of_command);
    }
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_pos, rest_of_command);
    sscanf(rest_of_command, "%s %[^\n]%*c", command_pos, rest_of_command);
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_size, rest_of_command);
    sscanf(rest_of_command, "%d %[^\n]%*c", &size, rest_of_command);
    sscanf(rest_of_command, "%s %[^\n]%*c", b_or_f, rest_of_command);
    sscanf(command_pos, "%d:%d", &line_num, &start_position);
    //removestr --file /root/file1.txt --pos 2:1 --size 3 -b
    if (strcmp(command_dash_dash_file, "--file") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--file'!");
        return;
    }
    if (strcmp(command_dash_dash_pos, "--pos") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--pos'!");
        return;
    }
    if (strcmp(command_dash_dash_size, "--size") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--size'!");
        return;
    }
    if (command_file[0] != '/' || command_file[1] != 'r' || command_file[2] != 'o' || command_file[3] != 'o' ||
        command_file[4] != 't' || command_file[5] != '/') {
        print_message("[ERROR] invalid address!");
        return;
    }
    if (!(line_num > 0) || !(start_position > -1)) {
        print_message("[ERROR] invalid position!");
        return;
    }
    char path[strlen(command_file) - 1];
    for (int i = 0; i < strlen(command_file) - 1; ++i) {
        path[i] = command_file[i + 1];
        path[i + 1] = '\0';
    }
//    printf("[removestr] [%s] [%s] [%s] [%d]:[%d] [%s] [%d] [%s]\n", command_dash_dash_file, path, command_dash_dash_pos, line_num, start_position, command_dash_dash_size, size, b_or_f);
//    printf("[%s] [%d]:[%d] [%d] [%s]\n", path, line_num, start_position, size, b_or_f);
    int checker = 0, flag = 1, file_pointer = 0;
    char filetext[1000];
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        print_message("[ERROR] invalid address!");
        return;
    }
    for (int counter_line = 1; flag; counter_line++) {
        for (int counter_char = 0; 1; counter_char++) {
            //printf("line = %d, col = %d\n", counter_line, counter_char);
            char c = fgetc(file);
            filetext[file_pointer++] = c;
            if (c == EOF) {
                flag = 0;
                break;
            }
            if (counter_line == line_num && counter_char == start_position) {
                if (!strcmp(b_or_f, "-f")) {
                    filetext[file_pointer--] = '\0';
                    size--;
                    while (size--) {
                        c = fgetc(file);
                        if (c == EOF) {
                            break;
                        }
                    }
                    if (c != EOF) {
                        checker = 1;
                    }
                } else {
                    while (size-- && file_pointer >= 0) {
                        if (filetext[file_pointer] == '\n') {
                        }
                        filetext[file_pointer--] = '\0';
                    }
                    if (file_pointer >= 0) {
                        checker = 1;
                    }
                }
                flag = 0;
                break;
            }
        }
    }
    char c = fgetc(file);
    while (c != EOF) {
        filetext[file_pointer++] = c;
        c = fgetc(file);
    }
    fclose(file);
    if (checker == 0) {
        print_message("[ERROR] invalid position or size!");
        return;
    }
    file = fopen(path, "w");
    if (checker == 1) {
        fprintf(file, "%s", filetext);
    }
    fclose(file);
    print_message("[DONE] Removed successfully!");
    return;
}
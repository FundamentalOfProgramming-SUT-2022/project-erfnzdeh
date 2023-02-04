#include <stdio.h>

typedef long long ll;
#define TRUE  1
#define FALSE 0

void insertstr(const char *input_rest_of_command) {
    char GRAND_STRING[1000];
    char rest_of_command[1000];
    char command_dash_dash_file[1000];
    char command_file[1000];
    char command_trash_x[1000];
    char command_dash_dash_str[1000];
    char command_str[1000];
    char command_dash_dash_pos[1000];
    char command_pos[1000];
    int line_num = 0;
    int start_position = 0;
    strcpy(rest_of_command, input_rest_of_command);
//    printf("[CHECK] rest of command = %s\n", rest_of_command);
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_file, rest_of_command);
//    printf("[CHECK] rest of command = %s\n", rest_of_command);
    if (rest_of_command[0] == '"') {
        rest_of_command[0] = 'X';
        for (int i = 0; i < 1000; ++i) {
            if (rest_of_command[i + 1] != '"') {
                command_file[i] = rest_of_command[i + 1];
                command_file[i + 1] = '\0';
                rest_of_command[i + 1] = 'X';
            } else {
                rest_of_command[i + 1] = 'X';
                break;
            }
//            printf("[CHECK] rest of command = %s | command_file = %s\n", rest_of_command, command_file);
        }
        sscanf(rest_of_command, "%s %[^\n]%*c", command_trash_x, rest_of_command);
    } else {
        sscanf(rest_of_command, "%s %[^\n]%*c", command_file, rest_of_command);
    }
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_str, rest_of_command);

//    printf("[CHECK] rest of command = %s\n", rest_of_command);
    if (rest_of_command[0] == '"') {
        rest_of_command[0] = 'X';
        for (int i = 0; i < 1000; ++i) {
            if (rest_of_command[i + 1] == '"' && rest_of_command[i] != 92) {
                if (rest_of_command[i + 1] != 92) rest_of_command[i + 1] = 'X';
//                printf("[IF]\n");
                break;
            } else {
                command_str[i] = rest_of_command[i + 1];
                command_str[i + 1] = '\0';
                if (rest_of_command[i + 1] != 92) rest_of_command[i + 1] = 'X';
//                printf("[ELSE] %s rest_of_command[%d] %c\n", rest_of_command, i, rest_of_command[i]);
            }
//            printf("[CHECK] rest of command = %s | command_str = %s\n", rest_of_command, command_str);
        }
        sscanf(rest_of_command, "%s %[^\n]%*c", command_trash_x, rest_of_command);
    } else {
        print_message("[ERROR] invalid string!");
    }
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_pos, rest_of_command);
    sscanf(rest_of_command, "%s %[^\n]%*c", command_pos, rest_of_command);
    sscanf(command_pos, "%d:%d", &line_num, &start_position);
//    printf("[insertstr] [%s] [%s] [%s] [%s] [%s] [%d]:[%d]\n", command_dash_dash_file, command_file, command_dash_dash_str, command_str, command_dash_dash_pos, line_num, start_position);
    if (strcmp(command_dash_dash_file, "--file") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--file'!");
        return;
    }
    if (strcmp(command_dash_dash_pos, "--pos") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--pos'!");
        return;
    }
    if (strcmp(command_dash_dash_str, "--str") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--str'!");
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

    char str[1000];
    int counter1 = 0;
    int counter2 = 0;
    while(1) {
        if (command_str[counter2] == '\\' && command_str[counter2 + 1] == '\"') {
            str[counter1] = '\"';
            counter1++;
            counter2++;
            counter2++;
            continue;
        }
        if (command_str[counter2 - 1] != '\\' && command_str[counter2] == '\\' && command_str[counter2 + 1] == 'n') {
            str[counter1] = '\n';
            counter1++;
            counter2++;
            counter2++;
            continue;
        }
        if (command_str[counter2] == '\\' && command_str[counter2 + 1] == '\\' && command_str[counter2 + 2] == 'n') {
            str[counter1] = '\\';
            counter1++;
            str[counter1] = 'n';
            counter1++;
            counter2++;
            counter2++;
            counter2++;
            continue;
        }
        str[counter1] = command_str[counter2];
        if (command_str[counter2] == '\0') break;
        counter1++;
        counter2++;
    }
//    printf("%s >>> %s\n", command_str, str);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        print_message("[ERROR] invalid address!");
        return;
    }
    int check = 0, flag = 1, n = 0;
    for (int line_counter = 1; flag; line_counter++) {
        for (int col_counter = 0; 1; col_counter++) {
            char c = fgetc(file);
            //printf("c = %c\n", c);
            if (line_counter == line_num && col_counter == start_position) {
                check = 1;
                for (int i = 0; str[i] != '\0'; i++) {
                    GRAND_STRING[n++] = str[i];
                }
            }
            if (c == EOF) {
                flag = 0;
                break;
            }
            GRAND_STRING[n++] = c;
            if (c == '\n') break;
        }

    }
    if (check == 0) {
        print_message("[ERROR] invalid position!");
        return;
    }
    fclose(file);
    file = fopen(path, "w");
    fprintf(file, "%s", GRAND_STRING);
    fclose(file);
    print_message("[DONE] Inserted successfully!");
    return;
}
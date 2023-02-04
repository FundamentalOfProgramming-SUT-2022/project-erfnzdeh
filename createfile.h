#include <stdio.h>

typedef long long ll;
#define TRUE  1
#define FALSE 0
#define MAX 10000

void print_message(char *message);
int isFileExists(const char *file_name);

void createfile(const char *rest_of_command) {
//    print_message("createfile initiated:");
    char command_dash_dash_file[1000];
    char path[1000];
    sscanf(rest_of_command, "%s %[^\n]%*c", command_dash_dash_file, path);
    if (strcmp(command_dash_dash_file, "--file") != 0) {
        print_message("[ERROR] invalid input. seems like you forgot to put '--file' after 'createfile'!");
        return;
    }

//    /* CHECK */ printf("[FIXING THE PATH] raw path = '%s'\n", path);
    int strlen_path = strlen(path);
    char fixed_path[1000];
    if (path[0] == '"') {
        if (path[strlen_path - 1] != '"') {
            print_message("[ERROR] invalid input. seems like you forgot to put '\"' at the end of the path.");
            return;
        }
    }
    if (path[0] == '"') {
        for (int i = 0; i < strlen_path - 2; i++) {
            fixed_path[i] = path[i + 1];
        }
    } else {
        for (int i = 0; i < strlen_path; i++) {
            fixed_path[i] = path[i];
        }
    }
//    /* CHECK */ printf("[FIXING THE PATH] fixed path = '%s'\n", fixed_path);

    char* token = strtok(fixed_path, "/");
//    /* CHECK */ printf("[CHECK] token = '%s'\n", token);
    if (fixed_path[0] != '/' || strcmp(token,"root") != 0) {
        print_message("invalid path!");
        return;
    }
    int check;
    int strlen_token;
    int change_directory_counter = 0;
    while (token != NULL) {
        check  = mkdir(token);
        chdir(token);
        change_directory_counter++;
//        /* CHECK */ printf("[CHECK] check = '%d'\n", check);
        token = strtok(NULL, "/");
        strlen_token = strlen(token);
//        /* CHECK */ printf("[CHECK] token = '%s'\n", token);
        if (token[strlen_token - 1] == 't' && token[strlen_token - 2] == 'x' && token[strlen_token - 3] == 't' && token[strlen_token - 4] == '.') {
//            /* CHECK */ printf("[CHECK] .txt is here.\n");
            if (isFileExists(token)) {
                print_message("[ERROR] File already exists!");
                break;
            }
            FILE *file = fopen(token, "w");
            fclose(file);
            print_message("[DONE] File created successfully!");
            break;
        }
    }
    while (change_directory_counter != 0) {
//        /* CHECK */ printf("[CHECK] change_directory_counter = %d\n", change_directory_counter);
        chdir("..");
        change_directory_counter--;
    }
}
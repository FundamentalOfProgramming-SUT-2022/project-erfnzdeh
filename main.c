#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include "createfile.h"
#include "cat.h"
#include "insertstr.h"

void print_message(char *message) {
    printf("%s\n", message);
}

int isFileExists(const char *file_name) {
    FILE *file;
    if ((file = fopen(file_name, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

void goToAddress(char* address)
{
    char* token;
    token = strtok(address, "/");
    while(token != NULL)
    {
        mkdir(token);
        chdir(token);
        token = strtok(NULL, "/");
    }
}

void goToRoot()
{
    char cwd[1000];
    getcwd(cwd, 100);
    int cwdsize = strlen(cwd);
    while(cwd[cwdsize - 1] != 't' || cwd[cwdsize- 2 ] != 'o' || cwd[cwdsize - 3] != 'o' || cwd[cwdsize - 4] != 'r' || cwd[cwdsize - 5] != '/')
    {
        chdir("..");
        getcwd(cwd, 100);
        cwdsize = strlen(cwd);
    }
    chdir("..");
}

void removestr() {
    printf("command = removestr\n");
}

void copystr() {
    printf("command = copystr\n");
}

void cutstr() {
    printf("command = cutstr\n");
}

void pastestr() {
    printf("command = pastestr\n");
}
//void find();
//void compare();

char CWD[100];
char full_input[1000];

int main() {
    do {
        printf("Vim ~ %s\n", getcwd(CWD, 100));
        printf(">");
        scanf("%[^\n]%*c", full_input);
        char command_main[1000];
        char command_rest[1000];
        sscanf(full_input, "%s %[^\n]%*c", command_main, command_rest);
//        printf("Let's check the command:\n");
//        printf("[1] command_main = %s\n", command_main);
//        printf("[2] command_rest = %s\n", command_rest);
//        printf("\n");
        if (strcmp(command_main, "createfile") == 0) {
            createfile(command_rest);
        } else if (strcmp(command_main, "insertstr") == 0) {
            insertstr(command_rest);
        } else if (strcmp(command_main, "cat") == 0) {
            cat(command_rest);
        } else if (strcmp(command_main, "removetstr") == 0) {
            removestr();
        } else if (strcmp(command_main, "copy") == 0) {
            copystr();
        } else if (strcmp(command_main, "cut") == 0) {
            cutstr();
        } else if (strcmp(command_main, "pastestr") == 0) {
            pastestr();
        } else if (strcmp(command_main, "find") == 0) {
            // find();
        } else if (strcmp(command_main, "help") == 0) {
            printf("commands list: (Credit AidaJalali)\n");
            printf("createfile        |  createfile --file name_of_file\n");
            printf("cat               |  cat        --file name_of_file\n");
            printf("insert            |  insert     --file name_of_file --str content --pos y:x\n");
            printf("remove            |  removestr  --file name_of_file --pos y:x --size size f_b\n");
            printf("copy              |  copystr    --file name_of_file --pos y:x --size size f_b\n");
            printf("paste             |  pastestr   --file name_of_file --pos y:x                \n");
            printf("cut               |  cutstr     --file name_of_file --pos y:x --size size f_b\n");
            printf("auto-indent       |  auto-indent name_of_file                                 \n");
            printf("compare           |  compare     name_of_file_A name_of_file_B                \n");
        } else if (strcmp(command_main, "exit") == 0) {
            //VALID AS FUCK.
        } else {
            print_message("invalid command");
        }
    } while (strcmp(full_input, "exit"));
    printf("bye bye.");
}
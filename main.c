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
#include "removestr.h"
#include "copystr.h"
#include "pastestr.h"
#include "cutstr.h"

void print_message(char *message) {
    printf("%s\n", message);
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
        } else if (strcmp(command_main, "removestr") == 0) {
            removestr(command_rest);
        } else if (strcmp(command_main, "copystr") == 0) {
            copystr(command_rest);
        } else if (strcmp(command_main, "cutstr") == 0) {
            cutstr(command_rest);
        } else if (strcmp(command_main, "pastestr") == 0) {
            pastestr(command_rest);
        } else if (strcmp(command_main, "find") == 0) {
            print_message("404");
        } else if (strcmp(command_main, "help") == 0) {
            printf("commands list: (Credit AidaJalali)\n");
            printf("createfile        |  createfile --file name_of_file\n");
            printf("cat               |  cat        --file name_of_file\n");
            printf("insert            |  insertstr  --file name_of_file --str content --pos y:x\n");
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
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "createfile.h"

typedef long long ll;
#define TRUE  1
#define FALSE 0
#define print_invalid printf("invalid command")

void insertstr();
void cat();
void removestr();
void copystr();
void cutstr();
void pastestr();
//void find();
//void compare();

char CWD[100];

int main() {
    printf(" ~ Vim ~ \n");
    printf("%s\n", getcwd(CWD, 100));
    char command[100];
    /* Copied from AidaJalali / TEMP */
    printf("commands list :\n");
    printf("createfile        |  createfile --file name_of_file\n");
    printf("cat               |  cat        --file name_of_file\n");
    printf("insert            |  insert     --file name_of_file --str content --pos y:x\n");
    printf("remove            |  removestr  --file name_of_file --pos y:x --size size f_b\n");
    printf("copy              |  copystr    --file name_of_file --pos y:x --size size f_b\n");
    printf("paste             |  pastestr   --file name_of_file --pos y:x                \n");
    printf("cut               |  cutstr     --file name_of_file --pos y:x --size size f_b\n");
    // replace           |                                                          \n
    // grep              |                                                          \n
    // undo              |                                                          \n
    printf("auto-indent       | auto-indent name_of_file                                 \n");
    printf("compare           | compare     name_of_file_A name_of_file_B                \n");
    // tree              |                                                          \n
    // find              |                                                          \n
    /* Copied from AidaJalali / TEMP */
    do {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "createfile") == 0) {
            createfile();
        } else if (strcmp(command, "insertstr") == 0) {
            insertstr();
        } else if (strcmp(command, "cat") == 0) {
            cat();
        } else if (strcmp(command, "removetstr") == 0) {
            removestr();
        } else if (strcmp(command, "copy") == 0) {
            copystr();
        } else if (strcmp(command, "cut") == 0) {
            cutstr();
        } else if (strcmp(command, "pastestr") == 0) {
            pastestr();
        } else if (strcmp(command, "find") == 0) {
            // find();
        } else {
            print_invalid;
        }
    } while (strcmp(command, "exit"));
    printf("bye.");
}

void insertstr() {
    printf("command = insertstr\n");
}

void cat() {
    printf("command = cat\n");
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
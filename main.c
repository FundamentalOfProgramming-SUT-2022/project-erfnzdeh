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

typedef long long ll;

#define TRUE  1
#define FALSE 0

void createfile();
void insertstr();
void cat();
void removestr();
void copystr();
void cutstr();
//void pastestr();
//void find();
//void compare();

int main() {
    printf(" ~ Vim ~ \n");
    char command[100];
    while (1) {
        printf(">");
        printf(" ");
        scanf("%s", command);
        if (!strcmp(command, "createfile")) {
            createfile();
        } else if (!strcmp(command, "insertstr")) {
            insertstr();
        } else if (!strcmp(command, "cat")) {
            cat();
        } else if (!strcmp(command, "removestr")) {
            removestr();
        } else if (!strcmp(command, "copystr")) {
            copystr();
        } else if (!strcmp(command, "cutstr")) {
            cutstr();
        } else if (!strcmp(command, "exit")) {
            break;
        } else {
            printf("invalid input\n");
        }
    }
}

void createfile() {
    printf("command = createfile\n");
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
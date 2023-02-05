#include <stdio.h>
#include "string.h"

typedef long long ll;
#define TRUE  1
#define FALSE 0

void print_message(char *message);
//char clipboard[10000] = {'\0'};

/* LINK: https://codeforwin.org/c-programming/c-program-to-list-all-files-in-a-directory-recursively */

void recursive_tree(char *basepath, int round, int max) {
    //base case.
    if (round == max) {
        return;
    }
    //rest
    char path[1000];
    DIR *directory;
    struct dirent *dir_entry;
    struct stat statbuf;
    directory = opendir(basepath);
    while ((dir_entry = readdir(directory)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
            continue;
        else {
            if (round > 0) {
                for (int i = 0; i < (round - 1) * 6 + 2; i++)
                    printf(" ");
                printf("|");
                for (int i = 0; i < 4; i++)
                    printf("-");
            }
            printf("%s\n", dir_entry->d_name);
            int mark = isFileExists(dir_entry->d_name);
            if (!mark) {
                strcpy(path, basepath);
                strcat(path, "/");
                strcat(path, dir_entry->d_name);
                recursive_tree(path, round + 1, max);
            }
        }
    }
    closedir(directory);
}

void tree(char *input_rest_of_command) {
    int number, dpth;
    scanf("%d", &number);
    if (number == -1)
        dpth = 30;
    else if (number < -1) {
        print_message("[ERROR] Invalid depth!")
    } else {
        dpth = number;
    }
    recursive_tree("root/", 0, dpth);
}
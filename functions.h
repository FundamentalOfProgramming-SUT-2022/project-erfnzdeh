#include "stdlib.h"
#include "string.h"

typedef long long ll;
#define TRUE  1
#define FALSE 0

char clipboard[10000] = {'\0'};

int isFileExists(const char *path)
{
    // Check for file existence
    if (access(path, F_OK) == -1)
        return 0;
    return 1;
}

/* Didn't use this shit. */
char* remove_leading_slash(char* address) { // credit: Heokhe
    if (address[0] != '/') return address;
    int len = strlen(address);
    char* output = malloc(sizeof(char) * len);
    for (int i = 1; i < len; i++) {
        char ch = address[i];
        output[i - 1] = address[i];
    }
    return output;
}
#include "stdlib.h"
#include "string.h"

typedef long long ll;
#define TRUE  1
#define FALSE 0

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
#include "stdio.h"

int main () {
    char c[1];
    scanf("%s", c);
    printf("%s\n", c);
    printf("%d\n", c[0]);
    if (c[0] == 92) {
        printf("works!");
    }
}
/*

/
/
47

*/
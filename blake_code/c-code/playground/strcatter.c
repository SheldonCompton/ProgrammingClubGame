#include <stdio.h>
#include <string.h>

int main() {
    char a[];
    char b[] = "Jeff";
    int len = strlen(a) + strlen(b) + 1;
    char c[len];
    strcpy(c, a);
    strcat(c, b);
    strcat(c, "\0");
    printf("%s\n", c);
    return 0;
}

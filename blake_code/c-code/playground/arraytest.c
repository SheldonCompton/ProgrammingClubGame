#include <stdio.h>
#include <stdlib.h>

void jibmou(char jimbo[]);

int main() {
    char jimbo[5] = {'a','s','d','f','g'};
    jibmou(jimbo);
    return 0;
}

void jibmou(char jimbo[]) {
    printf("%c\n", jimbo[3]);
}

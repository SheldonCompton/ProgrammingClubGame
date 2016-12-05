#include <stdio.h>
#include <stdlib.h>

int main() {
    char jeff[4][4] = {{'o', 'i', 'u', 'e'}, {'o', 'i', 'u', 'e'}, {'o', 'i', 'u', 'e'}, {'o', 'i', 'u', 'e'}};
    int i, j;
    for (i = 0; i < 4; i = i + 1) {
        for (j = 0; j < 4; j = j + 1) {
            printf("%c", jeff[i][j]);
        }
        printf("\n");
    }
    return 0;
}

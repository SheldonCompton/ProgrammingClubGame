#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[255];
    fp = fopen("test.txt", "r");
    fgets(buffer, 255, (FILE*)fp);
    printf("Content:\n%s\n", buffer);
    fgets(buffer, 255, (FILE*)fp);
    printf("Content:\n%s\n", buffer);
    return 0;
}

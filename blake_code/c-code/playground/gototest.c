#include <stdio.h>
#include <stdlib.h>

int main()
{
    label:
    printf("Hi\n");
    printf("There\n");
    goto label;
    return 0;
}

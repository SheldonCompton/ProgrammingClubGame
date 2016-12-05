#include <stdio.h>

typedef struct Test
{
    int number;
    char letter;
} Test;

Test functionator() {
    Test testinator;
    testinator.number = 5;
    testinator.letter = 'j';
    return testinator;
}

int main()
{
    Test jimbo = functionator();
    printf("Values are %d and %c. Exiting..\n", jimbo.number, jimbo.letter);
    return 0;
}

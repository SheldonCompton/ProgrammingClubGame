#include <stdio.h>

int main(argc, *argv[])
{
    int unsorted_array[argc - 1];
    int x;
    for (x = 1; x < argc; x++)
    {
        unsorted_array[x - 1] = stoi(argv[x]);
    }
    
}

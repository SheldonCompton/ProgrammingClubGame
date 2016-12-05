#include <stdio.h>

void readFile(char roomfile[]);

int main()
{
    printf("Initial Output \n");

    return 0;
}

void readFile(char roomfile[])
{
    FILE *fp;
    char roomname[64];
    char roomdesc[1024];
    char exits[16][9];
    fp = fopen(roomfile, "r");
    fgets(roomname, 64, (FILE*)fp);
    fgets(roomdesc, 1024, (FILE*)fp);
    int i = 0;
    for(i = 0; i < 16; i = i + 1)
    {
        char buffer[8];
        fgets(buffer, 8, (FILE*)fp);
        exits[i] = buffer;
        exits[i][8] = '\0';
    }
}

void getRoomInfo()
{
    // GET ROOM INFO 
}

void setRoomInfo()
{
    char roomdesc[];
    char exits[][];
}


#ifndef TXT_ADV_FUNCTIONS
#define TXT_ADV_FUNCTIONS

// GLOBALS
int TURN;       // turn counter

// Structures
typedef struct Room
{
    char name[64];
    char description[1024];
    char exits[16][9];
} Room;

// Load Room File
Room loadRoom(char filename[])
{
    FILE *fp;
    Room roomfile;
    fp = fopen(filename, "r");
    fgets(roomfile.name, 64, (FILE*)fp);
    fgets(roomfile.description, 1024, (FILE*)fp);
    int i;
    for(i = 0; i < 16; i = i + 1)
    {
        char buffer[8];
        fgets(buffer, 8, (FILE*)fp);
        roomfile.exits[i] = buffer;
        roomfile.exits[i][8] = '\0';
    }
    fclose(fp);
    return roomfile;
}
// Unload Room File
void unloadRoom()
{
    //
}

// Get Room Name
void getName()
{
    //
}
// Get Room Descritpion
void getDescription()
{
    //
}
// Get Room Exits
void getExit()
{
    //
}

// Set Room Name
void setName()
{
    //
}
// Set Room Description
void setDescription()
{
    //
}
// Set Room Exits
void setExit()
{
    //
}

// Get Inventory
void getInv()
{
    //
}
// Get Stats
void getStats()
{
    //
}

// Add Item to Inventory
void addItem()
{
    //
}
// Remove Item from Inventory
void removeItem()
{
    //
}

#endif /*!TXT_ADV_FUNCTIONS*/

#include <stdio.h>
#include <stdlib.h>


void printBoard(char board[][], int bsize)
{
    int i, j;
    for (i = 0; i < bsize; i = i + 1)
    {
        printf("%d\t", i);
        for (j = 0; j < bsize; j = j + 1)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    char botnum[bsize][3];
    for (i = 0; i < bsize; i = i + 1)
    {
        sprintf(botnum[i], "%d", i);
    }
    for (i = 0; i < bsize; i = i + 1) { printf("%c", botnum[bsize][0]); }
    for (i = 0; i < bsize; i = i + 1) { printf("%c", botnum[bsize][1]); }
}

int main()
{
    char bsizechars[3] = {'1','9','\0'};
    int bsize;
    int x = 0;
    // Board Init
    while (x == 0)
    {
        printf("Welcome to the Virtual Goban!\nWhat board size would you like?\n : ");
        
        fgets(bsizechars, 3, stdin);
        bsize = atoi(bsizechars);
        
        if (bsize < 99) { x = 1; }
        else
        {
        printf("Please choose a size below 100.\n");
        }
    }
    char board[bsize][bsize];
    int i, j;
    for (i = 0; i < bsize; i = i + 1)
    {
        for (j = 0; j < bsize; j = j + 1)
        {
        board[i][j] = '+';
        }
    }
    char komichars[4];
    printf("What should white's komi be? Please type an integer; the komi will be a half-point more than what you put(ex. 6 == 6.5). You may enter negative numbers.\n : ");
    fgets(komichars, 4, stdin);
    int komi = atoi(komichars);
    printf("Let the game begin!\nPress RETURN to continue");
    getchar();
    // Game Vars
    char turn = 'b';    // whose turn it is
    int blackpts = 0;   // black points
    int whitepts = komi;// white points
    int passval = 0;    // pass counter
    int coords[2];      // stone placement coords
    char stone = 'O'    // stone type ; white 0 or black O
    char input[6];      // input buffer
    x = 0;
    // Game Loop
    while (x == 0)
    {
        printBoard(board, bsize);
        if (turn == 'b') { printf("Black's Turn (h for help) : "); }
        else { printf("White's Turn (h for help) : "); }
        fgets(input, 6, stdin);
        switch (input[0])
        {
            case 'h':
                printf("Commands \nh : this help text\np : pass turn\ns : place a stone\n");
                break;
            case 'p':
                printf("Passing turn.\n");
                if (passval == 1) { x = 1; }
                passval = 1;
                if (turn == 'b') { turn = 'w'; } else { turn = 'b'; }
                break;
            case 's':
                // set coords
                HORIZONTAL:
                printf("Horizontal Location : ");
                fgets(input, 3, stdin);
                coords[0] = atoi(input);
                if ((coords[0] < 1) || (coords[0] > bsize)) 
                {
                    printf("Please use an appropriate number.\n");
                    goto HORIZONTAL;
                }
                VERTICAL:
                printf("Vertical Location : ");
                fgets(input, 3, stdin);
                coords[1] = atoi(input);
                if ((coords[1] < 1) || (coords[1] > bsize)) 
                {
                    printf("Please use an appropriate number.\n");
                    goto VERTICAL;
                }
                // apply to board
                if (turn == 'b') { stone = 'O'; } else { stone = '0'; }
                board[coords[0],coords[1]] = stone;
                passval = 0; //reset the pass counter
                break;
            default:
                printf("Your input was invalid. Try again. (h for help)\n");
        }
    }
    // End Game Loop goes Here
    printf("Final Board : \n");
    printBoard(board, bsize);
    return 0;
}

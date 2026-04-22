#include <stdlib.h>
#include <stdio.h>

#include <time.h>

#include "arg.h"
#include "draw.h"
#include "generate.h"
#include "defs.h"

GameState GameMode = MD_MAIN_MENU;

void mainLoop()
{
    /*This switch shouldn't be necessary since GameMode is global
    switch (GameMode)
    {
        case MAIN_MENU:
            drawToScreen(MAIN_MENU);
            break;
        case PLAYING:
            drawToScreen(PLAYING);
            break;
        case GAMEOVER:
            break;
        default: //How did you even get here???
            fprintf(stderr, "Error: GameMode outside of range. Exiting program\n");
            exit(EXIT_FAILURE);
            break;
    }
    */
    drawToScreen();
    return;
}

int main(int argc, char* argv[])
{
    //Start the program
    srand(time(NULL));
    //Check the arguments
    int argIndex;
    initArgs(argc, argv);
    
    if(searchArgs("-h", "-help", "--help", NULL) > -1)
    {
        printHelpText();
        return 0;
    }

    //Argument to check custom window size
    if ((argIndex = searchArgs("-w", NULL)) > -1)
    {
        if(checkArgType(argIndex + 1) == 'p' && checkArgType(argIndex + 2) == 'p')
            initDisplay(atoi(myArgs[argIndex + 1]),atoi(myArgs[argIndex + 2]));
        else
        {
            printf("Please make sure that you are using the correct syntax for window sizes,"
                  " using default window size\n");
            initDisplay(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
        }
    }
    else initDisplay(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

    //Draw the main menu
    //Ask user for prompt (generate puzzle, open file, create puzzle, quit)

    //Generate a puzzle and store it in puzzle buffer
    initPuzzle(10, 10);
    //Display the puzzle on the screen

    //Ask user for input
    //Add input to the puzzle
    //Redisplay the puzzle
    //Check if the puzzle is solved
    //If not, go back to asking user for input
    //If so, game is completed. Ask user to restart or quit
    /*while(GameMode != MD_QUIT)*/ mainLoop();
    return 0;
}
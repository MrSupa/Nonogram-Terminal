#include <stdlib.h>
#include "draw.h"
#include "defs.h"
#include "generate.h"
#include "string.h"

Display GameDisplay = {};
                        

void initDisplay(int w, int h)
{
    GameDisplay.window_w = w;
    GameDisplay.window_h = h;
    GameDisplay.buffer = malloc(sizeof(char*) * (w * h + 1));//The last char* is for null character
}

void drawToScreen()
{
    switch (GameMode)
    {
        case MD_MAIN_MENU:
            drawMainMenu();
            break;
        case MD_PLAYING:
            break;
        default:
	    fprintf(stderr, "Error: Gamemode is not initialized, exiting program\n");
            exit(EXIT_FAILURE);
    }

    return;
}

int drawMainMenu()
{
    int index   = 0;
    int row     = 0;
    int column  = 0;

    const int width   = GameDisplay.window_w;
    const int height  = GameDisplay.window_h;

    //TODO: This main menu display code is UGLY, but it works for now...
    //TODO: Make sure there is a set minimum size for window initialization or else if it is too small it will break the display
    for(int i = 0; i < (width * height - 1); i++)
    {
        
        if (column == (width - 1))//End of the screen
        {
            GameDisplay.buffer[i] = '\n';
            row++;
            column = 0;
        }
        else if(row == 0 || row == (height - 1) || column == 0 || column == (width - 2))//Fill border with '*'
        {
            //GameDisplay.buffer[i] = (column % 10) + '0';//This is to show the number of the row 0-9
            GameDisplay.buffer[i] = '*';
            column++;
        }
        else if(row == 3 && column == ((width - 9) / 2))//This part displays the menu text and options
        {
            memcpy(GameDisplay.buffer + i, "Main Menu", 9);
            i+=8;
            column += 9;
        }
        else if (row == 5 && column == ((width - 25) / 2)) // This is for the generate random game option
        {
          memcpy(GameDisplay.buffer + i, "1: Generate Random Puzzle", 25);
          i += 24;
	  column += 25;
	} 
        else if (row == 7 && column == ((width - 12) / 2)) // This is for the generate random game option
        {
          memcpy(GameDisplay.buffer + i, "2: Open File", 12);
          i += 11;
	  column += 12;
	} 
        else if (row == 9 && column == ((width - 16) / 2)) // This is for the generate random game option
        {
          memcpy(GameDisplay.buffer + i, "3: Create Puzzle", 16);
          i += 15;
	  column += 16;
	} 
        else if (row == 11 && column == ((width - 7) / 2)) // This is for the generate random game option
        {
          memcpy(GameDisplay.buffer + i, "Q: Quit", 7);
          i += 6;
	  column += 7;
	} 
        else
        {
            GameDisplay.buffer[i] = ' ';
            column++;
        }
            
    }

    printf("%s", GameDisplay.buffer);
    return 0;
}

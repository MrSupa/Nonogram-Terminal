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

int drawToScreen()
{
    switch (GameMode)
    {
        case MD_MAIN_MENU:
            drawMainMenu();
            break;
        case MD_PLAYING:
            break;
    }

}

int drawMainMenu()
{
    int index   = 0;
    int row     = 0;
    int column  = 0;

    const int width   = GameDisplay.window_w;
    const int height  = GameDisplay.window_h;

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
            GameDisplay.buffer[i] = (column % 10) + '0';//This is to show the number of the row 0-9
            column++;
        }
        else if(row == 3 && column == ((width - 9) / 2))//This part displays the menu text and options
        {
            memcpy(GameDisplay.buffer + i, "Main Menu", 9);
            column += 9;
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

#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include "defs.h"

#define DEFAULT_WINDOW_WIDTH    40
#define DEFAULT_WINDOW_HEIGHT   20

//This can change in the future
#define MINIMUM_WINDOW_WIDTH    40
#define MINIMUM_WINDOW_HEIGHT   20

typedef struct Display
{
    int     window_w;
    int     window_h;
    char*   buffer;
} Display;

extern Display GameDisplay;

void initDisplay(int w, int h);

/// @brief Draws to the screen 
/// @return 0 if there are no problems, 1 if cannot draw properly
int drawToScreen();

int drawMainMenu();

#endif //DRAW_H

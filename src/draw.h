#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include "defs.h"

#define WINDOW_WIDTH    120
#define WINDOW_HEIGHT   40

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
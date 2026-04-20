#ifndef GENERATE_H
#define GENERATE_H

#include <stdio.h>

typedef struct
{
    int width;
    int height;
    int x;
    int y;
    char* buffer;
} Puzzle;

extern Puzzle GamePuzzle;

void initPuzzle(int w, int h);

int generatePuzzle();

int writeFileToBuffer(char* File);

#endif //GENERATE_H
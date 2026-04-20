#include <stdlib.h>

#include "generate.h"
#include "arg.h"

Puzzle GamePuzzle = {};


void initPuzzle(int w, int h)
{
    GamePuzzle.width = w;
    GamePuzzle.height = h;
    GamePuzzle.buffer = malloc(sizeof(char*) * (w * h + 1)); //The last char* is for null character

}

int generatePuzzle()
{
    //Reading from file
    if(searchArgs("-file", "-f", NULL) > -1)
    {
        //Read from file name and generate here
        return 0;
    }

    //Random number puzzle generation (50% chance filled or not filled)
    for(int i = 0; i < (GamePuzzle.width * GamePuzzle.height); i++)
    {
        GamePuzzle.buffer[i] = (rand() % 2) ? 'x' : 'o';
    }

    GamePuzzle.buffer[GamePuzzle.width * GamePuzzle.height] = '\0';
    return 0;
    
}

int writeFileToBuffer(char *File)
{
    return 0;
}

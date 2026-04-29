#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include "arg.h"

uint8_t argMask = 0b00000000;

char** myArgs = NULL;
int numArgs = -1;

void initArgs(int myargc, char **myargv)
{
    numArgs = myargc;

    //Allocate memory for each of the c strings
    myArgs = malloc(sizeof(char *) * myargc);
    if(myArgs == NULL)
    {
        fprintf(stderr, "Error: failed to allocate memory for myArgs. Exiting program\n");
        exit(EXIT_FAILURE);
    }

    printf("\n There are %d arguments\n", myargc);
    for(int i = 0; i<myargc; i++)
    {
        myArgs[i] = strdup(myargv[i]);
        printf("\nargc: %d, argv: %s\n", i, myargv[i]);
    }
}

int searchArgs(char *value, ...)
{
    va_list args;
    va_start(args, value);

    char* current;

    if(numArgs <= -1 || myArgs == NULL)
    {
        fprintf(stderr, "Error: Arguments have not been initialized. Exiting program\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 1; i < numArgs; i++)
    {
        if (strcmp(value, myArgs[i]) == 0) 
            {
                va_end(args);
                return i;
            }

        while((current = va_arg(args, char *)) != NULL)
        {
            if (strcmp(current, myArgs[i]) == 0) 
            {
                va_end(args);
                return i;
            }
        }
        va_start(args, value);
    }

    va_end(args);
    return -1;
}

char checkArgType(int index)
{
    if(!isArgIndexValid(index)) return '\0';//There is no argument here

    char type = 'x';
    char* arg = strdup(myArgs[index]);

    if(isdigit(*arg))
    {
        //TODO: This
    }


    free(arg);
    return type;
}

bool isArgIndexValid(int index)
{
    if(index >= numArgs || index < 0) return false;
    return true;
}

void printHelpText()
{
    printf("\nThis is nonogram, VERY COOL :)\n");
}

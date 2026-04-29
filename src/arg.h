#ifndef ARG_H
#define ARG_H

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

#define ARG_READFILE    0b00000010
#define ARG_PLAY        0b00000100
#define ARG_WIN_MANUAL  0b00001000

extern uint8_t argMask;

extern char** myArgs;
extern int numArgs;

void initArgs(int myargc, char** myargv);

/**
 * @brief Checks through
 * 
 * @param String argument to look for 
 * @return index of argument, -1 if not found 
 */
int searchArgs(char* value, ...);

/**
 * @brief Checks the Argument type at the given argument index
 * 
 * @param index 
 * @return  '\0' if the argument does not go to the index,
 * 
 *          'p' if the argument is a positive integer or 0
 * 
 *          'n' if the argument is a negative integer
 * 
 *          'f' if the argument is a positive float
 *
 *          'b' if the argument is a negative float (b for backwards)
 * 
 *          'c' if the argument is a single character
 * 
 *          's' if the argument is a string
 * 
 *          '1' if the argument is an option with 1 dash
 * 
 *          '2' if the argument is an option with 2 dashes
 * 
 *          'x' if other/unknown
 */
char checkArgType(int index);

bool isArgIndexValid(int index);

void printHelpText();

#endif //ARG_H
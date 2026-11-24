/*
 * File        : constant.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Identifies integer and float constants.
 */

#include "lexer.h"

/*
 * Function     : is_integer_constant()
 * Description  : Checks whether token contains
 *                only digits.
 */
int is_integer_constant(char *token)
{
    int i;

    /* STEP-1 : Traverse token */
    for(i = 0; token[i] != '\0'; i++)
    {
        if(!isdigit(token[i]))
        {
            return 0;
        }
    }

    return 1;
}

/*
 * Function     : is_float_constant()
 * Description  : Checks whether token contains
 *                a valid decimal point.
 */
int is_float_constant(char *token)
{
    int i;
    int dot_count = 0;

    for(i = 0; token[i] != '\0'; i++)
    {
        if(token[i] == '.')
        {
            dot_count++;
        }
        else if(!isdigit(token[i]))
        {
            return 0;
        }
    }

    return (dot_count == 1);
}
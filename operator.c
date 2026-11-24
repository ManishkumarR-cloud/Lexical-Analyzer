/*
 * File        : operator.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Recognizes operators.
 */

#include "lexer.h"

int is_operator(char *token)
{
    char *operators[] =
    {
        "+",
        "-",
        "*",
        "/",
        "%",
        "=",
        "==",
        "!=",
        "<",
        ">",
        "<=",
        ">=",
        "++",
        "--",
        "&&",
        "||"
    };

    int total_operators =
            sizeof(operators) / sizeof(operators[0]);

    /* STEP-1 : Compare token with operators */
    for(int i = 0; i < total_operators; i++)
    {
        if(strcmp(token, operators[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}
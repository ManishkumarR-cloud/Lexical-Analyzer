/*
 * File        : keyword.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Checks whether a given token
 *               is a C language keyword.
 */

#include "lexer.h"

/*
 * Function     : is_keyword()
 * Description  : Compares token against
 *                known C keywords.
 */
int is_keyword(char *token)
{
    char *keywords[] =
    {
        "int",
        "char",
        "float",
        "double",
        "void",
        "if",
        "else",
        "while",
        "for",
        "return",
        "switch",
        "case",
        "break",
        "continue"
    };

    int total_keywords =
        sizeof(keywords) / sizeof(keywords[0]);

    /* STEP-1 : Compare token with each keyword */
    for(int i = 0; i < total_keywords; i++)
    {
        if(strcmp(token, keywords[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}
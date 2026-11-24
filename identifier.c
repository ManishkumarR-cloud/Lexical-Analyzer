/*
 * File        : identifier.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Validates identifiers.
 */

#include "lexer.h"

/*
 * Function     : is_identifier()
 * Description  : Checks whether token satisfies
 *                identifier naming rules.
 */
int is_identifier(char *token)
{
    /* STEP-1 : First character must be
       alphabet or underscore */
    if(!(isalpha(token[0]) || token[0] == '_'))
    {
        return 0;
    }

    /* STEP-2 : Remaining characters must be
       alphanumeric or underscore */
    for(int i = 1; token[i] != '\0'; i++)
    {
        if(!(isalnum(token[i]) || token[i] == '_'))
        {
            return 0;
        }
    }

    return 1;
}
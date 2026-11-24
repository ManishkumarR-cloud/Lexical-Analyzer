/*
 * File        : input.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Token classification engine.
 */

#include "lexer.h"

void process_file(FILE *fp)
{
    char token[MAX_TOKEN_LEN];

    printf("\n");
    printf("-------------------------------------------------\n");
    printf("%-20s %-20s\n",
           "LEXEME",
           "TOKEN TYPE");
    printf("-------------------------------------------------\n");

    /* STEP-1 : Read tokens */
    while(fscanf(fp, "%99s", token) != EOF)
    {
        /* STEP-2 : Check keyword */
        if(is_keyword(token))
        {
            printf("%-20s KEYWORD\n", token);
        }

        /* STEP-3 : Check identifier */
        else if(is_identifier(token))
        {
            printf("%-20s IDENTIFIER\n", token);
        }

        /* STEP-4 : Check integer constant */
        else if(is_integer_constant(token))
        {
            printf("%-20s INTEGER CONSTANT\n", token);
        }

        /* STEP-5 : Check float constant */
        else if(is_float_constant(token))
        {
            printf("%-20s FLOAT CONSTANT\n", token);
        }

        /* STEP-6 : Check operators */
        else if(is_operator(token))
        {
            printf("%-20s OPERATOR\n", token);
        }

        /* STEP-7 : Check symbols */
        else if(strlen(token) == 1 &&
                is_symbol(token[0]))
        {
            printf("%-20s SYMBOL\n", token);
        }
    }

    printf("-------------------------------------------------\n");
}
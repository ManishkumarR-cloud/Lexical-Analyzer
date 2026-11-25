/*
 * File        : error.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Handles invalid token reporting.
 */

#include "lexer.h"

void report_invalid_token(char *token)
{
    printf("ERROR : Invalid Token -> %s\n", token);
}

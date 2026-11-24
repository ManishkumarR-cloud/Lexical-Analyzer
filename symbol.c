/*
 * File        : symbol.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Recognizes delimiters/symbols.
 */

#include "lexer.h"

int is_symbol(char ch)
{
    switch(ch)
    {
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
        case ';':
        case ',':
            return 1;

        default:
            return 0;
    }
}
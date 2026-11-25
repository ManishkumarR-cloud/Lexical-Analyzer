/*
 * File        : lexer.h
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Header file containing declarations,
 *               macros and function prototypes used
 *               throughout the project.
 */

#ifndef LEXER_H
#define LEXER_H

/*----------------------------------------------------------
 * Standard Header Files
 *---------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*----------------------------------------------------------
 * Macro Definitions
 *---------------------------------------------------------*/
#define MAX_TOKEN_LEN 100

/*----------------------------------------------------------
 * Validation Functions
 *---------------------------------------------------------*/
int validate_arguments(int argc, char *argv[]);
int validate_file_extension(char *filename);

/*----------------------------------------------------------
 * Keyword & Identifier Functions
 *---------------------------------------------------------*/
int is_keyword(char *token);
int is_identifier(char *token);

/*----------------------------------------------------------
 * Constant Recognition Functions
 *---------------------------------------------------------*/
int is_integer_constant(char *token);
int is_float_constant(char *token);

/*----------------------------------------------------------
 * Operator Recognition Functions
 *---------------------------------------------------------*/
int is_operator(char *token);

/*----------------------------------------------------------
 * Symbol Recognition Functions
 *---------------------------------------------------------*/
int is_symbol(char ch);

/*----------------------------------------------------------
 * Error Handling Functions
 *---------------------------------------------------------*/
void report_invalid_token(char *token);

/*----------------------------------------------------------
 * Symbol Table Functions
 *---------------------------------------------------------*/
void add_to_symbol_table(char *identifier);
void display_symbol_table(void);

/*----------------------------------------------------------
 * Statistics Functions
 *---------------------------------------------------------*/
void display_statistics(void);

/*----------------------------------------------------------
 * File Processing Functions
 *---------------------------------------------------------*/
void process_file(FILE *fp);

#endif /* LEXER_H */
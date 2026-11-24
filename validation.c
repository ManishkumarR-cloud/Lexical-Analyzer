/*
 * File        : validation.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Performs command line argument
 *               validation and file extension checking.
 */

#include "lexer.h"

/*
 * Function     : validate_file_extension()
 * Description  : Checks whether user provided
 *                file is a '.c' file.
 * Return Value :
 *      1 -> Valid
 *      0 -> Invalid
 */
int validate_file_extension(char *filename)
{
    /* STEP-1 : Find last occurrence of '.' */
    char *extension = strrchr(filename, '.');

    /* STEP-2 : Check whether extension exists */
    if(extension == NULL)
    {
        return 0;
    }

    /* STEP-3 : Compare extension with ".c" */
    if(strcmp(extension, ".c") == 0)
    {
        return 1;
    }

    return 0;
}

/*
 * Function     : validate_arguments()
 * Description  : Validates command line arguments.
 */
int validate_arguments(int argc, char *argv[])
{
    /* STEP-1 : Verify number of arguments */
    if(argc != 2)
    {
        printf("Usage : ./lexer <source_file.c>\n");
        return 0;
    }

    /* STEP-2 : Validate file extension */
    if(validate_file_extension(argv[1]) == 0)
    {
        printf("Error : Only .c files are supported\n");
        return 0;
    }

    return 1;
}
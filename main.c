/*
 * File        : main.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Entry point of the lexical analyzer.
 */

#include "lexer.h"

int main(int argc, char *argv[])
{
    FILE *fp;

    /* STEP-1 : Validate command line arguments */
    if(validate_arguments(argc, argv) == 0)
    {
        return 1;
    }

    /* STEP-2 : Open source file */
    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Error : Unable to open file %s\n",
               argv[1]);
        return 1;
    }

    printf("\nSource File : %s\n", argv[1]);

    /* STEP-3 : Process source file */
    process_file(fp);

    /* STEP-4 : Close file */
    fclose(fp);

    return 0;
}
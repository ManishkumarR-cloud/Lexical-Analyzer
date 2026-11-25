/*
 * File        : input.c
 * Author      : Manish Kumar R
 * Project     : Lexical Analyzer
 * Description : Character-by-character lexical analyzer.
 */

#include "lexer.h"

/* Statistics Counters */
int keyword_count = 0;
int identifier_count = 0;
int integer_count = 0;
int float_count = 0;
int operator_count = 0;
int symbol_count = 0;

/* Line Number */
int line_number = 1;

/* Symbol Table */
char symbol_table[100][50];
int symbol_table_count = 0;


/*-----------------------------------------------------------*/
/* Add identifier to symbol table                            */
/*-----------------------------------------------------------*/
void add_to_symbol_table(char *identifier)
{
    int i;

    for(i = 0; i < symbol_table_count; i++)
    {
        if(strcmp(symbol_table[i], identifier) == 0)
        {
            return;
        }
    }

    strcpy(symbol_table[symbol_table_count++],
           identifier);
}


/*-----------------------------------------------------------*/
/* Display Symbol Table                                      */
/*-----------------------------------------------------------*/
void display_symbol_table(void)
{
    int i;

    printf("\n");
    printf("=================================\n");
    printf("         SYMBOL TABLE\n");
    printf("=================================\n");

    for(i = 0; i < symbol_table_count; i++)
    {
        printf("%2d --> %s\n",
               i + 1,
               symbol_table[i]);
    }
}


/*-----------------------------------------------------------*/
/* Display Statistics                                        */
/*-----------------------------------------------------------*/
void display_statistics(void)
{
    printf("\n");
    printf("=================================\n");
    printf("      TOKEN STATISTICS\n");
    printf("=================================\n");

    printf("Keywords     : %d\n", keyword_count);
    printf("Identifiers  : %d\n", identifier_count);
    printf("Integers     : %d\n", integer_count);
    printf("Floats       : %d\n", float_count);
    printf("Operators    : %d\n", operator_count);
    printf("Symbols      : %d\n", symbol_count);
}


/*-----------------------------------------------------------*/
/* Main Lexical Analyzer Function                            */
/*-----------------------------------------------------------*/
void process_file(FILE *fp)
{
    char ch;
    char token[MAX_TOKEN_LEN];
    int index;

    printf("\n");
    printf("====================================================\n");
    printf("LINE\tLEXEME\t\tTOKEN TYPE\n");
    printf("====================================================\n");

    while((ch = fgetc(fp)) != EOF)
    {
        /*---------------------------------------------*/
        /* Line Count                                  */
        /*---------------------------------------------*/
        if(ch == '\n')
        {
            line_number++;
            continue;
        }

        /*---------------------------------------------*/
        /* Skip Spaces                                 */
        /*---------------------------------------------*/
        if(isspace(ch))
        {
            continue;
        }

        /*---------------------------------------------*/
        /* Skip Preprocessor Directives                */
        /*---------------------------------------------*/
        if(ch == '#')
        {
            while((ch = fgetc(fp)) != EOF &&
                  ch != '\n');

            line_number++;
            continue;
        }

        /*---------------------------------------------*/
        /* Handle Comments                             */
        /*---------------------------------------------*/
        if(ch == '/')
        {
            char next = fgetc(fp);

            /* Single Line Comment */
            if(next == '/')
            {
                while((ch = fgetc(fp)) != EOF &&
                      ch != '\n');

                line_number++;
                continue;
            }

            /* Multi Line Comment */
            if(next == '*')
            {
                char prev = 0;

                while((ch = fgetc(fp)) != EOF)
                {
                    if(ch == '\n')
                    {
                        line_number++;
                    }

                    if(prev == '*' &&
                       ch == '/')
                    {
                        break;
                    }

                    prev = ch;
                }

                continue;
            }

            ungetc(next, fp);
        }

        /*---------------------------------------------*/
        /* Keywords / Identifiers                      */
        /*---------------------------------------------*/
        if(isalpha(ch) || ch == '_')
        {
            index = 0;

            token[index++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isalnum(ch) || ch == '_'))
            {
                token[index++] = ch;
            }

            token[index] = '\0';

            if(ch != EOF)
            {
                ungetc(ch, fp);
            }

            if(is_keyword(token))
            {
                keyword_count++;

                printf("%d\t%-15s KEYWORD\n",
                       line_number,
                       token);
            }
            else
            {
                identifier_count++;

                add_to_symbol_table(token);

                printf("%d\t%-15s IDENTIFIER\n",
                       line_number,
                       token);
            }
        }

        /*---------------------------------------------*/
        /* Integer & Float Constants                   */
        /*---------------------------------------------*/
        else if(isdigit(ch))
        {
            index = 0;

            token[index++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isdigit(ch) || ch == '.'))
            {
                token[index++] = ch;
            }

            token[index] = '\0';

            if(ch != EOF)
            {
                ungetc(ch, fp);
            }

            if(is_float_constant(token))
            {
                float_count++;

                printf("%d\t%-15s FLOAT CONSTANT\n",
                       line_number,
                       token);
            }
            else
            {
                integer_count++;

                printf("%d\t%-15s INTEGER CONSTANT\n",
                       line_number,
                       token);
            }
        }

        /*---------------------------------------------*/
        /* Symbols                                     */
        /*---------------------------------------------*/
        else if(is_symbol(ch))
        {
            symbol_count++;

            printf("%d\t%c\t\tSYMBOL\n",
                   line_number,
                   ch);
        }

        /*---------------------------------------------*/
        /* Operators & Compound Operators              */
        /*---------------------------------------------*/
        else if(ch == '+' || ch == '-' ||
                ch == '=' || ch == '!' ||
                ch == '<' || ch == '>' ||
                ch == '&' || ch == '|' ||
                ch == '*' || ch == '/')
        {
            char next = fgetc(fp);
            char op[3];

            op[0] = ch;

            if((ch == '+' && next == '+') ||
               (ch == '-' && next == '-') ||
               (ch == '=' && next == '=') ||
               (ch == '!' && next == '=') ||
               (ch == '<' && next == '=') ||
               (ch == '>' && next == '=') ||
               (ch == '&' && next == '&') ||
               (ch == '|' && next == '|'))
            {
                op[1] = next;
                op[2] = '\0';
            }
            else
            {
                op[1] = '\0';

                if(next != EOF)
                {
                    ungetc(next, fp);
                }
            }

            operator_count++;

            printf("%d\t%-15s OPERATOR\n",
                   line_number,
                   op);
        }

        /*---------------------------------------------*/
        /* Invalid Token                               */
        /*---------------------------------------------*/
        else
        {
            char invalid[2];

            invalid[0] = ch;
            invalid[1] = '\0';

            report_invalid_token(invalid);
        }
    }

    display_symbol_table();

    display_statistics();
}
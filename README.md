Lexical Analyzer in C
Overview
A comprehensive Lexical Analyzer implemented in C that performs the first phase of compiler design by scanning C source code and converting it into meaningful tokens.

The analyzer reads a source file character-by-character, identifies lexemes, classifies them into appropriate token categories, generates a symbol table, tracks token statistics, and reports lexical errors.

Features
Token Recognition
Keywords
Identifiers
Integer Constants
Floating Point Constants
Operators
Compound Operators
Symbols / Delimiters
Comment Handling
Single-line comments
Multi-line comments
Additional Features
Character-by-character scanning using fgetc()
Preprocessor directive handling
Symbol table generation
Token statistics generation
Invalid token detection
Line number tracking
Command-line validation
File extension validation
File existence validation
Project Structure
Lexical_Analyzer/
│
├── main.c
├── lexer.h
├── validation.c
├── keyword.c
├── identifier.c
├── constant.c
├── operator.c
├── symbol.c
├── input.c
├── error.c
├── test.c
├── README.md
└── .gitignore
Compilation
gcc main.c validation.c keyword.c identifier.c constant.c operator.c symbol.c input.c error.c -o lexer
Execution
./lexer test.c
Technologies Used
C Programming
GCC Compiler
File Handling
Character Processing
String Processing
Compiler Design Concepts
Author
Manish Kumar R

GitHub: https://github.com/ManishkumarR-cloud

LinkedIn: https://www.linkedin.com/in/manishkumar-r
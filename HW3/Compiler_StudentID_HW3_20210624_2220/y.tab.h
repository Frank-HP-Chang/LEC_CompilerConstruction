/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOL = 258,
    STRING = 259,
    INT = 260,
    FLOAT = 261,
    ENDL = 262,
    SEMICOLON = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LEQ = 267,
    EQL = 268,
    NEQ = 269,
    ADD_ASSIGN = 270,
    SUB_ASSIGN = 271,
    MUL_ASSIGN = 272,
    QUO_ASSIGN = 273,
    REM_ASSIGN = 274,
    LAND = 275,
    LOR = 276,
    NEWLINE = 277,
    PRINT = 278,
    PRINTLN = 279,
    IF = 280,
    ELSE = 281,
    FOR = 282,
    WHILE = 283,
    TRUE = 284,
    FALSE = 285,
    INT_LIT = 286,
    FLOAT_LIT = 287,
    STRING_LIT = 288,
    IDENT = 289
  };
#endif
/* Tokens.  */
#define BOOL 258
#define STRING 259
#define INT 260
#define FLOAT 261
#define ENDL 262
#define SEMICOLON 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LEQ 267
#define EQL 268
#define NEQ 269
#define ADD_ASSIGN 270
#define SUB_ASSIGN 271
#define MUL_ASSIGN 272
#define QUO_ASSIGN 273
#define REM_ASSIGN 274
#define LAND 275
#define LOR 276
#define NEWLINE 277
#define PRINT 278
#define PRINTLN 279
#define IF 280
#define ELSE 281
#define FOR 282
#define WHILE 283
#define TRUE 284
#define FALSE 285
#define INT_LIT 286
#define FLOAT_LIT 287
#define STRING_LIT 288
#define IDENT 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 79 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *id_val;
    char *s_val;
    
    /* ... */

#line 131 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

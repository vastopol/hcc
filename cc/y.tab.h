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
    LO = 258,
    FUNCTION = 259,
    BEGINPARAMS = 260,
    ENDPARAMS = 261,
    BEGINLOCALS = 262,
    ENDLOCALS = 263,
    BEGINBODY = 264,
    ENDBODY = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    BEGINLOOP = 273,
    ENDLOOP = 274,
    DO = 275,
    READ = 276,
    WRITE = 277,
    CONTINUE = 278,
    RETURN = 279,
    INTEGER = 280,
    NUMBER = 281,
    ID = 282,
    TRUE = 283,
    FALSE = 284,
    ASSIGN = 285,
    OR = 286,
    AND = 287,
    NOT = 288,
    NE = 289,
    EQ = 290,
    LE = 291,
    GE = 292,
    HI = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "compiler.y" /* yacc.c:1909  */


// TERMINALS
// declarations of union members for lexical values of tokens
int        junk;         // for one-of-a-kind lexical values
int	     int_val;      // values of integer literals, i.e., NUMBER
string*    ident;        // points to identifers' actual lexemes

// NONTERMINALS
// declarations of union members lexical values of non-terminals,
// which are pointers to translation records
string*    code;         // for all nonterminals.


#line 108 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

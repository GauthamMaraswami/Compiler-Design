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
    ID = 258,
    NUM = 259,
    dtype = 260,
    assop = 261,
    sumop = 262,
    mulop = 263,
    unary = 264,
    logicalopbin = 265,
    logicalnot = 266,
    relop = 267,
    ifstmt = 268,
    elsestmt = 269,
    whilestmt = 270,
    charcnst = 271,
    badcharcnst = 272,
    floatcnst = 273,
    stringcnst = 274,
    breakval = 275,
    returnval = 276,
    switchval = 277,
    casestmt = 278,
    structs = 279,
    unions = 280,
    defaultstmt = 281
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define dtype 260
#define assop 261
#define sumop 262
#define mulop 263
#define unary 264
#define logicalopbin 265
#define logicalnot 266
#define relop 267
#define ifstmt 268
#define elsestmt 269
#define whilestmt 270
#define charcnst 271
#define badcharcnst 272
#define floatcnst 273
#define stringcnst 274
#define breakval 275
#define returnval 276
#define switchval 277
#define casestmt 278
#define structs 279
#define unions 280
#define defaultstmt 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 2 "parser.y" /* yacc.c:1909  */

	int ival;
	float fval;
	char cval;
  	char sval[100];
	struct var{
			char val[10];
			int type;
	}expressionvar;

#line 117 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

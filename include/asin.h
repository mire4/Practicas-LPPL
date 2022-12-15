/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    IF_ = 258,
    ELSE_ = 259,
    FOR_ = 260,
    RETURN_ = 261,
    ASIG_ = 262,
    OPIGUALDAD_ = 263,
    OPDESIGUALDAD_ = 264,
    OPMAYOR_ = 265,
    OPMENOR_ = 266,
    OPMAYORIGUAL_ = 267,
    OPMENORIGUAL_ = 268,
    OPMAS_ = 269,
    OPMENOS_ = 270,
    OPMUL_ = 271,
    OPDIV_ = 272,
    OPAND_ = 273,
    OPOR_ = 274,
    OPNEGACION_ = 275,
    APAR_ = 276,
    CPAR_ = 277,
    ALLAVE_ = 278,
    CLLAVE_ = 279,
    ACOR_ = 280,
    CCOR_ = 281,
    COMA_ = 282,
    PCOMA_ = 283,
    TRUE_ = 284,
    FALSE_ = 285,
    INT_ = 286,
    BOOL_ = 287,
    READ_ = 288,
    PRINT_ = 289,
    CTE_ = 290,
    ID_ = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "src/asin.y"

  int cent;
  char *ident;
  PF pf;

#line 100 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */

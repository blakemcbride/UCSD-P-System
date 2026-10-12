/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_TEST_LONG_INTEGER_GRAMMAR_YACC_H_INCLUDED
# define YY_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_TEST_LONG_INTEGER_GRAMMAR_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef GRAMMAR_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define GRAMMAR_DEBUG 1
#  else
#   define GRAMMAR_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define GRAMMAR_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined GRAMMAR_DEBUG */
#if GRAMMAR_DEBUG
extern int grammar_debug;
#endif

/* Token kinds.  */
#ifndef GRAMMAR_TOKENTYPE
# define GRAMMAR_TOKENTYPE
  enum grammar_tokentype
  {
    GRAMMAR_EMPTY = -2,
    GRAMMAR_EOF = 0,               /* "end of file"  */
    GRAMMAR_error = 256,           /* error  */
    GRAMMAR_UNDEF = 257,           /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    AT = 259,                      /* AT  */
    EOLN = 260,                    /* EOLN  */
    JUNK = 261,                    /* JUNK  */
    LP = 262,                      /* LP  */
    MINUS = 263,                   /* MINUS  */
    NOT = 264,                     /* NOT  */
    NUMBER = 265,                  /* NUMBER  */
    PERCENT = 266,                 /* PERCENT  */
    PLUS = 267,                    /* PLUS  */
    RP = 268,                      /* RP  */
    SLASH = 269,                   /* SLASH  */
    STAR = 270,                    /* STAR  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    LT = 273,                      /* LT  */
    LE = 274,                      /* LE  */
    GT = 275,                      /* GT  */
    GE = 276,                      /* GE  */
    unary = 277                    /* unary  */
  };
  typedef enum grammar_tokentype grammar_token_kind_t;
#endif

/* Value type.  */
#if ! defined GRAMMAR_STYPE && ! defined GRAMMAR_STYPE_IS_DECLARED
union GRAMMAR_STYPE
{
#line 55 "subprojects/ucsd-psystem-xc/test_long_integer/grammar.y"

    long_integer *lv_number;

#line 98 "subprojects/ucsd-psystem-xc/test_long_integer/grammar.yacc.h"

};
typedef union GRAMMAR_STYPE GRAMMAR_STYPE;
# define GRAMMAR_STYPE_IS_TRIVIAL 1
# define GRAMMAR_STYPE_IS_DECLARED 1
#endif


extern GRAMMAR_STYPE grammar_lval;


int grammar_parse (void);


#endif /* !YY_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_TEST_LONG_INTEGER_GRAMMAR_YACC_H_INCLUDED  */

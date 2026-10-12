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

#ifndef YY_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_UCSDPSYS_ASSEMBLE_GRAMMAR_YACC_H_INCLUDED
# define YY_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_UCSDPSYS_ASSEMBLE_GRAMMAR_YACC_H_INCLUDED
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
    AND_AND = 258,                 /* AND_AND  */
    ASSIGN = 259,                  /* ASSIGN  */
    AT = 260,                      /* AT  */
    BIT_AND = 261,                 /* BIT_AND  */
    BIT_OR = 262,                  /* BIT_OR  */
    CARAT = 263,                   /* CARAT  */
    COLON = 264,                   /* COLON  */
    COMMA = 265,                   /* COMMA  */
    DIV = 266,                     /* DIV  */
    DOLLAR = 267,                  /* DOLLAR  */
    DOT_ELSE = 268,                /* DOT_ELSE  */
    DOT_END = 269,                 /* DOT_END  */
    DOT_ENDC = 270,                /* DOT_ENDC  */
    DOT_EQU = 271,                 /* DOT_EQU  */
    DOT_FUNC = 272,                /* DOT_FUNC  */
    DOT_IF = 273,                  /* DOT_IF  */
    DOT_MACRO = 274,               /* DOT_MACRO  */
    DOT_PROC = 275,                /* DOT_PROC  */
    EOLN = 276,                    /* EOLN  */
    EQ = 277,                      /* EQ  */
    GE = 278,                      /* GE  */
    GT = 279,                      /* GT  */
    HASH = 280,                    /* HASH  */
    INTEGER_CONSTANT = 281,        /* INTEGER_CONSTANT  */
    JUNK = 282,                    /* JUNK  */
    LB = 283,                      /* LB  */
    LBRACE = 284,                  /* LBRACE  */
    LE = 285,                      /* LE  */
    LGROUP = 286,                  /* LGROUP  */
    LP = 287,                      /* LP  */
    LT = 288,                      /* LT  */
    MINUS = 289,                   /* MINUS  */
    MOD = 290,                     /* MOD  */
    NAME = 291,                    /* NAME  */
    NE = 292,                      /* NE  */
    NOT = 293,                     /* NOT  */
    OPCODE = 294,                  /* OPCODE  */
    OPCODE_6502 = 295,             /* OPCODE_6502  */
    OPCODE_PRELUDE = 296,          /* OPCODE_PRELUDE  */
    OPCODE_NAME_LIST = 297,        /* OPCODE_NAME_LIST  */
    OR_OR = 298,                   /* OR_OR  */
    PLUS = 299,                    /* PLUS  */
    QUESTION_MARK = 300,           /* QUESTION_MARK  */
    RB = 301,                      /* RB  */
    RBRACE = 302,                  /* RBRACE  */
    REAL_CONSTANT = 303,           /* REAL_CONSTANT  */
    RGROUP = 304,                  /* RGROUP  */
    RP = 305,                      /* RP  */
    SHIFT_LEFT = 306,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 307,             /* SHIFT_RIGHT  */
    SPECIAL = 308,                 /* SPECIAL  */
    STAR = 309,                    /* STAR  */
    STRING_CONSTANT = 310,         /* STRING_CONSTANT  */
    TILDE = 311,                   /* TILDE  */
    unary = 312,                   /* unary  */
    PLUS_PLUS = 313,               /* PLUS_PLUS  */
    MINUS_MINUS = 314,             /* MINUS_MINUS  */
    highest_precedence = 315       /* highest_precedence  */
  };
  typedef enum grammar_tokentype grammar_token_kind_t;
#endif

/* Value type.  */
#if ! defined GRAMMAR_STYPE && ! defined GRAMMAR_STYPE_IS_DECLARED
union GRAMMAR_STYPE
{
#line 154 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"

    opcode::pointer *lv_opcode;
    int lv_integer;
    expression::pointer *lv_expression;
    expression_list *lv_expression_list;
    rcstring *lv_string;
    double lv_real;
    variable_name *lv_variable_name;

#line 142 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.h"

};
typedef union GRAMMAR_STYPE GRAMMAR_STYPE;
# define GRAMMAR_STYPE_IS_TRIVIAL 1
# define GRAMMAR_STYPE_IS_DECLARED 1
#endif


extern GRAMMAR_STYPE grammar_lval;


int grammar_parse (void);


#endif /* !YY_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_UCSDPSYS_ASSEMBLE_GRAMMAR_YACC_H_INCLUDED  */

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

#ifndef YY_PASCAL_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_LIB_PASCAL_GRAMMAR_YACC_H_INCLUDED
# define YY_PASCAL_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_LIB_PASCAL_GRAMMAR_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef PASCAL_GRAMMAR_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PASCAL_GRAMMAR_DEBUG 1
#  else
#   define PASCAL_GRAMMAR_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PASCAL_GRAMMAR_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PASCAL_GRAMMAR_DEBUG */
#if PASCAL_GRAMMAR_DEBUG
extern int pascal_grammar_debug;
#endif

/* Token kinds.  */
#ifndef PASCAL_GRAMMAR_TOKENTYPE
# define PASCAL_GRAMMAR_TOKENTYPE
  enum pascal_grammar_tokentype
  {
    PASCAL_GRAMMAR_EMPTY = -2,
    END_OF_FILE = 0,               /* "end of file"  */
    PASCAL_GRAMMAR_error = 256,    /* error  */
    PASCAL_GRAMMAR_UNDEF = 257,    /* "invalid token"  */
    AND = 258,                     /* AND  */
    ARRAY = 259,                   /* ARRAY  */
    ARROW = 260,                   /* "->"  */
    ASSIGN = 261,                  /* ":="  */
    AT = 262,                      /* AT  */
    BEGIN = 263,                   /* BEGIN  */
    BITWISE_AND = 264,             /* BITWISE_AND  */
    BITWISE_NOT = 265,             /* BITWISE_NOT  */
    BITWISE_OR = 266,              /* BITWISE_OR  */
    CARAT = 267,                   /* "^"  */
    CASE = 268,                    /* CASE  */
    CODE_tok = 269,                /* "code"  */
    COLON = 270,                   /* ":"  */
    COMMA = 271,                   /* ","  */
    COMMENT = 272,                 /* COMMENT  */
    CONST = 273,                   /* CONST  */
    DATA_tok = 274,                /* "data"  */
    DIV = 275,                     /* DIV  */
    DO = 276,                      /* DO  */
    DOT = 277,                     /* "."  */
    DOWNTO = 278,                  /* DOWNTO  */
    ELIPSIS = 279,                 /* ".."  */
    ELSE = 280,                    /* ELSE  */
    END = 281,                     /* END  */
    EQ = 282,                      /* "="  */
    EXTERNAL = 283,                /* EXTERNAL  */
    FILE_tok = 284,                /* "file"  */
    FOR = 285,                     /* FOR  */
    FORWARD = 286,                 /* FORWARD  */
    FUNCTION = 287,                /* FUNCTION  */
    GE = 288,                      /* ">="  */
    GOTO = 289,                    /* GOTO  */
    GT = 290,                      /* ">"  */
    IF = 291,                      /* IF  */
    IMPLEMENTATION = 292,          /* IMPLEMENTATION  */
    IN = 293,                      /* IN  */
    INTEGER_CONSTANT = 294,        /* INTEGER_CONSTANT  */
    INTERFACE = 295,               /* INTERFACE  */
    INTRINSIC = 296,               /* INTRINSIC  */
    JUNK = 297,                    /* JUNK  */
    LABEL = 298,                   /* LABEL  */
    LB = 299,                      /* "["  */
    LE = 300,                      /* "<="  */
    LONG_INTEGER_CONSTANT = 301,   /* LONG_INTEGER_CONSTANT  */
    LP = 302,                      /* "("  */
    LT = 303,                      /* "<"  */
    MINUS = 304,                   /* "-"  */
    MOD = 305,                     /* MOD  */
    MUL = 306,                     /* "*"  */
    NAME = 307,                    /* NAME  */
    NE = 308,                      /* "<>"  */
    NOT = 309,                     /* NOT  */
    OF = 310,                      /* OF  */
    OR = 311,                      /* OR  */
    OTHERWISE = 312,               /* OTHERWISE  */
    PACKED = 313,                  /* PACKED  */
    PLUS = 314,                    /* "+"  */
    PROCEDURE = 315,               /* PROCEDURE  */
    PROGRAM = 316,                 /* PROGRAM  */
    QUESTION_MARK = 317,           /* "?"  */
    RB = 318,                      /* "]"  */
    REAL_CONSTANT = 319,           /* REAL_CONSTANT  */
    RECORD = 320,                  /* RECORD  */
    REPEAT = 321,                  /* REPEAT  */
    RP = 322,                      /* ")"  */
    SCAN = 323,                    /* SCAN  */
    SEGMENT = 324,                 /* SEGMENT  */
    SEMICOLON = 325,               /* ";"  */
    SEPARATE = 326,                /* SEPARATE  */
    SET = 327,                     /* SET  */
    SIZEOF_tok = 328,              /* "sizeof"  */
    SLASH = 329,                   /* "/"  */
    STRING_CONSTANT = 330,         /* STRING_CONSTANT  */
    THEN = 331,                    /* THEN  */
    TO = 332,                      /* TO  */
    TYPE = 333,                    /* TYPE  */
    TYPE_NAME = 334,               /* TYPE_NAME  */
    UNIT = 335,                    /* UNIT  */
    UNTIL = 336,                   /* UNTIL  */
    USES = 337,                    /* USES  */
    VAR = 338,                     /* VAR  */
    WHILE = 339,                   /* WHILE  */
    WITH = 340,                    /* WITH  */
    WRITE = 341,                   /* WRITE  */
    WRITELN = 342,                 /* WRITELN  */
    ternary = 343,                 /* ternary  */
    unary = 344,                   /* unary  */
    highest_prec = 345             /* highest_prec  */
  };
  typedef enum pascal_grammar_tokentype pascal_grammar_token_kind_t;
#endif

/* Value type.  */
#if ! defined PASCAL_GRAMMAR_STYPE && ! defined PASCAL_GRAMMAR_STYPE_IS_DECLARED
union PASCAL_GRAMMAR_STYPE
{
#line 160 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"

    bit_address *lv_bit_address;
    case_list *lv_case_list;
    case_range *lv_case_range;
    expression::pointer *lv_expression;
    expression_list *lv_expression_list;
    statement::pointer *lv_statement; // MUST be a pointer
    statement_list *lv_statement_list;
    rcstring *lv_string; // MUST be a pointer
    variable_name *lv_variable_name;
    variable_name_list *lv_variable_name_list;
    type::pointer *lv_type;
    type_record::pointer *lv_type_record;
    name_type *lv_name_type;
    name_type_list *lv_name_type_list;
    int lv_int;
    variant::pointer *lv_variant;
    type_list *lv_type_list;

#line 182 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.h"

};
typedef union PASCAL_GRAMMAR_STYPE PASCAL_GRAMMAR_STYPE;
# define PASCAL_GRAMMAR_STYPE_IS_TRIVIAL 1
# define PASCAL_GRAMMAR_STYPE_IS_DECLARED 1
#endif


extern PASCAL_GRAMMAR_STYPE pascal_grammar_lval;


int pascal_grammar_parse (void);


#endif /* !YY_PASCAL_GRAMMAR_SUBPROJECTS_UCSD_PSYSTEM_XC_LIB_PASCAL_GRAMMAR_YACC_H_INCLUDED  */

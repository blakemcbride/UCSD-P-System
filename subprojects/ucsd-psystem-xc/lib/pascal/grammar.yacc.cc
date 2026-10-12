/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PASCAL_GRAMMAR_STYPE
/* Substitute the variable and function names.  */
#define yyparse         pascal_grammar_parse
#define yylex           pascal_grammar_lex
#define yyerror         pascal_grammar_error
#define yydebug         pascal_grammar_debug
#define yynerrs         pascal_grammar_nerrs
#define yylval          pascal_grammar_lval
#define yychar          pascal_grammar_char

/* First part of user prologue.  */
#line 21 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"


#include <cassert>
#include <lib/ac/stdio.h>
#include <lib/ac/stdlib.h>

#include <lib/bit_address.h>
#include <lib/case/list.h>
#include <lib/case/range.h>
#include <lib/debug.h>
#include <lib/expression/list.h>
#include <lib/name_type.h>
#include <lib/name_type/list.h>
#include <lib/pascal/grammar.h>
#include <lib/pascal/lex.h>
#include <lib/rcstring/list.h>
#include <lib/statement.h>
#include <lib/statement/list.h>
#include <lib/translator.h>
#include <lib/type/anything.h>
#include <lib/type/boolean.h>
#include <lib/type/char.h>
#include <lib/type/error.h>
#include <lib/type/file.h>
#include <lib/type/integer.h>
#include <lib/type/list.h>
#include <lib/type/nothing.h>
#include <lib/type/pointer/unpacked.h>
#include <lib/type/real.h>
#include <lib/type/record.h>
#include <lib/type/reference/implicit.h>
#include <lib/type/string.h>
#include <lib/variable/name.h>
#include <lib/variable/name/list.h>
#include <lib/variant.h>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

#define YYFPRINTF pascal_lex_trace_print

static translator *context;


#line 124 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.yacc.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ARRAY = 4,                      /* ARRAY  */
  YYSYMBOL_ARROW = 5,                      /* "->"  */
  YYSYMBOL_ASSIGN = 6,                     /* ":="  */
  YYSYMBOL_AT = 7,                         /* AT  */
  YYSYMBOL_BEGIN = 8,                      /* BEGIN  */
  YYSYMBOL_BITWISE_AND = 9,                /* BITWISE_AND  */
  YYSYMBOL_BITWISE_NOT = 10,               /* BITWISE_NOT  */
  YYSYMBOL_BITWISE_OR = 11,                /* BITWISE_OR  */
  YYSYMBOL_CARAT = 12,                     /* "^"  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_CODE_tok = 14,                  /* "code"  */
  YYSYMBOL_COLON = 15,                     /* ":"  */
  YYSYMBOL_COMMA = 16,                     /* ","  */
  YYSYMBOL_COMMENT = 17,                   /* COMMENT  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_DATA_tok = 19,                  /* "data"  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_DOT = 22,                       /* "."  */
  YYSYMBOL_DOWNTO = 23,                    /* DOWNTO  */
  YYSYMBOL_ELIPSIS = 24,                   /* ".."  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_END = 26,                       /* END  */
  YYSYMBOL_EQ = 27,                        /* "="  */
  YYSYMBOL_EXTERNAL = 28,                  /* EXTERNAL  */
  YYSYMBOL_FILE_tok = 29,                  /* "file"  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_FORWARD = 31,                   /* FORWARD  */
  YYSYMBOL_FUNCTION = 32,                  /* FUNCTION  */
  YYSYMBOL_GE = 33,                        /* ">="  */
  YYSYMBOL_GOTO = 34,                      /* GOTO  */
  YYSYMBOL_GT = 35,                        /* ">"  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_IMPLEMENTATION = 37,            /* IMPLEMENTATION  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_INTEGER_CONSTANT = 39,          /* INTEGER_CONSTANT  */
  YYSYMBOL_INTERFACE = 40,                 /* INTERFACE  */
  YYSYMBOL_INTRINSIC = 41,                 /* INTRINSIC  */
  YYSYMBOL_JUNK = 42,                      /* JUNK  */
  YYSYMBOL_LABEL = 43,                     /* LABEL  */
  YYSYMBOL_LB = 44,                        /* "["  */
  YYSYMBOL_LE = 45,                        /* "<="  */
  YYSYMBOL_LONG_INTEGER_CONSTANT = 46,     /* LONG_INTEGER_CONSTANT  */
  YYSYMBOL_LP = 47,                        /* "("  */
  YYSYMBOL_LT = 48,                        /* "<"  */
  YYSYMBOL_MINUS = 49,                     /* "-"  */
  YYSYMBOL_MOD = 50,                       /* MOD  */
  YYSYMBOL_MUL = 51,                       /* "*"  */
  YYSYMBOL_NAME = 52,                      /* NAME  */
  YYSYMBOL_NE = 53,                        /* "<>"  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_OF = 55,                        /* OF  */
  YYSYMBOL_OR = 56,                        /* OR  */
  YYSYMBOL_OTHERWISE = 57,                 /* OTHERWISE  */
  YYSYMBOL_PACKED = 58,                    /* PACKED  */
  YYSYMBOL_PLUS = 59,                      /* "+"  */
  YYSYMBOL_PROCEDURE = 60,                 /* PROCEDURE  */
  YYSYMBOL_PROGRAM = 61,                   /* PROGRAM  */
  YYSYMBOL_QUESTION_MARK = 62,             /* "?"  */
  YYSYMBOL_RB = 63,                        /* "]"  */
  YYSYMBOL_REAL_CONSTANT = 64,             /* REAL_CONSTANT  */
  YYSYMBOL_RECORD = 65,                    /* RECORD  */
  YYSYMBOL_REPEAT = 66,                    /* REPEAT  */
  YYSYMBOL_RP = 67,                        /* ")"  */
  YYSYMBOL_SCAN = 68,                      /* SCAN  */
  YYSYMBOL_SEGMENT = 69,                   /* SEGMENT  */
  YYSYMBOL_SEMICOLON = 70,                 /* ";"  */
  YYSYMBOL_SEPARATE = 71,                  /* SEPARATE  */
  YYSYMBOL_SET = 72,                       /* SET  */
  YYSYMBOL_SIZEOF_tok = 73,                /* "sizeof"  */
  YYSYMBOL_SLASH = 74,                     /* "/"  */
  YYSYMBOL_STRING_CONSTANT = 75,           /* STRING_CONSTANT  */
  YYSYMBOL_THEN = 76,                      /* THEN  */
  YYSYMBOL_TO = 77,                        /* TO  */
  YYSYMBOL_TYPE = 78,                      /* TYPE  */
  YYSYMBOL_TYPE_NAME = 79,                 /* TYPE_NAME  */
  YYSYMBOL_UNIT = 80,                      /* UNIT  */
  YYSYMBOL_UNTIL = 81,                     /* UNTIL  */
  YYSYMBOL_USES = 82,                      /* USES  */
  YYSYMBOL_VAR = 83,                       /* VAR  */
  YYSYMBOL_WHILE = 84,                     /* WHILE  */
  YYSYMBOL_WITH = 85,                      /* WITH  */
  YYSYMBOL_WRITE = 86,                     /* WRITE  */
  YYSYMBOL_WRITELN = 87,                   /* WRITELN  */
  YYSYMBOL_ternary = 88,                   /* ternary  */
  YYSYMBOL_unary = 89,                     /* unary  */
  YYSYMBOL_highest_prec = 90,              /* highest_prec  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_pascal = 92,                    /* pascal  */
  YYSYMBOL_define_builtin_symbols = 93,    /* define_builtin_symbols  */
  YYSYMBOL_program = 94,                   /* program  */
  YYSYMBOL_scope_part = 95,                /* scope_part  */
  YYSYMBOL_program_scope_part = 96,        /* program_scope_part  */
  YYSYMBOL_scope_part_clauses = 97,        /* scope_part_clauses  */
  YYSYMBOL_program_scope_part_clauses = 98, /* program_scope_part_clauses  */
  YYSYMBOL_scope_part_clause = 99,         /* scope_part_clause  */
  YYSYMBOL_program_scope_part_clause = 100, /* program_scope_part_clause  */
  YYSYMBOL_const_clause = 101,             /* const_clause  */
  YYSYMBOL_constant_declaration = 102,     /* constant_declaration  */
  YYSYMBOL_label_clause = 103,             /* label_clause  */
  YYSYMBOL_label_names = 104,              /* label_names  */
  YYSYMBOL_label_name = 105,               /* label_name  */
  YYSYMBOL_type_clause = 106,              /* type_clause  */
  YYSYMBOL_type_eq = 107,                  /* type_eq  */
  YYSYMBOL_type_declaration = 108,         /* type_declaration  */
  YYSYMBOL_var_clause = 109,               /* var_clause  */
  YYSYMBOL_var_colon = 110,                /* var_colon  */
  YYSYMBOL_variable_declaration = 111,     /* variable_declaration  */
  YYSYMBOL_variable_names = 112,           /* variable_names  */
  YYSYMBOL_comma = 113,                    /* comma  */
  YYSYMBOL_variable_name = 114,            /* variable_name  */
  YYSYMBOL_simple_type = 115,              /* simple_type  */
  YYSYMBOL_simple_type_unbound = 116,      /* simple_type_unbound  */
  YYSYMBOL_complex_type = 117,             /* complex_type  */
  YYSYMBOL_complex_type_unbound = 118,     /* complex_type_unbound  */
  YYSYMBOL_array_begin = 119,              /* array_begin  */
  YYSYMBOL_array_dims = 120,               /* array_dims  */
  YYSYMBOL_enumerated_type = 121,          /* enumerated_type  */
  YYSYMBOL_enumerated_begin = 122,         /* enumerated_begin  */
  YYSYMBOL_enumerated_end = 123,           /* enumerated_end  */
  YYSYMBOL_enumerated_tags = 124,          /* enumerated_tags  */
  YYSYMBOL_enumerated_tag = 125,           /* enumerated_tag  */
  YYSYMBOL_elipsis = 126,                  /* elipsis  */
  YYSYMBOL_subrange_type = 127,            /* subrange_type  */
  YYSYMBOL_record_type = 128,              /* record_type  */
  YYSYMBOL_record_body = 129,              /* record_body  */
  YYSYMBOL_record_begin = 130,             /* record_begin  */
  YYSYMBOL_record_fields = 131,            /* record_fields  */
  YYSYMBOL_record_field = 132,             /* record_field  */
  YYSYMBOL_record_variant_part = 133,      /* record_variant_part  */
  YYSYMBOL_record_variant_cond = 134,      /* record_variant_cond  */
  YYSYMBOL_record_variants = 135,          /* record_variants  */
  YYSYMBOL_record_variant = 136,           /* record_variant  */
  YYSYMBOL_record_mark = 137,              /* record_mark  */
  YYSYMBOL_function = 138,                 /* function  */
  YYSYMBOL_function_prototype = 139,       /* function_prototype  */
  YYSYMBOL_function_introducer = 140,      /* function_introducer  */
  YYSYMBOL_segment = 141,                  /* segment  */
  YYSYMBOL_proc_proto_name = 142,          /* proc_proto_name  */
  YYSYMBOL_procedure_introducer = 143,     /* procedure_introducer  */
  YYSYMBOL_function_arguments = 144,       /* function_arguments  */
  YYSYMBOL_parameters = 145,               /* parameters  */
  YYSYMBOL_parameter = 146,                /* parameter  */
  YYSYMBOL_compound_statement = 147,       /* compound_statement  */
  YYSYMBOL_compound_begin = 148,           /* compound_begin  */
  YYSYMBOL_compound_end = 149,             /* compound_end  */
  YYSYMBOL_statement_list = 150,           /* statement_list  */
  YYSYMBOL_sl_statement = 151,             /* sl_statement  */
  YYSYMBOL_twrap_begin = 152,              /* twrap_begin  */
  YYSYMBOL_twrap_end = 153,                /* twrap_end  */
  YYSYMBOL_statement = 154,                /* statement  */
  YYSYMBOL_empty_statement = 155,          /* empty_statement  */
  YYSYMBOL_until_statement = 156,          /* until_statement  */
  YYSYMBOL_repeat_begin = 157,             /* repeat_begin  */
  YYSYMBOL_with_statement = 158,           /* with_statement  */
  YYSYMBOL_with_expression = 159,          /* with_expression  */
  YYSYMBOL_with_part = 160,                /* with_part  */
  YYSYMBOL_while_statement = 161,          /* while_statement  */
  YYSYMBOL_writeln_statement = 162,        /* writeln_statement  */
  YYSYMBOL_writeln_selector = 163,         /* writeln_selector  */
  YYSYMBOL_writeln_expression_list = 164,  /* writeln_expression_list  */
  YYSYMBOL_writeln_expression = 165,       /* writeln_expression  */
  YYSYMBOL_expression_statement = 166,     /* expression_statement  */
  YYSYMBOL_expression_list = 167,          /* expression_list  */
  YYSYMBOL_expression = 168,               /* expression  */
  YYSYMBOL_scan_op = 169,                  /* scan_op  */
  YYSYMBOL_set_expression_parts = 170,     /* set_expression_parts  */
  YYSYMBOL_set_expression_part = 171,      /* set_expression_part  */
  YYSYMBOL_if_statement = 172,             /* if_statement  */
  YYSYMBOL_optional_semicolon = 173,       /* optional_semicolon  */
  YYSYMBOL_uses_clause = 174,              /* uses_clause  */
  YYSYMBOL_uses_clause_begin = 175,        /* uses_clause_begin  */
  YYSYMBOL_uses_clause_interfaces = 176,   /* uses_clause_interfaces  */
  YYSYMBOL_uses_clause_interface = 177,    /* uses_clause_interface  */
  YYSYMBOL_uses_clause_interface_push = 178, /* uses_clause_interface_push  */
  YYSYMBOL_num = 179,                      /* num  */
  YYSYMBOL_uses_clause_interface_pop = 180, /* uses_clause_interface_pop  */
  YYSYMBOL_uses_clause_declarations = 181, /* uses_clause_declarations  */
  YYSYMBOL_uses_clause_declaration = 182,  /* uses_clause_declaration  */
  YYSYMBOL_for_statement = 183,            /* for_statement  */
  YYSYMBOL_for_dirn = 184,                 /* for_dirn  */
  YYSYMBOL_case_statement = 185,           /* case_statement  */
  YYSYMBOL_otherwise = 186,                /* otherwise  */
  YYSYMBOL_no_colon_here = 187,            /* no_colon_here  */
  YYSYMBOL_case_begin = 188,               /* case_begin  */
  YYSYMBOL_case_end = 189,                 /* case_end  */
  YYSYMBOL_case_item_list = 190,           /* case_item_list  */
  YYSYMBOL_case_item = 191,                /* case_item  */
  YYSYMBOL_case_expression = 192,          /* case_expression  */
  YYSYMBOL_case_range = 193,               /* case_range  */
  YYSYMBOL_label_statement = 194,          /* label_statement  */
  YYSYMBOL_label_name_colon = 195,         /* label_name_colon  */
  YYSYMBOL_goto_statement = 196,           /* goto_statement  */
  YYSYMBOL_var_statement = 197,            /* var_statement  */
  YYSYMBOL_unit = 198,                     /* unit  */
  YYSYMBOL_unit_common = 199,              /* unit_common  */
  YYSYMBOL_unit_name_and_segments = 200,   /* unit_name_and_segments  */
  YYSYMBOL_unit_separate = 201,            /* unit_separate  */
  YYSYMBOL_unit_name = 202,                /* unit_name  */
  YYSYMBOL_unit_segments = 203,            /* unit_segments  */
  YYSYMBOL_unit_code = 204,                /* unit_code  */
  YYSYMBOL_unit_data = 205,                /* unit_data  */
  YYSYMBOL_unit_interface = 206,           /* unit_interface  */
  YYSYMBOL_unit_interface_declarations = 207, /* unit_interface_declarations  */
  YYSYMBOL_unit_interface_declaration = 208, /* unit_interface_declaration  */
  YYSYMBOL_unit_implementation = 209,      /* unit_implementation  */
  YYSYMBOL_unit_implementation_declarations = 210, /* unit_implementation_declarations  */
  YYSYMBOL_unit_implementation_declaration = 211, /* unit_implementation_declaration  */
  YYSYMBOL_unit_init = 212,                /* unit_init  */
  YYSYMBOL_subunit_clause = 213,           /* subunit_clause  */
  YYSYMBOL_subunit_check = 214             /* subunit_check  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 262 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"


static void
print_token_int(FILE *fp, const YYSTYPE *yylval)
{
    YYFPRINTF(fp, "%d", yylval->lv_int);
}


static void
print_token_string(FILE *fp, const YYSTYPE *yylval)
{
    YYFPRINTF(fp, "%s", yylval->lv_string->quote_c().c_str());
}


#line 389 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined PASCAL_GRAMMAR_STYPE_IS_TRIVIAL && PASCAL_GRAMMAR_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1908

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  284
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   345


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if PASCAL_GRAMMAR_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   294,   294,   300,   310,   324,   332,   340,   355,   356,
     357,   362,   363,   364,   368,   369,   370,   371,   372,   376,
     377,   378,   379,   380,   381,   382,   386,   387,   391,   400,
     408,   414,   423,   430,   438,   448,   449,   453,   454,   456,
     461,   481,   482,   486,   487,   489,   494,   523,   529,   538,
     540,   544,   551,   561,   569,   576,   583,   585,   591,   598,
     604,   610,   616,   626,   635,   637,   643,   655,   661,   663,
     673,   679,   688,   694,   703,   709,   710,   714,   723,   724,
     736,   743,   769,   780,   786,   788,   790,   799,   804,   812,
     813,   817,   826,   834,   838,   852,   853,   854,   858,   870,
     875,   879,   883,   890,   904,   914,   920,   924,   938,   939,
     944,   946,   955,   964,   965,   970,   975,   981,   990,  1017,
    1026,  1036,  1042,  1051,  1056,  1061,  1067,  1073,  1086,  1088,
    1094,  1099,  1104,  1106,  1108,  1110,  1112,  1114,  1116,  1118,
    1120,  1122,  1124,  1126,  1132,  1139,  1156,  1161,  1166,  1174,
    1181,  1191,  1201,  1208,  1215,  1224,  1226,  1231,  1237,  1243,
    1250,  1256,  1264,  1276,  1285,  1291,  1297,  1302,  1304,  1311,
    1327,  1334,  1341,  1353,  1362,  1368,  1375,  1382,  1388,  1400,
    1407,  1414,  1422,  1430,  1437,  1444,  1450,  1461,  1475,  1483,
    1491,  1498,  1506,  1513,  1523,  1531,  1539,  1547,  1554,  1561,
    1568,  1575,  1582,  1589,  1597,  1602,  1604,  1614,  1627,  1629,
    1635,  1637,  1647,  1653,  1663,  1672,  1685,  1686,  1690,  1694,
    1702,  1703,  1713,  1724,  1729,  1737,  1742,  1750,  1755,  1756,
    1760,  1761,  1762,  1763,  1768,  1781,  1783,  1788,  1797,  1810,
    1817,  1818,  1826,  1835,  1840,  1842,  1851,  1862,  1877,  1886,
    1917,  1926,  1936,  1941,  1950,  1957,  1975,  1979,  1983,  1991,
    1992,  2018,  2026,  2027,  2028,  2032,  2041,  2050,  2056,  2057,
    2061,  2062,  2063,  2065,  2073,  2079,  2080,  2084,  2085,  2086,
    2087,  2091,  2096,  2100,  2108
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if PASCAL_GRAMMAR_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ARRAY",
  "\"->\"", "\":=\"", "AT", "BEGIN", "BITWISE_AND", "BITWISE_NOT",
  "BITWISE_OR", "\"^\"", "CASE", "\"code\"", "\":\"", "\",\"", "COMMENT",
  "CONST", "\"data\"", "DIV", "DO", "\".\"", "DOWNTO", "\"..\"", "ELSE",
  "END", "\"=\"", "EXTERNAL", "\"file\"", "FOR", "FORWARD", "FUNCTION",
  "\">=\"", "GOTO", "\">\"", "IF", "IMPLEMENTATION", "IN",
  "INTEGER_CONSTANT", "INTERFACE", "INTRINSIC", "JUNK", "LABEL", "\"[\"",
  "\"<=\"", "LONG_INTEGER_CONSTANT", "\"(\"", "\"<\"", "\"-\"", "MOD",
  "\"*\"", "NAME", "\"<>\"", "NOT", "OF", "OR", "OTHERWISE", "PACKED",
  "\"+\"", "PROCEDURE", "PROGRAM", "\"?\"", "\"]\"", "REAL_CONSTANT",
  "RECORD", "REPEAT", "\")\"", "SCAN", "SEGMENT", "\";\"", "SEPARATE",
  "SET", "\"sizeof\"", "\"/\"", "STRING_CONSTANT", "THEN", "TO", "TYPE",
  "TYPE_NAME", "UNIT", "UNTIL", "USES", "VAR", "WHILE", "WITH", "WRITE",
  "WRITELN", "ternary", "unary", "highest_prec", "$accept", "pascal",
  "define_builtin_symbols", "program", "scope_part", "program_scope_part",
  "scope_part_clauses", "program_scope_part_clauses", "scope_part_clause",
  "program_scope_part_clause", "const_clause", "constant_declaration",
  "label_clause", "label_names", "label_name", "type_clause", "type_eq",
  "type_declaration", "var_clause", "var_colon", "variable_declaration",
  "variable_names", "comma", "variable_name", "simple_type",
  "simple_type_unbound", "complex_type", "complex_type_unbound",
  "array_begin", "array_dims", "enumerated_type", "enumerated_begin",
  "enumerated_end", "enumerated_tags", "enumerated_tag", "elipsis",
  "subrange_type", "record_type", "record_body", "record_begin",
  "record_fields", "record_field", "record_variant_part",
  "record_variant_cond", "record_variants", "record_variant",
  "record_mark", "function", "function_prototype", "function_introducer",
  "segment", "proc_proto_name", "procedure_introducer",
  "function_arguments", "parameters", "parameter", "compound_statement",
  "compound_begin", "compound_end", "statement_list", "sl_statement",
  "twrap_begin", "twrap_end", "statement", "empty_statement",
  "until_statement", "repeat_begin", "with_statement", "with_expression",
  "with_part", "while_statement", "writeln_statement", "writeln_selector",
  "writeln_expression_list", "writeln_expression", "expression_statement",
  "expression_list", "expression", "scan_op", "set_expression_parts",
  "set_expression_part", "if_statement", "optional_semicolon",
  "uses_clause", "uses_clause_begin", "uses_clause_interfaces",
  "uses_clause_interface", "uses_clause_interface_push", "num",
  "uses_clause_interface_pop", "uses_clause_declarations",
  "uses_clause_declaration", "for_statement", "for_dirn", "case_statement",
  "otherwise", "no_colon_here", "case_begin", "case_end", "case_item_list",
  "case_item", "case_expression", "case_range", "label_statement",
  "label_name_colon", "goto_statement", "var_statement", "unit",
  "unit_common", "unit_name_and_segments", "unit_separate", "unit_name",
  "unit_segments", "unit_code", "unit_data", "unit_interface",
  "unit_interface_declarations", "unit_interface_declaration",
  "unit_implementation", "unit_implementation_declarations",
  "unit_implementation_declaration", "unit_init", "subunit_clause",
  "subunit_check", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-304)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-285)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,  -304,   127,   -31,  -304,  -304,    11,  -304,  -304,   134,
     126,    88,   132,   173,   240,   130,  -304,  -304,   183,   180,
     243,  -304,  -304,  -304,  -304,    68,   -17,  -304,    68,    68,
      68,  -304,    68,  -304,    68,    68,  -304,   198,   204,     7,
     204,  -304,    -3,  -304,  -304,  -304,   -31,  -304,    94,  -304,
      22,   196,   228,     5,  -304,  -304,  -304,   250,  -304,  -304,
    -304,    40,  -304,  -304,   250,    49,  -304,  -304,   237,  -304,
    -304,  -304,   203,   205,   210,   309,   102,     1,    83,    83,
       6,  -304,    68,  -304,    17,  -304,   386,  -304,   194,   211,
      68,    68,    68,  -304,  -304,   152,  -304,  -304,  -304,  -304,
    -304,   245,  -304,   215,  -304,  -304,  -304,  1810,  -304,  -304,
     -17,   437,  -304,    68,  -304,  -304,  -304,   437,  -304,  -304,
    -304,  -304,  -304,    68,  -304,    68,    68,  -304,  -304,  -304,
      68,    16,   166,  -304,   478,  -304,  -304,  -304,  -304,  -304,
     478,  -304,   175,   276,  -304,   206,  -304,  1810,  1810,  1810,
    1810,   -17,  1810,   271,  1662,  -304,  1810,  1810,  1810,   272,
    1810,  1810,  -304,  -304,  -304,   241,   246,  -304,  1810,  1810,
    -304,  -304,   281,  -304,  -304,  -304,  -304,   206,  -304,  -304,
    -304,   251,  -304,  1538,  -304,  -304,  -304,  1810,  -304,   386,
    -304,   252,  -304,  -304,  -304,    68,    68,    68,  -304,  -304,
    -304,  -304,  -304,  -304,   899,  -304,  -304,   437,   242,  1833,
      44,    13,   112,  -304,   257,   261,  -304,   244,   263,  -304,
      68,  -304,  -304,    14,   850,  -304,   249,  -304,   209,   478,
    -304,    63,   128,   254,  -304,   255,   437,  1810,  -304,   114,
     114,   948,  1587,  -304,   750,  -304,   850,    34,  -304,   999,
     114,   114,   114,   114,  1810,   478,  1048,   118,  -304,  1538,
    -304,  -304,    35,  1703,  1810,  1810,  -304,  1810,    68,  1810,
    1810,  1810,  1810,  1810,  1810,  1736,  1810,  1810,  1810,  1810,
    1810,  1810,  1810,  1810,  1810,  1538,   256,  -304,   289,   212,
    -304,   116,   162,  -304,  -304,   437,  -304,   260,  -304,   437,
    1810,  -304,   437,  -304,    10,  -304,  -304,   519,   222,   290,
     258,  -304,   259,  -304,  -304,  1810,  -304,   478,  -304,  -304,
    -304,  -304,  -304,  1538,  -304,  1810,   386,  1810,  -304,  1810,
    -304,  1097,   264,   801,   386,  1810,   386,  1810,  -304,    12,
    -304,  1146,   114,  1538,   114,  -304,  1644,  1644,  1644,  1644,
     618,  1195,  1644,  -304,   659,  1538,  1644,   716,   114,   114,
    1644,   716,   716,  1244,   114,  1777,   295,  1810,   386,  1810,
    -304,   116,   116,   304,    68,    68,    68,  -304,  -304,  -304,
    -304,   437,  -304,  1293,  -304,    90,  -304,    68,  -304,   317,
      93,   318,  -304,   280,   437,  -304,    21,  -304,  -304,  -304,
    1538,  -304,   573,   311,  1538,  -304,    -2,  -304,  -304,  -304,
    -304,  -304,  1538,  -304,  1810,  -304,  1810,  -304,  -304,  1810,
    -304,  -304,  1810,   322,   386,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,    25,   268,  -304,  -304,   437,   284,  -304,   478,
    1810,  -304,  -304,   259,  -304,  -304,  1810,   386,  -304,  -304,
    1810,  -304,  1342,  1538,  1630,  -304,  -304,   259,  -304,   332,
    -304,  -304,   437,  -304,   273,  -304,   700,  -304,  1391,  -304,
    1440,  1810,   295,  -304,  -304,  1810,   297,   386,  1810,  1538,
    -304,  -304,  -304,  -304,  1489,    14,  -304,   275,  -304
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,   259,    11,     3,     0,     1,   260,     0,
       0,     0,   262,     0,     0,     0,   256,   268,     0,     0,
       0,   258,     2,    13,   123,     0,     0,   109,     0,     0,
       0,    12,    19,    21,    23,    25,    20,     8,   113,     0,
     113,     7,   130,    24,   220,    22,   259,     5,   108,   275,
       0,     0,     0,     0,    51,    52,    26,     0,    34,    32,
      33,    50,    30,    35,     0,    50,    47,    41,    50,    27,
      36,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,   122,     0,   125,   144,   128,   218,     0,
     270,   271,   272,   273,   269,   108,   282,   281,   257,   261,
     265,     0,   263,     0,    38,    39,    37,     0,    49,    29,
       0,     0,   219,     0,    45,    43,    44,     0,   102,   101,
     100,    10,     9,    14,    16,    17,    18,    15,     6,   114,
       0,    50,     0,   116,     0,   104,   110,   111,   107,   112,
       0,   106,    50,    47,   127,   130,   121,     0,     0,     0,
       0,     0,     0,   168,     0,   169,     0,     0,     0,   172,
       0,     0,   173,   170,   146,     0,     0,   171,     0,     0,
     156,   155,     0,   133,   131,   134,   140,   130,   142,   141,
     143,   154,   135,   163,   138,   136,   132,     0,   139,   144,
     137,     0,   221,   228,   283,   277,   278,   279,   280,   276,
     266,   264,   168,   172,     0,    31,    69,     0,    60,    73,
     172,     0,   170,    87,     0,    54,    64,     0,     0,    67,
       0,    56,    65,     0,     0,    48,     0,    63,    50,     0,
     115,     0,     0,     0,    53,     0,     0,     0,   126,   186,
     187,     0,     0,   253,     0,   204,   212,    50,   210,     0,
     183,   178,   185,   184,     0,     0,     0,     0,   147,   148,
     252,   129,     0,     0,     0,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   216,   244,   248,     0,
     251,     0,   108,    28,    57,     0,    68,     0,    88,     0,
       0,    40,     0,    77,    50,    75,    86,     0,    50,     0,
     216,    89,   216,    79,    78,     0,    46,     0,   118,   117,
     103,   105,   254,   255,   242,     0,   144,     0,   205,     0,
     167,     0,     0,     0,   144,     0,   144,     0,   153,     0,
     157,   160,   192,   203,   189,   176,   197,   199,   200,   193,
       0,   164,   201,   182,     0,   164,   202,   195,   190,   188,
     198,   196,   194,     0,   191,   217,     0,     0,   144,     0,
     225,     0,     0,     0,   230,   231,   232,   233,   222,   229,
      59,     0,    61,     0,    70,     0,    74,     0,    72,   172,
      52,     0,    93,     0,     0,    82,   217,    83,   217,    85,
      80,   119,     0,   214,   213,   211,     0,   175,   174,   151,
     150,   149,   145,   159,     0,   152,     0,   166,   180,     0,
     179,   181,     0,   240,   144,   245,   243,   237,   249,   246,
     250,   226,     0,     0,    58,    55,     0,     0,    76,     0,
       0,    91,    90,   216,   236,   235,     0,   144,   208,   209,
       0,   158,   161,   165,   206,   241,   239,   216,   223,     0,
     227,    71,     0,    94,    92,    95,     0,    84,     0,   215,
       0,     0,     0,   224,    62,    96,     0,   144,     0,   162,
     238,    97,    99,   234,     0,     0,   207,     0,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,   344,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
     -46,   321,   274,  -304,   -21,   -38,   283,   323,   -37,  -304,
     324,   -29,   -60,    27,  -133,  -131,  -217,  -103,  -304,  -304,
    -304,  -304,  -304,  -304,   -32,   111,  -304,  -304,  -125,  -304,
    -304,   -35,   -34,  -304,  -304,  -112,  -304,    69,   -42,  -304,
    -304,   285,  -304,   325,  -304,   135,    58,  -304,   286,   191,
     226,  -304,  -304,  -185,  -304,  -304,  -304,  -304,  -304,    37,
    -304,  -304,  -304,  -304,   -41,  -304,  -229,   -66,  -304,  -304,
      46,  -304,  -298,  -304,  -304,  -304,  -304,  -304,  -303,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,   -96,  -304,
      18,    15,     8,  -304,  -304,  -304,  -304,  -304,   333,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     4,    74,    13,    75,    14,   122,    31,
      32,    69,    33,    61,   172,    34,   107,    70,    35,   117,
      71,    68,   113,    66,   233,   216,   226,   227,   218,   385,
     219,   220,   388,   304,   305,   315,   221,   222,   309,   223,
     310,   311,   312,   393,   464,   465,   485,    36,    37,    38,
      39,   138,    40,    77,   132,   133,   173,    42,    83,    84,
      85,    86,   261,   174,   175,   176,   177,   178,   257,   258,
     179,   180,   181,   339,   340,   182,   466,   224,   450,   247,
     248,   184,   366,    43,    44,    88,   192,   193,   372,   378,
     292,   379,   185,   446,   186,   424,   456,   187,   427,   286,
     287,   288,   289,   188,   189,   190,    87,     5,     9,    10,
      11,    12,    21,    53,   103,    18,    48,    94,    50,    95,
     199,    98,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,   110,    90,   234,   290,    62,    93,   235,   217,   234,
      91,    92,   397,   413,   399,   306,   134,   296,   144,   322,
     183,   140,    58,    81,   101,   448,   108,   307,   414,   123,
      24,   229,   108,   458,   307,    59,   144,   125,   126,    78,
       8,   204,   297,    81,   350,   -66,   354,   131,    96,   195,
     108,   449,    57,   142,     1,    64,   108,   196,   197,    57,
     -66,    64,    60,    15,   370,   108,    54,    79,   431,   432,
     -66,   135,    41,    54,   371,   102,   141,   386,   298,   415,
      82,   239,   240,   241,   242,   384,   244,   145,   246,   205,
     249,   250,   251,    55,   252,   253,   318,   328,   234,   -66,
      55,   228,   256,   259,   294,   145,   436,   -66,    97,   143,
     109,   -66,    25,   -81,   -66,    54,   337,    57,    64,   112,
      54,   285,   332,   183,   234,   -66,   266,     7,   -81,   459,
     243,  -267,   296,   128,   335,   136,   268,   300,   -81,   336,
     225,   403,    55,   249,   127,   467,   130,    55,   -54,   409,
      57,   411,    64,   437,    54,   370,    16,   297,   273,   472,
    -274,   275,   137,    27,   198,   371,    17,   -81,    19,   129,
      25,   323,    28,    20,   392,   -81,   234,    30,  -274,   -81,
      25,    55,   -81,   429,   401,   130,   234,   329,   331,   333,
     236,   108,   380,   -81,   308,    22,   382,   341,   342,   343,
      47,   344,   131,   346,   347,   348,   349,   351,   352,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   461,
      49,    27,    57,    64,   317,   108,    72,   368,   369,    73,
      28,    27,    51,   230,   383,    30,   231,   394,   108,   457,
      28,    23,   373,   114,   387,    30,   374,   303,    24,   400,
     377,    76,   115,   108,   375,   376,   104,    52,    25,   402,
     183,   404,   469,   246,   116,   105,    99,   100,   183,   259,
     183,   412,  -108,   118,   191,   119,  -120,   106,   434,  -120,
     120,   194,   237,    26,   200,   201,   -34,   -32,   254,    82,
     419,   441,   483,   255,   419,   345,   260,   295,   263,   285,
    -108,   285,   183,   285,   291,   300,   463,   302,   234,    27,
     121,  -284,   299,   367,   301,   381,   395,    24,    28,   316,
    -284,   426,    29,    30,   320,   321,   365,    25,   396,   398,
     433,   407,   -51,   439,   391,   440,   447,   455,   460,   462,
     473,  -108,   488,   475,   482,     6,    56,   111,   341,   124,
     452,    63,    26,   453,    67,   438,   454,   327,   183,   474,
     487,   442,   443,   481,   139,    80,   319,   308,   262,  -108,
     146,   238,   410,   451,   355,   405,   480,   430,    27,    89,
     468,   183,   428,   425,   470,     0,     0,    28,     0,     0,
       0,     0,    30,   147,    24,   148,     0,     0,     0,   149,
       0,    57,    64,     0,     0,   479,   419,     0,     0,   355,
       0,   183,   484,     0,   303,     0,   150,     0,     0,     0,
     151,     0,   152,     0,     0,   153,     0,     0,     0,     0,
     154,     0,   155,   156,     0,   157,     0,   158,   159,     0,
     160,   206,     0,     0,   147,   161,   148,   162,     0,   207,
     163,     0,   164,     0,   165,     0,   308,     0,     0,   166,
       0,   167,     0,     0,     0,    60,   208,     0,     0,     0,
     168,   169,   170,   171,     0,     0,   202,     0,     0,     0,
       0,   154,   206,   155,   209,   147,   157,   148,   158,   210,
     207,   160,     0,     0,     0,   211,   161,     0,   162,     0,
       0,   212,   213,     0,     0,   165,     0,   208,     0,   214,
     166,     0,   167,     0,     0,     0,   215,   202,     0,     0,
       0,     0,   154,   206,   155,   156,   147,   157,   148,   158,
     203,   207,   160,     0,     0,     0,   232,   161,     0,   162,
       0,     0,   212,     0,     0,     0,   165,     0,   208,     0,
     214,   166,     0,   167,     0,     0,     0,   215,   202,     0,
       0,     0,     0,   154,     0,   155,   156,     0,   157,     0,
     158,   389,     0,   160,     0,     0,   264,   232,   161,   265,
     162,     0,     0,   212,     0,   266,     0,   165,     0,     0,
       0,   214,   166,   267,   167,   268,   444,     0,   390,     0,
     269,     0,     0,     0,     0,     0,   270,     0,   271,     0,
       0,   272,     0,     0,     0,     0,     0,   273,   274,   417,
     275,   276,   277,   278,   279,   -50,   280,   -50,     0,   281,
       0,     0,   282,     0,   108,   283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
     445,     0,     0,     0,     0,     0,     0,   -50,     0,     0,
     417,     0,   -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,     0,   -50,     0,     0,   108,     0,   -50,     0,   -50,
       0,   418,   -50,     0,     0,     0,   -50,     0,     0,     0,
       0,   -50,     0,   -50,     0,     0,     0,     0,   -50,     0,
       0,   417,     0,   -50,     0,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,     0,   -50,     0,   476,   108,     0,   -50,   264,
     -50,     0,     0,   -50,     0,     0,   421,   -50,   266,     0,
       0,     0,   -50,     0,   -50,     0,   267,     0,   268,   -50,
       0,     0,     0,     0,   -50,     0,   -50,   -50,     0,   -50,
       0,   -50,   -50,   264,   -50,     0,   265,     0,     0,   -50,
     273,   -50,   266,   275,   -50,     0,   278,   279,   -50,     0,
     267,     0,   268,   -50,     0,   -50,     0,   269,     0,     0,
       0,     0,     0,   270,     0,   271,     0,     0,   272,     0,
     284,     0,     0,     0,   273,   274,     0,   275,   276,   277,
     278,   279,     0,   280,   264,     0,   281,   265,     0,   282,
       0,     0,   283,   266,     0,     0,   313,     0,     0,     0,
       0,   267,     0,   268,   284,   314,   326,     0,   269,     0,
       0,     0,     0,     0,   270,     0,   271,     0,     0,   272,
       0,     0,     0,     0,     0,   273,   274,     0,   275,   276,
     277,   278,   279,   264,   280,     0,   265,   281,     0,     0,
     282,     0,   266,   283,     0,   313,     0,     0,   408,     0,
     267,     0,   268,     0,   314,   284,     0,   269,     0,     0,
       0,     0,     0,   270,     0,   271,     0,     0,   272,     0,
       0,     0,     0,     0,   273,   274,     0,   275,   276,   277,
     278,   279,   264,   280,     0,   265,   281,     0,     0,   282,
       0,   266,   283,     0,     0,     0,     0,     0,     0,   267,
       0,   268,     0,     0,   284,     0,   269,     0,     0,     0,
       0,     0,   270,     0,   271,     0,     0,   272,     0,     0,
       0,     0,     0,   273,   274,     0,   275,   276,   277,   278,
     279,   264,   280,     0,   265,   281,     0,     0,   282,     0,
     266,   283,     0,     0,     0,     0,     0,     0,   267,   293,
     268,     0,     0,   284,     0,   269,     0,     0,     0,     0,
       0,   270,     0,   271,     0,     0,   272,     0,     0,     0,
       0,     0,   273,   274,     0,   275,   276,   277,   278,   279,
       0,   280,   264,   324,   281,   265,     0,   282,     0,     0,
     283,   266,     0,     0,     0,     0,     0,     0,     0,   267,
       0,   268,   284,     0,     0,     0,   269,     0,     0,     0,
       0,     0,   270,     0,   271,     0,     0,   272,     0,     0,
       0,     0,     0,   273,   274,     0,   275,   276,   277,   278,
     279,   264,   280,     0,   265,   281,     0,     0,   282,     0,
     266,   283,     0,     0,     0,     0,   330,     0,   267,   334,
     268,     0,     0,   284,     0,   269,     0,     0,     0,     0,
       0,   270,     0,   271,     0,     0,   272,     0,     0,     0,
       0,     0,   273,   274,     0,   275,   276,   277,   278,   279,
     264,   280,     0,   265,   281,     0,     0,   282,     0,   266,
     283,     0,     0,   406,     0,     0,     0,   267,     0,   268,
       0,     0,   284,     0,   269,     0,     0,     0,     0,     0,
     270,     0,   271,     0,     0,   272,     0,     0,     0,     0,
       0,   273,   274,     0,   275,   276,   277,   278,   279,   264,
     280,     0,   265,   281,     0,     0,   282,     0,   266,   283,
       0,   416,     0,     0,     0,     0,   267,     0,   268,     0,
       0,   284,     0,   269,     0,     0,     0,     0,     0,   270,
       0,   271,     0,     0,   272,     0,     0,     0,     0,     0,
     273,   274,     0,   275,   276,   277,   278,   279,   264,   280,
       0,   265,   281,     0,     0,   282,     0,   266,   283,     0,
       0,     0,     0,     0,     0,   267,     0,   268,     0,     0,
     284,     0,   269,     0,     0,     0,     0,     0,   270,     0,
     271,     0,     0,   272,     0,     0,     0,     0,     0,   273,
     274,     0,   275,   276,   277,   278,   279,   264,   280,     0,
     265,   281,     0,     0,   282,     0,   266,   283,   420,   422,
       0,     0,     0,     0,   267,     0,   268,     0,     0,   284,
       0,   269,     0,     0,     0,     0,     0,   270,     0,   271,
       0,     0,   272,     0,     0,     0,     0,     0,   273,   274,
       0,   275,   276,   277,   278,   279,   264,   280,     0,   265,
     281,     0,     0,   282,     0,   266,   283,     0,     0,     0,
       0,     0,     0,   267,     0,   268,     0,     0,   284,     0,
     269,     0,     0,     0,     0,     0,   270,     0,   271,     0,
       0,   272,     0,     0,     0,     0,     0,   273,   274,     0,
     275,   276,   277,   278,   279,   264,   280,     0,   265,   281,
       0,     0,   282,     0,   266,   283,   435,   471,     0,     0,
       0,     0,   267,     0,   268,     0,     0,   284,     0,   269,
       0,     0,     0,     0,     0,   270,     0,   271,     0,     0,
     272,     0,     0,     0,     0,     0,   273,   274,     0,   275,
     276,   277,   278,   279,   264,   280,     0,   265,   281,     0,
       0,   282,     0,   266,   283,     0,     0,     0,     0,     0,
       0,   267,   477,   268,     0,     0,   284,     0,   269,     0,
       0,     0,     0,     0,   270,     0,   271,     0,     0,   272,
       0,     0,     0,     0,     0,   273,   274,     0,   275,   276,
     277,   278,   279,   264,   280,     0,   265,   281,     0,     0,
     282,     0,   266,   283,     0,     0,   478,     0,     0,     0,
     267,     0,   268,     0,     0,   284,     0,   269,     0,     0,
       0,     0,     0,   270,     0,   271,     0,     0,   272,     0,
       0,     0,     0,     0,   273,   274,     0,   275,   276,   277,
     278,   279,   264,   280,     0,   265,   281,     0,     0,   282,
       0,   266,   283,     0,     0,     0,     0,     0,     0,   267,
       0,   268,     0,     0,   284,     0,   269,     0,     0,     0,
       0,     0,   270,     0,   271,     0,     0,   272,     0,     0,
       0,     0,     0,   273,   274,     0,   275,   276,   277,   278,
     279,   264,   280,     0,   265,   281,     0,     0,   282,     0,
     266,   283,     0,     0,     0,     0,   486,     0,   267,     0,
     268,     0,     0,   284,     0,   269,     0,     0,     0,     0,
       0,   270,     0,   271,     0,     0,   272,     0,     0,     0,
       0,     0,   273,   274,     0,   275,   276,   277,   278,   279,
     264,   280,     0,   325,   281,     0,     0,   282,     0,   266,
     283,     0,     0,     0,     0,     0,     0,   267,     0,   268,
       0,     0,   284,     0,   269,     0,     0,     0,     0,     0,
     270,     0,   271,     0,     0,   272,     0,     0,     0,     0,
       0,   273,   274,   264,   275,   276,   277,   278,   279,     0,
     280,     0,   266,   281,     0,     0,   282,   264,     0,   283,
     267,     0,   268,     0,     0,     0,   266,   269,     0,     0,
       0,   284,     0,   270,   267,   271,   268,     0,   272,   147,
       0,   148,     0,     0,   273,   274,     0,   275,   276,   277,
     278,   279,     0,   280,     0,     0,   281,     0,   273,   282,
       0,   275,   283,   277,   278,   279,     0,     0,     0,     0,
     281,   202,     0,   282,   284,     0,   154,     0,   155,   156,
     147,   157,   148,   158,   203,     0,   160,     0,   284,     0,
       0,   161,     0,   162,     0,   245,   163,     0,     0,     0,
     165,     0,     0,     0,     0,   166,     0,   167,     0,     0,
       0,     0,   202,   147,     0,   148,     0,   154,     0,   155,
     156,     0,   157,     0,   158,   203,     0,   160,     0,     0,
       0,     0,   161,     0,   162,     0,     0,   163,     0,     0,
     338,   165,     0,     0,     0,   202,   166,     0,   167,     0,
     154,     0,   155,   156,   147,   157,   148,   158,   203,     0,
     160,     0,     0,     0,     0,   161,     0,   162,     0,     0,
     163,     0,     0,   353,   165,     0,     0,     0,     0,   166,
       0,   167,     0,     0,     0,     0,   202,   147,     0,   148,
       0,   154,     0,   155,   156,     0,   157,     0,   158,   203,
       0,   160,     0,     0,   423,     0,   161,     0,   162,     0,
     147,   163,   148,     0,     0,   165,     0,     0,     0,   202,
     166,     0,   167,     0,   154,     0,   155,   156,     0,   157,
       0,   158,   203,     0,   160,     0,     0,     0,     0,   161,
       0,   162,   202,     0,   163,     0,     0,   154,   165,   155,
     156,     0,   157,   166,   158,   167,     0,   160,     0,     0,
       0,     0,   161,     0,   162,     0,     0,   163,     0,     0,
       0,   165,     0,     0,     0,     0,   166,     0,   167
};

static const yytype_int16 yycheck[] =
{
      29,    61,    48,   134,   189,    26,    48,   140,   111,   140,
      48,    48,   310,     1,   312,     1,    15,     4,     1,   236,
      86,    15,    39,    26,    19,    27,    16,    13,    16,    75,
       8,    15,    16,     8,    13,    52,     1,    75,    75,    32,
      71,   107,    29,    26,   273,     1,   275,    76,    26,    95,
      16,    53,    25,    82,    61,    28,    16,    95,    95,    32,
      16,    34,    79,    52,    39,    16,    52,    60,   371,   372,
      26,    70,    14,    52,    49,    70,    70,    67,    65,    67,
      83,   147,   148,   149,   150,   302,   152,    70,   154,   110,
     156,   157,   158,    79,   160,   161,   229,    63,   229,    55,
      79,   130,   168,   169,   207,    70,    16,    63,    50,    82,
      70,    67,    18,     1,    70,    52,    81,    90,    91,    70,
      52,   187,   255,   189,   255,    81,    12,     0,    16,   432,
     151,    37,     4,    75,    16,    52,    22,    44,    26,    21,
     113,   326,    79,   209,    75,   443,    83,    79,    55,   334,
     123,   336,   125,    63,    52,    39,    22,    29,    44,   457,
       8,    47,    79,    69,    95,    49,    40,    55,    80,    67,
      18,   237,    78,    41,   307,    63,   307,    83,    26,    67,
      18,    79,    70,   368,   317,    83,   317,   247,   254,   255,
      15,    16,   295,    81,   223,    22,   299,   263,   264,   265,
      70,   267,   231,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   436,
      37,    69,   195,   196,    15,    16,    28,    15,    16,    31,
      78,    69,    52,    67,   300,    83,    70,    15,    16,   424,
      78,     1,    80,     6,   304,    83,   292,   220,     8,   315,
     292,    47,    15,    16,   292,   292,     6,    14,    18,   325,
     326,   327,   447,   329,    27,    15,    70,    39,   334,   335,
     336,   337,    32,    70,    80,    70,    67,    27,   381,    70,
      70,    70,     6,    43,    39,    70,    15,    15,    47,    83,
     350,   394,   477,    47,   354,   268,    15,    55,    47,   365,
      60,   367,   368,   369,    52,    44,   439,    44,   439,    69,
       1,    71,    55,    24,    70,    55,    26,     8,    78,    70,
      80,    26,    82,    83,    70,    70,    70,    18,    70,    70,
      26,    67,    15,    15,   307,    55,    25,    15,    70,    55,
       8,    32,    67,    70,    47,     1,    25,    64,   414,    75,
     416,    28,    43,   419,    30,   387,   422,   246,   424,   462,
     485,   396,   396,   475,    79,    40,   231,   396,   177,    60,
      84,   145,   335,   414,   440,   329,   472,   369,    69,    46,
     446,   447,   367,   365,   450,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    83,     7,     8,     9,    -1,    -1,    -1,    13,
      -1,   374,   375,    -1,    -1,   471,   466,    -1,    -1,   475,
      -1,   477,   478,    -1,   387,    -1,    30,    -1,    -1,    -1,
      34,    -1,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    -1,    46,    47,    -1,    49,    -1,    51,    52,    -1,
      54,     4,    -1,    -1,     7,    59,     9,    61,    -1,    12,
      64,    -1,    66,    -1,    68,    -1,   485,    -1,    -1,    73,
      -1,    75,    -1,    -1,    -1,    79,    29,    -1,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    44,     4,    46,    47,     7,    49,     9,    51,    52,
      12,    54,    -1,    -1,    -1,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    -1,    68,    -1,    29,    -1,    72,
      73,    -1,    75,    -1,    -1,    -1,    79,    39,    -1,    -1,
      -1,    -1,    44,     4,    46,    47,     7,    49,     9,    51,
      52,    12,    54,    -1,    -1,    -1,    58,    59,    -1,    61,
      -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    29,    -1,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    39,    -1,
      -1,    -1,    -1,    44,    -1,    46,    47,    -1,    49,    -1,
      51,    52,    -1,    54,    -1,    -1,     3,    58,    59,     6,
      61,    -1,    -1,    64,    -1,    12,    -1,    68,    -1,    -1,
      -1,    72,    73,    20,    75,    22,    23,    -1,    79,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,     1,
      47,    48,    49,    50,    51,     7,    53,     9,    -1,    56,
      -1,    -1,    59,    -1,    16,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
       1,    -1,    44,    -1,    46,    47,     7,    49,     9,    51,
      52,    -1,    54,    -1,    -1,    16,    -1,    59,    -1,    61,
      -1,    63,    64,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    39,    -1,
      -1,     1,    -1,    44,    -1,    46,    47,     7,    49,     9,
      51,    52,    -1,    54,    -1,    15,    16,    -1,    59,     3,
      61,    -1,    -1,    64,    -1,    -1,    67,    68,    12,    -1,
      -1,    -1,    73,    -1,    75,    -1,    20,    -1,    22,    39,
      -1,    -1,    -1,    -1,    44,    -1,    46,    47,    -1,    49,
      -1,    51,    52,     3,    54,    -1,     6,    -1,    -1,    59,
      44,    61,    12,    47,    64,    -1,    50,    51,    68,    -1,
      20,    -1,    22,    73,    -1,    75,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,
      74,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    -1,    53,     3,    -1,    56,     6,    -1,    59,
      -1,    -1,    62,    12,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    20,    -1,    22,    74,    24,    76,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,     3,    53,    -1,     6,    56,    -1,    -1,
      59,    -1,    12,    62,    -1,    15,    -1,    -1,    67,    -1,
      20,    -1,    22,    -1,    24,    74,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,     3,    53,    -1,     6,    56,    -1,    -1,    59,
      -1,    12,    62,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    -1,    -1,    74,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,     3,    53,    -1,     6,    56,    -1,    -1,    59,    -1,
      12,    62,    -1,    -1,    -1,    -1,    -1,    -1,    20,    70,
      22,    -1,    -1,    74,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    48,    49,    50,    51,
      -1,    53,     3,    55,    56,     6,    -1,    59,    -1,    -1,
      62,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    74,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,     3,    53,    -1,     6,    56,    -1,    -1,    59,    -1,
      12,    62,    -1,    -1,    -1,    -1,    67,    -1,    20,    21,
      22,    -1,    -1,    74,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    48,    49,    50,    51,
       3,    53,    -1,     6,    56,    -1,    -1,    59,    -1,    12,
      62,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    74,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    51,     3,
      53,    -1,     6,    56,    -1,    -1,    59,    -1,    12,    62,
      -1,    15,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,
      -1,    74,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    48,    49,    50,    51,     3,    53,
      -1,     6,    56,    -1,    -1,    59,    -1,    12,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,
      74,    -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    48,    49,    50,    51,     3,    53,    -1,
       6,    56,    -1,    -1,    59,    -1,    12,    62,    63,    15,
      -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    74,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    48,    49,    50,    51,     3,    53,    -1,     6,
      56,    -1,    -1,    59,    -1,    12,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    74,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    48,    49,    50,    51,     3,    53,    -1,     6,    56,
      -1,    -1,    59,    -1,    12,    62,    63,    15,    -1,    -1,
      -1,    -1,    20,    -1,    22,    -1,    -1,    74,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      48,    49,    50,    51,     3,    53,    -1,     6,    56,    -1,
      -1,    59,    -1,    12,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    74,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,
      49,    50,    51,     3,    53,    -1,     6,    56,    -1,    -1,
      59,    -1,    12,    62,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    22,    -1,    -1,    74,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,     3,    53,    -1,     6,    56,    -1,    -1,    59,
      -1,    12,    62,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    -1,    -1,    74,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,    50,
      51,     3,    53,    -1,     6,    56,    -1,    -1,    59,    -1,
      12,    62,    -1,    -1,    -1,    -1,    67,    -1,    20,    -1,
      22,    -1,    -1,    74,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    48,    49,    50,    51,
       3,    53,    -1,     6,    56,    -1,    -1,    59,    -1,    12,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    74,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,     3,    47,    48,    49,    50,    51,    -1,
      53,    -1,    12,    56,    -1,    -1,    59,     3,    -1,    62,
      20,    -1,    22,    -1,    -1,    -1,    12,    27,    -1,    -1,
      -1,    74,    -1,    33,    20,    35,    22,    -1,    38,     7,
      -1,     9,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      50,    51,    -1,    53,    -1,    -1,    56,    -1,    44,    59,
      -1,    47,    62,    49,    50,    51,    -1,    -1,    -1,    -1,
      56,    39,    -1,    59,    74,    -1,    44,    -1,    46,    47,
       7,    49,     9,    51,    52,    -1,    54,    -1,    74,    -1,
      -1,    59,    -1,    61,    -1,    63,    64,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,    -1,
      -1,    -1,    39,     7,    -1,     9,    -1,    44,    -1,    46,
      47,    -1,    49,    -1,    51,    52,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    61,    -1,    -1,    64,    -1,    -1,
      67,    68,    -1,    -1,    -1,    39,    73,    -1,    75,    -1,
      44,    -1,    46,    47,     7,    49,     9,    51,    52,    -1,
      54,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    73,
      -1,    75,    -1,    -1,    -1,    -1,    39,     7,    -1,     9,
      -1,    44,    -1,    46,    47,    -1,    49,    -1,    51,    52,
      -1,    54,    -1,    -1,    57,    -1,    59,    -1,    61,    -1,
       7,    64,     9,    -1,    -1,    68,    -1,    -1,    -1,    39,
      73,    -1,    75,    -1,    44,    -1,    46,    47,    -1,    49,
      -1,    51,    52,    -1,    54,    -1,    -1,    -1,    -1,    59,
      -1,    61,    39,    -1,    64,    -1,    -1,    44,    68,    46,
      47,    -1,    49,    73,    51,    75,    -1,    54,    -1,    -1,
      -1,    -1,    59,    -1,    61,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    92,    93,    94,   198,    93,     0,    71,   199,
     200,   201,   202,    96,    98,    52,    22,    40,   206,    80,
      41,   203,    22,     1,     8,    18,    43,    69,    78,    82,
      83,   100,   101,   103,   106,   109,   138,   139,   140,   141,
     143,   147,   148,   174,   175,   213,   214,    70,   207,    37,
     209,    52,    14,   204,    52,    79,   102,   114,    39,    52,
      79,   104,   105,   108,   114,   112,   114,   111,   112,   102,
     108,   111,    28,    31,    95,    97,    47,   144,    32,    60,
     144,    26,    83,   149,   150,   151,   152,   197,   176,   199,
     101,   106,   109,   139,   208,   210,    26,   147,   212,    70,
      39,    19,    70,   205,     6,    15,    27,   107,    16,    70,
     113,   107,    70,   113,     6,    15,    27,   110,    70,    70,
      70,     1,    99,   101,   103,   106,   109,   138,   147,    67,
      83,   112,   145,   146,    15,    70,    52,    79,   142,   142,
      15,    70,   112,   114,     1,    70,   149,     7,     9,    13,
      30,    34,    36,    39,    44,    46,    47,    49,    51,    52,
      54,    59,    61,    64,    66,    68,    73,    75,    84,    85,
      86,    87,   105,   147,   154,   155,   156,   157,   158,   161,
     162,   163,   166,   168,   172,   183,   185,   188,   194,   195,
     196,    80,   177,   178,    70,   101,   106,   109,   138,   211,
      39,    70,    39,    52,   168,   105,     4,    12,    29,    47,
      52,    58,    64,    65,    72,    79,   116,   118,   119,   121,
     122,   127,   128,   130,   168,   114,   117,   118,   112,    15,
      67,    70,    58,   115,   116,   115,    15,     6,   151,   168,
     168,   168,   168,   105,   168,    63,   168,   170,   171,   168,
     168,   168,   168,   168,    47,    47,   168,   159,   160,   168,
      15,   153,   150,    47,     3,     6,    12,    20,    22,    27,
      33,    35,    38,    44,    45,    47,    48,    49,    50,    51,
      53,    56,    59,    62,    74,   168,   190,   191,   192,   193,
     154,    52,   181,    70,   118,    55,     4,    29,    65,    55,
      44,    70,    44,   114,   124,   125,     1,    13,   112,   129,
     131,   132,   133,    15,    24,   126,    70,    15,   115,   146,
      70,    70,   117,   168,    55,     6,    76,   126,    63,   113,
      67,   168,   115,   168,    21,    16,    21,    81,    67,   164,
     165,   168,   168,   168,   168,   114,   168,   168,   168,   168,
     167,   168,   168,    67,   167,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,    70,   173,    24,    15,    16,
      39,    49,   179,    80,   101,   106,   109,   139,   180,   182,
     118,    55,   118,   168,   117,   120,    67,   113,   123,    52,
      79,   114,   115,   134,    15,    26,    70,   173,    70,   173,
     168,   115,   168,   154,   168,   171,    16,    67,    67,   154,
     160,   154,   168,     1,    16,    67,    15,     1,    63,   113,
      63,    67,    15,    57,   186,   191,    26,   189,   192,   154,
     193,   179,   179,    26,   118,    63,    16,    63,   125,    15,
      55,   118,   132,   133,    23,    77,   184,    25,    27,    53,
     169,   165,   168,   168,   168,    15,   187,   154,     8,   179,
      70,   117,    55,   115,   135,   136,   167,   173,   168,   154,
     168,    15,   173,     8,   118,    70,    15,    21,    16,   168,
     189,   136,    47,   154,   168,   137,    67,   129,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    94,    95,    96,    97,    97,
      97,    98,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   102,   103,
     104,   104,   105,   105,   105,   106,   106,   107,   107,   107,
     108,   109,   109,   110,   110,   110,   111,   112,   112,   113,
     113,   114,   114,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   118,   118,   118,   118,   119,   119,
     120,   120,   121,   122,   123,   124,   124,   125,   126,   126,
     127,   127,   128,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   133,   134,   134,   135,   135,   135,   136,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   141,   141,
     142,   142,   143,   144,   144,   144,   145,   145,   146,   146,
     146,   147,   147,   148,   149,   150,   150,   150,   151,   151,
     152,   153,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   155,   156,   157,   158,   159,   160,
     160,   161,   162,   162,   162,   163,   163,   164,   164,   164,
     165,   165,   165,   166,   167,   167,   167,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   175,
     176,   176,   177,   178,   178,   179,   179,   180,   181,   181,
     182,   182,   182,   182,   183,   184,   184,   185,   185,   186,
     187,   187,   188,   189,   190,   190,   191,   192,   193,   193,
     193,   194,   195,   196,   197,   197,   198,   199,   200,   201,
     201,   202,   203,   203,   203,   204,   205,   206,   207,   207,
     208,   208,   208,   208,   209,   210,   210,   211,   211,   211,
     211,   212,   212,   213,   214
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     0,     4,     2,     2,     0,     2,
       2,     0,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     3,
       1,     3,     1,     1,     1,     2,     2,     1,     1,     1,
       4,     2,     2,     1,     1,     1,     4,     1,     3,     1,
       0,     1,     1,     1,     1,     4,     1,     2,     4,     3,
       1,     3,     6,     1,     1,     1,     1,     1,     2,     1,
       1,     3,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     3,     2,     4,     2,     1,     1,     2,     1,
       3,     3,     4,     1,     3,     1,     2,     3,     6,     0,
       3,     3,     3,     5,     3,     5,     3,     3,     0,     1,
       1,     1,     3,     0,     2,     3,     1,     3,     3,     4,
       2,     3,     2,     1,     1,     1,     3,     2,     1,     3,
       0,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     2,     1,     3,
       3,     4,     4,     3,     1,     1,     1,     1,     3,     2,
       1,     3,     5,     1,     1,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     3,     2,     2,     4,
       4,     4,     3,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     5,     9,     1,     1,
       1,     3,     1,     3,     4,     6,     0,     1,     2,     3,
       0,     2,     3,     5,     6,     1,     2,     3,     0,     2,
       1,     1,     1,     1,     8,     1,     1,     4,     7,     2,
       0,     1,     3,     1,     1,     3,     3,     1,     1,     3,
       3,     2,     2,     2,     4,     4,     3,     4,     2,     0,
       1,     4,     0,     3,     4,     2,     2,     2,     0,     2,
       1,     1,     1,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = PASCAL_GRAMMAR_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == PASCAL_GRAMMAR_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PASCAL_GRAMMAR_error or PASCAL_GRAMMAR_UNDEF. */
#define YYERRCODE PASCAL_GRAMMAR_UNDEF


/* Enable debugging if requested.  */
#if PASCAL_GRAMMAR_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_COMMENT: /* COMMENT  */
#line 283 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1640 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_INTEGER_CONSTANT: /* INTEGER_CONSTANT  */
#line 283 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1648 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_LONG_INTEGER_CONSTANT: /* LONG_INTEGER_CONSTANT  */
#line 283 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1656 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_NAME: /* NAME  */
#line 283 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1664 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_REAL_CONSTANT: /* REAL_CONSTANT  */
#line 287 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1672 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_STRING_CONSTANT: /* STRING_CONSTANT  */
#line 287 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1680 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_TYPE_NAME: /* TYPE_NAME  */
#line 287 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1688 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_array_begin: /* array_begin  */
#line 279 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_int(yyoutput, yyvaluep);
}
#line 1696 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_segment: /* segment  */
#line 279 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_int(yyoutput, yyvaluep);
}
#line 1704 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_proc_proto_name: /* proc_proto_name  */
#line 283 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1712 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_writeln_selector: /* writeln_selector  */
#line 279 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_int(yyoutput, yyvaluep);
}
#line 1720 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_scan_op: /* scan_op  */
#line 279 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_int(yyoutput, yyvaluep);
}
#line 1728 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_num: /* num  */
#line 279 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_int(yyoutput, yyvaluep);
}
#line 1736 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_for_dirn: /* for_dirn  */
#line 279 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_int(yyoutput, yyvaluep);
}
#line 1744 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_unit_name_and_segments: /* unit_name_and_segments  */
#line 287 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1752 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

    case YYSYMBOL_unit_name: /* unit_name  */
#line 287 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
         {
    print_token_string(yyoutput, yyvaluep);
}
#line 1760 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !PASCAL_GRAMMAR_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PASCAL_GRAMMAR_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = PASCAL_GRAMMAR_EMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == PASCAL_GRAMMAR_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= END_OF_FILE)
    {
      yychar = END_OF_FILE;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == PASCAL_GRAMMAR_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = PASCAL_GRAMMAR_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = PASCAL_GRAMMAR_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* pascal: program program_scope_part "."  */
#line 295 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // do NOT call context->scope_end here, so there is
            // something left for translator::traverse to work on.
            context->program_end();
        }
#line 2154 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 3: /* pascal: unit  */
#line 301 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // do NOT call context->scope_end here, so there is
            // something left for translator::traverse to work on.
            context->program_end();
        }
#line 2164 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 4: /* define_builtin_symbols: %empty  */
#line 310 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            //
            // We define the builtin symbols after the first token has
            // been fetched, so that any (*$XXX*) control comments
            // have had a chance to operate first.  In this way, for
            // example, system compiles (*$U-*) can influence which
            // builtin symbols are created, and (*$B*) will change the
            // codefile's byte sex.
            //
            context->define_builtin_symbols();
        }
#line 2180 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 5: /* program: PROGRAM define_builtin_symbols NAME ";"  */
#line 325 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->program_scope(*(yyvsp[-1].lv_string));
            delete (yyvsp[-1].lv_string);
        }
#line 2189 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 6: /* scope_part: scope_part_clauses compound_statement  */
#line 333 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_attach_body(*(yyvsp[0].lv_statement));
            delete (yyvsp[0].lv_statement);
        }
#line 2198 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 7: /* program_scope_part: program_scope_part_clauses compound_statement  */
#line 341 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_attach_body(*(yyvsp[0].lv_statement));
            delete (yyvsp[0].lv_statement);
        }
#line 2207 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 8: /* scope_part_clauses: %empty  */
#line 355 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->scope_part_begin(); }
#line 2213 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 11: /* program_scope_part_clauses: %empty  */
#line 362 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->scope_part_begin(); }
#line 2219 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 28: /* constant_declaration: variable_name type_eq expression ";"  */
#line 392 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->constant_declaration(*(yyvsp[-3].lv_variable_name), *(yyvsp[-1].lv_expression));
            delete (yyvsp[-3].lv_variable_name);
            delete (yyvsp[-1].lv_expression);
        }
#line 2229 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 29: /* label_clause: LABEL label_names ";"  */
#line 401 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->label_declaration(*(yyvsp[-1].lv_variable_name_list));
            delete (yyvsp[-1].lv_variable_name_list);
        }
#line 2238 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 30: /* label_names: label_name  */
#line 409 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_variable_name_list) = new variable_name_list();
            (yyval.lv_variable_name_list)->push_back(*(yyvsp[0].lv_variable_name));
            delete (yyvsp[0].lv_variable_name);
        }
#line 2248 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 31: /* label_names: label_names comma label_name  */
#line 415 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_variable_name_list) = (yyvsp[-2].lv_variable_name_list);
            (yyval.lv_variable_name_list)->push_back(*(yyvsp[0].lv_variable_name));
            delete (yyvsp[0].lv_variable_name);
        }
#line 2258 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 32: /* label_name: NAME  */
#line 424 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Extension, not in UCSD pascal.
            (yyval.lv_variable_name) = new variable_name(*(yyvsp[0].lv_string));
            delete (yyvsp[0].lv_string);
            context->complain_about_named_label(*(yyval.lv_variable_name));
        }
#line 2269 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 33: /* label_name: TYPE_NAME  */
#line 431 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Extension, not in UCSD pascal.  This can happen when a
            // label shadows a type in an outer scope.
            (yyval.lv_variable_name) = new variable_name(*(yyvsp[0].lv_string));
            delete (yyvsp[0].lv_string);
            context->complain_about_named_label(*(yyval.lv_variable_name));
        }
#line 2281 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 34: /* label_name: INTEGER_CONSTANT  */
#line 439 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            int n = pascal_lex_integer_constant_to_int(*(yyvsp[0].lv_string));
            rcstring ns = rcstring::printf("%d", n);
            (yyval.lv_variable_name) = new variable_name(ns);
            delete (yyvsp[0].lv_string);
        }
#line 2292 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 38: /* type_eq: ":="  */
#line 455 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { yyerror("that \":=\" should be \"=\""); }
#line 2298 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 39: /* type_eq: ":"  */
#line 457 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { yyerror("that \":\" should be \"=\""); }
#line 2304 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 40: /* type_declaration: variable_name type_eq complex_type_unbound ";"  */
#line 462 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Hint a name to the type.  It is possible the type is an
            // anonymous record or an anonymous enumeration.
            type::pointer tp = *(yyvsp[-1].lv_type);
            tp->name_hint((yyvsp[-3].lv_variable_name)->get_name());

            context->type_declaration(*(yyvsp[-3].lv_variable_name), tp);
            delete (yyvsp[-3].lv_variable_name);
            delete (yyvsp[-1].lv_type);

            //
            // This type could resolve an outstanding forward type,
            // go looking to see if it has.
            //
            context->late_binding_opportunity();
        }
#line 2325 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 44: /* var_colon: "="  */
#line 488 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { yyerror("that \"=\" should be \":\""); }
#line 2331 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 45: /* var_colon: ":="  */
#line 490 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { yyerror("that \":=\" should be \":\""); }
#line 2337 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 46: /* variable_declaration: variable_names var_colon complex_type ";"  */
#line 495 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Hint a name to the type.  It is possible the type is an
            // anonymous record or an anonymous enumeration.
            type::pointer tp = *(yyvsp[-1].lv_type);
            tp->name_hint((yyvsp[-3].lv_variable_name_list)->get(0).get_name());

            //
            // All relevant types should be resolved by now.  There
            // should be no forward declared types in the type of this
            // variable.  Barf if there is.
            //
            if (tp->need_late_binding())
            {
                pascal_lex_error
                (
                    (yyvsp[-3].lv_variable_name_list)->get(0).get_location(),
                    "the type is not completely defined"
                );
                tp = type_error::create();
            }

            context->variable_declaration(*(yyvsp[-3].lv_variable_name_list), tp);
            delete (yyvsp[-3].lv_variable_name_list);
            delete (yyvsp[-1].lv_type);
        }
#line 2367 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 47: /* variable_names: variable_name  */
#line 524 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_variable_name_list) = new variable_name_list();
            (yyval.lv_variable_name_list)->push_back(*(yyvsp[0].lv_variable_name));
            delete (yyvsp[0].lv_variable_name);
        }
#line 2377 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 48: /* variable_names: variable_names comma variable_name  */
#line 530 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_variable_name_list) = (yyvsp[-2].lv_variable_name_list);
            (yyval.lv_variable_name_list)->push_back(*(yyvsp[0].lv_variable_name));
            delete (yyvsp[0].lv_variable_name);
        }
#line 2387 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 50: /* comma: %empty  */
#line 540 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { yyerror("missing comma"); }
#line 2393 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 51: /* variable_name: NAME  */
#line 545 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // We do this so the variable name has an accurate location
            // attached to it.  This makes for better error messages.
            (yyval.lv_variable_name) = new variable_name(*(yyvsp[0].lv_string));
            delete (yyvsp[0].lv_string);
        }
#line 2404 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 52: /* variable_name: TYPE_NAME  */
#line 552 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // This can happen when a variable shadows a type in an
            // outer scope.
            (yyval.lv_variable_name) = new variable_name(*(yyvsp[0].lv_string));
            delete (yyvsp[0].lv_string);
        }
#line 2415 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 53: /* simple_type: simple_type_unbound  */
#line 562 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_type) = new type::pointer(type::late_binding(*(yyvsp[0].lv_type)));
            delete (yyvsp[0].lv_type);
        }
#line 2424 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 54: /* simple_type_unbound: TYPE_NAME  */
#line 570 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // There is no guarantee this has been bound.
            type::pointer tsp = context->type_lookup(*(yyvsp[0].lv_string), false);
            (yyval.lv_type) = new type::pointer(tsp);
            delete (yyvsp[0].lv_string);
        }
#line 2435 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 55: /* simple_type_unbound: TYPE_NAME "[" expression "]"  */
#line 577 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = context->type_lookup(*(yyvsp[-3].lv_string), *(yyvsp[-1].lv_expression));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[-3].lv_string);
            delete (yyvsp[-1].lv_expression);
        }
#line 2446 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 56: /* simple_type_unbound: subrange_type  */
#line 584 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_type) = (yyvsp[0].lv_type); }
#line 2452 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 57: /* simple_type_unbound: "^" complex_type_unbound  */
#line 586 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = type_pointer_unpacked::create(*(yyvsp[0].lv_type));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_type);
        }
#line 2462 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 58: /* simple_type_unbound: PACKED "file" OF complex_type_unbound  */
#line 592 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            yyerror("packed files are not supported");
            type::pointer tp = type_file::create(*(yyvsp[0].lv_type));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_type);
        }
#line 2473 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 59: /* simple_type_unbound: "file" OF complex_type_unbound  */
#line 599 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = type_file::create(*(yyvsp[0].lv_type));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_type);
        }
#line 2483 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 60: /* simple_type_unbound: "file"  */
#line 605 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer vp = type_nothing::create();
            type::pointer tp = type_file::create(vp);
            (yyval.lv_type) = new type::pointer(tp);
        }
#line 2493 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 61: /* simple_type_unbound: SET OF complex_type_unbound  */
#line 611 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = context->set_type(*(yyvsp[0].lv_type));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_type);
        }
#line 2503 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 62: /* simple_type_unbound: array_begin "[" array_dims "]" OF complex_type_unbound  */
#line 617 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = context->new_array_type((yyvsp[-5].lv_int), *(yyvsp[-3].lv_type_list), *(yyvsp[0].lv_type));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[-3].lv_type_list);
            delete (yyvsp[0].lv_type);
        }
#line 2514 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 63: /* complex_type: complex_type_unbound  */
#line 627 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = type::late_binding(*(yyvsp[0].lv_type));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_type);
        }
#line 2524 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 64: /* complex_type_unbound: simple_type_unbound  */
#line 636 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_type) = (yyvsp[0].lv_type); }
#line 2530 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 65: /* complex_type_unbound: record_type  */
#line 638 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = *(yyvsp[0].lv_type);
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_type);
        }
#line 2540 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 66: /* complex_type_unbound: NAME  */
#line 644 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            //
            // This almost always means that it is not a defined type
            // name, even though the user has used it as one.  However,
            // it is also possible to forward reference a type name in a
            // type declaration.
            //
            type::pointer tsp = context->type_lookup(*(yyvsp[0].lv_string), true);
            (yyval.lv_type) = new type::pointer(tsp);
            delete (yyvsp[0].lv_string);
        }
#line 2556 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 67: /* complex_type_unbound: enumerated_type  */
#line 657 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_type) = (yyvsp[0].lv_type); }
#line 2562 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 68: /* array_begin: PACKED ARRAY  */
#line 662 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 1; }
#line 2568 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 69: /* array_begin: ARRAY  */
#line 664 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 0; }
#line 2574 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 70: /* array_dims: complex_type  */
#line 674 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_type_list) = new type_list();
            (yyval.lv_type_list)->push_back(*(yyvsp[0].lv_type));
            delete (yyvsp[0].lv_type);
        }
#line 2584 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 71: /* array_dims: array_dims "," complex_type  */
#line 680 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_type_list) = (yyvsp[-2].lv_type_list);
            (yyval.lv_type_list)->push_back(*(yyvsp[0].lv_type));
            delete (yyvsp[0].lv_type);
        }
#line 2594 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 72: /* enumerated_type: enumerated_begin enumerated_tags enumerated_end  */
#line 690 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_type) = (yyvsp[-2].lv_type); }
#line 2600 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 73: /* enumerated_begin: "("  */
#line 696 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = context->enumerated_begin();
            (yyval.lv_type) = new type::pointer(tp);
        }
#line 2609 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 74: /* enumerated_end: ")"  */
#line 705 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->enumerated_end(); }
#line 2615 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 77: /* enumerated_tag: variable_name  */
#line 716 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->enumerated_tag(*(yyvsp[0].lv_variable_name));
            delete (yyvsp[0].lv_variable_name);
        }
#line 2624 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 79: /* elipsis: ":"  */
#line 725 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            pascal_lex_warning
            (
                "Oh, barf!  I know that using a colon here instead of "
                "\"..\" is allegedly valid Pascal, but do we really "
                "have to be this ugly?"
            );
        }
#line 2637 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 80: /* subrange_type: expression elipsis expression  */
#line 737 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = context->subrange_type(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 2648 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 81: /* subrange_type: REAL_CONSTANT  */
#line 744 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            rcstring_list a;
            a.split(*(yyvsp[0].lv_string), ".");
            while (a.size() < 2)
                a.push_back("13");
            pascal_lex_error
            (
                pascal_lex_location(),
                "the subrange appears to be missing a dot, "
                    "did you mean %s..%s instead?",
                a[0].c_str(),
                a[1].c_str()
            );
            location locn = pascal_lex_location();
            expression::pointer e1 =
                context->integer_expression_factory(locn, a[0]);
            expression::pointer e2 =
                context->integer_expression_factory(locn, a[1]);
            type::pointer tp = context->subrange_type(e1, e2);
            (yyval.lv_type) = new type::pointer(tp);
            delete (yyvsp[0].lv_string);
        }
#line 2675 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 82: /* record_type: record_begin record_body END  */
#line 770 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type_record::pointer trp = *(yyvsp[-2].lv_type_record);
            trp->attach_variant(*(yyvsp[-1].lv_variant));
            context->record_end();
            (yyval.lv_type) = new type::pointer(trp);
            delete (yyvsp[-1].lv_variant);
        }
#line 2687 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 83: /* record_body: record_fields optional_semicolon  */
#line 781 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            unsigned nwords = context->get_data_mark().get_size_in_words();
            variant::pointer vp = variant::create(nwords);
            (yyval.lv_variant) = new variant::pointer(vp);
        }
#line 2697 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 84: /* record_body: record_fields ";" record_variant_part optional_semicolon  */
#line 787 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_variant) = (yyvsp[-1].lv_variant); }
#line 2703 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 85: /* record_body: record_variant_part optional_semicolon  */
#line 789 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_variant) = (yyvsp[-1].lv_variant); }
#line 2709 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 86: /* record_body: error  */
#line 791 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            unsigned nwords = context->get_data_mark().get_size_in_words();
            variant::pointer vp = variant::create(nwords);
            (yyval.lv_variant) = new variant::pointer(vp);
        }
#line 2719 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 87: /* record_begin: RECORD  */
#line 800 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type_record::pointer tp = context->record_begin(false);
            (yyval.lv_type_record) = new type_record::pointer(tp);
        }
#line 2728 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 88: /* record_begin: PACKED RECORD  */
#line 805 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type_record::pointer tp = context->record_begin(true);
            (yyval.lv_type_record) = new type_record::pointer(tp);
        }
#line 2737 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 91: /* record_field: variable_names ":" complex_type_unbound  */
#line 818 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->record_field(*(yyvsp[-2].lv_variable_name_list), *(yyvsp[0].lv_type));
            delete (yyvsp[-2].lv_variable_name_list);
            delete (yyvsp[0].lv_type);
        }
#line 2747 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 92: /* record_variant_part: CASE record_variant_cond OF record_variants  */
#line 827 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            variant::pointer vp = context->variant_record_end();
            (yyval.lv_variant) = new variant::pointer(vp);
        }
#line 2756 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 93: /* record_variant_cond: simple_type  */
#line 835 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->variant_record_begin(*(yyvsp[0].lv_type));
        }
#line 2764 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 94: /* record_variant_cond: variable_name ":" simple_type  */
#line 839 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // The variable is NOT part of the variant section.
            variable_name_list vnl;
            vnl.push_back(*(yyvsp[-2].lv_variable_name));
            context->record_field(vnl, *(yyvsp[0].lv_type));
            delete (yyvsp[-2].lv_variable_name);

            context->variant_record_begin(*(yyvsp[0].lv_type));
            delete (yyvsp[0].lv_type);
        }
#line 2779 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 98: /* record_variant: expression_list ":" "(" record_mark record_body ")"  */
#line 859 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->variant_record_field(*(yyvsp[-5].lv_expression_list), *(yyvsp[-1].lv_variant));
            context->set_data_mark(*(yyvsp[-2].lv_bit_address));
            delete (yyvsp[-5].lv_expression_list);
            delete (yyvsp[-2].lv_bit_address);
            delete (yyvsp[-1].lv_variant);
        }
#line 2791 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 99: /* record_mark: %empty  */
#line 870 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_bit_address) = new bit_address(context->get_data_mark()); }
#line 2797 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 100: /* function: function_prototype scope_part ";"  */
#line 876 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_end();
        }
#line 2805 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 101: /* function: function_prototype FORWARD ";"  */
#line 880 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_to_be_continued();
        }
#line 2813 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 102: /* function: function_prototype EXTERNAL ";"  */
#line 884 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_end_external();
        }
#line 2821 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 103: /* function_prototype: function_introducer function_arguments ":" simple_type ";"  */
#line 891 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            if (context->current_function_definition_was_forward())
            {
                yyerror
                (
                    "must not specify a return type for functions "
                    "previously declared as forward"
                );
            }
            else
                context->scope_attach_return_type(*(yyvsp[-1].lv_type));
            delete (yyvsp[-1].lv_type);
        }
#line 2839 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 104: /* function_prototype: function_introducer function_arguments ";"  */
#line 905 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Sigh.  Yet another fugly Pascal-ism.  This isn't an error
            // if they already forward declared this function.  What if
            // we made FUNCTION and PROCEDURE the same keyword?  Correct
            // programs would compile without errors, but so would some
            // incorrect programs.
            if (!context->current_function_definition_was_forward())
                yyerror("must specify a return type for functions");
        }
#line 2853 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 105: /* function_prototype: procedure_introducer function_arguments ":" simple_type ";"  */
#line 915 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            yyerror("must not specify a return type for procedures");
            context->scope_attach_return_type(*(yyvsp[-1].lv_type));
            delete (yyvsp[-1].lv_type);
        }
#line 2863 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 107: /* function_introducer: segment FUNCTION proc_proto_name  */
#line 925 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->function_scope(*(yyvsp[0].lv_string), true, (yyvsp[-2].lv_int));
            delete (yyvsp[0].lv_string);

            // Attach a bogus type to start with, to give the pretty
            // printer a clue that it's a function and not a procedure.
            if (!context->current_function_definition_was_forward())
                context->scope_attach_return_type(type_integer::create());
        }
#line 2877 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 108: /* segment: %empty  */
#line 938 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 0; }
#line 2883 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 109: /* segment: SEGMENT  */
#line 940 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 1; }
#line 2889 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 110: /* proc_proto_name: NAME  */
#line 945 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_string) = (yyvsp[0].lv_string); }
#line 2895 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 111: /* proc_proto_name: TYPE_NAME  */
#line 947 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // This can happen when the new procedure name or function
            // name shadows a named type.
            (yyval.lv_string) = (yyvsp[0].lv_string);
        }
#line 2905 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 112: /* procedure_introducer: segment PROCEDURE proc_proto_name  */
#line 956 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->function_scope(*(yyvsp[0].lv_string), false, (yyvsp[-2].lv_int));
            delete (yyvsp[0].lv_string);
        }
#line 2914 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 113: /* function_arguments: %empty  */
#line 964 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->scope_attach_function_parameters(new name_type_list); }
#line 2920 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 114: /* function_arguments: "(" ")"  */
#line 966 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->complain_about_empty_parens();
            context->scope_attach_function_parameters(new name_type_list);
        }
#line 2929 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 115: /* function_arguments: "(" parameters ")"  */
#line 971 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->scope_attach_function_parameters((yyvsp[-1].lv_name_type_list)); }
#line 2935 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 116: /* parameters: parameter  */
#line 976 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_name_type_list) = new name_type_list();
            (yyval.lv_name_type_list)->push_back(*(yyvsp[0].lv_name_type));
            delete (yyvsp[0].lv_name_type);
        }
#line 2945 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 117: /* parameters: parameters ";" parameter  */
#line 982 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_name_type_list) = (yyvsp[-2].lv_name_type_list);
            (yyval.lv_name_type_list)->push_back(*(yyvsp[0].lv_name_type));
            delete (yyvsp[0].lv_name_type);
        }
#line 2955 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 118: /* parameter: variable_names ":" simple_type  */
#line 991 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = *(yyvsp[0].lv_type);
            if (false)
                tp = type_reference::create(tp);

            //
            // Strings and arrays and records are always passed as references,
            // even when the user asked for call by value.  They get copied at
            // the beginning of the function, instead.
            //
            // But not long ints or sets.
            //
            if
            (
                type_string::is_a(tp)
            ||
                type_array::is_a(tp)
            ||
                type_record::is_a(tp)
            )
                tp = type_reference_implicit::create(tp);

            (yyval.lv_name_type) = new name_type(*(yyvsp[-2].lv_variable_name_list), tp);
            delete (yyvsp[-2].lv_variable_name_list);
            delete (yyvsp[0].lv_type);
        }
#line 2986 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 119: /* parameter: VAR variable_names ":" simple_type  */
#line 1018 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            type::pointer tp = *(yyvsp[0].lv_type);
            tp = type_reference::create(tp);

            (yyval.lv_name_type) = new name_type(*(yyvsp[-2].lv_variable_name_list), tp);
            delete (yyvsp[-2].lv_variable_name_list);
            delete (yyvsp[0].lv_type);
        }
#line 2999 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 120: /* parameter: VAR variable_names  */
#line 1027 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // This allows you to pass "anything" to native machine code.
            type::pointer tp = type_reference::create(type_anything::create());
            (yyval.lv_name_type) = new name_type(*(yyvsp[0].lv_variable_name_list), tp);
            delete (yyvsp[0].lv_variable_name_list);
        }
#line 3010 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 121: /* compound_statement: compound_begin statement_list compound_end  */
#line 1037 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->compound_statement_factory(*(yyvsp[-1].lv_statement_list));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-1].lv_statement_list);
        }
#line 3020 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 122: /* compound_statement: compound_begin compound_end  */
#line 1043 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement_list sl;
            statement::pointer sp = context->compound_statement_factory(sl);
            (yyval.lv_statement) = new statement::pointer(sp);
        }
#line 3030 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 123: /* compound_begin: BEGIN  */
#line 1052 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->compound_scope_begin(); }
#line 3036 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 124: /* compound_end: END  */
#line 1057 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->compound_scope_end(); }
#line 3042 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 125: /* statement_list: sl_statement  */
#line 1062 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_statement_list) = new statement_list();
            (yyval.lv_statement_list)->push_back(*(yyvsp[0].lv_statement));
            delete (yyvsp[0].lv_statement);
        }
#line 3052 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 126: /* statement_list: statement_list ";" sl_statement  */
#line 1068 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_statement_list) = (yyvsp[-2].lv_statement_list);
            (yyval.lv_statement_list)->push_back(*(yyvsp[0].lv_statement));
            delete (yyvsp[0].lv_statement);
        }
#line 3062 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 127: /* statement_list: statement_list error  */
#line 1074 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement_list) = (yyvsp[-1].lv_statement_list); }
#line 3068 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 128: /* sl_statement: var_statement  */
#line 1087 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3074 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 129: /* sl_statement: twrap_begin statement twrap_end  */
#line 1089 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[-1].lv_statement); }
#line 3080 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 130: /* twrap_begin: %empty  */
#line 1094 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->compound_scope_begin(); }
#line 3086 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 131: /* twrap_end: %empty  */
#line 1099 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->compound_scope_end(); }
#line 3092 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 132: /* statement: case_statement  */
#line 1105 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3098 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 133: /* statement: compound_statement  */
#line 1107 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3104 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 134: /* statement: empty_statement  */
#line 1109 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3110 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 135: /* statement: expression_statement  */
#line 1111 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3116 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 136: /* statement: for_statement  */
#line 1113 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3122 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 137: /* statement: goto_statement  */
#line 1115 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3128 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 138: /* statement: if_statement  */
#line 1117 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3134 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 139: /* statement: label_statement  */
#line 1119 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3140 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 140: /* statement: until_statement  */
#line 1121 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3146 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 141: /* statement: while_statement  */
#line 1123 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3152 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 142: /* statement: with_statement  */
#line 1125 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3158 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 143: /* statement: writeln_statement  */
#line 1127 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3164 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 144: /* empty_statement: %empty  */
#line 1132 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->empty_statement_factory();
            (yyval.lv_statement) = new statement::pointer(sp);
        }
#line 3173 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 145: /* until_statement: repeat_begin statement_list UNTIL expression  */
#line 1140 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->until_statement(*(yyvsp[-2].lv_statement_list), *(yyvsp[0].lv_expression));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_statement_list);
            delete (yyvsp[0].lv_expression);

            /*
             * We end the scope here, rather than at UNTIL, so that a
             * variable allocated and calculated within the loop can be
             * used to control the loop exit.
             */
            context->compound_scope_end();
        }
#line 3191 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 146: /* repeat_begin: REPEAT  */
#line 1157 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->compound_scope_begin(); }
#line 3197 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 147: /* with_statement: WITH with_part  */
#line 1162 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_statement) = (yyvsp[0].lv_statement); }
#line 3203 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 148: /* with_expression: expression  */
#line 1167 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->with_scope_begin(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = (yyvsp[0].lv_expression);
        }
#line 3212 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 149: /* with_part: with_expression DO statement  */
#line 1175 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->with_scope_end(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_statement);
        }
#line 3223 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 150: /* with_part: with_expression "," with_part  */
#line 1182 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->with_scope_end(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_statement);
        }
#line 3234 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 151: /* while_statement: WHILE expression DO statement  */
#line 1192 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->while_statement(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_statement);
        }
#line 3245 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 152: /* writeln_statement: writeln_selector "(" writeln_expression_list ")"  */
#line 1202 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp =
                context->writeln_statement_factory(*(yyvsp[-1].lv_expression_list), (yyvsp[-3].lv_int));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-1].lv_expression_list);
        }
#line 3256 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 153: /* writeln_statement: writeln_selector "(" ")"  */
#line 1209 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->complain_about_empty_parens();
            statement::pointer sp =
                context->writeln_statement_factory(expression_list(), (yyvsp[-2].lv_int));
            (yyval.lv_statement) = new statement::pointer(sp);
        }
#line 3267 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 154: /* writeln_statement: writeln_selector  */
#line 1216 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp =
                context->writeln_statement_factory(expression_list(), (yyvsp[0].lv_int));
            (yyval.lv_statement) = new statement::pointer(sp);
        }
#line 3277 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 155: /* writeln_selector: WRITELN  */
#line 1225 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 1; }
#line 3283 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 156: /* writeln_selector: WRITE  */
#line 1227 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 0; }
#line 3289 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 157: /* writeln_expression_list: writeln_expression  */
#line 1232 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_expression_list) = new expression_list();
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 3299 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 158: /* writeln_expression_list: writeln_expression_list "," writeln_expression  */
#line 1238 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_expression_list) = (yyvsp[-2].lv_expression_list);
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 3309 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 159: /* writeln_expression_list: writeln_expression_list error  */
#line 1244 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_expression_list) = (yyvsp[-1].lv_expression_list);
        }
#line 3317 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 160: /* writeln_expression: expression  */
#line 1251 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->writeln1_expression_factory(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3327 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 161: /* writeln_expression: expression ":" expression  */
#line 1257 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->writeln2_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3339 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 162: /* writeln_expression: expression ":" expression ":" expression  */
#line 1265 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->writeln3_expression_factory(*(yyvsp[-4].lv_expression), *(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-4].lv_expression);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3352 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 163: /* expression_statement: expression  */
#line 1277 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->expression_statement(*(yyvsp[0].lv_expression));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[0].lv_expression);
        }
#line 3362 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 164: /* expression_list: expression  */
#line 1286 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_expression_list) = new expression_list();
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 3372 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 165: /* expression_list: expression_list comma expression  */
#line 1292 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_expression_list) = (yyvsp[-2].lv_expression_list);
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 3382 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 166: /* expression_list: expression_list error  */
#line 1298 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_expression_list) = (yyvsp[-1].lv_expression_list); }
#line 3388 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 167: /* expression: "(" expression ")"  */
#line 1303 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_expression) = (yyvsp[-1].lv_expression); }
#line 3394 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 168: /* expression: INTEGER_CONSTANT  */
#line 1305 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->integer_expression_factory(pascal_lex_location(), *(yyvsp[0].lv_string));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 3405 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 169: /* expression: LONG_INTEGER_CONSTANT  */
#line 1312 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            if (!context->feature_long_integer_constants())
            {
                pascal_lex_warning
                (
                    "long integer constants were not available in the "
                    "UCSD native compiler"
                );
            }

            expression::pointer ep =
                context->lint_expression_factory(pascal_lex_location(), *(yyvsp[0].lv_string));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 3425 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 170: /* expression: REAL_CONSTANT  */
#line 1328 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->real_expression_factory(pascal_lex_location(), *(yyvsp[0].lv_string));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 3436 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 171: /* expression: STRING_CONSTANT  */
#line 1335 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->string_expression_factory(pascal_lex_location(), *(yyvsp[0].lv_string));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 3447 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 172: /* expression: NAME  */
#line 1342 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            //
            // For now, we assume this expression is on the right-hand
            // side of an assignment.  A later production deals with
            // flipping to the left-hand side.
            //
            expression::pointer ep =
                context->name_expression(pascal_lex_location(), *(yyvsp[0].lv_string));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 3463 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 173: /* expression: PROGRAM  */
#line 1354 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Pascal is weird.  So we defined "program" as a built-in symbol,
            // to make some feeble attempt at bringing a smidgin of consistency
            // to what is, basically, a totally WTF language.
            expression::pointer ep =
                context->name_expression(pascal_lex_location(), "program");
            (yyval.lv_expression) = new expression::pointer(ep);
        }
#line 3476 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 174: /* expression: "sizeof" "(" expression ")"  */
#line 1363 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->sizeof_expression(*(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-1].lv_expression);
        }
#line 3486 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 175: /* expression: "sizeof" "(" simple_type ")"  */
#line 1369 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->sizeof_expression(pascal_lex_location(), *(yyvsp[-1].lv_type));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-1].lv_type);
        }
#line 3497 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 176: /* expression: expression "." variable_name  */
#line 1376 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->dot_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_variable_name));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_variable_name);
        }
#line 3508 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 177: /* expression: expression "^"  */
#line 1383 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->dereference_expression(*(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-1].lv_expression);
        }
#line 3518 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 178: /* expression: "*" expression  */
#line 1390 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            yyerror
            (
                "this is Pascal, not C, the dereference operator is a "
                "post-fix \"^\" not a prefix \"*\""
            );
            expression::pointer ep = context->dereference_expression(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3533 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 179: /* expression: expression "[" expression "]"  */
#line 1401 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->array_index_expression(*(yyvsp[-3].lv_expression), *(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[-1].lv_expression);
        }
#line 3544 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 180: /* expression: expression "[" expression_list "]"  */
#line 1408 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->array_index_expression(*(yyvsp[-3].lv_expression), *(yyvsp[-1].lv_expression_list));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[-1].lv_expression_list);
        }
#line 3555 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 181: /* expression: expression "(" expression_list ")"  */
#line 1415 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->function_call_expression(*(yyvsp[-3].lv_expression), *(yyvsp[-1].lv_expression_list));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[-1].lv_expression_list);
        }
#line 3567 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 182: /* expression: expression "(" ")"  */
#line 1423 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->complain_about_empty_parens();
            expression::pointer ep =
                context->function_call_expression(*(yyvsp[-2].lv_expression), expression_list());
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
        }
#line 3579 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 183: /* expression: "-" expression  */
#line 1432 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->negate_expression(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3589 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 184: /* expression: "+" expression  */
#line 1439 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->unary_plus_expression(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3599 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 185: /* expression: NOT expression  */
#line 1445 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->not_expression(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3609 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 186: /* expression: AT expression  */
#line 1451 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // This is an extension used by some Pascal implementations.
            // UCSD Pascal didn't originally have it.
            context->complain_about_address_of();
            expression::pointer ep =
                context->address_of_expression_factory(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
            // FIXME: we need a (*$extension*) to turn this on and off
        }
#line 3624 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 187: /* expression: BITWISE_AND expression  */
#line 1463 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            yyerror
            (
                "this is Pacal, not C, the address-of operator is "
                "written \"@\" not \"&\""
            );
            context->complain_about_address_of();
            expression::pointer ep =
                context->address_of_expression_factory(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3641 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 188: /* expression: expression "*" expression  */
#line 1476 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->multiplication_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3653 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 189: /* expression: expression DIV expression  */
#line 1484 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->integer_division_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3665 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 190: /* expression: expression MOD expression  */
#line 1492 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->modulo_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3676 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 191: /* expression: expression "/" expression  */
#line 1499 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->real_division_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3688 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 192: /* expression: expression AND expression  */
#line 1507 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->and_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3699 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 193: /* expression: expression IN expression  */
#line 1514 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            DEBUG(1, "mark a");
            expression::pointer ep = context->in_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            DEBUG(1, "mark b");
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
            DEBUG(1, "mark c");
        }
#line 3713 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 194: /* expression: expression "+" expression  */
#line 1524 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->addition_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3725 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 195: /* expression: expression "-" expression  */
#line 1532 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->subtraction_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3737 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 196: /* expression: expression OR expression  */
#line 1540 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->logical_or_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3749 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 197: /* expression: expression "=" expression  */
#line 1548 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->eq_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3760 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 198: /* expression: expression "<>" expression  */
#line 1555 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->ne_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3771 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 199: /* expression: expression ">=" expression  */
#line 1562 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->ge_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3782 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 200: /* expression: expression ">" expression  */
#line 1569 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->gt_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3793 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 201: /* expression: expression "<=" expression  */
#line 1576 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->le_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3804 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 202: /* expression: expression "<" expression  */
#line 1583 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->lt_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3815 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 203: /* expression: expression ":=" expression  */
#line 1590 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->assignment_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3827 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 204: /* expression: "[" "]"  */
#line 1598 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->empty_set_expression();
            (yyval.lv_expression) = new expression::pointer(ep);
        }
#line 3836 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 205: /* expression: "[" set_expression_parts "]"  */
#line 1603 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_expression) = (yyvsp[-1].lv_expression); }
#line 3842 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 206: /* expression: expression "?" expression ":" expression  */
#line 1606 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->ternary_expression(*(yyvsp[-4].lv_expression), *(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-4].lv_expression);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3855 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 207: /* expression: SCAN "(" expression "," scan_op expression "," expression ")"  */
#line 1615 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep =
                context->scan_expression_factory(*(yyvsp[-6].lv_expression), (yyvsp[-4].lv_int), *(yyvsp[-3].lv_expression), *(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);

            delete (yyvsp[-6].lv_expression);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[-1].lv_expression);
        }
#line 3869 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 208: /* scan_op: "="  */
#line 1628 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 0; }
#line 3875 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 209: /* scan_op: "<>"  */
#line 1630 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 1; }
#line 3881 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 210: /* set_expression_parts: set_expression_part  */
#line 1636 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_expression) = (yyvsp[0].lv_expression); }
#line 3887 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 211: /* set_expression_parts: set_expression_parts comma set_expression_part  */
#line 1638 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->addition_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3898 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 212: /* set_expression_part: expression  */
#line 1648 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->set_expression(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 3908 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 213: /* set_expression_part: expression elipsis expression  */
#line 1654 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->set_expression(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 3919 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 214: /* if_statement: IF expression THEN statement  */
#line 1664 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            DEBUG(1, "if {");
            statement::pointer sp = context->if_statement(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_statement);
            DEBUG(1, "}");
        }
#line 3932 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 215: /* if_statement: IF expression THEN statement ELSE statement  */
#line 1673 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            DEBUG(1, "if {");
            statement::pointer sp = context->if_statement(*(yyvsp[-4].lv_expression), *(yyvsp[-2].lv_statement), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-4].lv_expression);
            delete (yyvsp[-2].lv_statement);
            delete (yyvsp[0].lv_statement);
            DEBUG(1, "}");
        }
#line 3946 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 219: /* uses_clause_begin: USES variable_names ";"  */
#line 1695 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->uses(*(yyvsp[-1].lv_variable_name_list));
            delete (yyvsp[-1].lv_variable_name_list);
        }
#line 3955 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 223: /* uses_clause_interface_push: UNIT NAME num num BEGIN  */
#line 1725 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->uses_interface_push(*(yyvsp[-3].lv_string), (yyvsp[-2].lv_int), -1, (yyvsp[-1].lv_int));
            delete (yyvsp[-3].lv_string);
        }
#line 3964 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 224: /* uses_clause_interface_push: UNIT NAME num num num BEGIN  */
#line 1730 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->uses_interface_push(*(yyvsp[-4].lv_string), (yyvsp[-3].lv_int), (yyvsp[-2].lv_int), (yyvsp[-1].lv_int));
            delete (yyvsp[-4].lv_string);
        }
#line 3973 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 225: /* num: INTEGER_CONSTANT  */
#line 1738 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_int) = pascal_lex_integer_constant_to_int(*(yyvsp[0].lv_string));
            delete (yyvsp[0].lv_string);
        }
#line 3982 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 226: /* num: "-" num  */
#line 1744 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_int) = -(yyvsp[0].lv_int);
        }
#line 3990 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 227: /* uses_clause_interface_pop: UNIT END ";"  */
#line 1751 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->uses_interface_pop(); }
#line 3996 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 233: /* uses_clause_declaration: function_prototype  */
#line 1764 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->scope_end(); }
#line 4002 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 234: /* for_statement: FOR expression ":=" expression for_dirn expression DO statement  */
#line 1769 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp =
                context->for_statement(*(yyvsp[-6].lv_expression), *(yyvsp[-4].lv_expression), (yyvsp[-3].lv_int), *(yyvsp[-2].lv_expression), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-6].lv_expression);
            delete (yyvsp[-4].lv_expression);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_statement);
        }
#line 4016 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 235: /* for_dirn: TO  */
#line 1782 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 0; }
#line 4022 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 236: /* for_dirn: DOWNTO  */
#line 1784 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_int) = 1; }
#line 4028 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 237: /* case_statement: case_begin case_item_list optional_semicolon case_end  */
#line 1789 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer none;
            statement::pointer sp =
                context->case_statement_factory(*(yyvsp[-3].lv_expression), *(yyvsp[-2].lv_case_list), none);
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[-2].lv_case_list);
        }
#line 4041 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 238: /* case_statement: case_begin case_item_list ";" otherwise statement optional_semicolon case_end  */
#line 1799 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp =
                context->case_statement_factory(*(yyvsp[-6].lv_expression), *(yyvsp[-5].lv_case_list), *(yyvsp[-2].lv_statement));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-6].lv_expression);
            delete (yyvsp[-5].lv_case_list);
            delete (yyvsp[-2].lv_statement);
        }
#line 4054 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 239: /* otherwise: OTHERWISE no_colon_here  */
#line 1811 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->complain_about_otherwise();
        }
#line 4062 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 241: /* no_colon_here: ":"  */
#line 1819 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            yyerror("there should be no colon after \"otherwise\"");
        }
#line 4070 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 242: /* case_begin: CASE expression OF  */
#line 1827 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = context->case_stack_push(*(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-1].lv_expression);
        }
#line 4080 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 243: /* case_end: END  */
#line 1836 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->case_stack_pop(); }
#line 4086 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 244: /* case_item_list: case_item  */
#line 1841 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_case_list) = (yyvsp[0].lv_case_list); }
#line 4092 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 245: /* case_item_list: case_item_list ";" case_item  */
#line 1843 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_case_list) = (yyvsp[-2].lv_case_list);
            (yyval.lv_case_list)->push_back(*(yyvsp[0].lv_case_list));
            delete (yyvsp[0].lv_case_list);
        }
#line 4102 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 246: /* case_item: case_range ":" statement  */
#line 1852 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = *(yyvsp[0].lv_statement);
            (yyval.lv_case_list) = new case_list(context->case_stack_type());
            (yyvsp[-2].lv_case_range)->push_into_list(*(yyval.lv_case_list), sp);
            delete (yyvsp[-2].lv_case_range);
            delete (yyvsp[0].lv_statement);
        }
#line 4114 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 247: /* case_expression: expression  */
#line 1863 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // Quietly convert string constants of length one into
            // character constants, if necessary.
            expression::pointer ep = *(yyvsp[0].lv_expression);
            delete (yyvsp[0].lv_expression);
            expression::pointer ep2 =
                context->char_from_string_of_length_one(ep);
            if (ep2)
                ep = ep2;
            (yyval.lv_expression) = new expression::pointer(ep);
        }
#line 4130 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 248: /* case_range: case_expression  */
#line 1878 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep = *(yyvsp[0].lv_expression);
            delete (yyvsp[0].lv_expression);

            (yyval.lv_case_range) = new case_range(context->case_stack_type());
            if (context->case_stack_check(ep))
                (yyval.lv_case_range)->push_back(ep);
        }
#line 4143 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 249: /* case_range: case_expression ".." case_expression  */
#line 1887 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            expression::pointer ep1 = *(yyvsp[-2].lv_expression);
            delete (yyvsp[-2].lv_expression);
            expression::pointer ep3 = *(yyvsp[0].lv_expression);
            delete (yyvsp[0].lv_expression);

            (yyval.lv_case_range) = new case_range(context->case_stack_type());
            if
            (
                context->case_stack_check(ep1)
            &&
                context->case_stack_check(ep3)
            )
            {
                long v1 = ep1->optimize()->get_integer_value();
                long v3 = ep3->optimize()->get_integer_value();
                if (v1 > v3)
                {
                    pascal_lex_error
                    (
                        ep1->get_location(),
                        "case value range reversed"
                    );
                    expression::pointer x = ep1;
                    ep1 = ep3;
                    ep3 = x;
                }
                (yyval.lv_case_range)->push_back(ep1, ep3);
            }
        }
#line 4178 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 250: /* case_range: case_range "," case_range  */
#line 1918 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_case_range) = new case_range(*(yyvsp[-2].lv_case_range) + *(yyvsp[0].lv_case_range));
            delete (yyvsp[-2].lv_case_range);
            delete (yyvsp[0].lv_case_range);
        }
#line 4188 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 251: /* label_statement: label_name_colon statement  */
#line 1927 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->label_statement(*(yyvsp[-1].lv_variable_name), *(yyvsp[0].lv_statement));
            (yyval.lv_statement) = new statement::pointer (sp);
            delete (yyvsp[-1].lv_variable_name);
            delete (yyvsp[0].lv_statement);
        }
#line 4199 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 252: /* label_name_colon: label_name ":"  */
#line 1937 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { (yyval.lv_variable_name) = (yyvsp[-1].lv_variable_name); }
#line 4205 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 253: /* goto_statement: GOTO label_name  */
#line 1942 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->goto_statement(*(yyvsp[0].lv_variable_name));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[0].lv_variable_name);
        }
#line 4215 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 254: /* var_statement: VAR variable_names ":" complex_type  */
#line 1951 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->var_statement(*(yyvsp[-2].lv_variable_name_list), *(yyvsp[0].lv_type));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_variable_name_list);
            delete (yyvsp[0].lv_type);
        }
#line 4226 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 255: /* var_statement: VAR variable_name ":=" expression  */
#line 1958 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            statement::pointer sp = context->var_statement(*(yyvsp[-2].lv_variable_name), *(yyvsp[0].lv_expression));
            (yyval.lv_statement) = new statement::pointer(sp);
            delete (yyvsp[-2].lv_variable_name);
            delete (yyvsp[0].lv_expression);
        }
#line 4237 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 258: /* unit_name_and_segments: unit_name unit_segments  */
#line 1984 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->unit_scope(*(yyvsp[-1].lv_string));
            delete (yyvsp[-1].lv_string);
        }
#line 4246 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 260: /* unit_separate: SEPARATE  */
#line 1993 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            pascal_lex_warning
            (
                "the \"separate\" keyword is not present in the II.1 native "
                "compiler, and it's a bit odd in the II.0 native compiler"
            );

            //
            // Not nothing, precisely.
            //
            // The Apple Pascal compiler, based on II.1, treats the
            // SEPARATE keyword as an error.
            //
            // The II.0 compiler sources, on the other hand, use it to
            // choose between segkinds.  "SEPARATE" thus means "not
            // completely linked yet".
            // I.e. use a segkind of SEPRTSEG instead of UNITSEG.
            //
            // Sure would be nice to have some II.1 sources to read.
            //
            context->unit_is_separate();
        }
#line 4273 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 261: /* unit_name: unit_separate UNIT NAME ";"  */
#line 2019 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            (yyval.lv_string) = (yyvsp[-1].lv_string);
            context->complain_if_not_swapping();
        }
#line 4282 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 265: /* unit_code: "code" INTEGER_CONSTANT  */
#line 2033 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            long n = pascal_lex_integer_constant_to_int(*(yyvsp[0].lv_string));
            context->unit_intrinsic_code(n);
            delete (yyvsp[0].lv_string);
        }
#line 4292 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 266: /* unit_data: "data" INTEGER_CONSTANT  */
#line 2042 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            long n = pascal_lex_integer_constant_to_int(*(yyvsp[0].lv_string));
            context->unit_intrinsic_data(n);
            delete (yyvsp[0].lv_string);
        }
#line 4302 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 267: /* unit_interface: INTERFACE unit_interface_declarations  */
#line 2051 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->unit_interface_end(); }
#line 4308 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 268: /* unit_interface_declarations: %empty  */
#line 2056 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->unit_interface_begin(); }
#line 4314 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 273: /* unit_interface_declaration: function_prototype  */
#line 2066 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            // This is a FORWARD declaration in disguise
            context->scope_to_be_continued();
        }
#line 4323 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 274: /* unit_implementation: IMPLEMENTATION unit_implementation_declarations  */
#line 2074 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->unit_implementation_end(); }
#line 4329 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 275: /* unit_implementation_declarations: %empty  */
#line 2079 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        { context->unit_implementation_begin(); }
#line 4335 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 281: /* unit_init: compound_statement  */
#line 2092 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_attach_body(*(yyvsp[0].lv_statement));
            delete (yyvsp[0].lv_statement);
        }
#line 4344 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 283: /* subunit_clause: subunit_check unit_common ";"  */
#line 2101 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->scope_end();
        }
#line 4352 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;

  case 284: /* subunit_check: %empty  */
#line 2108 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"
        {
            context->complain_if_not_syscomp();
        }
#line 4360 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"
    break;


#line 4364 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.yacc.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == PASCAL_GRAMMAR_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= END_OF_FILE)
        {
          /* Return failure if at end of input.  */
          if (yychar == END_OF_FILE)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = PASCAL_GRAMMAR_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != PASCAL_GRAMMAR_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2113 "subprojects/ucsd-psystem-xc/lib/pascal/grammar.y"



void
pascal_parse(translator *tp, const rcstring &filename)
{
    context = tp;
    extern int yyparse();
    pascal_lex_open(filename);
    yyparse();
    pascal_lex_close();
}


void
pascal_grammar_debug_set(bool flag)
{
    yydebug = flag;
}


void
pascal_grammar_comment(const rcstring &arg)
{
    context->comment(arg);
}


bool
pascal_grammar_warnings_are_silent(void)
{
    return context->warnings_are_silent();
}


bool
pascal_grammar_warnings_are_errors(void)
{
    return context->warnings_are_errors();
}


bool
pascal_grammar_string_escapes(void)
{
    return context->feature_string_escapes();
}


bool
pascal_grammar_type_name(const rcstring &name)
{
    return context->is_a_type_name(name);
}


void
pascal_grammar_complain_about_hex_constant(void)
{
    context->complain_about_hex_constant();
}


void
pascal_grammar_complain_about_binary_constant(void)
{
    context->complain_about_binary_constant();
}


void
pascal_grammar_fail_hook(void)
{
    if (context)
        context->fail_hook();
}


void
pascal_grammar_notify_interface_text(const rcstring &text)
{
    assert(context);
    context->unit_interface_text(text);
}


// vim: set ts=8 sw=4 et :

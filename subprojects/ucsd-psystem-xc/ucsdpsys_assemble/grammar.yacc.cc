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
#define YYSTYPE         GRAMMAR_STYPE
/* Substitute the variable and function names.  */
#define yyparse         grammar_parse
#define yylex           grammar_lex
#define yyerror         grammar_error
#define yydebug         grammar_debug
#define yynerrs         grammar_nerrs
#define yylval          grammar_lval
#define yychar          grammar_char

/* First part of user prologue.  */
#line 22 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"


#include <cassert>
#include <lib/ac/stdio.h>
#include <lib/ac/stdlib.h>

#include <lib/expression/list.h>

#include <ucsdpsys_assemble/assembler.h>
#include <ucsdpsys_assemble/expression/6502/absolute.h>
#include <ucsdpsys_assemble/expression/6502/absolute_indexed.h>
#include <ucsdpsys_assemble/expression/6502/absolute_indexed_indirect.h>
#include <ucsdpsys_assemble/expression/6502/absolute_indirect.h>
#include <ucsdpsys_assemble/expression/6502/absolute_indirect_indexed.h>
#include <ucsdpsys_assemble/expression/6502/immediate.h>
#include <ucsdpsys_assemble/expression/special/x.h>
#include <ucsdpsys_assemble/lex.h>
#include <ucsdpsys_assemble/opcode.h>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

#define YYFPRINTF lex_trace_print

static assembler *context;


opcode::pointer
grammar_lookup_opcode(const rcstring &name)
{
    return context->lookup_opcode(name);
}


expression::pointer
grammar_lookup_special(const rcstring &name)
{
    return context->lookup_special(name);
}


void
assembler::parse(const rcstring &filename)
{
    context = this;
    extern int yyparse(void);
    lex_open(filename);
    yyparse();
    lout.flush();
    lex_close();
}


output::pointer
assembler::get_source_column(void)
{
    assert(context);
    return context->get_source_column_inner();
}


output::pointer
assembler::get_source_column_inner(void)
{
    return lout.get_source_column();
}


static bool
is_x_register(const expression::pointer &ep)
{
    return !!dynamic_cast<const expression_special_x *>(ep.get());
}



#line 156 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"

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
  YYSYMBOL_AND_AND = 3,                    /* AND_AND  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_AT = 5,                         /* AT  */
  YYSYMBOL_BIT_AND = 6,                    /* BIT_AND  */
  YYSYMBOL_BIT_OR = 7,                     /* BIT_OR  */
  YYSYMBOL_CARAT = 8,                      /* CARAT  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_DOLLAR = 12,                    /* DOLLAR  */
  YYSYMBOL_DOT_ELSE = 13,                  /* DOT_ELSE  */
  YYSYMBOL_DOT_END = 14,                   /* DOT_END  */
  YYSYMBOL_DOT_ENDC = 15,                  /* DOT_ENDC  */
  YYSYMBOL_DOT_EQU = 16,                   /* DOT_EQU  */
  YYSYMBOL_DOT_FUNC = 17,                  /* DOT_FUNC  */
  YYSYMBOL_DOT_IF = 18,                    /* DOT_IF  */
  YYSYMBOL_DOT_MACRO = 19,                 /* DOT_MACRO  */
  YYSYMBOL_DOT_PROC = 20,                  /* DOT_PROC  */
  YYSYMBOL_EOLN = 21,                      /* EOLN  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_HASH = 25,                      /* HASH  */
  YYSYMBOL_INTEGER_CONSTANT = 26,          /* INTEGER_CONSTANT  */
  YYSYMBOL_JUNK = 27,                      /* JUNK  */
  YYSYMBOL_LB = 28,                        /* LB  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_LGROUP = 31,                    /* LGROUP  */
  YYSYMBOL_LP = 32,                        /* LP  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_MOD = 35,                       /* MOD  */
  YYSYMBOL_NAME = 36,                      /* NAME  */
  YYSYMBOL_NE = 37,                        /* NE  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_OPCODE = 39,                    /* OPCODE  */
  YYSYMBOL_OPCODE_6502 = 40,               /* OPCODE_6502  */
  YYSYMBOL_OPCODE_PRELUDE = 41,            /* OPCODE_PRELUDE  */
  YYSYMBOL_OPCODE_NAME_LIST = 42,          /* OPCODE_NAME_LIST  */
  YYSYMBOL_OR_OR = 43,                     /* OR_OR  */
  YYSYMBOL_PLUS = 44,                      /* PLUS  */
  YYSYMBOL_QUESTION_MARK = 45,             /* QUESTION_MARK  */
  YYSYMBOL_RB = 46,                        /* RB  */
  YYSYMBOL_RBRACE = 47,                    /* RBRACE  */
  YYSYMBOL_REAL_CONSTANT = 48,             /* REAL_CONSTANT  */
  YYSYMBOL_RGROUP = 49,                    /* RGROUP  */
  YYSYMBOL_RP = 50,                        /* RP  */
  YYSYMBOL_SHIFT_LEFT = 51,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 52,               /* SHIFT_RIGHT  */
  YYSYMBOL_SPECIAL = 53,                   /* SPECIAL  */
  YYSYMBOL_STAR = 54,                      /* STAR  */
  YYSYMBOL_STRING_CONSTANT = 55,           /* STRING_CONSTANT  */
  YYSYMBOL_TILDE = 56,                     /* TILDE  */
  YYSYMBOL_unary = 57,                     /* unary  */
  YYSYMBOL_PLUS_PLUS = 58,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 59,               /* MINUS_MINUS  */
  YYSYMBOL_highest_precedence = 60,        /* highest_precedence  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_assemble = 62,                  /* assemble  */
  YYSYMBOL_end = 63,                       /* end  */
  YYSYMBOL_prelude = 64,                   /* prelude  */
  YYSYMBOL_prelude_opcode = 65,            /* prelude_opcode  */
  YYSYMBOL_empty_line = 66,                /* empty_line  */
  YYSYMBOL_proc_list = 67,                 /* proc_list  */
  YYSYMBOL_proc = 68,                      /* proc  */
  YYSYMBOL_proc_begin = 69,                /* proc_begin  */
  YYSYMBOL_opcodes = 70,                   /* opcodes  */
  YYSYMBOL_opcode = 71,                    /* opcode  */
  YYSYMBOL_prelop = 72,                    /* prelop  */
  YYSYMBOL_name_list = 73,                 /* name_list  */
  YYSYMBOL_name_list_item = 74,            /* name_list_item  */
  YYSYMBOL_expr6502 = 75,                  /* expr6502  */
  YYSYMBOL_expression_list = 76,           /* expression_list  */
  YYSYMBOL_expressions = 77,               /* expressions  */
  YYSYMBOL_expression = 78,                /* expression  */
  YYSYMBOL_variable_name = 79,             /* variable_name  */
  YYSYMBOL_label = 80                      /* label  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_uint8 yy_state_t;

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
         || (defined GRAMMAR_STYPE_IS_TRIVIAL && GRAMMAR_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if GRAMMAR_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   200,   203,   211,   212,   216,   217,   218,
     222,   229,   230,   234,   241,   248,   254,   261,   270,   271,
     275,   276,   292,   293,   303,   304,   308,   316,   323,   330,
     338,   344,   359,   365,   374,   390,   392,   400,   410,   421,
     430,   441,   452,   473,   484,   485,   490,   496,   505,   513,
     519,   526,   528,   535,   543,   550,   556,   564,   572,   580,
     588,   596,   604,   612,   620,   628,   636,   644,   652,   660,
     671,   679,   684
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if GRAMMAR_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND_AND", "ASSIGN",
  "AT", "BIT_AND", "BIT_OR", "CARAT", "COLON", "COMMA", "DIV", "DOLLAR",
  "DOT_ELSE", "DOT_END", "DOT_ENDC", "DOT_EQU", "DOT_FUNC", "DOT_IF",
  "DOT_MACRO", "DOT_PROC", "EOLN", "EQ", "GE", "GT", "HASH",
  "INTEGER_CONSTANT", "JUNK", "LB", "LBRACE", "LE", "LGROUP", "LP", "LT",
  "MINUS", "MOD", "NAME", "NE", "NOT", "OPCODE", "OPCODE_6502",
  "OPCODE_PRELUDE", "OPCODE_NAME_LIST", "OR_OR", "PLUS", "QUESTION_MARK",
  "RB", "RBRACE", "REAL_CONSTANT", "RGROUP", "RP", "SHIFT_LEFT",
  "SHIFT_RIGHT", "SPECIAL", "STAR", "STRING_CONSTANT", "TILDE", "unary",
  "PLUS_PLUS", "MINUS_MINUS", "highest_precedence", "$accept", "assemble",
  "end", "prelude", "prelude_opcode", "empty_line", "proc_list", "proc",
  "proc_begin", "opcodes", "opcode", "prelop", "name_list",
  "name_list_item", "expr6502", "expression_list", "expressions",
  "expression", "variable_name", "label", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,     2,   430,   -36,   -36,   101,   -35,   -36,   -36,   101,
     -32,   -36,   -36,     6,   -36,     5,   -36,   -36,   101,   101,
     -36,   101,   -36,   101,   118,   -16,   -10,     9,   392,   -36,
       7,   -36,     3,   -35,   -35,   -36,   -36,   -36,   101,   101,
     152,   -36,   -36,   -36,   101,   101,   101,   101,   -36,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   -36,
     -36,   101,   -32,   -36,   -36,    50,    52,   420,   186,   220,
     -36,   -36,     1,     1,   -36,    24,    24,    24,    24,    24,
       1,   -36,    24,     1,   -36,   392,   -36,   101,   -36,   101,
     -36,   -36,   101,    49,   -36,   -36,   -36,    -1,   434,   -36,
     -36,   254,   288,     8,   101,   101,   101,   -36,    22,   323,
     -36,   -36,   -36,   -36,   -36,   358,   392,    84,   -36,   -31,
     -28,   -26,    47,   -36,   -36,    13,    11,   -36,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     9,     0,     0,    10,    70,    44,
       0,     6,     7,     3,     8,     0,    55,    49,     0,     0,
      48,     0,    50,     0,     0,     0,     0,    45,    46,    34,
       0,    32,     0,     0,     0,     2,    12,    18,     0,     0,
       0,    52,    53,    54,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      26,     0,     0,    31,     4,     0,     0,     0,     0,     0,
      51,    63,    62,    61,    59,    64,    68,    69,    66,    67,
      57,    60,    65,    56,    58,    47,    33,     0,    17,     0,
      15,    25,    44,     0,    24,    19,    22,    71,     0,    28,
      27,     0,     0,     0,     0,     0,     0,    35,     0,    36,
      72,    20,    16,    14,    21,    40,    43,     0,    23,     0,
       0,     0,    39,    37,    42,     0,     0,    38,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -36,   -36,    63,   -36,   -36,   -36,   -36,
     -29,    64,   -36,    10,   -36,   -25,   -36,    -5,     4,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    35,     2,    11,    94,    13,    36,    37,    67,
      95,    96,    30,    31,   108,    26,    27,    28,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,     8,     3,    38,    29,    59,    15,    44,   110,    38,
      25,    60,    47,    40,    41,    39,    42,    62,    43,    61,
      32,    39,   123,    33,    64,   124,    34,   125,    63,   114,
      44,    45,    46,    68,    69,    47,    55,    65,    66,    71,
      72,    73,    74,   118,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   104,    58,    85,   126,    54,    55,
      87,    16,    89,   127,   128,    12,    14,   103,    57,   111,
       0,    88,    86,    90,   105,    17,     0,     0,    58,     0,
      18,   106,   101,    19,   102,    20,     0,     0,   109,     0,
      44,    45,    46,    21,   121,    47,     0,     0,     0,   115,
     116,   117,   107,     0,    22,    23,    49,    50,    51,     0,
       0,     0,     0,    16,    52,     0,     0,    53,    54,    55,
       0,    56,     0,     0,    44,    45,    46,    17,    57,    47,
       0,     0,    18,     0,   122,    19,     0,    20,    58,    48,
      49,    50,    51,     0,     0,    21,     0,     0,    52,     0,
       0,    53,    54,    55,     0,    56,    22,    23,    44,    45,
      46,     0,    57,    47,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    49,    50,    51,     0,     0,     0,
       0,     0,    52,     0,     0,    53,    54,    55,     0,    56,
       0,     0,    44,    45,    46,     0,    57,    47,     0,     0,
       0,    70,     0,     0,     0,     0,    58,    99,    49,    50,
      51,     0,     0,     0,     0,     0,    52,     0,     0,    53,
      54,    55,     0,    56,     0,     0,    44,    45,    46,     0,
      57,    47,     0,     0,     0,     0,     0,     0,     0,     0,
      58,   100,    49,    50,    51,     0,     0,     0,     0,     0,
      52,     0,     0,    53,    54,    55,     0,    56,     0,     0,
      44,    45,    46,     0,    57,    47,     0,     0,     0,     0,
       0,     0,     0,     0,    58,   112,    49,    50,    51,     0,
       0,     0,     0,     0,    52,     0,     0,    53,    54,    55,
       0,    56,     0,     0,    44,    45,    46,     0,    57,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    58,   113,
      49,    50,    51,     0,     0,     0,     0,     0,    52,     0,
       0,    53,    54,    55,     0,    56,     0,     0,     0,    44,
      45,    46,    57,   119,    47,     0,     0,     0,     0,     0,
       0,     0,    58,     0,     0,    49,    50,    51,     0,     0,
       0,     0,     0,    52,     0,     0,    53,    54,    55,     0,
      56,     0,     0,     0,    44,    45,    46,    57,   120,    47,
       0,     0,     0,     0,     0,     0,     0,    58,     0,     0,
      49,    50,    51,     0,     0,     0,     0,     0,    52,     0,
       0,    53,    54,    55,     0,    56,     0,     0,    44,    45,
      46,     0,    57,    47,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    49,    50,    51,     0,     0,     0,
     -13,    91,    52,     0,     0,    53,    54,    55,     0,    56,
     -11,     4,     0,     0,   -13,    91,    57,   -13,     5,     6,
     -13,     7,     0,     0,   -11,     0,    58,   -11,     5,     6,
     -11,     7,     5,     6,     0,     7,     8,     0,     0,    92,
      93,     9,    10,     0,     0,     0,     8,     0,     0,     0,
       8,     9,    10,    92,    93,     9,    10
};

static const yytype_int8 yycheck[] =
{
       5,    36,     0,     4,    36,    21,     2,     6,     9,     4,
       6,    21,    11,    18,    19,    16,    21,    10,    23,    10,
      14,    16,    53,    17,    21,    53,    20,    53,    21,    21,
       6,     7,     8,    38,    39,    11,    35,    33,    34,    44,
      45,    46,    47,    21,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     5,    54,    61,    10,    34,    35,
      10,    12,    10,    50,    53,     2,     2,    92,    44,    98,
      -1,    21,    62,    21,    25,    26,    -1,    -1,    54,    -1,
      31,    32,    87,    34,    89,    36,    -1,    -1,    93,    -1,
       6,     7,     8,    44,    10,    11,    -1,    -1,    -1,   104,
     105,   106,    53,    -1,    55,    56,    22,    23,    24,    -1,
      -1,    -1,    -1,    12,    30,    -1,    -1,    33,    34,    35,
      -1,    37,    -1,    -1,     6,     7,     8,    26,    44,    11,
      -1,    -1,    31,    -1,    50,    34,    -1,    36,    54,    21,
      22,    23,    24,    -1,    -1,    44,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    55,    56,     6,     7,
       8,    -1,    44,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,    37,
      -1,    -1,     6,     7,     8,    -1,    44,    11,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    54,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    37,    -1,    -1,     6,     7,     8,    -1,
      44,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    -1,    37,    -1,    -1,
       6,     7,     8,    -1,    44,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      -1,    37,    -1,    -1,     6,     7,     8,    -1,    44,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    -1,    -1,    -1,     6,
       7,     8,    44,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,
      37,    -1,    -1,    -1,     6,     7,     8,    44,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    -1,    -1,     6,     7,
       8,    -1,    44,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    22,    23,    24,    -1,    -1,    -1,
       0,     1,    30,    -1,    -1,    33,    34,    35,    -1,    37,
       0,     1,    -1,    -1,    14,     1,    44,    17,    18,    19,
      20,    21,    -1,    -1,    14,    -1,    54,    17,    18,    19,
      20,    21,    18,    19,    -1,    21,    36,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      36,    41,    42,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,    64,     0,     1,    18,    19,    21,    36,    41,
      42,    65,    66,    67,    72,    79,    12,    26,    31,    34,
      36,    44,    55,    56,    78,    79,    76,    77,    78,    36,
      73,    74,    14,    17,    20,    63,    68,    69,     4,    16,
      78,    78,    78,    78,     6,     7,     8,    11,    21,    22,
      23,    24,    30,    33,    34,    35,    37,    44,    54,    21,
      21,    10,    10,    21,    21,    79,    79,    70,    78,    78,
      49,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    74,    10,    21,    10,
      21,     1,    39,    40,    66,    71,    72,    79,    80,    21,
      21,    78,    78,    76,     5,    25,    32,    53,    75,    78,
       9,    71,    21,    21,    21,    78,    78,    78,    21,    10,
      10,    10,    50,    53,    53,    53,    10,    50,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      66,    67,    67,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     0,     2,     1,     1,     1,
       1,     0,     2,     2,     5,     3,     5,     3,     0,     2,
       2,     3,     1,     3,     1,     1,     3,     4,     4,     3,
       3,     3,     1,     3,     1,     1,     1,     3,     5,     3,
       2,     5,     4,     2,     0,     1,     1,     3,     1,     1,
       1,     3,     2,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = GRAMMAR_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == GRAMMAR_EMPTY)                                        \
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
   Use GRAMMAR_error or GRAMMAR_UNDEF. */
#define YYERRCODE GRAMMAR_UNDEF


/* Enable debugging if requested.  */
#if GRAMMAR_DEBUG

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
  YY_USE (yykind);
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
#else /* !GRAMMAR_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !GRAMMAR_DEBUG */


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

  yychar = GRAMMAR_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == GRAMMAR_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= GRAMMAR_EOF)
    {
      yychar = GRAMMAR_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == GRAMMAR_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = GRAMMAR_UNDEF;
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
  yychar = GRAMMAR_EMPTY;
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
  case 2: /* assemble: prelude proc_list end  */
#line 195 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        { context->dot_end(); }
#line 1380 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 3: /* end: %empty  */
#line 200 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            yyerror("missing .end directive");
        }
#line 1388 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 4: /* end: DOT_END EOLN  */
#line 204 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            lex_discard_input();
            context->listing_eoln();
        }
#line 1397 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 10: /* empty_line: EOLN  */
#line 223 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->listing_eoln();
        }
#line 1405 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 13: /* proc: proc_begin opcodes  */
#line 235 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->proc_end();
        }
#line 1413 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 14: /* proc_begin: DOT_PROC variable_name COMMA expression EOLN  */
#line 242 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->proc_begin(*(yyvsp[-3].lv_variable_name), *(yyvsp[-1].lv_expression), false);
            delete (yyvsp[-3].lv_variable_name);
            delete (yyvsp[-1].lv_expression);
            context->listing_eoln();
        }
#line 1424 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 15: /* proc_begin: DOT_PROC variable_name EOLN  */
#line 249 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->proc_begin(*(yyvsp[-1].lv_variable_name), expression::pointer(), false);
            delete (yyvsp[-1].lv_variable_name);
            context->listing_eoln();
        }
#line 1434 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 16: /* proc_begin: DOT_FUNC variable_name COMMA expression EOLN  */
#line 255 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->proc_begin(*(yyvsp[-3].lv_variable_name), *(yyvsp[-1].lv_expression), true);
            delete (yyvsp[-3].lv_variable_name);
            delete (yyvsp[-1].lv_expression);
            context->listing_eoln();
        }
#line 1445 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 17: /* proc_begin: DOT_FUNC variable_name EOLN  */
#line 262 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->proc_begin(*(yyvsp[-1].lv_variable_name), expression::pointer(), true);
            delete (yyvsp[-1].lv_variable_name);
            context->listing_eoln();
        }
#line 1455 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 21: /* opcode: OPCODE expression_list EOLN  */
#line 277 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            /*
             * This is the generic form, and we try to get as many
             * opcodes to use it as pissible.
             *
             * But some vendors came up with some really funky
             * annotation, and this simple consistent form can sometimes
             * be insufficient.
             */
            opcode::pointer op = *(yyvsp[-2].lv_opcode);
            op->interpret(*(yyvsp[-1].lv_expression_list));
            delete (yyvsp[-2].lv_opcode);
            delete (yyvsp[-1].lv_expression_list);
            context->listing_eoln();
        }
#line 1475 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 23: /* opcode: OPCODE_6502 expr6502 EOLN  */
#line 294 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            opcode::pointer op = *(yyvsp[-2].lv_opcode);
            expression_list args;
            args.push_back(*(yyvsp[-1].lv_expression));
            op->interpret(args);
            delete (yyvsp[-2].lv_opcode);
            delete (yyvsp[-1].lv_expression);
            context->listing_eoln();
        }
#line 1489 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 26: /* prelop: OPCODE_PRELUDE expression_list EOLN  */
#line 309 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            opcode::pointer op = *(yyvsp[-2].lv_opcode);
            op->interpret(*(yyvsp[-1].lv_expression_list));
            delete (yyvsp[-2].lv_opcode);
            delete (yyvsp[-1].lv_expression_list);
            context->listing_eoln();
        }
#line 1501 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 27: /* prelop: variable_name DOT_EQU expression EOLN  */
#line 317 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->define_symbol(*(yyvsp[-3].lv_variable_name), *(yyvsp[-1].lv_expression));
            delete (yyvsp[-3].lv_variable_name);
            delete (yyvsp[-1].lv_expression);
            context->listing_eoln();
        }
#line 1512 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 28: /* prelop: variable_name ASSIGN expression EOLN  */
#line 324 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->define_symbol(*(yyvsp[-3].lv_variable_name), *(yyvsp[-1].lv_expression));
            delete (yyvsp[-3].lv_variable_name);
            delete (yyvsp[-1].lv_expression);
            context->listing_eoln();
        }
#line 1523 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 29: /* prelop: DOT_MACRO variable_name EOLN  */
#line 331 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            rcstring_list contents;
            lex_macro_slurp(contents);
            context->define_macro(*(yyvsp[-1].lv_variable_name), contents);
            delete (yyvsp[-1].lv_variable_name);
            context->listing_eoln();
        }
#line 1535 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 30: /* prelop: DOT_IF expression EOLN  */
#line 339 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->dot_if(*(yyvsp[-1].lv_expression));
            delete (yyvsp[-1].lv_expression);
            context->listing_eoln();
        }
#line 1545 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 31: /* prelop: OPCODE_NAME_LIST name_list EOLN  */
#line 345 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            /*
             * This form is used for opcodes that take list of names.
             * For example: .ref, .public
             */
            opcode::pointer op = *(yyvsp[-2].lv_opcode);
            op->interpret(*(yyvsp[-1].lv_expression_list));
            delete (yyvsp[-2].lv_opcode);
            delete (yyvsp[-1].lv_expression_list);
            context->listing_eoln();
        }
#line 1561 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 32: /* name_list: name_list_item  */
#line 360 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            (yyval.lv_expression_list) = new expression_list();
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 1571 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 33: /* name_list: name_list COMMA name_list_item  */
#line 366 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            (yyval.lv_expression_list) = (yyvsp[-2].lv_expression_list);
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 1581 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 34: /* name_list_item: NAME  */
#line 375 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            variable_name vn(*(yyvsp[0].lv_string), lex_location());
            expression::pointer ep =
                context->name_expression_factory(vn);
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 1593 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 35: /* expr6502: SPECIAL  */
#line 391 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        { (yyval.lv_expression) = (yyvsp[0].lv_expression); }
#line 1599 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 36: /* expr6502: expression  */
#line 393 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Absolute
            // Zero Page
            expression::pointer ep = expression_6502_absolute::create(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 1611 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 37: /* expr6502: expression COMMA SPECIAL  */
#line 401 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Absolute Indexed
            // Zero Page Indexed
            expression::pointer ep =
                expression_6502_absolute_indexed::create(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1625 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 38: /* expr6502: LP expression COMMA SPECIAL RP  */
#line 412 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Abolute Indexed Indirect
            // Zero Page Indexed Indirect
            expression::pointer ep =
                expression_6502_absolute_indexed_indirect::create(*(yyvsp[-3].lv_expression), *(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[-1].lv_expression);
        }
#line 1639 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 39: /* expr6502: LP expression RP  */
#line 423 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Absolute Indirect
            expression::pointer ep =
                expression_6502_absolute_indirect::create(*(yyvsp[-1].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-1].lv_expression);
        }
#line 1651 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 40: /* expr6502: AT expression  */
#line 432 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Absolute Indirect
            //
            // Apple Pascal Operating System Reference Manual, p. 149
            expression::pointer ep =
                expression_6502_absolute_indirect::create(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 1665 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 41: /* expr6502: LP expression RP COMMA SPECIAL  */
#line 443 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Absolute Indirect Indexed
            // Zero Page Indirect Indexed
            expression::pointer ep =
                expression_6502_absolute_indirect_indexed::create(*(yyvsp[-3].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-3].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1679 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 42: /* expr6502: AT expression COMMA SPECIAL  */
#line 454 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Apple Pascal Operating System Reference Manual, p. 149
            if (is_x_register(*(yyvsp[0].lv_expression)))
            {
                // @e,X  ==>  (e,X)
                expression::pointer ep =
                    expression_6502_absolute_indexed_indirect::create(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
                (yyval.lv_expression) = new expression::pointer(ep);
            }
            else
            {
                // @e,Y  ==>  (e),Y
                expression::pointer ep =
                    expression_6502_absolute_indirect_indexed::create(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
                (yyval.lv_expression) = new expression::pointer(ep);
            }
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1703 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 43: /* expr6502: HASH expression  */
#line 474 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            // Immediate
            expression::pointer ep = expression_6502_immediate::create(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 1714 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 44: /* expression_list: %empty  */
#line 484 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        { (yyval.lv_expression_list) = new expression_list(); }
#line 1720 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 45: /* expression_list: expressions  */
#line 486 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        { (yyval.lv_expression_list) = (yyvsp[0].lv_expression_list); }
#line 1726 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 46: /* expressions: expression  */
#line 491 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            (yyval.lv_expression_list) = new expression_list();
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 1736 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 47: /* expressions: expressions COMMA expression  */
#line 497 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            (yyval.lv_expression_list) = (yyvsp[-2].lv_expression_list);
            (yyval.lv_expression_list)->push_back(*(yyvsp[0].lv_expression));
            delete (yyvsp[0].lv_expression);
        }
#line 1746 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 48: /* expression: NAME  */
#line 506 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            variable_name vn(*(yyvsp[0].lv_string), lex_location());
            expression::pointer ep =
                context->name_expression_factory(vn);
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 1758 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 49: /* expression: INTEGER_CONSTANT  */
#line 514 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->integer_expression_factory(lex_location(), (yyvsp[0].lv_integer));
            (yyval.lv_expression) = new expression::pointer(ep);
        }
#line 1768 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 50: /* expression: STRING_CONSTANT  */
#line 520 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->string_expression_factory(lex_location(), *(yyvsp[0].lv_string));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_string);
        }
#line 1779 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 51: /* expression: LGROUP expression RGROUP  */
#line 527 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        { (yyval.lv_expression) = (yyvsp[-1].lv_expression); }
#line 1785 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 52: /* expression: MINUS expression  */
#line 530 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep = context->negate_expression_factory(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 1795 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 53: /* expression: PLUS expression  */
#line 537 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->unary_plus_expression_factory(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 1806 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 54: /* expression: TILDE expression  */
#line 544 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->bitwise_not_expression_factory(*(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[0].lv_expression);
        }
#line 1817 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 55: /* expression: DOLLAR  */
#line 551 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->dollar_expression_factory(lex_location());
            (yyval.lv_expression) = new expression::pointer(ep);
        }
#line 1827 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 56: /* expression: expression PLUS expression  */
#line 557 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->addition_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1839 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 57: /* expression: expression MINUS expression  */
#line 565 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->subtraction_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1851 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 58: /* expression: expression STAR expression  */
#line 573 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->multiplication_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1863 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 59: /* expression: expression DIV expression  */
#line 581 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->division_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1875 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 60: /* expression: expression MOD expression  */
#line 589 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->modulo_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1887 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 61: /* expression: expression CARAT expression  */
#line 597 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->xor_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1899 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 62: /* expression: expression BIT_OR expression  */
#line 605 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->bitwise_or_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1911 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 63: /* expression: expression BIT_AND expression  */
#line 613 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->bitwise_and_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1923 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 64: /* expression: expression EQ expression  */
#line 621 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->eq_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1935 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 65: /* expression: expression NE expression  */
#line 629 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->ne_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1947 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 66: /* expression: expression LE expression  */
#line 637 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->le_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1959 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 67: /* expression: expression LT expression  */
#line 645 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->lt_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1971 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 68: /* expression: expression GE expression  */
#line 653 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->ge_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1983 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 69: /* expression: expression GT expression  */
#line 661 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            expression::pointer ep =
                context->gt_expression_factory(*(yyvsp[-2].lv_expression), *(yyvsp[0].lv_expression));
            (yyval.lv_expression) = new expression::pointer(ep);
            delete (yyvsp[-2].lv_expression);
            delete (yyvsp[0].lv_expression);
        }
#line 1995 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 70: /* variable_name: NAME  */
#line 672 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            (yyval.lv_variable_name) = new variable_name(*(yyvsp[0].lv_string), lex_location());
            delete (yyvsp[0].lv_string);
        }
#line 2004 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 71: /* label: variable_name  */
#line 680 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->define_label(*(yyvsp[0].lv_variable_name));
            delete (yyvsp[0].lv_variable_name);
        }
#line 2013 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;

  case 72: /* label: variable_name COLON  */
#line 685 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.y"
        {
            context->define_label(*(yyvsp[-1].lv_variable_name));
            delete (yyvsp[-1].lv_variable_name);
        }
#line 2022 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"
    break;


#line 2026 "subprojects/ucsd-psystem-xc/ucsdpsys_assemble/grammar.yacc.cc"

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
  yytoken = yychar == GRAMMAR_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= GRAMMAR_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == GRAMMAR_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = GRAMMAR_EMPTY;
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
  if (yychar != GRAMMAR_EMPTY)
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


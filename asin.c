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




/* First part of user prologue.  */
#line 9 "src/asin.y"

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"

#line 78 "asin.c"

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

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF_ = 3,                        /* IF_  */
  YYSYMBOL_ELSE_ = 4,                      /* ELSE_  */
  YYSYMBOL_FOR_ = 5,                       /* FOR_  */
  YYSYMBOL_RETURN_ = 6,                    /* RETURN_  */
  YYSYMBOL_ASIG_ = 7,                      /* ASIG_  */
  YYSYMBOL_OPIGUALDAD_ = 8,                /* OPIGUALDAD_  */
  YYSYMBOL_OPDESIGUALDAD_ = 9,             /* OPDESIGUALDAD_  */
  YYSYMBOL_OPMAYOR_ = 10,                  /* OPMAYOR_  */
  YYSYMBOL_OPMENOR_ = 11,                  /* OPMENOR_  */
  YYSYMBOL_OPMAYORIGUAL_ = 12,             /* OPMAYORIGUAL_  */
  YYSYMBOL_OPMENORIGUAL_ = 13,             /* OPMENORIGUAL_  */
  YYSYMBOL_OPMAS_ = 14,                    /* OPMAS_  */
  YYSYMBOL_OPMENOS_ = 15,                  /* OPMENOS_  */
  YYSYMBOL_OPMUL_ = 16,                    /* OPMUL_  */
  YYSYMBOL_OPDIV_ = 17,                    /* OPDIV_  */
  YYSYMBOL_OPAND_ = 18,                    /* OPAND_  */
  YYSYMBOL_OPOR_ = 19,                     /* OPOR_  */
  YYSYMBOL_OPNEGACION_ = 20,               /* OPNEGACION_  */
  YYSYMBOL_APAR_ = 21,                     /* APAR_  */
  YYSYMBOL_CPAR_ = 22,                     /* CPAR_  */
  YYSYMBOL_ALLAVE_ = 23,                   /* ALLAVE_  */
  YYSYMBOL_CLLAVE_ = 24,                   /* CLLAVE_  */
  YYSYMBOL_ACOR_ = 25,                     /* ACOR_  */
  YYSYMBOL_CCOR_ = 26,                     /* CCOR_  */
  YYSYMBOL_COMA_ = 27,                     /* COMA_  */
  YYSYMBOL_PCOMA_ = 28,                    /* PCOMA_  */
  YYSYMBOL_TRUE_ = 29,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 30,                    /* FALSE_  */
  YYSYMBOL_INT_ = 31,                      /* INT_  */
  YYSYMBOL_BOOL_ = 32,                     /* BOOL_  */
  YYSYMBOL_READ_ = 33,                     /* READ_  */
  YYSYMBOL_PRINT_ = 34,                    /* PRINT_  */
  YYSYMBOL_CTE_ = 35,                      /* CTE_  */
  YYSYMBOL_ID_ = 36,                       /* ID_  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_lista_declaraciones = 40,       /* lista_declaraciones  */
  YYSYMBOL_declaracion = 41,               /* declaracion  */
  YYSYMBOL_declaracion_variable = 42,      /* declaracion_variable  */
  YYSYMBOL_constante = 43,                 /* constante  */
  YYSYMBOL_tipo_simple = 44,               /* tipo_simple  */
  YYSYMBOL_declaracion_funcion = 45,       /* declaracion_funcion  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_parametros_formales = 47,       /* parametros_formales  */
  YYSYMBOL_lista_parametros_formales = 48, /* lista_parametros_formales  */
  YYSYMBOL_bloque = 49,                    /* bloque  */
  YYSYMBOL_declaracion_variable_local = 50, /* declaracion_variable_local  */
  YYSYMBOL_lista_instrucciones = 51,       /* lista_instrucciones  */
  YYSYMBOL_instruccion = 52,               /* instruccion  */
  YYSYMBOL_intruccion_expresion = 53,      /* intruccion_expresion  */
  YYSYMBOL_instruccion_entrada_salida = 54, /* instruccion_entrada_salida  */
  YYSYMBOL_instruccion_seleccion = 55,     /* instruccion_seleccion  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_instruccion_iteracion = 57,     /* instruccion_iteracion  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_expresion_opcional = 59,        /* expresion_opcional  */
  YYSYMBOL_expresion = 60,                 /* expresion  */
  YYSYMBOL_expresion_logica = 61,          /* expresion_logica  */
  YYSYMBOL_expresion_igualdad = 62,        /* expresion_igualdad  */
  YYSYMBOL_expresion_relacional = 63,      /* expresion_relacional  */
  YYSYMBOL_expresion_adicion = 64,         /* expresion_adicion  */
  YYSYMBOL_expresion_multiplicativa = 65,  /* expresion_multiplicativa  */
  YYSYMBOL_expresion_unaria = 66,          /* expresion_unaria  */
  YYSYMBOL_expresion_sufijo = 67,          /* expresion_sufijo  */
  YYSYMBOL_parametros_actuales = 68,       /* parametros_actuales  */
  YYSYMBOL_lista_parametros_actuales = 69, /* lista_parametros_actuales  */
  YYSYMBOL_operador_logico = 70,           /* operador_logico  */
  YYSYMBOL_operador_igualdad = 71,         /* operador_igualdad  */
  YYSYMBOL_operador_relacional = 72,       /* operador_relacional  */
  YYSYMBOL_operador_adicion = 73,          /* operador_adicion  */
  YYSYMBOL_operador_multiplicativo = 74,   /* operador_multiplicativo  */
  YYSYMBOL_operador_unario = 75            /* operador_unario  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    46,    58,    59,    62,    63,    66,    73,
      87,   101,   102,   103,   106,   107,   111,   110,   126,   127,
     130,   138,   148,   155,   156,   159,   160,   163,   164,   165,
     166,   167,   170,   171,   174,   185,   198,   197,   205,   204,
     217,   218,   221,   222,   236,   261,   262,   272,   273,   286,
     287,   297,   298,   308,   309,   320,   321,   331,   332,   333,
     342,   370,   384,   385,   388,   389,   392,   393,   396,   397,
     400,   401,   402,   403,   406,   407,   410,   411,   414,   415,
     416
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF_", "ELSE_", "FOR_",
  "RETURN_", "ASIG_", "OPIGUALDAD_", "OPDESIGUALDAD_", "OPMAYOR_",
  "OPMENOR_", "OPMAYORIGUAL_", "OPMENORIGUAL_", "OPMAS_", "OPMENOS_",
  "OPMUL_", "OPDIV_", "OPAND_", "OPOR_", "OPNEGACION_", "APAR_", "CPAR_",
  "ALLAVE_", "CLLAVE_", "ACOR_", "CCOR_", "COMA_", "PCOMA_", "TRUE_",
  "FALSE_", "INT_", "BOOL_", "READ_", "PRINT_", "CTE_", "ID_", "$accept",
  "programa", "$@1", "lista_declaraciones", "declaracion",
  "declaracion_variable", "constante", "tipo_simple",
  "declaracion_funcion", "$@2", "parametros_formales",
  "lista_parametros_formales", "bloque", "declaracion_variable_local",
  "lista_instrucciones", "instruccion", "intruccion_expresion",
  "instruccion_entrada_salida", "instruccion_seleccion", "$@3",
  "instruccion_iteracion", "$@4", "expresion_opcional", "expresion",
  "expresion_logica", "expresion_igualdad", "expresion_relacional",
  "expresion_adicion", "expresion_multiplicativa", "expresion_unaria",
  "expresion_sufijo", "parametros_actuales", "lista_parametros_actuales",
  "operador_logico", "operador_igualdad", "operador_relacional",
  "operador_adicion", "operador_multiplicativo", "operador_unario", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -121,     6,    23,  -121,  -121,  -121,    23,  -121,  -121,   -25,
    -121,  -121,    31,    15,   -21,  -121,    18,  -121,  -121,  -121,
      19,    35,    23,  -121,    21,    34,    45,  -121,  -121,    53,
      51,    23,  -121,  -121,  -121,    23,  -121,    50,     7,    31,
      73,    74,   -12,  -121,  -121,  -121,   -12,  -121,  -121,    83,
      85,    39,  -121,  -121,  -121,  -121,  -121,  -121,    81,    47,
      49,   109,    75,    84,  -121,  -121,    78,   -12,   -12,    95,
     102,    48,    89,   -12,   -12,   -12,   -12,  -121,  -121,  -121,
      78,  -121,  -121,    78,  -121,  -121,  -121,  -121,    78,  -121,
    -121,    78,  -121,  -121,    78,    27,  -121,   104,    99,  -121,
     105,  -121,  -121,   106,   108,  -121,   107,   110,  -121,   111,
      49,   109,    75,    84,  -121,   -12,  -121,   -12,  -121,   103,
     112,   -12,  -121,   126,   113,    82,   114,  -121,  -121,  -121,
     -12,  -121,   131,   -12,  -121,    82,   116,  -121,  -121,    82,
    -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    14,    15,     3,     4,     6,     0,
       7,     5,    16,     0,     0,     8,     0,    12,    13,    11,
       0,     0,    18,     9,     0,     0,     0,    19,    10,    20,
       0,     0,    23,    17,    21,    25,    24,     0,     0,     0,
       0,     0,     0,    78,    79,    80,     0,    25,    33,     0,
       0,    59,    57,    26,    28,    29,    30,    31,     0,    42,
      45,    47,    49,    51,    53,    55,     0,     0,    40,     0,
       0,     0,     0,     0,     0,    62,     0,    32,    66,    67,
       0,    68,    69,     0,    70,    71,    72,    73,     0,    74,
      75,     0,    76,    77,     0,    59,    56,     0,     0,    41,
       0,    58,    27,     0,     0,    43,    64,     0,    63,     0,
      46,    48,    50,    52,    54,     0,    36,     0,    22,     0,
       0,     0,    61,    60,     0,     0,     0,    34,    35,    65,
       0,    60,     0,    40,    44,     0,     0,    37,    38,     0,
      39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,   130,   115,   128,   -15,  -121,  -121,
    -121,   117,  -121,  -121,    96,  -120,  -121,  -121,  -121,  -121,
    -121,  -121,    11,   -42,  -121,    65,    63,    59,    58,   -65,
    -121,  -121,    30,  -121,  -121,  -121,  -121,  -121,  -121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    52,     9,    10,    16,
      26,    27,    33,    35,    38,    53,    54,    55,    56,   125,
      57,   139,    98,    58,    59,    60,    61,    62,    63,    64,
      65,   107,   108,    80,    83,    88,    91,    94,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    96,    43,    44,    70,   132,     3,    25,    45,    46,
      40,    12,    41,    42,    21,   137,    25,    17,    18,   140,
      37,    43,    44,    19,    51,    97,    99,    45,    46,   114,
      47,   104,   105,   106,   109,    48,    17,    18,    13,    22,
      49,    50,    19,    51,    17,    18,    74,    23,    75,    28,
      19,    40,   115,    41,     4,     5,    14,    81,    82,    15,
      75,    24,    43,    44,    76,    78,    79,    30,    45,    46,
      29,    47,   102,   124,    32,   126,    48,    17,    18,   106,
      31,    49,    50,    19,    51,    40,    39,    41,   134,    89,
      90,    99,    43,    44,    67,    68,    43,    44,    45,    46,
      92,    93,    45,    46,    72,    47,    73,    17,    18,    77,
      48,    17,    18,    19,    95,    49,    50,    19,    51,    84,
      85,    86,    87,   100,   101,   103,   116,   117,   119,   118,
     120,   127,   122,   130,   121,   135,    11,   123,   138,   131,
     128,    20,   133,    71,   136,   110,   111,   112,    34,   113,
      36,   129
};

static const yytype_uint8 yycheck[] =
{
      42,    66,    14,    15,    46,   125,     0,    22,    20,    21,
       3,    36,     5,     6,    35,   135,    31,    29,    30,   139,
      35,    14,    15,    35,    36,    67,    68,    20,    21,    94,
      23,    73,    74,    75,    76,    28,    29,    30,     7,    21,
      33,    34,    35,    36,    29,    30,     7,    28,    21,    28,
      35,     3,    25,     5,    31,    32,    25,     8,     9,    28,
      21,    26,    14,    15,    25,    18,    19,    22,    20,    21,
      36,    23,    24,   115,    23,   117,    28,    29,    30,   121,
      27,    33,    34,    35,    36,     3,    36,     5,   130,    14,
      15,   133,    14,    15,    21,    21,    14,    15,    20,    21,
      16,    17,    20,    21,    21,    23,    21,    29,    30,    28,
      28,    29,    30,    35,    36,    33,    34,    35,    36,    10,
      11,    12,    13,    28,    22,    36,    22,    28,    22,    24,
      22,    28,    22,     7,    27,     4,     6,    26,    22,    26,
      28,    13,    28,    47,   133,    80,    83,    88,    31,    91,
      35,   121
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    31,    32,    40,    41,    42,    44,
      45,    41,    36,     7,    25,    28,    46,    29,    30,    35,
      43,    35,    21,    28,    26,    44,    47,    48,    28,    36,
      22,    27,    23,    49,    48,    50,    42,    44,    51,    36,
       3,     5,     6,    14,    15,    20,    21,    23,    28,    33,
      34,    36,    43,    52,    53,    54,    55,    57,    60,    61,
      62,    63,    64,    65,    66,    67,    75,    21,    21,    60,
      60,    51,    21,    21,     7,    21,    25,    28,    18,    19,
      70,     8,     9,    71,    10,    11,    12,    13,    72,    14,
      15,    73,    16,    17,    74,    36,    66,    60,    59,    60,
      28,    22,    24,    36,    60,    60,    60,    68,    69,    60,
      62,    63,    64,    65,    66,    25,    22,    28,    24,    22,
      22,    27,    22,    26,    60,    56,    60,    28,    28,    69,
       7,    26,    52,    28,    60,     4,    59,    52,    22,    58,
      52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    43,    44,    44,    46,    45,    47,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    56,    55,    58,    57,
      59,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     0,     7,     0,     1,
       2,     4,     7,     0,     2,     0,     2,     3,     1,     1,
       1,     1,     2,     1,     5,     5,     0,     8,     0,    10,
       0,     1,     1,     3,     6,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       4,     4,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
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
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

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
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
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
  yychar = YYEMPTY;
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
  case 2: /* $@1: %empty  */
#line 46 "src/asin.y"
                          {
                            dvar = 0;
                            niv = 0;
                            cargaContexto(niv);
                          }
#line 1252 "asin.c"
    break;

  case 3: /* programa: $@1 lista_declaraciones  */
#line 52 "src/asin.y"
                          {
                            if ((yyvsp[0].cent) == 0)
                            { yyerror("Error. Debe de haber al menos una función main."); }
                          }
#line 1261 "asin.c"
    break;

  case 4: /* lista_declaraciones: declaracion  */
#line 58 "src/asin.y"
                                        { (yyval.cent) = (yyvsp[0].cent); }
#line 1267 "asin.c"
    break;

  case 5: /* lista_declaraciones: lista_declaraciones declaracion  */
#line 59 "src/asin.y"
                                                            { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent); }
#line 1273 "asin.c"
    break;

  case 6: /* declaracion: declaracion_variable  */
#line 62 "src/asin.y"
                                                 { (yyval.cent) = 0; }
#line 1279 "asin.c"
    break;

  case 7: /* declaracion: declaracion_funcion  */
#line 63 "src/asin.y"
                                                { (yyval.cent) = (yyvsp[0].cent); }
#line 1285 "asin.c"
    break;

  case 8: /* declaracion_variable: tipo_simple ID_ PCOMA_  */
#line 67 "src/asin.y"
                          {
                            if (insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1))
                              dvar += TALLA_TIPO_SIMPLE;
                            else
                              yyerror("Error. Variable ya declarada.");
                          }
#line 1296 "asin.c"
    break;

  case 9: /* declaracion_variable: tipo_simple ID_ ASIG_ constante PCOMA_  */
#line 74 "src/asin.y"
                          {
                            if ((yyvsp[-1].cent) != T_ENTERO)
                              yyerror("Error. Constante no entera");
                            else if ((yyvsp[-4].cent) != (yyvsp[-1].cent))
                              yyerror("Error. Tipo de variable diferente del asignado.");
                            else
                            {
                              if (insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1))
                                dvar += TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Error. Variable ya declarada.");
                            }
                          }
#line 1314 "asin.c"
    break;

  case 10: /* declaracion_variable: tipo_simple ID_ ACOR_ CTE_ CCOR_ PCOMA_  */
#line 88 "src/asin.y"
                          {
                            if ((yyvsp[-2].cent) != T_ENTERO)
                              yyerror("Error. Tamaño del array de tipo incorrecto.");
                            else
                            {
                              if (insTdS((yyvsp[-4].ident), VARIABLE, (yyvsp[-5].cent), niv, dvar, -1))
                                dvar += TALLA_TIPO_SIMPLE;
                              else
                                yyerror("Error. Variable ya declarada.");
                            }
                          }
#line 1330 "asin.c"
    break;

  case 11: /* constante: CTE_  */
#line 101 "src/asin.y"
                                 { (yyval.cent) = T_ENTERO; }
#line 1336 "asin.c"
    break;

  case 12: /* constante: TRUE_  */
#line 102 "src/asin.y"
                                  { (yyval.cent) = T_LOGICO; }
#line 1342 "asin.c"
    break;

  case 13: /* constante: FALSE_  */
#line 103 "src/asin.y"
                                   { (yyval.cent) = T_LOGICO; }
#line 1348 "asin.c"
    break;

  case 14: /* tipo_simple: INT_  */
#line 106 "src/asin.y"
                                 { (yyval.cent) = T_ENTERO; }
#line 1354 "asin.c"
    break;

  case 15: /* tipo_simple: BOOL_  */
#line 107 "src/asin.y"
                                  { (yyval.cent) = T_LOGICO; }
#line 1360 "asin.c"
    break;

  case 16: /* $@2: %empty  */
#line 111 "src/asin.y"
                          {
                            niv = 1;
                            cargaContexto(niv); 
                          }
#line 1369 "asin.c"
    break;

  case 17: /* declaracion_funcion: tipo_simple ID_ $@2 APAR_ parametros_formales CPAR_ bloque  */
#line 116 "src/asin.y"
                          {
                            if (insTdS((yyvsp[-5].ident), FUNCION, (yyvsp[-6].cent), niv - 1, -1, (yyvsp[-2].cent)))
                            {
                              if (strcmp((yyvsp[-5].ident), "main\0") != 0) { (yyval.cent) = 1; }
                              else { (yyval.cent) = 0; }
                            }
                            else { yyerror("Error. Declaración repetida de la función."); }
                          }
#line 1382 "asin.c"
    break;

  case 18: /* parametros_formales: %empty  */
#line 126 "src/asin.y"
                                                { (yyval.cent)  = insTdD(-1, T_VACIO); }
#line 1388 "asin.c"
    break;

  case 19: /* parametros_formales: lista_parametros_formales  */
#line 127 "src/asin.y"
                                                      { (yyval.cent) = (yyvsp[0].pf).ref; }
#line 1394 "asin.c"
    break;

  case 20: /* lista_parametros_formales: tipo_simple ID_  */
#line 131 "src/asin.y"
                          {
                            (yyval.pf).ref = insTdD(-1 , (yyvsp[-1].cent));
                            int talla = TALLA_TIPO_SIMPLE;
                            (yyval.pf).talla = talla;
                            if (!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -talla, -1))
                              yyerror("Error. Declaración repetida del parámetro.");
                          }
#line 1406 "asin.c"
    break;

  case 21: /* lista_parametros_formales: tipo_simple ID_ COMA_ lista_parametros_formales  */
#line 139 "src/asin.y"
                          {
                            (yyval.pf).ref = insTdD((yyvsp[0].pf).ref, (yyvsp[-3].cent));
                            int talla = (yyvsp[0].pf).talla + TALLA_TIPO_SIMPLE;
                            (yyval.pf).talla = talla;
                            if (!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -talla, -1))
                              yyerror("Error. Declaración repetida del parámetro.");
                          }
#line 1418 "asin.c"
    break;

  case 22: /* bloque: ALLAVE_ declaracion_variable_local lista_instrucciones RETURN_ expresion PCOMA_ CLLAVE_  */
#line 149 "src/asin.y"
                          {
                            INF infoFunc = obtTdD(-1);
                            if (infoFunc.tipo != (yyvsp[-2].cent)) { yyerror("Error. Tipo de retorno incorrecto."); }
                          }
#line 1427 "asin.c"
    break;

  case 34: /* instruccion_entrada_salida: READ_ APAR_ ID_ CPAR_ PCOMA_  */
#line 175 "src/asin.y"
                          {
                            SIMB infoVar = obtTdS((yyvsp[-2].ident));
                            if (infoVar.t == T_ERROR)
                            {
                              yyerror("Error. Variable sin declarar."); 
                            } else if (infoVar.t != T_ENTERO)
                            {
                              yyerror("Error. Variable diferente de entero.");
                            }
                          }
#line 1442 "asin.c"
    break;

  case 35: /* instruccion_entrada_salida: PRINT_ APAR_ expresion CPAR_ PCOMA_  */
#line 186 "src/asin.y"
                          {
                            if ((yyvsp[-2].cent) == T_ERROR)
                            {
                              yyerror("Error. Variable sin declarar."); 
                            } else if ((yyvsp[-2].cent) != T_ENTERO)
                            {
                              yyerror("Error. Variable diferente de entero.");
                            }
                          }
#line 1456 "asin.c"
    break;

  case 36: /* $@3: %empty  */
#line 198 "src/asin.y"
                          {
                            if ((yyvsp[-1].cent) != T_LOGICO) { yyerror("Error. Condición incorrecta."); }
                          }
#line 1464 "asin.c"
    break;

  case 38: /* $@4: %empty  */
#line 205 "src/asin.y"
                          {
                            if ((yyvsp[-5].cent) == T_ERROR) {
                              yyerror("Error. Inicialización incorrecta."); 
                            } else if ((yyvsp[-3].cent) != T_LOGICO) {
                              yyerror("Error. Condición incorrecta."); 
                            } else if ((yyvsp[-1].cent) == T_ERROR) {
                              yyerror("Error. Paso incorrecto"); 
                            }
                          }
#line 1478 "asin.c"
    break;

  case 40: /* expresion_opcional: %empty  */
#line 217 "src/asin.y"
                                                { (yyval.cent) = T_VACIO; }
#line 1484 "asin.c"
    break;

  case 41: /* expresion_opcional: expresion  */
#line 218 "src/asin.y"
                                      { (yyval.cent) = (yyvsp[0].cent); }
#line 1490 "asin.c"
    break;

  case 42: /* expresion: expresion_logica  */
#line 221 "src/asin.y"
                                             { (yyval.cent) = (yyvsp[0].cent); }
#line 1496 "asin.c"
    break;

  case 43: /* expresion: ID_ ASIG_ expresion  */
#line 223 "src/asin.y"
                          {
                            SIMB infoVar = obtTdS((yyvsp[-2].ident));
                            if (infoVar.t == T_ERROR) {
                              yyerror("Error. Variable sin declarar."); 
                              (yyval.cent) = T_ERROR;
                            } else if (infoVar.t == T_ARRAY) {
                              yyerror("Error. Asignación sin indicar índice."); 
                              (yyval.cent) = T_ERROR;
                            } else if (infoVar.t != (yyvsp[0].cent)) {
                              yyerror("Error. Tipo incorrecto en la asignación."); 
                              (yyval.cent) = T_ERROR;
                            } else { (yyval.cent) = T_VACIO; }
                          }
#line 1514 "asin.c"
    break;

  case 44: /* expresion: ID_ ACOR_ expresion CCOR_ ASIG_ expresion  */
#line 237 "src/asin.y"
                          {
                            SIMB infoVar = obtTdS((yyvsp[-5].ident));
                            if (infoVar.t == T_ERROR) {
                              yyerror("Error. Variable sin declarar."); 
                              (yyval.cent) = T_ERROR;
                            } else if (infoVar.t != T_ARRAY) {
                              yyerror("Error. Variable de tipo diferente a array."); 
                              (yyval.cent) = T_ERROR;
                            } else if ((yyvsp[-3].cent) == T_ENTERO) {
                              yyerror("Error. Índice de tipo incorrecto."); 
                              (yyval.cent) = T_ERROR;
                            } else {
                              DIM infoArray = obtTdA(infoVar.ref);
                              if (infoArray.telem != (yyvsp[0].cent)) {
                                yyerror("Error. Tipo incorrecto en la asignación."); 
                                (yyval.cent) = T_ERROR;
                              } else {
                                (yyval.cent) = T_VACIO;
                              }
                            }

                          }
#line 1541 "asin.c"
    break;

  case 45: /* expresion_logica: expresion_igualdad  */
#line 261 "src/asin.y"
                                               { (yyval.cent) = (yyvsp[0].cent); }
#line 1547 "asin.c"
    break;

  case 46: /* expresion_logica: expresion_logica operador_logico expresion_igualdad  */
#line 263 "src/asin.y"
                            { 
                              if ((yyvsp[-2].cent) == T_LOGICO && (yyvsp[0].cent) == T_LOGICO) { (yyval.cent) = T_LOGICO; }
					                    else {
                                yyerror("Error. Los tipos (logicos) no coinciden."); 
                                (yyval.cent) = T_ERROR;
                              }
                            }
#line 1559 "asin.c"
    break;

  case 47: /* expresion_igualdad: expresion_relacional  */
#line 272 "src/asin.y"
                                                 { (yyval.cent) = (yyvsp[0].cent); }
#line 1565 "asin.c"
    break;

  case 48: /* expresion_igualdad: expresion_igualdad operador_igualdad expresion_relacional  */
#line 274 "src/asin.y"
                            { 
                              if (((yyvsp[-2].cent) == T_ENTERO && (yyvsp[0].cent) == T_ENTERO) ||
                                ((yyvsp[-2].cent) == T_LOGICO && (yyvsp[0].cent) == T_LOGICO)) 
                              { 
                                (yyval.cent) = T_LOGICO; 
                              } else { 
                                yyerror("Error. Los tipos (igualdad) no coinciden."); 
                                (yyval.cent) = T_ERROR;
                              }
                            }
#line 1580 "asin.c"
    break;

  case 49: /* expresion_relacional: expresion_adicion  */
#line 286 "src/asin.y"
                                              { (yyval.cent) = (yyvsp[0].cent); }
#line 1586 "asin.c"
    break;

  case 50: /* expresion_relacional: expresion_relacional operador_relacional expresion_adicion  */
#line 288 "src/asin.y"
                            { 
                              if ((yyvsp[-2].cent) == T_ENTERO && (yyvsp[0].cent) == T_ENTERO) { (yyval.cent) = T_LOGICO; }
                              else {
                                yyerror("Error. Los tipos (relacionales) no coinciden."); 
                                (yyval.cent) = T_ERROR;
                              }
                            }
#line 1598 "asin.c"
    break;

  case 51: /* expresion_adicion: expresion_multiplicativa  */
#line 297 "src/asin.y"
                                                     { (yyval.cent) = (yyvsp[0].cent); }
#line 1604 "asin.c"
    break;

  case 52: /* expresion_adicion: expresion_adicion operador_adicion expresion_multiplicativa  */
#line 299 "src/asin.y"
                            { 
                              if ((yyvsp[-2].cent) == T_ENTERO && (yyvsp[0].cent) == T_ENTERO) { (yyval.cent) = T_LOGICO; }
                              else {
                                yyerror("Error. Los tipos (adicionales) no coinciden."); 
                                (yyval.cent) = T_ERROR;
                              }
                            }
#line 1616 "asin.c"
    break;

  case 53: /* expresion_multiplicativa: expresion_unaria  */
#line 308 "src/asin.y"
                                             { (yyval.cent) = (yyvsp[0].cent); }
#line 1622 "asin.c"
    break;

  case 54: /* expresion_multiplicativa: expresion_multiplicativa operador_multiplicativo expresion_unaria  */
#line 310 "src/asin.y"
                            { 
                              if ((yyvsp[-2].cent) == T_ENTERO && (yyvsp[0].cent) == T_ENTERO) { (yyval.cent) = T_LOGICO; }
                              else {
                                yyerror("Error. Los tipos (multiplicativos) no coinciden."); 
                                (yyval.cent) = T_ERROR;
                              }
                            }
#line 1634 "asin.c"
    break;

  case 55: /* expresion_unaria: expresion_sufijo  */
#line 320 "src/asin.y"
                                             { (yyval.cent) = (yyvsp[0].cent); }
#line 1640 "asin.c"
    break;

  case 56: /* expresion_unaria: operador_unario expresion_unaria  */
#line 322 "src/asin.y"
                            { 
                              if ((yyvsp[0].cent) == T_LOGICO) { (yyval.cent) = T_LOGICO; }
                              else { 
                                yyerror("Error. No es de tipo lógico (unaria).");
                                (yyval.cent) = T_ERROR;
                              }
                            }
#line 1652 "asin.c"
    break;

  case 57: /* expresion_sufijo: constante  */
#line 331 "src/asin.y"
                                      { (yyval.cent) = T_ENTERO; }
#line 1658 "asin.c"
    break;

  case 58: /* expresion_sufijo: APAR_ expresion CPAR_  */
#line 332 "src/asin.y"
                                                  { (yyval.cent) = (yyvsp[-1].cent); }
#line 1664 "asin.c"
    break;

  case 59: /* expresion_sufijo: ID_  */
#line 334 "src/asin.y"
                          {
                            SIMB infoVar = obtTdS((yyvsp[0].ident));
                            if (infoVar.t != T_ERROR) { (yyval.cent) = infoVar.t; }
                            else {
                              yyerror("Error. Variable no declarada.");
                              (yyval.cent) = T_ERROR;
                            }
                          }
#line 1677 "asin.c"
    break;

  case 60: /* expresion_sufijo: ID_ ACOR_ expresion CCOR_  */
#line 343 "src/asin.y"
                          {
                            SIMB infoVar = obtTdS((yyvsp[-3].ident));
                            if (infoVar.t == T_ERROR)
                            {
                              yyerror("Error. Variable no declarada.");
                              (yyval.cent) = T_ERROR;
                            }
                            else if (infoVar.t != T_ARRAY)
                            {
                              yyerror("Error. Variable de tipo incorrecto, se esperaba tipo array.");
                              (yyval.cent) = T_ERROR;
                            }
                            else if ((yyvsp[-1].cent) != T_ENTERO )
                            {
                              yyerror("Error. Índice de tipo incorrecto, se esperaba tipo entero.");
                              (yyval.cent) = T_ERROR;
                            } else {
                              DIM infoArray = obtTdA(infoVar.ref);
                              // Revisar
                              // if ($3 < 0 || $3 >= infoArray.nelem) {
                              //   yyerror("Error. Índice fuera de rango.");
                              //   $$ = T_ERROR;
                              // }
                              // else { $$ = infoArray.telem; }
                              (yyval.cent) = infoArray.telem;
                            }    
                          }
#line 1709 "asin.c"
    break;

  case 61: /* expresion_sufijo: ID_ APAR_ parametros_actuales CPAR_  */
#line 371 "src/asin.y"
                          {
                            SIMB infoVar = obtTdS((yyvsp[-3].ident));
                            INF infoFunc = obtTdD(infoVar.ref);
                            if (infoVar.t == T_ERROR || infoFunc.tipo == T_ERROR) {
                              yyerror("Error. Función no declarada.");
                              (yyval.cent) = T_ERROR;
                            } else if (!cmpDom(infoVar.ref, (yyvsp[-1].cent))) {
                              yyerror("Error. Parámetros incorrectos.");
                              (yyval.cent) = T_ERROR;
                            } else { (yyval.cent) = infoVar.t; }
                          }
#line 1725 "asin.c"
    break;

  case 62: /* parametros_actuales: %empty  */
#line 384 "src/asin.y"
                                                { (yyval.cent) = insTdD(-1, T_VACIO); }
#line 1731 "asin.c"
    break;

  case 63: /* parametros_actuales: lista_parametros_actuales  */
#line 385 "src/asin.y"
                                                      { (yyval.cent) = (yyvsp[0].cent); }
#line 1737 "asin.c"
    break;

  case 64: /* lista_parametros_actuales: expresion  */
#line 388 "src/asin.y"
                                      { (yyval.cent) = insTdD(-1, (yyvsp[0].cent)); }
#line 1743 "asin.c"
    break;

  case 65: /* lista_parametros_actuales: expresion COMA_ lista_parametros_actuales  */
#line 389 "src/asin.y"
                                                                      { (yyval.cent) = insTdD((yyvsp[0].cent), (yyvsp[-2].cent)); }
#line 1749 "asin.c"
    break;


#line 1753 "asin.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (yychar != YYEMPTY)
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

#line 419 "src/asin.y"

/*****************************************************************************/

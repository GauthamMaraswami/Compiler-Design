/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 2 "parser.y" /* yacc.c:355  */

	int ival;
	float fval;
	char cval;
  	char sval[100];

#line 166 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 38 "parser.y" /* yacc.c:358  */

	#include<stdio.h>
	#include<string.h>
	#include <stdlib.h>
	#include <limits.h>
	#include "syntax.h"
	FILE *yyin;
	extern int line;
	extern int comment_stack[100];//for storing comment stack
	extern int stacktop;//top of comment stack
	extern int commentflag;
	char test[100];
    struct string id;
	struct string id_prev;
	int brac_act_flag=0;


#line 200 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,     2,
      32,    31,     2,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    27,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    33,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    62,    63,    64,    65,    66,    70,    72,
      73,    79,    80,    82,    83,    86,    88,    89,    92,    93,
      99,   101,   103,   105,   108,   111,   113,   115,   117,   119,
     120,   123,   124,   127,   128,   130,   132,   140,   141,   144,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   164,   165,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   181,   182,   183,   184,
     186,   187,   189,   190,   191,   193,   194,   195,   196,   198,
     199,   202,   203,   205,   206,   209,   210,   213,   214,   217,
     218,   221,   222,   223,   224,   227,   228,   229,   230,   231,
     235,   236,   237,   238,   239,   243,   245,   246,   248,   249,
     252,   255,   256,   259,   261,   262,   263,   264,   265,   267,
     268,   269,   270,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "dtype", "assop", "sumop",
  "mulop", "unary", "logicalopbin", "logicalnot", "relop", "ifstmt",
  "elsestmt", "whilestmt", "charcnst", "badcharcnst", "floatcnst",
  "stringcnst", "breakval", "returnval", "switchval", "casestmt",
  "structs", "unions", "defaultstmt", "';'", "','", "'['", "']'", "')'",
  "'('", "'}'", "'{'", "'&'", "':'", "$accept", "ED", "program",
  "declarationList", "declarationListhelper", "declaration",
  "varDeclaration", "varDeclList", "varDeclListhelper",
  "varDeclarationStmt", "varDeclInitialize", "varDeclId", "typeSpecifier",
  "funDeclaration", "funDeclarationphase1", "funDeclarationphase2",
  "funDeclarationphase3", "funName", "params", "paramList", "statement",
  "statement1", "statement2", "loopstatement", "loopstatement1",
  "stmtlist", "returnstmt", "loopstmtlist", "breakstmt", "selectionstmt",
  "selectionhelper", "expressionsemi", "expression", "simpleExpression",
  "unaryRelExpression", "relExpression", "sumExpression", "term",
  "iterationwhile", "factor", "mutable", "immutable", "callingnosq",
  "args", "arglist", "structoruniondefn", "structspecifier", "switch",
  "switchstatement", "switchimmutable", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    59,    44,    91,
      93,    41,    40,   125,   123,    38,    58
};
# endif

#define YYPACT_NINF -106

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-106)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     343,    -4,  -106,  -106,    11,   376,    24,  -106,  -106,  -106,
    -106,  -106,  -106,   376,    79,   103,  -106,  -106,   142,  -106,
      86,  -106,    63,    84,   125,   100,  -106,  -106,   112,   143,
    -106,  -106,    19,   154,  -106,    90,  -106,  -106,   343,   165,
    -106,   146,  -106,   146,   376,    -2,  -106,  -106,  -106,   142,
     197,   109,   178,   180,  -106,   174,  -106,  -106,   184,   268,
    -106,   207,  -106,  -106,    16,  -106,   376,   380,   380,   380,
      69,  -106,    91,  -106,    18,    27,  -106,  -106,   207,   214,
    -106,   207,  -106,  -106,  -106,   354,   190,  -106,  -106,   207,
     293,  -106,  -106,  -106,  -106,   191,   196,  -106,   108,   202,
     208,  -106,   154,   230,  -106,    12,  -106,    11,   135,    89,
    -106,   216,    63,   211,   180,  -106,    95,    16,   215,  -106,
    -106,  -106,  -106,  -106,  -106,   125,    16,  -106,    16,   222,
     223,   140,  -106,   228,    88,  -106,    97,  -106,  -106,  -106,
     231,   376,  -106,  -106,  -106,  -106,  -106,  -106,   234,  -106,
      41,  -106,   229,    52,  -106,  -106,  -106,  -106,   161,    23,
     200,   238,   233,  -106,   139,  -106,   243,  -106,  -106,   188,
    -106,   244,   177,  -106,   237,  -106,   150,   210,   242,  -106,
    -106,   377,   381,   383,  -106,  -106,  -106,   235,   318,  -106,
    -106,   394,   395,  -106,   396,   400,   408,   409,   318,   161,
     245,   249,  -106,  -106,   161,  -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   100,    23,     0,     0,     0,   101,   104,   103,
     102,   111,   112,     0,     0,     0,     2,     4,     9,    11,
       0,    12,     0,     0,    29,     0,     5,     3,     0,    76,
      80,    82,    84,    86,    88,    92,    91,    94,     6,     0,
      99,    77,    81,    92,     0,     0,    98,     1,     8,     9,
       0,    21,     0,    16,    20,     0,    36,    24,     0,     0,
      25,     0,    26,    30,   106,    72,     0,     0,     0,     0,
       0,    78,     0,     7,     0,     0,    93,    10,     0,     0,
      13,     0,    15,    27,    33,     0,     0,    34,    43,     0,
      35,    49,    50,    42,    48,    21,    32,   109,    92,     0,
     107,    79,    85,    83,    87,     0,    75,     0,     0,    92,
      18,     0,     0,     0,    16,    51,     0,     0,     0,    41,
      46,    44,    40,    45,    47,     0,     0,   105,     0,     0,
       0,     0,    95,     0,     0,    14,    67,    22,    17,    52,
       0,     0,    31,   108,    74,    73,    96,    97,     0,    19,
       0,    68,     0,     0,   110,    71,    70,    69,   114,     0,
       0,     0,     0,    90,     0,    89,     0,   123,   119,     0,
     120,     0,     0,   113,     0,    38,    43,     0,    49,    39,
      65,    50,    42,    48,    37,   122,   121,     0,     0,   117,
      66,    41,    46,    61,    44,    40,    45,    47,     0,   114,
       0,     0,   115,   118,   114,   116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,   250,  -106,   246,     4,     0,   111,   169,  -106,
     213,   252,     6,  -106,  -106,  -106,  -106,   271,  -106,   182,
    -105,  -106,   157,  -106,  -106,   240,   -49,   -52,   128,     1,
    -106,     2,   -47,    -8,     8,  -106,   251,   253,   147,   257,
      -1,  -106,  -106,  -106,  -106,  -106,     9,   -48,   -50,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    48,    18,   176,    52,    82,   134,
      53,    54,    89,    21,    22,    23,    24,    25,    62,    63,
      57,    58,    59,   165,   166,   177,   178,   179,   180,   181,
     157,   182,    28,    29,    30,    31,    32,    33,   123,    34,
      35,    36,    37,    99,   100,    38,    50,   183,   162,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    26,    27,    41,    43,    45,    20,   136,    66,    39,
      91,    94,    43,    42,    40,   129,   130,    97,    19,     1,
       2,    95,    49,   106,    20,     4,    67,     5,   -28,    76,
      61,    68,     7,     8,     9,    10,    75,    66,    19,    26,
      27,   120,   124,    43,    20,   155,    14,    39,    13,    19,
     163,    14,   110,    49,     6,    20,    44,    56,   112,    88,
      92,    93,    66,    98,   108,    43,    43,    43,    43,    98,
     140,   109,     1,     2,   101,    56,   105,   116,     4,   106,
       5,   143,    46,   159,    43,     7,     8,     9,    10,    51,
     119,   121,   122,     3,     1,     2,    70,    56,   133,    71,
     107,    13,     5,    47,    14,    66,   131,     7,     8,     9,
      10,   150,    11,    12,   126,    60,    98,    71,    72,    72,
     189,   148,   139,    13,   151,    98,    14,    98,   192,   197,
       3,    61,    64,   153,   149,   199,   200,    72,    79,    65,
      43,   -28,     1,     2,     3,    66,   201,     3,     4,   202,
       5,   156,     6,    66,   205,     7,     8,     9,    10,   174,
      85,    86,    69,    11,    12,   132,    11,    12,    74,    72,
     146,    13,   175,   -56,    14,    72,   -56,   191,   194,   195,
       1,     2,     3,   -56,   160,   111,     4,   161,     5,   111,
       6,   185,   186,     7,     8,     9,    10,   174,    85,    86,
      78,    11,    12,   167,   168,    80,    83,   169,    81,    13,
      95,   188,    14,     1,     2,     3,   170,    84,   113,     4,
      79,     5,   117,     6,   125,   118,     7,     8,     9,    10,
     174,    85,    86,   127,    11,    12,   128,    67,     1,     2,
       3,   137,    13,   135,     4,    14,     5,   141,     6,   144,
     145,     7,     8,     9,    10,   174,    85,    86,   147,    11,
      12,   154,   152,   158,   190,   -63,   173,    13,   -63,   198,
      14,     1,     2,     3,   172,   -63,   184,     4,   203,     5,
     187,     6,   204,   138,     7,     8,     9,    10,    73,    85,
      86,    55,    11,    12,   114,    77,     1,     2,     3,    90,
      13,    87,     4,    14,     5,   193,     6,   142,   118,     7,
       8,     9,    10,    96,    85,    86,   164,    11,    12,   103,
     102,     1,     2,     3,   196,    13,   104,     4,    14,     5,
       0,     6,     0,     0,     7,     8,     9,    10,   174,    85,
      86,     0,    11,    12,     0,     0,     1,     2,     3,     0,
      13,     0,     4,    14,     5,     0,     6,     1,     2,     7,
       8,     9,    10,     0,     0,     5,     0,    11,    12,     0,
       7,     8,     9,    10,     0,    13,     0,     0,    14,     1,
       2,   115,     0,     1,     2,     0,    13,     5,     0,    14,
       0,     0,     7,     8,     9,    10,     7,     8,     9,    10,
     -64,     0,     0,   -64,   -55,     0,   -62,   -55,    13,   -62,
     -64,    14,    13,     0,   -55,    14,   -62,   -54,   -59,   -57,
     -54,   -59,   -57,   -53,     0,     0,   -53,   -54,   -59,   -57,
       0,   -58,   -60,   -53,   -58,   -60,     0,     0,     0,     0,
       0,   -58,   -60
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,     4,     5,    13,     0,   112,    10,     0,
      59,    59,    13,     5,     3,     3,     4,    64,    18,     3,
       4,     3,    18,    70,    18,     9,     7,    11,    32,    31,
      24,    12,    16,    17,    18,    19,    44,    10,    38,    38,
      38,    90,    90,    44,    38,   150,    35,    38,    32,    49,
      27,    35,    34,    49,    13,    49,    32,    34,    31,    59,
      59,    59,    10,    64,    72,    66,    67,    68,    69,    70,
     117,    72,     3,     4,    66,    34,     7,    85,     9,   126,
      11,   128,     3,    31,    85,    16,    17,    18,    19,     3,
      90,    90,    90,     5,     3,     4,     6,    34,     9,     9,
       9,    32,    11,     0,    35,    10,   107,    16,    17,    18,
      19,    14,    24,    25,     6,    31,   117,     9,    29,    29,
     172,    33,    27,    32,    27,   126,    35,   128,   177,   177,
       5,   125,    32,   141,   134,   187,   188,    29,    29,    27,
     141,    32,     3,     4,     5,    10,   198,     5,     9,   199,
      11,   150,    13,    10,   204,    16,    17,    18,    19,    20,
      21,    22,     8,    24,    25,    30,    24,    25,     3,    29,
      30,    32,    33,    23,    35,    29,    26,   177,   177,   177,
       3,     4,     5,    33,    23,    74,     9,    26,    11,    78,
      13,     3,     4,    16,    17,    18,    19,    20,    21,    22,
       3,    24,    25,     3,     4,    27,    32,     7,    28,    32,
       3,    34,    35,     3,     4,     5,    16,    33,     4,     9,
      29,    11,    32,    13,    28,    15,    16,    17,    18,    19,
      20,    21,    22,    31,    24,    25,    28,     7,     3,     4,
       5,    30,    32,    27,     9,    35,    11,    32,    13,    27,
      27,    16,    17,    18,    19,    20,    21,    22,    30,    24,
      25,    27,    31,    34,    27,    23,    33,    32,    26,    34,
      35,     3,     4,     5,    36,    33,    33,     9,    33,    11,
      36,    13,    33,   114,    16,    17,    18,    19,    38,    21,
      22,    20,    24,    25,    81,    49,     3,     4,     5,    59,
      32,    33,     9,    35,    11,   177,    13,   125,    15,    16,
      17,    18,    19,    61,    21,    22,   159,    24,    25,    68,
      67,     3,     4,     5,   177,    32,    69,     9,    35,    11,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    -1,    -1,     3,     4,     5,    -1,
      32,    -1,     9,    35,    11,    -1,    13,     3,     4,    16,
      17,    18,    19,    -1,    -1,    11,    -1,    24,    25,    -1,
      16,    17,    18,    19,    -1,    32,    -1,    -1,    35,     3,
       4,    27,    -1,     3,     4,    -1,    32,    11,    -1,    35,
      -1,    -1,    16,    17,    18,    19,    16,    17,    18,    19,
      23,    -1,    -1,    26,    23,    -1,    23,    26,    32,    26,
      33,    35,    32,    -1,    33,    35,    33,    23,    23,    23,
      26,    26,    26,    23,    -1,    -1,    26,    33,    33,    33,
      -1,    23,    23,    33,    26,    26,    -1,    -1,    -1,    -1,
      -1,    33,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    11,    13,    16,    17,    18,
      19,    24,    25,    32,    35,    38,    39,    40,    42,    43,
      49,    50,    51,    52,    53,    54,    66,    68,    69,    70,
      71,    72,    73,    74,    76,    77,    78,    79,    82,    83,
       3,    77,    71,    77,    32,    70,     3,     0,    41,    42,
      83,     3,    44,    47,    48,    54,    34,    57,    58,    59,
      31,    49,    55,    56,    32,    27,    10,     7,    12,     8,
       6,     9,    29,    39,     3,    70,    31,    41,     3,    29,
      27,    28,    45,    32,    33,    21,    22,    33,    43,    49,
      62,    63,    66,    68,    84,     3,    48,    69,    77,    80,
      81,    71,    74,    73,    76,     7,    69,     9,    70,    77,
      34,    44,    31,     4,    47,    27,    70,    32,    15,    43,
      63,    66,    68,    75,    84,    28,     6,    31,    28,     3,
       4,    77,    30,     9,    46,    27,    57,    30,    45,    27,
      69,    32,    56,    69,    27,    27,    30,    30,    33,    43,
      14,    27,    31,    70,    27,    57,    66,    67,    34,    31,
      23,    26,    85,    27,    59,    60,    61,     3,     4,     7,
      16,    86,    36,    33,    20,    33,    43,    62,    63,    64,
      65,    66,    68,    84,    33,     3,     4,    36,    34,    64,
      27,    43,    63,    65,    66,    68,    75,    84,    34,    64,
      64,    64,    85,    33,    33,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    48,    48,    49,    50,    51,    52,    53,    54,    55,
      55,    56,    56,    57,    57,    58,    59,    60,    60,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    66,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    80,    80,    81,    81,
      82,    83,    83,    84,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     1,     1,     3,     4,     2,     0,     3,     0,     2,
       1,     1,     4,     1,     2,     2,     2,     3,     1,     0,
       1,     4,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     2,     3,     2,     2,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     5,     6,     7,
       1,     1,     2,     5,     5,     3,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     1,     3,     1,     5,
       5,     1,     1,     3,     1,     4,     5,     5,     2,     1,
       1,     1,     1,     1,     1,     4,     0,     1,     3,     1,
       6,     1,     1,     7,     0,     5,     7,     3,     5,     1,
       1,     2,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 58 "parser.y" /* yacc.c:1646  */
    {
	printf("Valid Expressions : ");
}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 101 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),test,id.val,line); printf("%s  %s  \n",(yyvsp[0].sval),id.val);}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 103 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[-3].sval),test,id.val,line);push_to_constants_table((yyvsp[-1].sval),"number",line);  printf("%s  %s  \n",(yyvsp[-3].sval),id.val);}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 105 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));strcpy(test,(yyvsp[0].sval));}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 111 "parser.y" /* yacc.c:1646  */
    { brac_act_flag=1; }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 115 "parser.y" /* yacc.c:1646  */
    {  id=openbraceencounter(id); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));  push_to_symbol_table((yyvsp[0].sval),test,id.val,line);printf("%s  %s  \n",(yyvsp[0].sval),id.val); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 127 "parser.y" /* yacc.c:1646  */
    {printf("close");id=closebraceencounter(id);}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 128 "parser.y" /* yacc.c:1646  */
    {printf("close");id=closebraceencounter(id);}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 132 "parser.y" /* yacc.c:1646  */
    {printf("open"); if(brac_act_flag==0) {id=openbraceencounter(id);} else {brac_act_flag=0;} }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 140 "parser.y" /* yacc.c:1646  */
    {printf("close"); id=closebraceencounter(id);}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 141 "parser.y" /* yacc.c:1646  */
    {printf("close");id=closebraceencounter(id);}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 193 "parser.y" /* yacc.c:1646  */
    { /*printf( " found assignment an:   %s\n" ,$2); */}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 209 "parser.y" /* yacc.c:1646  */
    {/*printf("add\n");*/}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 213 "parser.y" /* yacc.c:1646  */
    {/*printf("multiply\n");*/}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 222 "parser.y" /* yacc.c:1646  */
    {/*printf("mutable\n");*/}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 223 "parser.y" /* yacc.c:1646  */
    {/*printf("brackets\n");*/}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 224 "parser.y" /* yacc.c:1646  */
    {/*printf("calling\n");*/}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 230 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),"data",id.val,line); printf("%s  %s  \n",(yyvsp[0].sval),id.val); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 235 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 236 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 237 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"string",line);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 238 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"float",line);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 239 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 255 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval)); strcpy(test,(yyvsp[0].sval));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 256 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 267 "parser.y" /* yacc.c:1646  */
    {push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 268 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1647 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 274 "parser.y" /* yacc.c:1906  */

void yyerror()
{
	if(commentflag==1)
		printf("lexical comment error  at line %d : \n",line);
	else{
		printf("Invalid expressions at line %d : \n",line);
	}
}

int main()
{

    int i,j;
	id.val[0]='1';
	id.len=1;
	id.val[id.len]='\0';

	yyin=fopen("tester.c","r");
	yyparse();

	printf("\n\t\t\t\t\tsymbols table\n");
	printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \n","ID","name","type","scope","linecount");
	for(i=0;i<65535;++i)
	{
			if(symboltable[i].valid==1)
			{
				struct symbol * pointer=&symboltable[i];
				while(pointer->next!=NULL)
					{
					printf("%d \t\t %s \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->scope,pointer->linecount);
						
						for(j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
							pointer=pointer->next;
						
					}
				printf("%d \t\t %s \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->scope,pointer->linecount);
						
						for(j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
							pointer=pointer->next;
			
				printf("\n");
			}
	}
	/*
printf("\n\n\t\t\t\t\tconstant table\n");
	printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \n","ID","name","type","linecount","linenumbers");
	for(i=0;i<65535;++i)
	{
			if(constantstable[i].valid==1)
			{
				struct constants * pointer=&constantstable[i];
				while(pointer->next!=NULL)
					{
						printf("%d \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
						for(j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
						pointer=pointer->next;
						
					}
				printf("%d \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
				for(j=0;j<pointer->linecount;++j)
				{
					printf("\t%d ",pointer->lineno[j]);
				}
				pointer=pointer->next;
				printf("\n");
			}
	}*/
	return 0;
}

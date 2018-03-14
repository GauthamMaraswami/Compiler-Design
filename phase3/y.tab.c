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
#line 41 "parser.y" /* yacc.c:358  */

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
	int return_not_void_flag;


#line 201 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

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
       0,    61,    61,    66,    67,    68,    69,    70,    74,    76,
      77,    83,    84,    86,    87,    90,    92,    93,    96,    97,
     103,   105,   106,   114,   117,   120,   123,   125,   127,   129,
     131,   132,   135,   136,   139,   140,   142,   144,   152,   153,
     156,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   176,   177,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   193,   194,   195,
     196,   198,   199,   201,   202,   203,   205,   206,   207,   208,
     210,   211,   214,   215,   217,   218,   221,   222,   225,   226,
     229,   230,   233,   234,   235,   236,   239,   240,   241,   242,
     243,   247,   248,   249,   250,   251,   255,   257,   258,   260,
     261,   264,   267,   268,   271,   273,   274,   275,   276,   277,
     279,   280,   281,   282,   283
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

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,   -24,  -108,  -108,    18,   385,   -15,  -108,  -108,  -108,
    -108,  -108,  -108,   385,    49,   133,  -108,  -108,    88,  -108,
      51,  -108,    85,    96,   138,   115,  -108,  -108,   122,   158,
    -108,  -108,   127,   161,  -108,    66,  -108,  -108,   105,   167,
    -108,   159,  -108,   159,   385,    19,  -108,  -108,  -108,    88,
     194,   119,   173,   175,  -108,   169,  -108,  -108,   172,   265,
    -108,   199,  -108,  -108,   340,  -108,   385,   381,   381,   381,
      16,  -108,   351,  -108,    23,    70,  -108,  -108,   199,   160,
    -108,   199,  -108,  -108,  -108,   360,   183,  -108,  -108,   199,
     290,  -108,  -108,  -108,  -108,   184,   189,  -108,    73,   188,
     193,  -108,   161,   223,  -108,    93,  -108,    18,    26,    91,
    -108,   206,    85,   204,   234,   175,  -108,    54,   340,   208,
    -108,  -108,  -108,  -108,  -108,  -108,   138,   340,  -108,   340,
     217,   219,    75,  -108,   225,    53,  -108,   111,  -108,   228,
    -108,  -108,   216,   385,  -108,  -108,  -108,  -108,  -108,  -108,
     233,  -108,     3,  -108,  -108,   227,    84,  -108,  -108,  -108,
    -108,   163,   -20,   168,   235,   226,  -108,   141,  -108,   230,
    -108,  -108,   152,  -108,   237,   174,  -108,   248,  -108,   181,
     207,   239,  -108,  -108,   319,   382,   386,  -108,  -108,  -108,
     232,   315,  -108,  -108,   388,   399,  -108,   400,   401,   405,
     413,   315,   163,   244,   246,  -108,  -108,   163,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   100,   101,    24,     0,     0,     0,   102,   105,   104,
     103,   112,   113,     0,     0,     0,     2,     4,     9,    11,
       0,    12,     0,     0,    30,     0,     5,     3,     0,    77,
      81,    83,    85,    87,    89,    93,    92,    95,     6,     0,
     100,    78,    82,    93,     0,     0,    99,     1,     8,     9,
       0,    21,     0,    16,    20,     0,    37,    25,     0,     0,
      26,     0,    27,    31,   107,    73,     0,     0,     0,     0,
       0,    79,     0,     7,     0,     0,    94,    10,     0,     0,
      13,     0,    15,    28,    34,     0,     0,    35,    44,     0,
      36,    50,    51,    43,    49,    21,    33,   110,    93,     0,
     108,    80,    86,    84,    88,     0,    76,     0,     0,    93,
      18,     0,     0,     0,     0,    16,    52,     0,     0,     0,
      42,    47,    45,    41,    46,    48,     0,     0,   106,     0,
       0,     0,     0,    96,     0,     0,    14,    68,    23,     0,
      17,    53,     0,     0,    32,   109,    75,    74,    97,    98,
       0,    19,     0,    69,    22,     0,     0,   111,    72,    71,
      70,   115,     0,     0,     0,     0,    91,     0,    90,     0,
     124,   120,     0,   121,     0,     0,   114,     0,    39,    44,
       0,    50,    40,    66,    51,    43,    49,    38,   123,   122,
       0,     0,   118,    67,    42,    47,    62,    45,    41,    46,
      48,     0,   115,     0,     0,   116,   119,   115,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,   242,  -108,   236,    13,     0,    33,   176,  -108,
     211,   241,     6,  -108,  -108,  -108,  -108,   268,  -108,   170,
    -107,  -108,   142,  -108,  -108,   251,   -49,  -102,   136,     1,
    -108,     2,   -42,    -2,     8,  -108,   245,   250,   143,   252,
      -1,  -108,  -108,  -108,  -108,  -108,     9,   -44,  -104,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    48,    18,   179,    52,    82,   135,
      53,    54,    89,    21,    22,    23,    24,    25,    62,    63,
      57,    58,    59,   168,   169,   180,   181,   182,   183,   184,
     160,   185,    28,    29,    30,    31,    32,    33,   124,    34,
      35,    36,    37,    99,   100,    38,    50,   186,   165,   174
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    26,    27,    41,    43,   137,    20,   166,   -29,    39,
      91,    45,    43,    42,    56,    94,     6,    44,    19,     1,
       2,    40,    97,   105,    20,     4,    95,     5,   106,    66,
      61,    49,     7,     8,     9,    10,    66,    56,    19,    26,
      27,   121,    75,    43,    20,   158,   125,    39,    13,    19,
      76,    14,    46,    14,    51,    20,   133,   110,     3,    88,
      92,    93,    49,    98,    66,    43,    43,    43,    43,    98,
     108,   109,    70,   192,   101,    71,   142,    11,    12,   127,
      66,   141,    71,   117,    43,   106,   150,   145,   202,   203,
     120,   122,   123,     3,    66,    72,   130,   131,   205,   204,
     134,   112,    72,   208,    72,   148,   132,   111,     1,     2,
       3,   111,    11,    12,     4,   162,     5,    98,     6,    56,
      72,     7,     8,     9,    10,   152,    98,    60,    98,    11,
      12,   195,    61,    47,    67,   151,   200,    13,   153,    68,
      14,   156,    43,     3,     1,     2,     3,    64,    79,    65,
       4,   -29,     5,   159,     6,   188,   189,     7,     8,     9,
      10,   177,    85,    86,   113,    11,    12,   114,    66,    69,
      74,   170,   171,    13,   178,   172,    14,     1,     2,     3,
     194,   197,   198,     4,   173,     5,   163,     6,    72,   164,
       7,     8,     9,    10,   177,    85,    86,    78,    11,    12,
      80,    83,    95,    81,   -57,    84,    13,   -57,   191,    14,
       1,     2,     3,    79,   -57,   118,     4,   126,     5,   128,
       6,   129,   119,     7,     8,     9,    10,   177,    85,    86,
      67,    11,    12,   136,   138,     1,     2,     3,   139,    13,
     143,     4,    14,     5,   146,     6,   147,   155,     7,     8,
       9,    10,   177,    85,    86,   149,    11,    12,   154,   176,
     157,   161,   -64,   187,    13,   -64,   201,    14,     1,     2,
       3,   175,   -64,   190,     4,   193,     5,   206,     6,   207,
      73,     7,     8,     9,    10,    77,    85,    86,    55,    11,
      12,   140,   115,     1,     2,     3,   144,    13,    87,     4,
      14,     5,    96,     6,   167,   119,     7,     8,     9,    10,
      90,    85,    86,   103,    11,    12,   196,   102,     1,     2,
       3,   104,    13,   199,     4,    14,     5,     0,     6,     0,
       0,     7,     8,     9,    10,   177,    85,    86,     0,    11,
      12,     0,   -65,     1,     2,   -65,     0,    13,     0,     4,
      14,     5,   -65,     0,     1,     2,     7,     8,     9,    10,
     107,     0,     5,     1,     2,     0,     0,     7,     8,     9,
      10,     5,    13,     0,     0,    14,     7,     8,     9,    10,
       0,     0,     0,    13,     1,     2,    14,   116,     1,     2,
       0,     0,    13,     0,     0,    14,     5,     7,     8,     9,
      10,     7,     8,     9,    10,   -56,     0,     0,   -56,   -63,
       0,   -55,   -63,    13,   -55,   -56,    14,    13,     0,   -63,
      14,   -55,   -60,   -58,   -54,   -60,   -58,   -54,   -59,     0,
       0,   -59,   -60,   -58,   -54,     0,   -61,     0,   -59,   -61,
       0,     0,     0,     0,     0,     0,   -61
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,     4,     5,   112,     0,    27,    32,     0,
      59,    13,    13,     5,    34,    59,    13,    32,    18,     3,
       4,     3,    64,     7,    18,     9,     3,    11,    70,    10,
      24,    18,    16,    17,    18,    19,    10,    34,    38,    38,
      38,    90,    44,    44,    38,   152,    90,    38,    32,    49,
      31,    35,     3,    35,     3,    49,    30,    34,     5,    59,
      59,    59,    49,    64,    10,    66,    67,    68,    69,    70,
      72,    72,     6,   175,    66,     9,   118,    24,    25,     6,
      10,    27,     9,    85,    85,   127,    33,   129,   190,   191,
      90,    90,    90,     5,    10,    29,     3,     4,   202,   201,
       9,    31,    29,   207,    29,    30,   107,    74,     3,     4,
       5,    78,    24,    25,     9,    31,    11,   118,    13,    34,
      29,    16,    17,    18,    19,    14,   127,    31,   129,    24,
      25,   180,   126,     0,     7,   135,   180,    32,    27,    12,
      35,   143,   143,     5,     3,     4,     5,    32,    29,    27,
       9,    32,    11,   152,    13,     3,     4,    16,    17,    18,
      19,    20,    21,    22,     4,    24,    25,     7,    10,     8,
       3,     3,     4,    32,    33,     7,    35,     3,     4,     5,
     180,   180,   180,     9,    16,    11,    23,    13,    29,    26,
      16,    17,    18,    19,    20,    21,    22,     3,    24,    25,
      27,    32,     3,    28,    23,    33,    32,    26,    34,    35,
       3,     4,     5,    29,    33,    32,     9,    28,    11,    31,
      13,    28,    15,    16,    17,    18,    19,    20,    21,    22,
       7,    24,    25,    27,    30,     3,     4,     5,     4,    32,
      32,     9,    35,    11,    27,    13,    27,    31,    16,    17,
      18,    19,    20,    21,    22,    30,    24,    25,    30,    33,
      27,    34,    23,    33,    32,    26,    34,    35,     3,     4,
       5,    36,    33,    36,     9,    27,    11,    33,    13,    33,
      38,    16,    17,    18,    19,    49,    21,    22,    20,    24,
      25,   115,    81,     3,     4,     5,   126,    32,    33,     9,
      35,    11,    61,    13,   162,    15,    16,    17,    18,    19,
      59,    21,    22,    68,    24,    25,   180,    67,     3,     4,
       5,    69,    32,   180,     9,    35,    11,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    -1,    23,     3,     4,    26,    -1,    32,    -1,     9,
      35,    11,    33,    -1,     3,     4,    16,    17,    18,    19,
       9,    -1,    11,     3,     4,    -1,    -1,    16,    17,    18,
      19,    11,    32,    -1,    -1,    35,    16,    17,    18,    19,
      -1,    -1,    -1,    32,     3,     4,    35,    27,     3,     4,
      -1,    -1,    32,    -1,    -1,    35,    11,    16,    17,    18,
      19,    16,    17,    18,    19,    23,    -1,    -1,    26,    23,
      -1,    23,    26,    32,    26,    33,    35,    32,    -1,    33,
      35,    33,    23,    23,    23,    26,    26,    26,    23,    -1,
      -1,    26,    33,    33,    33,    -1,    23,    -1,    33,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33
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
      34,    44,    31,     4,     7,    47,    27,    70,    32,    15,
      43,    63,    66,    68,    75,    84,    28,     6,    31,    28,
       3,     4,    77,    30,     9,    46,    27,    57,    30,     4,
      45,    27,    69,    32,    56,    69,    27,    27,    30,    30,
      33,    43,    14,    27,    30,    31,    70,    27,    57,    66,
      67,    34,    31,    23,    26,    85,    27,    59,    60,    61,
       3,     4,     7,    16,    86,    36,    33,    20,    33,    43,
      62,    63,    64,    65,    66,    68,    84,    33,     3,     4,
      36,    34,    64,    27,    43,    63,    65,    66,    68,    75,
      84,    34,    64,    64,    64,    85,    33,    33,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    50,    51,    52,    53,    54,
      55,    55,    56,    56,    57,    57,    58,    59,    60,    60,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    66,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    79,    80,    80,    81,
      81,    82,    83,    83,    84,    85,    85,    85,    85,    85,
      86,    86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     1,     1,     3,     4,     2,     0,     3,     0,     2,
       1,     1,     5,     4,     1,     2,     2,     2,     3,     1,
       0,     1,     4,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     2,     3,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     2,     5,     6,
       7,     1,     1,     2,     5,     5,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     1,     3,     1,
       5,     5,     1,     1,     3,     1,     4,     5,     5,     2,
       1,     1,     1,     1,     1,     1,     4,     0,     1,     3,
       1,     6,     1,     1,     7,     0,     5,     7,     3,     5,
       1,     1,     2,     2,     1
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
#line 62 "parser.y" /* yacc.c:1646  */
    {
	printf("Valid Expressions : ");
}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 105 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),test,id.val,line); /*printf("%s  %s  \n",$1,id.val);*/}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "parser.y" /* yacc.c:1646  */
    {  
							if(strcmp((yyvsp[-2].sval),"-")==0)
							{
								printf("array size cannot be negative at line %d \n",line);
							}
							else{					
	push_to_symbol_table((yyvsp[-4].sval),test,id.val,line);push_to_constants_table((yyvsp[-1].sval),"number",line); }
						}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[-3].sval),test,id.val,line);push_to_constants_table((yyvsp[-1].sval),"number",line); }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 117 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));strcpy(test,(yyvsp[0].sval)); }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "parser.y" /* yacc.c:1646  */
    {if(strcmp((yyvsp[-1].sval),"void")==0&&return_not_void_flag==1){printf("return type mismatch error at line %d \n" ,line);} else if(strcmp((yyvsp[-1].sval),"void")!=0&&return_not_void_flag==0){printf("return type mismatch error at line %d \n" ,line);} return_not_void_flag=0;}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "parser.y" /* yacc.c:1646  */
    { brac_act_flag=1;strcpy((yyval.sval),(yyvsp[-1].sval)); }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 125 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-1].sval));}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "parser.y" /* yacc.c:1646  */
    {  id=openbraceencounter(id);  strcpy((yyval.sval),(yyvsp[-2].sval));}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 129 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));  push_to_symbol_table((yyvsp[0].sval),test,id.val,line);/*printf("%s  %s  \n",$1,id.val);*/ }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 135 "parser.y" /* yacc.c:1646  */
    {if(strcmp((yyvsp[-3].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 136 "parser.y" /* yacc.c:1646  */
    {if(strcmp((yyvsp[-1].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 139 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 140 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 144 "parser.y" /* yacc.c:1646  */
    {/*printf("open");*/ if(brac_act_flag==0) {id=openbraceencounter(id);} else {brac_act_flag=0;} }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 152 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/ id=closebraceencounter(id);}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 153 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 176 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1;}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 177 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 205 "parser.y" /* yacc.c:1646  */
    { /*printf( " found assignment an:   %s\n" ,$2); */}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 221 "parser.y" /* yacc.c:1646  */
    {/*printf("add\n");*/}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 225 "parser.y" /* yacc.c:1646  */
    {/*printf("multiply\n");*/}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 234 "parser.y" /* yacc.c:1646  */
    {/*printf("mutable\n");*/}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 235 "parser.y" /* yacc.c:1646  */
    {/*printf("brackets\n");*/}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 236 "parser.y" /* yacc.c:1646  */
    {/*printf("calling\n");*/}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 242 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),"data",id.val,line);/* printf("%s  %s  \n",$2,id.val); */}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 247 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 248 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 249 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"string",line);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 250 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"float",line);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 251 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 267 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval)); strcpy(test,(yyvsp[0].sval));}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 268 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 279 "parser.y" /* yacc.c:1646  */
    {push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 280 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1697 "y.tab.c" /* yacc.c:1646  */
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
#line 286 "parser.y" /* yacc.c:1906  */

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
/*
	printf("\n\t\t\t\t\tsymbols table\n");
	printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \n","ID","name","type","scope","linecount");
	for(i=0;i<65535;++i)
	{
			if(symboltable[i].valid==1)
			{
				struct symbol * pointer=&symboltable[i];
				while(pointer->next!=NULL)
					{
					printf("%d \t\t %s \t\t %s \t\t %s \t\t %d\n ",i,pointer->name,pointer->type,pointer->scope,pointer->linecount);
						
						
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
	}*/
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

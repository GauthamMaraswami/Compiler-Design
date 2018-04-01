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
	struct var{
			char val[100];
			int type;
	}expressionvar;

#line 170 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 58 "parser.y" /* yacc.c:358  */

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
	int parameter_count=0;
	struct identifier parameter_list[100];
	char funname_global[100];
	int argument_list[100];
	int argument_count=0;
	int elseifflag=0;

#line 210 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

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
       0,    83,    83,    88,    89,    90,    91,    92,    96,    98,
      99,   104,   105,   107,   108,   111,   113,   114,   117,   118,
     124,   126,   127,   135,   138,   141,   145,   154,   156,   158,
     160,   161,   164,   169,   176,   183,   190,   192,   200,   201,
     204,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   225,   226,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   242,   244,
     245,   246,   248,   251,   255,   257,   264,   265,   265,   267,
     269,   281,   282,   283,   285,   286,   292,   299,   300,   303,
     304,   306,   307,   310,   311,   314,   315,   318,   319,   324,
     325,   326,   327,   330,   331,   333,   346,   349,   353,   357,
     361,   365,   372,   373,   374,   375,   376,   380,   399,   400,
     402,   405,   411,   414,   415,   418,   420,   421,   422,   423,
     424,   427,   428,   429,   430,   431
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
  "markif", "selectiontomarkendofif", "elsetoputflag", "selectionstmt1",
  "selectionhelper", "$@1", "expressionsemi", "expression",
  "expressionhelper", "simpleExpression", "unaryRelExpression",
  "relExpression", "sumExpression", "term", "iterationwhile", "factor",
  "mutable", "mutablearr", "immutable", "callingnosq", "args", "arglist",
  "structoruniondefn", "structspecifier", "switch", "switchstatement",
  "switchimmutable", YY_NULLPTR
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

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     317,    63,  -129,  -129,    20,   395,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   328,    26,    14,  -129,  -129,    62,  -129,
      57,  -129,    32,     6,    65,    50,  -129,    56,  -129,    79,
    -129,    80,  -129,  -129,    19,   113,  -129,   117,    75,  -129,
    -129,   317,   124,   350,    99,  -129,  -129,  -129,   101,   129,
    -129,  -129,  -129,    62,   141,   110,   128,   133,  -129,  -129,
    -129,   127,   242,  -129,   165,  -129,  -129,   328,   395,  -129,
     395,    16,    16,    16,    98,  -129,   361,  -129,    25,    20,
      15,   160,  -129,  -129,   165,   195,  -129,  -129,   165,  -129,
    -129,   144,   370,   145,  -129,  -129,   165,   292,  -129,  -129,
    -129,  -129,  -129,   149,   158,  -129,   157,   175,   174,    80,
    -129,   113,   208,  -129,   155,  -129,    20,    28,   210,  -129,
     190,   191,  -129,   193,   206,   233,   133,   395,  -129,    42,
     395,  -129,  -129,  -129,  -129,  -129,  -129,    65,  -129,   328,
     -12,  -129,  -129,   218,  -129,   220,    60,  -129,  -129,  -129,
    -129,   222,  -129,   207,  -129,   223,  -129,  -129,  -129,  -129,
     248,  -129,  -129,   213,  -129,  -129,    34,   231,  -129,   243,
    -129,  -129,   132,  -129,   235,   181,  -129,  -129,    32,   246,
    -129,    77,   267,    96,  -129,  -129,   183,   216,   325,  -129,
     159,   245,   236,  -129,  -129,   368,   377,  -129,   392,   393,
     398,   406,  -129,  -129,   109,  -129,   254,   176,  -129,  -129,
    -129,   209,   267,  -129,   267,   181,   260,   261,  -129,  -129,
     181,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   105,   112,    24,     0,     0,    72,   113,   116,   115,
     114,   123,   124,     0,     0,     0,     2,     4,     9,    11,
       0,    12,     0,     0,    30,     0,     5,     0,     3,     0,
      81,    84,    88,    90,    92,    94,    96,   100,   103,    99,
     102,     6,     0,     0,   105,    85,    89,   100,     0,   100,
     104,     1,     8,     9,     0,    21,     0,    16,    20,    37,
      25,     0,     0,    26,     0,    27,    31,   118,     0,    79,
       0,     0,     0,     0,     0,    86,     0,     7,     0,     0,
       0,   100,   101,    10,     0,     0,    28,    13,     0,    15,
      34,     0,     0,     0,    35,    44,     0,    36,    51,    52,
      43,    50,    49,    21,    33,   121,     0,   119,     0,    75,
      87,    93,    91,    95,     0,    80,     0,     0,   100,    18,
       0,     0,   109,     0,     0,     0,    16,     0,    53,     0,
       0,    42,    47,    45,    41,    46,    48,     0,   117,     0,
       0,    83,    82,     0,   106,     0,     0,    14,   110,   111,
      23,     0,    17,     0,    54,     0,    32,   120,    70,    73,
      69,   107,   108,     0,    19,    22,     0,     0,    74,    77,
     122,    98,     0,    97,     0,   126,    76,    71,     0,     0,
      39,    44,     0,    51,    40,    67,    52,    43,    49,    38,
       0,     0,     0,    78,    68,    42,    47,    63,    45,    41,
      46,    48,   135,   131,     0,   132,     0,     0,   125,   134,
     133,     0,     0,   129,     0,   126,     0,     0,   127,   130,
     126,   128
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   238,  -129,   247,    -7,     0,   -48,   172,  -129,
     224,   240,     3,  -129,  -129,  -129,  -129,  -129,  -129,   169,
    -128,  -129,   152,  -129,  -129,   253,   -58,   226,   137,     1,
    -129,  -129,  -129,   105,  -129,  -129,     2,   -60,    -3,   -19,
      11,  -129,   251,   258,   -91,   252,     4,  -129,   229,  -129,
    -129,  -129,  -129,    13,   -57,  -126,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    52,    18,   181,    56,    89,   146,
      57,    58,    96,    21,    22,    23,    24,    25,    65,    66,
      60,    61,    62,   173,   174,   182,   183,   184,   185,   186,
      27,   160,   169,   108,   177,   178,   187,    29,    30,    31,
      32,    33,    34,    35,   101,    36,    37,    38,    39,    40,
     106,   107,    41,    54,   188,   192,   206
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    26,    28,    20,    98,   102,   135,   105,    45,    47,
      48,    53,   159,    42,    51,   158,    46,    49,    19,     1,
       2,    20,    59,    44,    80,    70,    71,    64,   103,    50,
     120,    72,     7,     8,     9,    10,   120,    63,    70,   132,
     136,    19,    26,    28,    20,   122,    53,    81,    13,   109,
     193,    14,    70,    19,    42,    14,    20,   117,   144,   119,
      55,   171,    95,    99,   100,     3,    59,     3,    59,   154,
       3,   115,    47,   129,    47,    47,    47,    47,    49,   157,
     118,   110,    67,   121,    11,    12,    11,    12,    68,   218,
      70,   200,    43,   163,   221,   -29,    47,   131,   133,   134,
     -58,     1,     2,   -58,    76,   114,    69,     4,   109,     5,
     -58,   109,   209,   210,     7,     8,     9,    10,   141,   -65,
     143,    73,   -65,    74,   196,   201,    75,    78,    43,   -65,
      13,    47,    82,    14,    47,     1,     2,     3,    75,    85,
      64,     4,    86,     5,    84,     6,   164,    91,     7,     8,
       9,    10,   179,    92,    93,    87,    11,    12,    44,     2,
      90,    88,   202,   203,    13,   180,   204,    14,   103,   123,
     176,     7,     8,     9,    10,   205,   127,   130,    85,     1,
       2,     3,   195,   198,   199,     4,   137,     5,   138,     6,
      14,    91,     7,     8,     9,    10,   179,    92,    93,   124,
      11,    12,   125,   139,   190,   140,   -66,   191,    13,   -66,
     212,    14,     1,     2,     3,    71,   -66,   147,     4,   145,
       5,   148,     6,   149,    91,     7,     8,     9,    10,   179,
      92,    93,   153,    11,    12,   155,   150,   151,   166,   -57,
     170,    13,   -57,   214,    14,     1,     2,     3,   161,   -57,
     162,     4,   165,     5,   167,     6,     6,    91,     7,     8,
       9,    10,   168,    92,    93,   175,    11,    12,   189,   208,
       1,     2,     3,   194,    13,    94,     4,    14,     5,    77,
       6,   207,    91,     7,     8,     9,    10,   179,    92,    93,
     211,    11,    12,   219,   220,     1,     2,     3,   152,    13,
      83,     4,    14,     5,   104,     6,   156,    91,     7,     8,
       9,    10,   126,    92,    93,    97,    11,    12,   172,   197,
       1,     2,     3,   112,    13,   113,     4,    14,     5,   111,
       6,     1,     2,     7,     8,     9,    10,     4,     0,     5,
       0,    11,    12,   142,     7,     8,     9,    10,   -64,    13,
       0,   -64,    14,     1,     2,     0,     0,     0,   -64,    79,
      13,     5,     0,    14,     1,     2,     7,     8,     9,    10,
     116,     0,     5,     1,     2,     0,     0,     7,     8,     9,
      10,     5,    13,     0,     0,    14,     7,     8,     9,    10,
       0,   -56,     0,    13,   -56,     0,    14,   128,     1,     2,
     -61,   -56,    13,   -61,     0,    14,     5,     0,     0,     0,
     -61,     7,     8,     9,    10,   -59,   -55,     0,   -59,   -55,
       0,   -60,     0,     0,   -60,   -59,   -55,    13,     0,   -62,
      14,   -60,   -62,   213,     0,     0,     0,   215,   216,   -62,
     217
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,     0,    62,    62,    97,    67,     4,     5,
      13,    18,   140,     0,     0,    27,     5,    13,    18,     3,
       4,    18,    34,     3,    43,    10,     7,    24,     3,     3,
      78,    12,    16,    17,    18,    19,    84,    31,    10,    97,
      97,    41,    41,    41,    41,    30,    53,    43,    32,    68,
     178,    35,    10,    53,    41,    35,    53,    76,    30,    34,
       3,    27,    62,    62,    62,     5,    34,     5,    34,    27,
       5,    74,    68,    92,    70,    71,    72,    73,    74,   139,
      76,    70,    32,    79,    24,    25,    24,    25,    32,   215,
      10,   182,    29,    33,   220,    32,    92,    97,    97,    97,
      23,     3,     4,    26,    29,     7,    27,     9,   127,    11,
      33,   130,     3,     4,    16,    17,    18,    19,   114,    23,
     116,     8,    26,     6,   182,   182,     9,     3,    29,    33,
      32,   127,    31,    35,   130,     3,     4,     5,     9,    29,
     137,     9,    32,    11,     3,    13,   146,    15,    16,    17,
      18,    19,    20,    21,    22,    27,    24,    25,     3,     4,
      33,    28,     3,     4,    32,    33,     7,    35,     3,     9,
     169,    16,    17,    18,    19,    16,    32,    32,    29,     3,
       4,     5,   182,   182,   182,     9,    28,    11,    31,    13,
      35,    15,    16,    17,    18,    19,    20,    21,    22,     4,
      24,    25,     7,    28,    23,    31,    23,    26,    32,    26,
      34,    35,     3,     4,     5,     7,    33,    27,     9,     9,
      11,    30,    13,    30,    15,    16,    17,    18,    19,    20,
      21,    22,   127,    24,    25,   130,    30,     4,    31,    23,
      27,    32,    26,    34,    35,     3,     4,     5,    30,    33,
      30,     9,    30,    11,    31,    13,    13,    15,    16,    17,
      18,    19,    14,    21,    22,    34,    24,    25,    33,    33,
       3,     4,     5,    27,    32,    33,     9,    35,    11,    41,
      13,    36,    15,    16,    17,    18,    19,    20,    21,    22,
      36,    24,    25,    33,    33,     3,     4,     5,   126,    32,
      53,     9,    35,    11,    64,    13,   137,    15,    16,    17,
      18,    19,    88,    21,    22,    62,    24,    25,   166,   182,
       3,     4,     5,    72,    32,    73,     9,    35,    11,    71,
      13,     3,     4,    16,    17,    18,    19,     9,    -1,    11,
      -1,    24,    25,   114,    16,    17,    18,    19,    23,    32,
      -1,    26,    35,     3,     4,    -1,    -1,    -1,    33,     9,
      32,    11,    -1,    35,     3,     4,    16,    17,    18,    19,
       9,    -1,    11,     3,     4,    -1,    -1,    16,    17,    18,
      19,    11,    32,    -1,    -1,    35,    16,    17,    18,    19,
      -1,    23,    -1,    32,    26,    -1,    35,    27,     3,     4,
      23,    33,    32,    26,    -1,    35,    11,    -1,    -1,    -1,
      33,    16,    17,    18,    19,    23,    23,    -1,    26,    26,
      -1,    23,    -1,    -1,    26,    33,    33,    32,    -1,    23,
      35,    33,    26,   207,    -1,    -1,    -1,   211,   212,    33,
     214
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    11,    13,    16,    17,    18,
      19,    24,    25,    32,    35,    38,    39,    40,    42,    43,
      49,    50,    51,    52,    53,    54,    66,    67,    73,    74,
      75,    76,    77,    78,    79,    80,    82,    83,    84,    85,
      86,    89,    90,    29,     3,    83,    77,    83,    75,    83,
       3,     0,    41,    42,    90,     3,    44,    47,    48,    34,
      57,    58,    59,    31,    49,    55,    56,    32,    32,    27,
      10,     7,    12,     8,     6,     9,    29,    39,     3,     9,
      76,    83,    31,    41,     3,    29,    32,    27,    28,    45,
      33,    15,    21,    22,    33,    43,    49,    62,    63,    66,
      73,    81,    91,     3,    48,    74,    87,    88,    70,    76,
      77,    80,    79,    82,     7,    75,     9,    76,    83,    34,
      44,    83,    30,     9,     4,     7,    47,    32,    27,    76,
      32,    43,    63,    66,    73,    81,    91,    28,    31,    28,
      31,    83,    85,    83,    30,     9,    46,    27,    30,    30,
      30,     4,    45,    70,    27,    70,    56,    74,    27,    57,
      68,    30,    30,    33,    43,    30,    31,    31,    14,    69,
      27,    27,    59,    60,    61,    34,    66,    71,    72,    20,
      33,    43,    62,    63,    64,    65,    66,    73,    91,    33,
      23,    26,    92,    57,    27,    43,    63,    65,    66,    73,
      81,    91,     3,     4,     7,    16,    93,    36,    33,     3,
       4,    36,    34,    64,    34,    64,    64,    64,    92,    33,
      33,    92
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    50,    51,    52,    53,    54,
      55,    55,    56,    56,    57,    57,    58,    59,    60,    60,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    66,
      66,    66,    67,    68,    69,    70,    71,    72,    71,    73,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    86,    87,    87,
      88,    88,    89,    90,    90,    91,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     1,     1,     3,     4,     2,     0,     3,     0,     2,
       1,     1,     5,     4,     1,     2,     2,     2,     3,     1,
       0,     1,     4,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     2,     3,     2,     2,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     5,
       5,     7,     1,     1,     1,     1,     1,     0,     2,     2,
       3,     1,     4,     4,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     5,     5,     1,
       1,     3,     1,     1,     2,     1,     4,     5,     5,     4,
       5,     5,     1,     1,     1,     1,     1,     4,     0,     1,
       3,     1,     6,     1,     1,     7,     0,     5,     7,     3,
       5,     1,     1,     2,     2,     1
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
#line 84 "parser.y" /* yacc.c:1646  */
    {
	printf("Valid Expressions : \n");
}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;fixgoto();}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "parser.y" /* yacc.c:1646  */
    {CreateDocument("return","","","",0,0);}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.sval),(yyvsp[0].sval));push_to_symbol_table((yyvsp[0].sval),test,id.val,line,0,"0",parameter_list,0,"-1"); /*printf("%s  %s  \n",$1,id.val);*/}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "parser.y" /* yacc.c:1646  */
    {  strcpy((yyval.sval),(yyvsp[-4].sval));
							if(strcmp((yyvsp[-2].sval),"-")==0)
							{
								printf("array size cannot be negative at line %d \n",line);
							}
							else{					
	push_to_symbol_table((yyvsp[-4].sval),test,id.val,line,0,(yyvsp[-1].sval),parameter_list,0,"-1");push_to_constants_table((yyvsp[-1].sval),"number",line); }
						}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-3].sval)); push_to_symbol_table((yyvsp[-3].sval),test,id.val,line,0,(yyvsp[-1].sval),parameter_list,0,"-1");push_to_constants_table((yyvsp[-1].sval),"number",line); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 138 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));strcpy(test,(yyvsp[0].sval)); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "parser.y" /* yacc.c:1646  */
    { //failhandler
	if(strcmp((yyvsp[-1].sval),"void")==0&&return_not_void_flag==1){printf("return type mismatch error at line %d \n" ,line);} else if(strcmp((yyvsp[-1].sval),"void")!=0&&return_not_void_flag==0){printf("return type mismatch error at line %d \n" ,line);} return_not_void_flag=0;}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 145 "parser.y" /* yacc.c:1646  */
    { brac_act_flag=1;strcpy((yyval.sval),(yyvsp[-1].sval));
	//this part of the code may not work if it fails copy l+5 and l+6 to failhandler
	struct string tempid;
	tempid=id;
	id.val[id.len-1]='\0';
	push_to_symbol_table(funname_global,(yyvsp[-1].sval),id.val,line,1,"0",parameter_list,parameter_count,tempid.val);
	parameter_count=0;
	id=tempid; }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-1].sval));}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 156 "parser.y" /* yacc.c:1646  */
    { strcpy(funname_global,(yyvsp[-1].sval)); id=openbraceencounter(id); strcpy((yyval.sval),(yyvsp[-2].sval));CreateDocument("goto 1","","","",0,0);}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "parser.y" /* yacc.c:1646  */
    {  }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "parser.y" /* yacc.c:1646  */
    {         
	strcpy(parameter_list[parameter_count].name,(yyvsp[-2].sval));
	strcpy(parameter_list[parameter_count].type,(yyvsp[-3].sval));
	++parameter_count;
	if(strcmp((yyvsp[-3].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 169 "parser.y" /* yacc.c:1646  */
    {
	strcpy(parameter_list[parameter_count].name,(yyvsp[0].sval));
	strcpy(parameter_list[parameter_count].type,(yyvsp[-1].sval));
	++parameter_count;
	if(strcmp((yyvsp[-1].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 176 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id); if(elseifflag==0)
{update_goto_stmt(2);}
else if(elseifflag==2)
{}
else
{update_goto_stmt(0);}}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 183 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);if(elseifflag==0)
{update_goto_stmt(2);}
else if(elseifflag==2)
{}
else
{update_goto_stmt(0);}}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "parser.y" /* yacc.c:1646  */
    {/*printf("open");*/ if(brac_act_flag==0) {id=openbraceencounter(id);} else {brac_act_flag=0;} }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 200 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/ id=closebraceencounter(id);}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 201 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;fixgoto();}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 221 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;fixgoto();}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 225 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1;}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 226 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1; if((yyvsp[-1].expressionvar).type==2||(yyvsp[-1].expressionvar).type==4||(yyvsp[-1].expressionvar).type==7){printf("return type cannot be array at %d\n",line);}}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 232 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;fixgoto();}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 239 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;fixgoto();}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 248 "parser.y" /* yacc.c:1646  */
    {if(elseifflag==0){push(-1,1);}}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 251 "parser.y" /* yacc.c:1646  */
    {addgotoonsuccessexec();}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 255 "parser.y" /* yacc.c:1646  */
    {elseifflag=1;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 257 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].expressionvar).type!=1){printf("expression in test  is not of type int at line %d\n",line-3);}
CreateDocument((yyvsp[0].expressionvar).val,"","","",1,0);
CreateDocument("","","","",0,1);

	}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 265 "parser.y" /* yacc.c:1646  */
    {elseifflag=2;}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.expressionvar).type=(yyvsp[0].expressionvar).type;
if(strlen((yyvsp[-1].sval))==2)
{
	char tempe[10];
	char c[10];CreateTempvar(c);
	strncpy(tempe,(yyvsp[-1].sval),1);
	CreateDocument(c,(yyvsp[-2].expressionvar).val,tempe,(yyvsp[0].expressionvar).val,0,0);
	CreateDocument((yyvsp[-2].expressionvar).val,c,"","",0,0);
}
else{
CreateDocument((yyvsp[-2].expressionvar).val,"","",(yyvsp[0].expressionvar).val,0,0); 
}}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 282 "parser.y" /* yacc.c:1646  */
    {CreateDocument((yyvsp[-3].expressionvar).val,"",(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 283 "parser.y" /* yacc.c:1646  */
    {CreateDocument((yyvsp[-3].expressionvar).val,"",(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0); }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;char c[10];CreateTempvar(c);if(strcmp((yyvsp[-1].sval),"++")==0){CreateDocument(c,(yyvsp[0].expressionvar).val,"+","1",0,0);}
else{
CreateDocument(c,(yyvsp[0].expressionvar).val,"-","1",0,0);	
}
CreateDocument((yyvsp[0].expressionvar).val,"","",c,0,0); 
strcpy((yyval.expressionvar).val,c);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-1].expressionvar).type;char c[10];CreateTempvar(c);if(strcmp((yyvsp[0].sval),"++")==0){CreateDocument(c,(yyvsp[-1].expressionvar).val,"+","1",0,0);}
else{
CreateDocument(c,(yyvsp[-1].expressionvar).val,"-","1",0,0);	
}
CreateDocument((yyvsp[-1].expressionvar).val,"","",c,0,0); 
strcpy((yyval.expressionvar).val,(yyvsp[-1].expressionvar).val);}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=1; char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=1;char c[10];CreateTempvar(c);CreateDocument(c,"","not",(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=1;char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=min((yyvsp[-2].expressionvar).type,(yyvsp[0].expressionvar).type); char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=min((yyvsp[-2].expressionvar).type,(yyvsp[0].expressionvar).type); char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;  strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 318 "parser.y" /* yacc.c:1646  */
    {update_goto_stmt(1);  }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 319 "parser.y" /* yacc.c:1646  */
    {update_goto_stmt(1);}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;  strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-1].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[-1].expressionvar).val);}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=-10;}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 330 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 331 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),"data",id.val,line,0,"0",parameter_list,0,"-1");
/* printf("%s  %s  \n",$2,id.val); */}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 333 "parser.y" /* yacc.c:1646  */
    { int ans=checkdeclaration(id,(yyvsp[0].sval));
/*printf("kkk%smmm%dlll%d\n,",$1,ans,line);*/
 if(ans==0){printf("variable %s is not declared in this scope at line %d \n",(yyvsp[0].sval),line);}
else if(ans==-1){printf("identifier %s previously defined as procedure at line %d\n",(yyvsp[0].sval),line);}
else if(ans==5){printf("identifier %s declared as void at line %d\n",(yyvsp[0].sval),line);}
else if(ans==2||ans==4||ans==7){printf("identifier %s is of type array line %d\n",(yyvsp[0].sval),line);}
 (yyval.expressionvar).type=ans;
 strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-3].expressionvar).type; sprintf((yyval.expressionvar).val,"%s%s%s%s",(yyvsp[-3].expressionvar).val,"[",(yyvsp[-1].expressionvar).val,"]");if((yyvsp[-1].expressionvar).type!=1)
 {printf("Expression in subscript not of type int at line %d\n",line);} 
 if((yyvsp[-3].expressionvar).type!=2&&(yyvsp[-3].expressionvar).type!=4&&(yyvsp[-3].expressionvar).type!=7) {printf("variable  is  at line is not declared as array %d\n",line);}}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-4].expressionvar).type; sprintf((yyval.expressionvar).val,"%s%s%s%s%s",(yyvsp[-4].expressionvar).val,"[",(yyvsp[-2].sval),(yyvsp[-1].expressionvar).val,"]");
if((yyvsp[-1].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if((yyvsp[-4].expressionvar).type!=2&&(yyvsp[-4].expressionvar).type!=4&&(yyvsp[-4].expressionvar).type!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-4].expressionvar).type;sprintf((yyval.expressionvar).val,"%s%s%s%s%s",(yyvsp[-4].expressionvar).val,"[",(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),"]");
if((yyvsp[-2].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if((yyvsp[-4].expressionvar).type!=2&&(yyvsp[-4].expressionvar).type!=4&&(yyvsp[-4].expressionvar).type!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 357 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclaration(id,(yyvsp[-3].sval)); (yyval.expressionvar).type=ans;sprintf((yyval.expressionvar).val,"%s%s%s%s",(yyvsp[-3].sval),"[",(yyvsp[-1].expressionvar).val,"]");
 if((yyvsp[-1].expressionvar).type!=1)
 {printf("Expression in subscript not of type int at line %d\n",line);} 
 if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 361 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclaration(id,(yyvsp[-4].sval)); (yyval.expressionvar).type=ans;sprintf((yyval.expressionvar).val,"%s%s%s%s%s",(yyvsp[-4].sval),"[",(yyvsp[-2].sval),(yyvsp[-1].expressionvar).val,"]");
if((yyvsp[-1].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 365 "parser.y" /* yacc.c:1646  */
    {  int ans=checkdeclaration(id,(yyvsp[-4].sval)); (yyval.expressionvar).type=ans;sprintf((yyval.expressionvar).val,"%s%s%s%s%s",(yyvsp[-4].sval),"[",(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),"]");
if((yyvsp[-2].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 372 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line); (yyval.expressionvar).type=1; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 373 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);(yyval.expressionvar).type=3; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 374 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"string",line);(yyval.expressionvar).type=4; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 375 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"float",line);(yyval.expressionvar).type=6; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 376 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);(yyval.expressionvar).type=-1; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 380 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclarationfunction(id,(yyvsp[-3].sval)); 
if(ans==0){printf("function %s is not declared in this scope at line %d \n",(yyvsp[-3].sval),line);}
else if(ans==-1){printf("identifier %s not declared as procedure at line %d\n",(yyvsp[-3].sval),line);}
else if(ans==-3){printf("return type of function %s is of type array at line %d\n",(yyvsp[-3].sval),line);}
else {int noparam=getnoofparametes(id,(yyvsp[-3].sval)); 
if(noparam!=(yyvsp[-1].ival)){printf("no of parameters does not match for function %s\n",(yyvsp[-3].sval));}
else {
int matched=match_params(argument_list,argument_count,id,(yyvsp[-3].sval));
if (matched==0)
{
	printf("argument types does not match\n");
}

}

}
argument_count=0;
}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 399 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=0;}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 400 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 402 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-2].ival)+1; if((yyvsp[0].expressionvar).type==2||(yyvsp[0].expressionvar).type==4||(yyvsp[0].expressionvar).type==7){argument_list[argument_count]=1;}
else {argument_list[argument_count]=0;}
++argument_count;}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 405 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1; if((yyvsp[0].expressionvar).type==2||(yyvsp[0].expressionvar).type==4||(yyvsp[0].expressionvar).type==7){argument_list[argument_count]=1;}
else {argument_list[argument_count]=0;}
++argument_count;
}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 414 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval)); strcpy(test,(yyvsp[0].sval));}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 415 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 418 "parser.y" /* yacc.c:1646  */
    { }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 427 "parser.y" /* yacc.c:1646  */
    {push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 428 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 429 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 430 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2081 "y.tab.c" /* yacc.c:1646  */
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
#line 434 "parser.y" /* yacc.c:1906  */

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

	yyin=fopen("Testcases/testcase6.c","r");
	
	yyparse();
	
	printthreeaddresscode();
	printf("\n\t\t\t\t\tsymbols table\n");
	printf("%s \t %s \t %s \t %s \t %s  %s \t %s \t %s   %s\n","ID","name","type","scope","linecount","fun_def_flag","array_dim","paramcount","parameters");
	for(i=0;i<65535;++i)
	{
			if(symboltable[i].valid==1)
			{
				struct symbol * pointer=&symboltable[i];
				while(pointer->next!=NULL)
					{
					printf("%d \t %s \t %s \t %s \t %d \t\t %d \t\t %s \t\t %d \t\t",i,pointer->name,pointer->type,pointer->scope,pointer->linecount,pointer->proc_defn_flag,pointer->arraydimention,pointer->parameter_count);
						for(int zz=0;zz<pointer->parameter_count;++zz)
						{
							printf("%s%s ",pointer->parameter_list[zz].type,pointer->parameter_list[zz].name);
						}
						printf("\n");
							pointer=pointer->next;
						
					}
				printf("%d \t %s \t %s \t %s \t %d \t\t %d \t\t %s \t\t %d \t\t",i,pointer->name,pointer->type,pointer->scope,pointer->linecount,pointer->proc_defn_flag,pointer->arraydimention,pointer->parameter_count);	
					for(int zz=0;zz<pointer->parameter_count;++zz)
						{
							printf("%s%s ",pointer->parameter_list[zz].type,pointer->parameter_list[zz].name);
						}
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

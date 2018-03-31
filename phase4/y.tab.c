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
			char val[10];
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
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

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
     160,   161,   164,   169,   176,   177,   179,   181,   189,   190,
     193,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   214,   215,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   231,   233,
     234,   235,   237,   239,   249,   250,   252,   253,   254,   256,
     257,   259,   260,   266,   273,   274,   277,   278,   280,   281,
     284,   285,   288,   289,   292,   293,   298,   299,   300,   301,
     304,   305,   307,   320,   323,   327,   331,   335,   339,   346,
     347,   348,   349,   350,   354,   373,   374,   376,   379,   385,
     388,   389,   392,   394,   395,   396,   397,   398,   401,   402,
     403,   404,   405
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
  "elsetoputflag", "selectionstmt1", "selectionhelper", "expressionsemi",
  "expression", "expressionhelper", "simpleExpression",
  "unaryRelExpression", "relExpression", "sumExpression", "term",
  "iterationwhile", "factor", "mutable", "mutablearr", "immutable",
  "callingnosq", "args", "arglist", "structoruniondefn", "structspecifier",
  "switch", "switchstatement", "switchimmutable", YY_NULLPTR
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

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     319,    40,  -115,  -115,    10,   412,    36,  -115,  -115,  -115,
    -115,  -115,  -115,   357,    35,   102,  -115,  -115,    25,  -115,
      82,  -115,    77,    64,   112,    97,  -115,  -115,   100,  -115,
     152,  -115,  -115,    79,   159,  -115,   104,   151,  -115,  -115,
     319,   187,   368,   163,  -115,  -115,  -115,   412,   157,   192,
    -115,  -115,  -115,    25,   201,   127,   179,   177,  -115,  -115,
    -115,   174,   244,  -115,   206,  -115,  -115,   357,  -115,   412,
     416,   416,   416,   346,  -115,   379,  -115,    23,    10,    29,
     208,   188,   152,  -115,  -115,   206,    27,  -115,  -115,   206,
    -115,  -115,   189,   390,   191,  -115,  -115,   206,   294,  -115,
    -115,  -115,  -115,  -115,   196,   209,  -115,   166,   203,   210,
    -115,   159,   232,  -115,   136,  -115,    10,    51,   231,  -115,
     215,   220,  -115,   222,    77,   224,   252,   177,   412,  -115,
      56,   412,  -115,  -115,  -115,  -115,  -115,  -115,   112,   357,
    -115,   357,   237,   240,   228,  -115,   241,    11,  -115,  -115,
    -115,     6,  -115,   245,  -115,   239,  -115,   250,  -115,  -115,
    -115,  -115,  -115,  -115,   256,  -115,  -115,  -115,    -6,  -115,
      33,   258,  -115,  -115,  -115,  -115,  -115,   133,  -115,   262,
     150,   273,  -115,    -1,   269,    61,  -115,  -115,    70,    81,
      83,  -115,    85,   260,   275,  -115,    89,    95,  -115,   137,
     138,   185,   218,  -115,  -115,   175,  -115,   266,   178,  -115,
    -115,  -115,   211,   269,  -115,   269,   150,   281,   284,  -115,
    -115,   150,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,   109,    24,     0,     0,     0,   110,   113,   112,
     111,   120,   121,     0,     0,     0,     2,     4,     9,    11,
       0,    12,     0,     0,    30,     0,     5,     3,     0,    80,
      81,    85,    87,    89,    91,    93,    97,   100,    96,    99,
       6,     0,     0,   102,    82,    86,    97,     0,     0,    97,
     101,     1,     8,     9,     0,    21,     0,    16,    20,    37,
      25,     0,     0,    26,     0,    27,    31,   115,    76,     0,
       0,     0,     0,     0,    83,     0,     7,     0,     0,     0,
      97,     0,    73,    98,    10,     0,     0,    28,    13,     0,
      15,    34,     0,     0,     0,    35,    44,     0,    36,    51,
      52,    43,    50,    49,    21,    33,   118,    97,     0,   116,
      84,    90,    88,    92,     0,    79,     0,     0,    97,    18,
       0,     0,   106,     0,     0,     0,     0,    16,     0,    53,
       0,     0,    42,    47,    45,    41,    46,    48,     0,     0,
     114,     0,     0,     0,     0,   103,     0,     0,    14,   107,
     108,    69,    23,     0,    17,     0,    54,     0,    32,   117,
      78,    77,   104,   105,     0,    19,    72,    70,     0,    22,
       0,     0,   119,    75,    74,    71,    95,     0,    94,     0,
     123,     0,    39,    44,     0,    51,    40,    67,    52,    43,
      49,    38,     0,     0,     0,    68,    42,    47,    63,    45,
      41,    46,    48,   132,   128,     0,   129,     0,     0,   122,
     131,   130,     0,     0,   126,     0,   123,     0,     0,   124,
     127,   123,   125
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,   280,  -115,   253,     5,     0,   -48,   194,  -115,
     236,   263,     3,  -115,  -115,  -115,  -115,  -115,  -115,   193,
    -114,  -115,   164,  -115,  -115,   271,   -51,   -89,   155,     1,
    -115,    46,  -115,     2,   -61,    -8,   -23,     9,  -115,   270,
     272,   -94,   268,     4,  -115,  -115,  -115,  -115,  -115,  -115,
      15,   -50,   -91,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    52,    18,   183,    56,    90,   147,
      57,    58,    97,    21,    22,    23,    24,    25,    65,    66,
      60,    61,    62,   178,   179,   184,   185,   186,   187,   188,
     168,    81,   175,   189,    28,    29,    30,    31,    32,    33,
      34,   102,    35,    36,    37,    38,    39,   108,   109,    40,
      54,   190,   194,   207
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    26,    27,    20,   136,    48,   106,     6,    44,    46,
     151,    99,   103,    43,    45,    41,     3,    49,    19,    79,
     166,    20,   -58,    53,    82,   -58,   104,    64,    59,   120,
       3,   125,   -58,   167,   126,    11,    12,   120,    50,    69,
      19,    26,    27,    20,   164,    14,    80,   133,   137,    11,
      12,    46,   117,    19,   173,    41,    20,   119,    53,   122,
     176,    69,    96,   100,   101,   115,    69,    59,    47,    42,
     130,   107,   -29,    46,    46,    46,    46,    49,   110,   118,
     159,   145,   121,   156,   -65,    55,    70,   -65,   203,   204,
     201,    71,   205,   -66,   -65,    63,   -66,    46,   132,   134,
     135,   206,    51,   -66,   -57,    82,   -64,   -57,    82,   -64,
      73,    59,   -56,    74,   -57,   -56,   -64,     3,   -61,   214,
     144,   -61,   -56,   216,   217,   219,   218,    68,   -61,    67,
     222,   115,    46,   197,   202,    46,     1,     2,     3,   142,
     143,    64,     4,    49,     5,   107,     6,   165,    92,     7,
       8,     9,    10,   181,    93,    94,    86,    11,    12,    87,
     -59,   -55,    69,   -59,   -55,    13,   182,    72,    14,   174,
     -59,   -55,   139,   192,   155,    74,   193,   157,   210,   211,
      75,     1,     2,     3,   196,   199,   200,     4,    83,     5,
      77,     6,    42,    92,     7,     8,     9,    10,   181,    93,
      94,    74,    11,    12,    85,    89,    88,    91,   -60,   104,
      13,   -60,   213,    14,     1,     2,     3,   123,   -60,   124,
       4,   128,     5,   131,     6,    86,    92,     7,     8,     9,
      10,   181,    93,    94,   140,    11,    12,   138,   141,    70,
     146,   -62,   148,    13,   -62,   215,    14,     1,     2,     3,
     149,   -62,   150,     4,   152,     5,   153,     6,   162,    92,
       7,     8,     9,    10,   160,    93,    94,   161,    11,    12,
     170,   163,     1,     2,     3,   169,    13,    95,     4,    14,
       5,   171,     6,   172,    92,     7,     8,     9,    10,   181,
      93,    94,   180,    11,    12,   191,   208,     1,     2,     3,
     195,    13,   212,     4,    14,     5,    84,     6,   209,    92,
       7,     8,     9,    10,   220,    93,    94,   221,    11,    12,
      76,   154,     1,     2,     3,   127,    13,   105,     4,    14,
       5,   158,     6,    98,   177,     7,     8,     9,    10,   198,
     113,   112,   111,    11,    12,     0,     0,     0,     0,     1,
       2,    13,     0,   114,    14,     4,     0,     5,     0,     0,
       1,     2,     7,     8,     9,    10,     4,     0,     5,     0,
       0,     1,     2,     7,     8,     9,    10,    78,    13,     5,
       0,    14,     1,     2,     7,     8,     9,    10,   116,    13,
       5,     0,    14,     1,     2,     7,     8,     9,    10,     0,
      13,     5,     0,    14,     0,     0,     7,     8,     9,    10,
       0,    13,     0,     0,    14,     1,     2,   129,     0,     1,
       2,     0,    13,     5,     0,    14,     0,     0,     7,     8,
       9,    10,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,    14,    13,     0,
       0,    14
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,     0,    98,    13,    67,    13,     4,     5,
     124,    62,    62,     3,     5,     0,     5,    13,    18,    42,
      14,    18,    23,    18,    47,    26,     3,    24,    34,    77,
       5,     4,    33,    27,     7,    24,    25,    85,     3,    10,
      40,    40,    40,    40,    33,    35,    42,    98,    98,    24,
      25,    47,    75,    53,   168,    40,    53,    34,    53,    30,
      27,    10,    62,    62,    62,    73,    10,    34,    32,    29,
      93,    67,    32,    69,    70,    71,    72,    73,    69,    75,
     141,    30,    78,    27,    23,     3,     7,    26,     3,     4,
     184,    12,     7,    23,    33,    31,    26,    93,    98,    98,
      98,    16,     0,    33,    23,   128,    23,    26,   131,    26,
       6,    34,    23,     9,    33,    26,    33,     5,    23,   208,
     116,    26,    33,   212,   213,   216,   215,    27,    33,    32,
     221,   139,   128,   184,   184,   131,     3,     4,     5,     3,
       4,   138,     9,   139,    11,   141,    13,   147,    15,    16,
      17,    18,    19,    20,    21,    22,    29,    24,    25,    32,
      23,    23,    10,    26,    26,    32,    33,     8,    35,   168,
      33,    33,     6,    23,   128,     9,    26,   131,     3,     4,
      29,     3,     4,     5,   184,   184,   184,     9,    31,    11,
       3,    13,    29,    15,    16,    17,    18,    19,    20,    21,
      22,     9,    24,    25,     3,    28,    27,    33,    23,     3,
      32,    26,    34,    35,     3,     4,     5,     9,    33,    31,
       9,    32,    11,    32,    13,    29,    15,    16,    17,    18,
      19,    20,    21,    22,    31,    24,    25,    28,    28,     7,
       9,    23,    27,    32,    26,    34,    35,     3,     4,     5,
      30,    33,    30,     9,    30,    11,     4,    13,    30,    15,
      16,    17,    18,    19,    27,    21,    22,    27,    24,    25,
      31,    30,     3,     4,     5,    30,    32,    33,     9,    35,
      11,    31,    13,    27,    15,    16,    17,    18,    19,    20,
      21,    22,    34,    24,    25,    33,    36,     3,     4,     5,
      27,    32,    36,     9,    35,    11,    53,    13,    33,    15,
      16,    17,    18,    19,    33,    21,    22,    33,    24,    25,
      40,   127,     3,     4,     5,    89,    32,    64,     9,    35,
      11,   138,    13,    62,   170,    16,    17,    18,    19,   184,
      72,    71,    70,    24,    25,    -1,    -1,    -1,    -1,     3,
       4,    32,    -1,     7,    35,     9,    -1,    11,    -1,    -1,
       3,     4,    16,    17,    18,    19,     9,    -1,    11,    -1,
      -1,     3,     4,    16,    17,    18,    19,     9,    32,    11,
      -1,    35,     3,     4,    16,    17,    18,    19,     9,    32,
      11,    -1,    35,     3,     4,    16,    17,    18,    19,    -1,
      32,    11,    -1,    35,    -1,    -1,    16,    17,    18,    19,
      -1,    32,    -1,    -1,    35,     3,     4,    27,    -1,     3,
       4,    -1,    32,    11,    -1,    35,    -1,    -1,    16,    17,
      18,    19,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    32,    -1,
      -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    11,    13,    16,    17,    18,
      19,    24,    25,    32,    35,    38,    39,    40,    42,    43,
      49,    50,    51,    52,    53,    54,    66,    70,    71,    72,
      73,    74,    75,    76,    77,    79,    80,    81,    82,    83,
      86,    87,    29,     3,    80,    74,    80,    32,    72,    80,
       3,     0,    41,    42,    87,     3,    44,    47,    48,    34,
      57,    58,    59,    31,    49,    55,    56,    32,    27,    10,
       7,    12,     8,     6,     9,    29,    39,     3,     9,    73,
      80,    68,    73,    31,    41,     3,    29,    32,    27,    28,
      45,    33,    15,    21,    22,    33,    43,    49,    62,    63,
      66,    70,    78,    88,     3,    48,    71,    80,    84,    85,
      74,    77,    76,    79,     7,    72,     9,    73,    80,    34,
      44,    80,    30,     9,    31,     4,     7,    47,    32,    27,
      73,    32,    43,    63,    66,    70,    78,    88,    28,     6,
      31,    28,     3,     4,    80,    30,     9,    46,    27,    30,
      30,    57,    30,     4,    45,    68,    27,    68,    56,    71,
      27,    27,    30,    30,    33,    43,    14,    27,    67,    30,
      31,    31,    27,    57,    66,    69,    27,    59,    60,    61,
      34,    20,    33,    43,    62,    63,    64,    65,    66,    70,
      88,    33,    23,    26,    89,    27,    43,    63,    65,    66,
      70,    78,    88,     3,     4,     7,    16,    90,    36,    33,
       3,     4,    36,    34,    64,    34,    64,    64,    64,    89,
      33,    33,    89
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
      66,    66,    67,    68,    69,    69,    70,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    79,    79,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    83,    84,    84,    85,    85,    86,
      87,    87,    88,    89,    89,    89,    89,    89,    90,    90,
      90,    90,    90
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
       6,     7,     1,     1,     1,     1,     2,     5,     5,     3,
       1,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     5,     5,     1,     1,     3,     1,
       1,     2,     1,     4,     5,     5,     4,     5,     5,     1,
       1,     1,     1,     1,     4,     0,     1,     3,     1,     6,
       1,     1,     7,     0,     5,     7,     3,     5,     1,     1,
       2,     2,     1
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
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.sval),(yyvsp[0].sval));push_to_symbol_table((yyvsp[0].sval),test,id.val,line,0,"0",parameter_list,0,"-1"); /*printf("%s  %s  \n",$1,id.val);*/}
#line 1517 "y.tab.c" /* yacc.c:1646  */
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
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-3].sval)); push_to_symbol_table((yyvsp[-3].sval),test,id.val,line,0,(yyvsp[-1].sval),parameter_list,0,"-1");push_to_constants_table((yyvsp[-1].sval),"number",line); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 138 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));strcpy(test,(yyvsp[0].sval)); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 141 "parser.y" /* yacc.c:1646  */
    { //failhandler
	if(strcmp((yyvsp[-1].sval),"void")==0&&return_not_void_flag==1){printf("return type mismatch error at line %d \n" ,line);} else if(strcmp((yyvsp[-1].sval),"void")!=0&&return_not_void_flag==0){printf("return type mismatch error at line %d \n" ,line);} return_not_void_flag=0;}
#line 1549 "y.tab.c" /* yacc.c:1646  */
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
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-1].sval));}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 156 "parser.y" /* yacc.c:1646  */
    { strcpy(funname_global,(yyvsp[-1].sval)); id=openbraceencounter(id); strcpy((yyval.sval),(yyvsp[-2].sval));}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "parser.y" /* yacc.c:1646  */
    {  }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "parser.y" /* yacc.c:1646  */
    {         
	strcpy(parameter_list[parameter_count].name,(yyvsp[-2].sval));
	strcpy(parameter_list[parameter_count].type,(yyvsp[-3].sval));
	++parameter_count;
	if(strcmp((yyvsp[-3].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 169 "parser.y" /* yacc.c:1646  */
    {
	strcpy(parameter_list[parameter_count].name,(yyvsp[0].sval));
	strcpy(parameter_list[parameter_count].type,(yyvsp[-1].sval));
	++parameter_count;
	if(strcmp((yyvsp[-1].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 176 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id); update_goto_stmt(0);}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 177 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);update_goto_stmt(0);}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "parser.y" /* yacc.c:1646  */
    {/*printf("open");*/ if(brac_act_flag==0) {id=openbraceencounter(id);} else {brac_act_flag=0;} }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 189 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/ id=closebraceencounter(id);}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 190 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 203 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 210 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 214 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1;}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 215 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1; if((yyvsp[-1].expressionvar).type==2||(yyvsp[-1].expressionvar).type==4||(yyvsp[-1].expressionvar).type==7){printf("return type cannot be array at %d\n",line);}}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 221 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "parser.y" /* yacc.c:1646  */
    {elseifflag=0;}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 237 "parser.y" /* yacc.c:1646  */
    {elseifflag=1;}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 239 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].expressionvar).type!=1){printf("expression in test  is not of type int at line %d\n",line-3);}
CreateDocument((yyvsp[0].expressionvar).val,"","","",1,0);
CreateDocument("","","","",0,1);
if(elseifflag==1)
{
	printf("this is else if stmt\n");
}
	}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.expressionvar).type=(yyvsp[0].expressionvar).type;CreateDocument((yyvsp[-2].expressionvar).val,"","",(yyvsp[0].expressionvar).val,0,0); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;char c[10];CreateTempvar(c);if(strcmp((yyvsp[-1].sval),"++")==0){CreateDocument(c,(yyvsp[0].expressionvar).val,"+","1",0,0);}
else{
CreateDocument(c,(yyvsp[0].expressionvar).val,"-","1",0,0);	
}
CreateDocument((yyvsp[0].expressionvar).val,"","",c,0,0); 
strcpy((yyval.expressionvar).val,c);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-1].expressionvar).type;char c[10];CreateTempvar(c);if(strcmp((yyvsp[0].sval),"++")==0){CreateDocument(c,(yyvsp[-1].expressionvar).val,"+","1",0,0);}
else{
CreateDocument(c,(yyvsp[-1].expressionvar).val,"-","1",0,0);	
}
CreateDocument((yyvsp[-1].expressionvar).val,"","",c,0,0); 
strcpy((yyval.expressionvar).val,(yyvsp[-1].expressionvar).val);}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=1; char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=1;char c[10];CreateTempvar(c);CreateDocument(c,"","not",(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=1;char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=min((yyvsp[-2].expressionvar).type,(yyvsp[0].expressionvar).type); char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=min((yyvsp[-2].expressionvar).type,(yyvsp[0].expressionvar).type); char c[10];CreateTempvar(c);CreateDocument(c,(yyvsp[-2].expressionvar).val,(yyvsp[-1].sval),(yyvsp[0].expressionvar).val,0,0);strcpy((yyval.expressionvar).val,c);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;  strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 292 "parser.y" /* yacc.c:1646  */
    {update_goto_stmt(1);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 293 "parser.y" /* yacc.c:1646  */
    {update_goto_stmt(1);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[0].expressionvar).type;  strcpy((yyval.expressionvar).val,(yyvsp[0].expressionvar).val);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=(yyvsp[-1].expressionvar).type; strcpy((yyval.expressionvar).val,(yyvsp[-1].expressionvar).val);}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.expressionvar).type=-10;}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 304 "parser.y" /* yacc.c:1646  */
    {}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 305 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),"data",id.val,line,0,"0",parameter_list,0,"-1");
/* printf("%s  %s  \n",$2,id.val); */}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 307 "parser.y" /* yacc.c:1646  */
    { int ans=checkdeclaration(id,(yyvsp[0].sval));
/*printf("kkk%smmm%dlll%d\n,",$1,ans,line);*/
 if(ans==0){printf("variable %s is not declared in this scope at line %d \n",(yyvsp[0].sval),line);}
else if(ans==-1){printf("identifier %s previously defined as procedure at line %d\n",(yyvsp[0].sval),line);}
else if(ans==5){printf("identifier %s declared as void at line %d\n",(yyvsp[0].sval),line);}
else if(ans==2||ans==4||ans==7){printf("identifier %s is of type array line %d\n",(yyvsp[0].sval),line);}
 (yyval.expressionvar).type=ans;
 strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-3].ival); if((yyvsp[-1].expressionvar).type!=1)
 {printf("Expression in subscript not of type int at line %d\n",line);} 
 if((yyvsp[-3].ival)!=2&&(yyvsp[-3].ival)!=4&&(yyvsp[-3].ival)!=7) {printf("variable  is  at line is not declared as array %d\n",line);}}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 323 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-4].ival); 
if((yyvsp[-1].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if((yyvsp[-4].ival)!=2&&(yyvsp[-4].ival)!=4&&(yyvsp[-4].ival)!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-4].ival);
if((yyvsp[-2].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if((yyvsp[-4].ival)!=2&&(yyvsp[-4].ival)!=4&&(yyvsp[-4].ival)!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 331 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclaration(id,(yyvsp[-3].sval)); (yyval.ival)=ans;
 if((yyvsp[-1].expressionvar).type!=1)
 {printf("Expression in subscript not of type int at line %d\n",line);} 
 if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 335 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclaration(id,(yyvsp[-4].sval)); (yyval.ival)=ans;
if((yyvsp[-1].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 339 "parser.y" /* yacc.c:1646  */
    {  int ans=checkdeclaration(id,(yyvsp[-4].sval)); (yyval.ival)=ans;
if((yyvsp[-2].expressionvar).type!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 346 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line); (yyval.expressionvar).type=1; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 347 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);(yyval.expressionvar).type=3; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 348 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"string",line);(yyval.expressionvar).type=4; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 349 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"float",line);(yyval.expressionvar).type=6; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 350 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);(yyval.expressionvar).type=-1; strcpy((yyval.expressionvar).val,(yyvsp[0].sval));}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 354 "parser.y" /* yacc.c:1646  */
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
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 373 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=0;}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 374 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 376 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-2].ival)+1; if((yyvsp[0].expressionvar).type==2||(yyvsp[0].expressionvar).type==4||(yyvsp[0].expressionvar).type==7){argument_list[argument_count]=1;}
else {argument_list[argument_count]=0;}
++argument_count;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1; if((yyvsp[0].expressionvar).type==2||(yyvsp[0].expressionvar).type==4||(yyvsp[0].expressionvar).type==7){argument_list[argument_count]=1;}
else {argument_list[argument_count]=0;}
++argument_count;
}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 388 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval)); strcpy(test,(yyvsp[0].sval));}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 389 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 392 "parser.y" /* yacc.c:1646  */
    { }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 401 "parser.y" /* yacc.c:1646  */
    {push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 402 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 403 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 404 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2028 "y.tab.c" /* yacc.c:1646  */
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
#line 408 "parser.y" /* yacc.c:1906  */

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

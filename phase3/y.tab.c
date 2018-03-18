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
#line 54 "parser.y" /* yacc.c:358  */

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


#line 206 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

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
       0,    79,    79,    84,    85,    86,    87,    88,    92,    94,
      95,   100,   101,   103,   104,   107,   109,   110,   113,   114,
     120,   122,   123,   131,   134,   137,   141,   150,   152,   154,
     156,   157,   160,   165,   172,   173,   175,   177,   185,   186,
     189,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   209,   210,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   226,   228,   229,
     230,   233,   236,   237,   239,   240,   241,   243,   244,   246,
     247,   248,   250,   251,   254,   255,   257,   258,   261,   262,
     265,   266,   269,   270,   275,   276,   277,   278,   281,   282,
     284,   296,   299,   303,   307,   311,   315,   322,   323,   324,
     325,   326,   330,   349,   350,   352,   355,   361,   364,   365,
     368,   370,   371,   372,   373,   374,   377,   378,   379,   380,
     381
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
  "selectionstmt1", "selectionhelper", "expressionsemi", "expression",
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

#define YYPACT_NINF -189

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-189)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      97,    52,  -189,  -189,     8,   418,    -5,  -189,  -189,  -189,
    -189,  -189,  -189,   418,    26,    49,  -189,  -189,    32,  -189,
      76,  -189,    53,    58,    94,    61,  -189,  -189,    78,  -189,
      93,  -189,  -189,    12,    99,  -189,   130,    89,  -189,  -189,
      97,   117,   363,   105,  -189,  -189,  -189,   418,     4,  -189,
    -189,  -189,    32,   125,   109,   123,   128,  -189,  -189,  -189,
     133,   288,  -189,   175,  -189,  -189,   374,  -189,   418,   422,
     422,   422,   144,  -189,   385,  -189,    19,     8,    56,   161,
     160,    93,  -189,  -189,   175,   167,  -189,  -189,   175,  -189,
    -189,   396,   179,  -189,  -189,   175,   313,  -189,  -189,  -189,
    -189,   178,   192,  -189,   181,   193,   195,  -189,    99,   218,
    -189,   108,  -189,   217,     8,    60,   219,  -189,   209,   208,
    -189,   210,    53,   212,   240,   128,  -189,     5,   418,   221,
    -189,  -189,  -189,  -189,  -189,  -189,    94,   374,  -189,   374,
     229,   234,   227,  -189,   233,    34,  -189,  -189,  -189,     7,
    -189,   237,  -189,  -189,   238,   418,  -189,  -189,  -189,  -189,
    -189,  -189,   243,  -189,    51,  -189,  -189,   244,   250,  -189,
    -189,  -189,  -189,   186,    -4,    88,   246,   251,  -189,   164,
    -189,   253,  -189,  -189,   200,  -189,   247,   197,  -189,   267,
    -189,   100,   230,   104,  -189,  -189,   126,   131,   172,  -189,
    -189,  -189,   255,   338,  -189,  -189,   204,   262,  -189,   342,
     419,   423,   425,   338,   186,   263,   265,  -189,  -189,   186,
    -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   100,   107,    24,     0,     0,     0,   108,   111,   110,
     109,   118,   119,     0,     0,     0,     2,     4,     9,    11,
       0,    12,     0,     0,    30,     0,     5,     3,     0,    78,
      79,    83,    85,    87,    89,    91,    95,    98,    94,    97,
       6,     0,     0,   100,    80,    84,    95,     0,     0,    99,
       1,     8,     9,     0,    21,     0,    16,    20,    37,    25,
       0,     0,    26,     0,    27,    31,   113,    74,     0,     0,
       0,     0,     0,    81,     0,     7,     0,     0,     0,    95,
       0,    71,    96,    10,     0,     0,    28,    13,     0,    15,
      34,     0,     0,    35,    44,     0,    36,    50,    51,    43,
      49,    21,    33,   116,    95,     0,   114,    82,    88,    86,
      90,     0,    77,    95,     0,     0,    95,    18,     0,     0,
     104,     0,     0,     0,     0,    16,    52,     0,     0,     0,
      42,    47,    45,    41,    46,    48,     0,     0,   112,     0,
       0,     0,     0,   101,     0,     0,    14,   105,   106,    68,
      23,     0,    17,    53,     0,     0,    32,   115,    76,    75,
     102,   103,     0,    19,     0,    69,    22,     0,     0,   117,
      73,    72,    70,   121,     0,     0,     0,     0,    93,     0,
      92,     0,   130,   126,     0,   127,     0,     0,   120,     0,
      39,    44,     0,    50,    40,    66,    51,    43,    49,    38,
     129,   128,     0,     0,   124,    67,    42,    47,    62,    45,
      41,    46,    48,     0,   121,     0,     0,   122,   125,   121,
     123
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,   260,  -189,   256,    -8,     0,   -59,   177,  -189,
     215,   248,    36,  -189,  -189,  -189,  -189,  -189,  -189,   183,
    -113,  -189,   140,  -189,  -189,   254,   -49,   -78,   135,     1,
    -100,  -189,     2,   -61,   -69,    -9,    15,  -189,   266,   264,
     147,   269,     3,  -189,  -189,  -189,  -189,  -189,  -189,     6,
     -48,  -188,  -189
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    51,    18,   191,    55,    89,   145,
      56,    57,    95,    21,    22,    23,    24,    25,    64,    65,
      59,    60,    61,   180,   181,   192,   193,   194,   195,   196,
      80,   172,   197,    28,    29,    30,    31,    32,    33,    34,
     134,    35,    36,    37,    38,    39,   105,   106,    40,    53,
     198,   177,   186
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    26,    27,   112,    48,   103,    41,    44,    46,   149,
      52,    43,    97,   100,    68,    68,    46,   118,    19,    69,
      45,   164,   101,   178,    70,   118,   217,    47,   154,    49,
      58,   220,   153,    78,   165,    82,    20,     3,    81,     3,
      19,    26,    27,    14,    52,    79,    41,   131,   135,    50,
      46,   170,    19,   117,    20,   168,    11,    12,    11,    12,
      63,    94,    98,    99,     6,   115,    68,   162,   112,   104,
      68,    46,    46,    46,    46,   113,    20,   116,   157,    54,
     119,    42,   127,   107,   -29,    58,   120,    58,    20,    62,
     143,   182,   183,    66,    46,   184,   130,   132,   133,     3,
       1,     2,     3,    68,   185,    67,     4,    71,     5,   204,
       6,   140,   141,     7,     8,     9,    10,   142,    74,    81,
      76,    11,    12,   -57,   214,   215,   -57,   -64,    84,    13,
     -64,    46,    14,   -57,    42,   216,    72,   -64,    85,    73,
     113,    86,   104,   207,   212,   163,    81,     1,     2,   -65,
      87,   111,   -65,     4,   -56,     5,    88,   -56,    46,   -65,
       7,     8,     9,    10,   -56,   171,    90,     1,     2,     3,
     121,   123,    63,     4,   124,     5,    13,     6,   101,    14,
       7,     8,     9,    10,   189,    91,    92,   137,    11,    12,
      73,   122,   206,   209,   210,   -63,    13,   190,   -63,    14,
       1,     2,     3,   200,   201,   -63,     4,    85,     5,   175,
       6,   128,   176,     7,     8,     9,    10,   189,    91,    92,
     136,    11,    12,   139,   138,    69,    73,   -55,   144,    13,
     -55,   203,    14,     1,     2,     3,   146,   -55,   147,     4,
     148,     5,   150,     6,   151,   129,     7,     8,     9,    10,
     189,    91,    92,   155,    11,    12,   158,   160,     1,     2,
       3,   159,    13,   161,     4,    14,     5,   166,     6,   167,
     169,     7,     8,     9,    10,   189,    91,    92,   173,    11,
      12,   174,   187,   202,   188,   -60,   199,    13,   -60,   213,
      14,     1,     2,     3,   205,   -60,   218,     4,   219,     5,
      75,     6,   152,   125,     7,     8,     9,    10,    83,    91,
      92,   102,    11,    12,   179,    96,     1,     2,     3,   156,
      13,    93,     4,    14,     5,     0,     6,   208,   129,     7,
       8,     9,    10,   108,    91,    92,   109,    11,    12,   211,
     110,     1,     2,     3,     0,    13,     0,     4,    14,     5,
       0,     6,     0,     0,     7,     8,     9,    10,   189,    91,
      92,     0,    11,    12,     0,   -58,     1,     2,   -58,     0,
      13,     0,    77,    14,     5,   -58,     0,     1,     2,     7,
       8,     9,    10,     4,     0,     5,     0,     0,     1,     2,
       7,     8,     9,    10,   114,    13,     5,     0,    14,     1,
       2,     7,     8,     9,    10,     0,    13,     5,     0,    14,
       0,     0,     7,     8,     9,    10,     0,    13,     0,     0,
      14,     1,     2,   126,     0,     1,     2,     0,    13,     5,
       0,    14,     0,     0,     7,     8,     9,    10,     7,     8,
       9,    10,   -54,     0,     0,   -54,   -59,     0,   -61,   -59,
      13,   -61,   -54,    14,    13,     0,   -59,    14,   -61
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,    72,    13,    66,     0,     4,     5,   122,
      18,     3,    61,    61,    10,    10,    13,    76,    18,     7,
       5,    14,     3,    27,    12,    84,   214,    32,   128,     3,
      34,   219,    27,    42,    27,    31,     0,     5,    47,     5,
      40,    40,    40,    35,    52,    42,    40,    96,    96,     0,
      47,   164,    52,    34,    18,   155,    24,    25,    24,    25,
      24,    61,    61,    61,    13,    74,    10,    33,   137,    66,
      10,    68,    69,    70,    71,    72,    40,    74,   139,     3,
      77,    29,    91,    68,    32,    34,    30,    34,    52,    31,
      30,     3,     4,    32,    91,     7,    96,    96,    96,     5,
       3,     4,     5,    10,    16,    27,     9,     8,    11,   187,
      13,     3,     4,    16,    17,    18,    19,   114,    29,   128,
       3,    24,    25,    23,   202,   203,    26,    23,     3,    32,
      26,   128,    35,    33,    29,   213,     6,    33,    29,     9,
     137,    32,   139,   192,   192,   145,   155,     3,     4,    23,
      27,     7,    26,     9,    23,    11,    28,    26,   155,    33,
      16,    17,    18,    19,    33,   164,    33,     3,     4,     5,
       9,     4,   136,     9,     7,    11,    32,    13,     3,    35,
      16,    17,    18,    19,    20,    21,    22,     6,    24,    25,
       9,    31,   192,   192,   192,    23,    32,    33,    26,    35,
       3,     4,     5,     3,     4,    33,     9,    29,    11,    23,
      13,    32,    26,    16,    17,    18,    19,    20,    21,    22,
      28,    24,    25,    28,    31,     7,     9,    23,     9,    32,
      26,    34,    35,     3,     4,     5,    27,    33,    30,     9,
      30,    11,    30,    13,     4,    15,    16,    17,    18,    19,
      20,    21,    22,    32,    24,    25,    27,    30,     3,     4,
       5,    27,    32,    30,     9,    35,    11,    30,    13,    31,
      27,    16,    17,    18,    19,    20,    21,    22,    34,    24,
      25,    31,    36,    36,    33,    23,    33,    32,    26,    34,
      35,     3,     4,     5,    27,    33,    33,     9,    33,    11,
      40,    13,   125,    88,    16,    17,    18,    19,    52,    21,
      22,    63,    24,    25,   174,    61,     3,     4,     5,   136,
      32,    33,     9,    35,    11,    -1,    13,   192,    15,    16,
      17,    18,    19,    69,    21,    22,    70,    24,    25,   192,
      71,     3,     4,     5,    -1,    32,    -1,     9,    35,    11,
      -1,    13,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    -1,    23,     3,     4,    26,    -1,
      32,    -1,     9,    35,    11,    33,    -1,     3,     4,    16,
      17,    18,    19,     9,    -1,    11,    -1,    -1,     3,     4,
      16,    17,    18,    19,     9,    32,    11,    -1,    35,     3,
       4,    16,    17,    18,    19,    -1,    32,    11,    -1,    35,
      -1,    -1,    16,    17,    18,    19,    -1,    32,    -1,    -1,
      35,     3,     4,    27,    -1,     3,     4,    -1,    32,    11,
      -1,    35,    -1,    -1,    16,    17,    18,    19,    16,    17,
      18,    19,    23,    -1,    -1,    26,    23,    -1,    23,    26,
      32,    26,    33,    35,    32,    -1,    33,    35,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    11,    13,    16,    17,    18,
      19,    24,    25,    32,    35,    38,    39,    40,    42,    43,
      49,    50,    51,    52,    53,    54,    66,    69,    70,    71,
      72,    73,    74,    75,    76,    78,    79,    80,    81,    82,
      85,    86,    29,     3,    79,    73,    79,    32,    72,     3,
       0,    41,    42,    86,     3,    44,    47,    48,    34,    57,
      58,    59,    31,    49,    55,    56,    32,    27,    10,     7,
      12,     8,     6,     9,    29,    39,     3,     9,    72,    79,
      67,    72,    31,    41,     3,    29,    32,    27,    28,    45,
      33,    21,    22,    33,    43,    49,    62,    63,    66,    69,
      87,     3,    48,    70,    79,    83,    84,    73,    76,    75,
      78,     7,    71,    79,     9,    72,    79,    34,    44,    79,
      30,     9,    31,     4,     7,    47,    27,    72,    32,    15,
      43,    63,    66,    69,    77,    87,    28,     6,    31,    28,
       3,     4,    79,    30,     9,    46,    27,    30,    30,    57,
      30,     4,    45,    27,    67,    32,    56,    70,    27,    27,
      30,    30,    33,    43,    14,    27,    30,    31,    67,    27,
      57,    66,    68,    34,    31,    23,    26,    88,    27,    59,
      60,    61,     3,     4,     7,    16,    89,    36,    33,    20,
      33,    43,    62,    63,    64,    65,    66,    69,    87,    33,
       3,     4,    36,    34,    64,    27,    43,    63,    65,    66,
      69,    77,    87,    34,    64,    64,    64,    88,    33,    33,
      88
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
      66,    67,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    88,    88,    88,    88,    88,    89,    89,    89,    89,
      89
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
       7,     1,     1,     1,     2,     5,     5,     3,     1,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     5,     5,     1,     1,     3,     1,     1,     2,
       1,     4,     5,     5,     4,     5,     5,     1,     1,     1,
       1,     1,     4,     0,     1,     3,     1,     6,     1,     1,
       7,     0,     5,     7,     3,     5,     1,     1,     2,     2,
       1
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
#line 80 "parser.y" /* yacc.c:1646  */
    {
	printf("Valid Expressions : ");
}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 122 "parser.y" /* yacc.c:1646  */
    { strcpy((yyval.sval),(yyvsp[0].sval));push_to_symbol_table((yyvsp[0].sval),test,id.val,line,0,"0",parameter_list,0,"-1"); /*printf("%s  %s  \n",$1,id.val);*/}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 123 "parser.y" /* yacc.c:1646  */
    {  strcpy((yyval.sval),(yyvsp[-4].sval));
							if(strcmp((yyvsp[-2].sval),"-")==0)
							{
								printf("array size cannot be negative at line %d \n",line);
							}
							else{					
	push_to_symbol_table((yyvsp[-4].sval),test,id.val,line,0,(yyvsp[-1].sval),parameter_list,0,"-1");push_to_constants_table((yyvsp[-1].sval),"number",line); }
						}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-3].sval)); push_to_symbol_table((yyvsp[-3].sval),test,id.val,line,0,(yyvsp[-1].sval),parameter_list,0,"-1");push_to_constants_table((yyvsp[-1].sval),"number",line); }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 134 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));strcpy(test,(yyvsp[0].sval)); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "parser.y" /* yacc.c:1646  */
    { //failhandler
	if(strcmp((yyvsp[-1].sval),"void")==0&&return_not_void_flag==1){printf("return type mismatch error at line %d \n" ,line);} else if(strcmp((yyvsp[-1].sval),"void")!=0&&return_not_void_flag==0){printf("return type mismatch error at line %d \n" ,line);} return_not_void_flag=0;}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "parser.y" /* yacc.c:1646  */
    { brac_act_flag=1;strcpy((yyval.sval),(yyvsp[-1].sval));
	//this part of the code may not work if it fails copy l+5 and l+6 to failhandler
	struct string tempid;
	tempid=id;
	id.val[id.len-1]='\0';
	push_to_symbol_table(funname_global,(yyvsp[-1].sval),id.val,line,1,"0",parameter_list,parameter_count,tempid.val);
	parameter_count=0;
	id=tempid; }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 150 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[-1].sval));}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 152 "parser.y" /* yacc.c:1646  */
    { strcpy(funname_global,(yyvsp[-1].sval)); id=openbraceencounter(id); strcpy((yyval.sval),(yyvsp[-2].sval));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 154 "parser.y" /* yacc.c:1646  */
    {  }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 160 "parser.y" /* yacc.c:1646  */
    {         
	strcpy(parameter_list[parameter_count].name,(yyvsp[-2].sval));
	strcpy(parameter_list[parameter_count].type,(yyvsp[-3].sval));
	++parameter_count;
	if(strcmp((yyvsp[-3].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 165 "parser.y" /* yacc.c:1646  */
    {
	strcpy(parameter_list[parameter_count].name,(yyvsp[0].sval));
	strcpy(parameter_list[parameter_count].type,(yyvsp[-1].sval));
	++parameter_count;
	if(strcmp((yyvsp[-1].sval),"void")==0){printf("parameter cannot be void at line %d",line);}}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 172 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 173 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 177 "parser.y" /* yacc.c:1646  */
    {/*printf("open");*/ if(brac_act_flag==0) {id=openbraceencounter(id);} else {brac_act_flag=0;} }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/ id=closebraceencounter(id);}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "parser.y" /* yacc.c:1646  */
    {/*printf("close");*/id=closebraceencounter(id);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 209 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1;}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 210 "parser.y" /* yacc.c:1646  */
    {return_not_void_flag=1; if((yyvsp[-1].ival)==2||(yyvsp[-1].ival)==4||(yyvsp[-1].ival)==7){printf("return type cannot be array at %d\n",line);}}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 233 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].ival)!=1){printf("expression in test  is not of type int at line %d\n",line-3);}}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.ival)=(yyvsp[-2].ival);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-1].ival);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1; }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1;}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 255 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1;}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=min((yyvsp[-2].ival),(yyvsp[0].ival));}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=min((yyvsp[-2].ival),(yyvsp[0].ival));}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-1].ival);}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=-10;}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 282 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),"data",id.val,line,0,"0",parameter_list,0,"-1");
/* printf("%s  %s  \n",$2,id.val); */}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 284 "parser.y" /* yacc.c:1646  */
    { int ans=checkdeclaration(id,(yyvsp[0].sval));
/*printf("kkk%smmm%dlll%d\n,",$1,ans,line);*/
 if(ans==0){printf("variable %s is not declared in this scope at line %d \n",(yyvsp[0].sval),line);}
else if(ans==-1){printf("identifier %s previously defined as procedure at line %d\n",(yyvsp[0].sval),line);}
else if(ans==5){printf("identifier %s declared as void at line %d\n",(yyvsp[0].sval),line);}
else if(ans==2||ans==4||ans==7){printf("identifier %s is of type array line %d\n",(yyvsp[0].sval),line);}
 (yyval.ival)=ans;}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-3].ival); if((yyvsp[-1].ival)!=1)
 {printf("Expression in subscript not of type int at line %d\n",line);} 
 if((yyvsp[-3].ival)!=2&&(yyvsp[-3].ival)!=4&&(yyvsp[-3].ival)!=7) {printf("variable  is  at line is not declared as array %d\n",line);}}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-4].ival); 
if((yyvsp[-1].ival)!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if((yyvsp[-4].ival)!=2&&(yyvsp[-4].ival)!=4&&(yyvsp[-4].ival)!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-4].ival);
if((yyvsp[-2].ival)!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if((yyvsp[-4].ival)!=2&&(yyvsp[-4].ival)!=4&&(yyvsp[-4].ival)!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 307 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclaration(id,(yyvsp[-3].sval)); (yyval.ival)=ans;
 if((yyvsp[-1].ival)!=1)
 {printf("Expression in subscript not of type int at line %d\n",line);} 
 if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 311 "parser.y" /* yacc.c:1646  */
    {int ans=checkdeclaration(id,(yyvsp[-4].sval)); (yyval.ival)=ans;
if((yyvsp[-1].ival)!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 315 "parser.y" /* yacc.c:1646  */
    {  int ans=checkdeclaration(id,(yyvsp[-4].sval)); (yyval.ival)=ans;
if((yyvsp[-2].ival)!=1) {printf("Expression in subscript not of type int at line %d\n",line);}
if(ans!=2&&ans!=4&&ans!=7) {printf("variable is  at line is not declared as array %d\n",line);}
}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 322 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line); (yyval.ival)=1;}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 323 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);(yyval.ival)=3;}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 324 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"string",line);(yyval.ival)=4;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 325 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"float",line);(yyval.ival)=6;}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 326 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);(yyval.ival)=-1;}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 330 "parser.y" /* yacc.c:1646  */
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
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=0;}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 350 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 352 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[-2].ival)+1; if((yyvsp[0].ival)==2||(yyvsp[0].ival)==4||(yyvsp[0].ival)==7){argument_list[argument_count]=1;}
else {argument_list[argument_count]=0;}
++argument_count;}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 355 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=1; if((yyvsp[0].ival)==2||(yyvsp[0].ival)==4||(yyvsp[0].ival)==7){argument_list[argument_count]=1;}
else {argument_list[argument_count]=0;}
++argument_count;
}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 364 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval)); strcpy(test,(yyvsp[0].sval));}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 365 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 368 "parser.y" /* yacc.c:1646  */
    { }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 377 "parser.y" /* yacc.c:1646  */
    {push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 378 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 379 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 380 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1946 "y.tab.c" /* yacc.c:1646  */
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
#line 384 "parser.y" /* yacc.c:1906  */

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

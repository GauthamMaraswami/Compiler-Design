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
    floatcnst = 272,
    stringcnst = 273,
    breakval = 274,
    returnval = 275,
    switchval = 276,
    casestmt = 277,
    structs = 278,
    unions = 279,
    defaultstmt = 280
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
#define floatcnst 272
#define stringcnst 273
#define breakval 274
#define returnval 275
#define switchval 276
#define casestmt 277
#define structs 278
#define unions 279
#define defaultstmt 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 2 "parser.y" /* yacc.c:355  */

	int ival;
	float fval;
	char cval;
  char sval[100];

#line 164 "y.tab.c" /* yacc.c:355  */
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
	FILE *yyin;
	extern int line;
extern int comment_stack[100];//for storing comment stack
extern int stacktop;//top of comment stack
extern int commentflag;
	char test[100];
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

//symbol table
struct symbol{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct symbol *next;
} symboltable[65535];

//constants table
struct constants{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct constants *next;
} constantstable[65535];

//no of constants
int countconstants=0;
int countsymbol=0;
//function to add symbol to symbol table
void push_to_symbol_table(char ctemp[],char type[],int l)
{
	unsigned long map=hash(ctemp);
map=map%65535;
	int len=strlen(ctemp);
	if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)==0) //case when the symbol is already in table first
	{
		
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;

	}
	else if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)!=0)//case when symbol not in table first
	{
		int found=0;
		struct symbol * pointer=&symboltable[map];
		while(pointer->next!=NULL)
		{
			if(strcmp(pointer->name,ctemp)==0)				
				{
					found=1;
				}
				pointer=pointer->next;
		}
		if(found==0)													////case when symbol not found
		{
			struct symbol * tempsymbol;
			strncpy(tempsymbol->name,ctemp,len);
			strcpy(tempsymbol->type,type);
			tempsymbol->linecount=0;
			tempsymbol->valid=1;
			tempsymbol->next=NULL;
			tempsymbol->lineno[tempsymbol->linecount]=l;
			tempsymbol->linecount++;
			pointer->next=tempsymbol;
		}
		if(found==1)													//case when symbol found at some other position
		{
			pointer->lineno[pointer->linecount]=l;
			pointer->linecount++;

		}

	}
	else{														   //hashtable map is free
		strncpy(symboltable[map].name,ctemp,len);
		strcpy(symboltable[map].type,type);
		symboltable[map].linecount=0;
		symboltable[map].valid=1;
		symboltable[map].next=NULL;
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;
		++countsymbol;
		}
		


}
//function to add constants to constant table
void push_to_constants_table(char ctemp[],char type[],int l)								//case when the symbol is already in table first
{
	unsigned long map=hash(ctemp);
	map=map%65535;
	int len=strlen(ctemp);
	if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)==0)
			{
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				

			}
			else if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)!=0)		//case when symbol not in table first
			{
				int found=0;
				struct constants * pointer=&constantstable[map];
				while(pointer->next!=NULL)
				{
					if(strcmp(pointer->name,ctemp)==0)
						{
							found=1;
						}
					pointer=pointer->next;
				}
				if(found==0)														////case when symbol not found
				{
					struct constants * tempconstants;
					strncpy(tempconstants->name,ctemp,l);
					strcpy(tempconstants->type,type);
					tempconstants->linecount=0;
					tempconstants->valid=1;
					tempconstants->next=NULL;
					tempconstants->lineno[tempconstants->linecount]=l;
					tempconstants->linecount++;
					pointer->next=tempconstants;
				}
				if(found==1)													//case when symbol found at some other position				
				{
					pointer->lineno[pointer->linecount]=l;
					pointer->linecount++;

				}

			}
			else{																				//hashtable map is free
				strncpy(constantstable[map].name,ctemp,l);
				strcpy(constantstable[map].type,type);
				constantstable[map].linecount=0;
				constantstable[map].valid=1;
				constantstable[map].next=NULL;
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				++countconstants;
				}
}


#line 341 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,     2,
      30,    31,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    26,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   200,   200,   205,   206,   207,   208,   209,   213,   215,
     216,   222,   223,   225,   226,   229,   231,   232,   235,   236,
     242,   244,   246,   248,   251,   253,   255,   256,   259,   260,
     263,   264,   267,   268,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   284,   285,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     301,   302,   303,   305,   306,   308,   309,   310,   312,   313,
     314,   315,   317,   318,   321,   322,   324,   325,   328,   329,
     332,   333,   336,   339,   340,   341,   342,   345,   346,   347,
     348,   349,   353,   354,   355,   356,   360,   362,   363,   365,
     366,   369,   372,   373,   376,   378,   379,   380,   381,   382,
     384,   385,   386,   387,   388
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "dtype", "assop", "sumop",
  "mulop", "unary", "logicalopbin", "logicalnot", "relop", "ifstmt",
  "elsestmt", "whilestmt", "charcnst", "floatcnst", "stringcnst",
  "breakval", "returnval", "switchval", "casestmt", "structs", "unions",
  "defaultstmt", "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'",
  "'&'", "':'", "$accept", "ED", "program", "declarationList",
  "declarationListhelper", "declaration", "varDeclaration", "varDeclList",
  "varDeclListhelper", "varDeclarationStmt", "varDeclInitialize",
  "varDeclId", "typeSpecifier", "funDeclaration", "funName", "params",
  "paramList", "statement", "loopstatement", "stmtlist", "returnstmt",
  "loopstmtlist", "breakstmt", "selectionstmt", "selectionhelper",
  "expressionsemi", "expression", "simpleExpression", "unaryRelExpression",
  "relExpression", "sumExpression", "term", "iterationwhile", "factor",
  "mutable", "immutable", "callingnosq", "args", "arglist",
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
     275,   276,   277,   278,   279,   280,    59,    44,    91,    93,
      40,    41,   123,   125,    38,    58
};
# endif

#define YYPACT_NINF -169

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-169)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     346,   -11,  -169,  -169,    15,   379,    38,  -169,  -169,  -169,
    -169,  -169,   379,    34,   101,  -169,  -169,   114,  -169,    71,
    -169,    91,  -169,  -169,   105,   132,  -169,  -169,    13,   142,
    -169,    64,  -169,  -169,   346,   152,  -169,   131,  -169,   131,
     379,    57,  -169,  -169,  -169,   114,   160,   106,   148,   149,
    -169,   151,   109,  -169,   379,    12,    12,    12,    73,  -169,
     357,  -169,    28,    69,  -169,  -169,   181,   185,  -169,   181,
    -169,   195,  -169,   102,   173,   179,  -169,   142,   202,  -169,
     154,  -169,    15,    11,    35,   180,  -169,   190,   187,   191,
     149,   181,   205,  -169,   109,  -169,   109,   206,   212,    81,
    -169,   192,    42,  -169,   292,   227,  -169,  -169,   213,   187,
    -169,  -169,  -169,  -169,  -169,   222,  -169,   181,   368,   224,
    -169,  -169,   162,  -169,  -169,  -169,  -169,    51,   195,  -169,
    -169,  -169,    88,   109,   225,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,   231,   379,   238,
      84,    74,   244,   137,   242,   247,   194,  -169,  -169,  -169,
     184,  -169,   249,   226,  -169,   259,  -169,   123,   248,   127,
     265,  -169,   129,   139,   168,  -169,  -169,   270,   324,  -169,
    -169,   169,   200,  -169,   201,   298,   299,   356,  -169,   324,
      74,   266,   273,  -169,  -169,    74,  -169
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,    92,    23,     0,     0,     0,    93,    95,    94,
     102,   103,     0,     0,     0,     2,     4,     9,    11,     0,
      12,     0,     5,     3,     0,    69,    73,    75,    77,    79,
      81,    84,    83,    86,     6,     0,    91,    70,    74,    84,
       0,     0,    90,     1,     8,     9,     0,    21,     0,    16,
      20,     0,    97,    65,     0,     0,     0,     0,     0,    71,
       0,     7,     0,     0,    85,    10,     0,     0,    13,     0,
      15,    26,   100,    84,     0,    98,    72,    78,    76,    80,
       0,    68,     0,     0,    84,    21,    18,     0,     0,     0,
      16,     0,     0,    27,     0,    96,     0,     0,     0,     0,
      87,     0,     0,    14,     0,    61,    22,    17,    29,     0,
      99,    67,    66,    88,    89,     0,    19,     0,     0,     0,
      31,    37,     0,    43,    44,    36,    42,     0,     0,    24,
     101,    45,     0,     0,     0,    30,    35,    40,    38,    34,
      39,    41,    64,    63,    62,    28,    46,     0,     0,     0,
       0,   105,     0,     0,     0,     0,     0,    82,   114,   110,
       0,   111,     0,     0,   104,     0,    33,    37,     0,    43,
       0,    59,    44,    36,    42,   113,   112,     0,     0,   108,
      60,    35,    40,    55,    38,    34,    39,    41,    32,     0,
     105,     0,     0,   106,   109,   105,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,   258,  -169,   262,    16,     0,    67,   221,  -169,
     245,   228,     7,  -169,   311,  -169,   189,   -95,  -169,   214,
     -99,   -92,   166,     1,  -169,     2,   -46,    -2,     8,  -169,
     280,   283,   171,   289,    -1,  -169,  -169,  -169,  -169,  -169,
       9,   -96,  -168,  -169
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    44,    17,   167,    48,    70,   102,
      49,    50,   117,    20,    21,    92,    93,   105,   157,   168,
     169,   170,   171,   172,   144,   173,    24,    25,    26,    27,
      28,    29,   140,    30,    31,    32,    33,    74,    75,    34,
      46,   174,   155,   162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    22,    23,    37,    39,   123,    72,    19,   126,    35,
      41,    39,    81,    38,   129,     1,     2,    18,    36,   -25,
      55,    54,   193,   137,    19,    56,   141,   196,     7,     8,
       9,    85,   142,    45,    18,    22,    23,    42,    63,    39,
     100,    19,    12,    35,   101,    18,    13,     3,    81,    13,
     110,    73,    19,    39,    39,    39,    39,    73,    83,    84,
      86,    45,    76,    60,     6,    10,    11,    54,    40,   182,
      58,   179,   187,    59,    47,   115,     1,     2,    91,    54,
      80,    99,     4,   104,     5,   190,   191,   147,    64,     7,
       8,     9,    60,    73,    54,    73,   153,   192,    54,   154,
      88,    43,   116,    12,   121,   124,   125,    13,    94,    60,
     113,    59,     1,     2,   146,   152,   132,    39,     4,     3,
       5,    52,   136,   138,   139,     7,     8,     9,   143,    87,
      60,    53,    73,    87,    67,    91,   -25,    10,    11,    12,
     158,   159,    54,    13,   160,   -50,   150,    39,   -50,   -57,
      57,   -58,   -57,   161,   -58,    62,   -50,    97,    98,    60,
     -57,   -49,   -58,    66,   -49,     1,     2,     3,   181,   184,
     185,     4,   -49,     5,    68,     6,    69,   134,     7,     8,
       9,    71,   118,   119,    85,    10,    11,   175,   176,    89,
     -56,   -48,    12,   -56,   -48,   135,    13,     1,     2,     3,
       3,   -56,   -48,     4,    95,     5,    96,     6,    67,    55,
       7,     8,     9,   165,   118,   119,   103,    10,    11,   104,
     106,   114,   -53,   -51,    12,   -53,   -51,   166,    13,     1,
       2,     3,   111,   -53,   -51,     4,   109,     5,   112,     6,
     128,   127,     7,     8,     9,   165,   118,   119,   130,    10,
      11,     1,     2,     3,   133,   148,    12,     4,   178,     5,
      13,     6,   149,   134,     7,     8,     9,   165,   118,   119,
     151,    10,    11,     1,     2,     3,   156,   163,    12,     4,
     164,     5,    13,     6,   177,   180,     7,     8,     9,   165,
     118,   119,    61,    10,    11,     1,     2,     3,   188,   194,
      12,     4,   189,     5,    13,     6,   195,    65,     7,     8,
       9,   107,   118,   119,    90,    10,    11,   145,   122,   108,
     -47,   -52,    12,   -47,   -52,   120,    13,     1,     2,     3,
      51,   -47,   -52,     4,   183,     5,    78,     6,    77,   186,
       7,     8,     9,   165,   118,   119,    79,    10,    11,     1,
       2,     3,     0,     0,    12,     4,     0,     5,    13,     6,
       1,     2,     7,     8,     9,     0,    82,     0,     5,    10,
      11,     1,     2,     7,     8,     9,    12,     0,   -54,     5,
      13,   -54,     1,     2,     7,     8,     9,    12,     0,   -54,
       5,    13,     0,     0,   131,     7,     8,     9,    12,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,    13
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,     4,     5,   104,    52,     0,   104,     0,
      12,    12,    58,     5,   109,     3,     4,    17,     3,    30,
       7,    10,   190,   122,    17,    12,   122,   195,    16,    17,
      18,     3,   127,    17,    34,    34,    34,     3,    40,    40,
      29,    34,    30,    34,     9,    45,    34,     5,    94,    34,
      96,    52,    45,    54,    55,    56,    57,    58,    60,    60,
      32,    45,    54,    28,    13,    23,    24,    10,    30,   168,
       6,   163,   168,     9,     3,    33,     3,     4,    71,    10,
       7,    82,     9,    32,    11,   177,   178,   133,    31,    16,
      17,    18,    28,    94,    10,    96,    22,   189,    10,    25,
      31,     0,   102,    30,   104,   104,   104,    34,     6,    28,
      29,     9,     3,     4,    26,    31,   118,   118,     9,     5,
      11,    30,   122,   122,   122,    16,    17,    18,   127,    62,
      28,    26,   133,    66,    28,   128,    30,    23,    24,    30,
       3,     4,    10,    34,     7,    22,   148,   148,    25,    22,
       8,    22,    25,    16,    25,     3,    33,     3,     4,    28,
      33,    22,    33,     3,    25,     3,     4,     5,   168,   168,
     168,     9,    33,    11,    26,    13,    27,    15,    16,    17,
      18,    30,    20,    21,     3,    23,    24,     3,     4,     4,
      22,    22,    30,    25,    25,    33,    34,     3,     4,     5,
       5,    33,    33,     9,    31,    11,    27,    13,    28,     7,
      16,    17,    18,    19,    20,    21,    26,    23,    24,    32,
      29,    29,    22,    22,    30,    25,    25,    33,    34,     3,
       4,     5,    26,    33,    33,     9,    31,    11,    26,    13,
      27,    14,    16,    17,    18,    19,    20,    21,    26,    23,
      24,     3,     4,     5,    30,    30,    30,     9,    32,    11,
      34,    13,    31,    15,    16,    17,    18,    19,    20,    21,
      32,    23,    24,     3,     4,     5,    32,    35,    30,     9,
      33,    11,    34,    13,    35,    26,    16,    17,    18,    19,
      20,    21,    34,    23,    24,     3,     4,     5,    33,    33,
      30,     9,    32,    11,    34,    13,    33,    45,    16,    17,
      18,    90,    20,    21,    69,    23,    24,   128,   104,    91,
      22,    22,    30,    25,    25,    33,    34,     3,     4,     5,
      19,    33,    33,     9,   168,    11,    56,    13,    55,   168,
      16,    17,    18,    19,    20,    21,    57,    23,    24,     3,
       4,     5,    -1,    -1,    30,     9,    -1,    11,    34,    13,
       3,     4,    16,    17,    18,    -1,     9,    -1,    11,    23,
      24,     3,     4,    16,    17,    18,    30,    -1,    22,    11,
      34,    25,     3,     4,    16,    17,    18,    30,    -1,    33,
      11,    34,    -1,    -1,    26,    16,    17,    18,    30,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    11,    13,    16,    17,    18,
      23,    24,    30,    34,    37,    38,    39,    41,    42,    48,
      49,    50,    59,    61,    62,    63,    64,    65,    66,    67,
      69,    70,    71,    72,    75,    76,     3,    70,    64,    70,
      30,    63,     3,     0,    40,    41,    76,     3,    43,    46,
      47,    50,    30,    26,    10,     7,    12,     8,     6,     9,
      28,    38,     3,    63,    31,    40,     3,    28,    26,    27,
      44,    30,    62,    70,    73,    74,    64,    67,    66,    69,
       7,    62,     9,    63,    70,     3,    32,    43,    31,     4,
      46,    48,    51,    52,     6,    31,    27,     3,     4,    70,
      29,     9,    45,    26,    32,    53,    29,    44,    47,    31,
      62,    26,    26,    29,    29,    33,    42,    48,    20,    21,
      33,    42,    55,    56,    59,    61,    77,    14,    27,    53,
      26,    26,    63,    30,    15,    33,    42,    56,    59,    61,
      68,    77,    53,    59,    60,    52,    26,    62,    30,    31,
      63,    32,    31,    22,    25,    78,    32,    54,     3,     4,
       7,    16,    79,    35,    33,    19,    33,    42,    55,    56,
      57,    58,    59,    61,    77,     3,     4,    35,    32,    57,
      26,    42,    56,    58,    59,    61,    68,    77,    33,    32,
      57,    57,    57,    78,    33,    33,    78
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    38,    38,    39,    40,
      40,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      46,    47,    47,    48,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    72,    73,    73,    74,
      74,    75,    76,    76,    77,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     2,     0,
       2,     1,     1,     3,     4,     2,     0,     3,     0,     2,
       1,     1,     4,     1,     6,     1,     0,     1,     4,     2,
       3,     2,     3,     2,     2,     2,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     2,     3,     2,     2,     1,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       2,     5,     7,     1,     1,     2,     5,     5,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     1,     3,     1,     4,     5,     5,
       2,     1,     1,     1,     1,     1,     4,     0,     1,     3,
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
#line 201 "parser.y" /* yacc.c:1646  */
    {
	printf("Valid Expressions : ");
}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 244 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),test,line);}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 246 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[-3].sval),test,line);push_to_constants_table((yyvsp[-1].sval),"number",line);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 248 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));strcpy(test,(yyvsp[0].sval));}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 251 "parser.y" /* yacc.c:1646  */
    {}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 253 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));  push_to_symbol_table((yyvsp[0].sval),"function",line);}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 312 "parser.y" /* yacc.c:1646  */
    { /*printf( " found assignment an:   %s\n" ,$2); */}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 348 "parser.y" /* yacc.c:1646  */
    { push_to_symbol_table((yyvsp[0].sval),"data",line); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 353 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 354 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"character",line);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 355 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"string",line);}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 356 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"float",line);}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 372 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval)); strcpy(test,(yyvsp[0].sval));}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 373 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.sval),(yyvsp[0].sval));}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 384 "parser.y" /* yacc.c:1646  */
    {push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 385 "parser.y" /* yacc.c:1646  */
    { push_to_constants_table((yyvsp[0].sval),"number",line);}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1702 "y.tab.c" /* yacc.c:1646  */
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
#line 391 "parser.y" /* yacc.c:1906  */

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
	yyin=fopen("tester.c","r");
	yyparse();
	printf("\n\t\t\t\t\tsymbols table\n");
	printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \n","ID","name","type","linecount","linenumbers");
	for(i=0;i<65535;++i)
	{
			if(symboltable[i].valid==1)
			{
				struct symbol * pointer=&symboltable[i];
				while(pointer->next!=NULL)
					{
						printf("%d \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
						for(j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
							pointer=pointer->next;
						
					}
				printf("%d \t\t %s \t\t %s\t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
						for(j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
							pointer=pointer->next;
			
				printf("\n");
			}
	}
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
	}
	return 0;
}

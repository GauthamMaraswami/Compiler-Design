#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int ival;
	float fval;
	char cval;
  char sval[100];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 39 "parser.y"
	#include<stdio.h>
#include<string.h>
	FILE *yyin;
	extern int line;
	char test[100];
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

/*symbol table*/
struct symbol{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct symbol *next;
} symboltable[65535];

/*constants table*/
struct constants{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct constants *next;
} constantstable[65535];

/*no of constants*/
int countconstants=0;
int countsymbol=0;
/*function to add symbol to symbol table*/
void push_to_symbol_table(char ctemp[],char type[],int l)
{
	unsigned long map=hash(ctemp);
map=map%65535;
	int len=strlen(ctemp);
	if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)==0) /*case when the symbol is already in table first*/
	{
		
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;

	}
	else if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)!=0)/*case when symbol not in table first*/
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
		if(found==0)													/*//case when symbol not found*/
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
		if(found==1)													/*case when symbol found at some other position*/
		{
			pointer->lineno[pointer->linecount]=l;
			pointer->linecount++;

		}

	}
	else{														   /*hashtable map is free*/
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
/*function to add constants to constant table*/
void push_to_constants_table(char ctemp[],char type[],int l)								/*case when the symbol is already in table first*/
{
	unsigned long map=hash(ctemp);
	map=map%65535;
	int len=strlen(ctemp);
	if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)==0)
			{
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				

			}
			else if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)!=0)		/*case when symbol not in table first*/
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
				if(found==0)														/*//case when symbol not found*/
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
				if(found==1)													/*case when symbol found at some other position				*/
				{
					pointer->lineno[pointer->linecount]=l;
					pointer->linecount++;

				}

			}
			else{																				/*hashtable map is free*/
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

#line 189 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define NUM 258
#define dtype 259
#define assop 260
#define sumop 261
#define mulop 262
#define unary 263
#define logicalopbin 264
#define logicalnot 265
#define relop 266
#define ifstmt 267
#define elsestmt 268
#define whilestmt 269
#define charcnst 270
#define floatcnst 271
#define stringcnst 272
#define breakval 273
#define returnval 274
#define switchval 275
#define casestmt 276
#define structs 277
#define unions 278
#define defaultstmt 279
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    6,    6,    6,    6,    6,    6,    8,   14,   14,
   13,   13,    1,    1,   15,   17,   17,   18,   18,   16,
   19,   19,    2,    3,    4,   20,   20,   22,   22,   21,
   21,   24,   24,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   26,   26,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   28,
    9,    9,   29,   29,    7,    7,    7,   30,   30,   30,
   30,   30,   27,   27,   33,   33,   34,   34,   35,   35,
   36,   36,   10,   37,   37,   31,   31,   31,   31,   31,
   38,   38,   38,   38,   32,   39,   39,   40,   40,   12,
    5,    5,   11,   41,   41,   41,   41,   41,   42,   42,
   42,   42,   42,
};
static const short yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    1,    2,    0,    2,
    1,    1,    3,    4,    2,    0,    3,    0,    2,    1,
    1,    4,    1,    6,    1,    0,    1,    4,    2,    3,
    2,    3,    2,    2,    2,    1,    1,    2,    2,    2,
    2,    1,    1,    1,    2,    3,    2,    2,    1,    1,
    2,    2,    2,    2,    2,    1,    1,    1,    1,    2,
    5,    7,    1,    1,    2,    5,    5,    3,    1,    2,
    2,    1,    3,    1,    2,    1,    3,    1,    3,    1,
    3,    1,    5,    1,    1,    4,    5,    5,    2,    1,
    1,    1,    1,    1,    4,    0,    1,    3,    1,    6,
    1,    1,    7,    0,    5,    7,    3,    5,    1,    1,
    2,    2,    1,
};
static const short yydefred[] = {                         0,
    0,   91,   23,    0,    0,    0,    0,   92,   94,   93,
    0,  101,  102,    0,    0,   11,    0,   12,    0,    0,
    1,    2,    3,    4,    5,    6,    7,    0,    0,    0,
    0,   72,   74,   76,    0,    0,   82,   84,   90,    0,
    0,   75,    0,    0,    0,   89,    0,    0,    0,    0,
   20,    0,    0,    0,    0,    8,    0,   65,    0,   71,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   13,    0,   15,   99,    0,    0,    0,   18,    0,    0,
   10,   73,    0,   68,    0,    0,    0,    0,    0,   81,
    0,    0,    0,    0,    0,    0,    0,   27,    0,   95,
    0,    0,   14,    0,    0,    0,   86,    0,    0,    0,
    0,   83,    0,   22,    0,    0,   17,   98,    0,   19,
    0,   67,   66,   87,   88,    0,   31,   37,   36,   44,
   42,    0,   43,    0,    0,   33,    0,    0,    0,    0,
    0,    0,    0,   59,    0,    0,    0,    0,   24,  100,
   45,    0,   30,   35,   34,   38,   39,   41,   40,   63,
   64,   62,   60,    0,    0,    0,    0,    0,    0,   55,
   32,  113,  109,    0,  110,    0,    0,  103,   28,   46,
  112,  111,    0,    0,  107,    0,    0,    0,    0,  105,
  108,    0,  106,
};
static const short yydgoto[] = {                         15,
  137,  121,   18,   19,   54,   21,  138,   23,  139,   25,
  140,   27,   55,   56,   49,   50,   73,  102,   51,   97,
  110,   98,  141,  112,  142,  143,   29,  144,  162,   30,
   31,   32,   33,   34,   35,   36,   37,   38,   75,   76,
  147,  176,
};
static const short yysindex[] = {                       456,
    0,    0,    0,  -35,  501,   38,   49,    0,    0,    0,
   53,    0,    0, -161,    0,    0, -157,    0,   61, -155,
    0,    0,    0,    0,    0,    0,    0, -237, -160,   44,
  -87,    0,    0,    0, -229, -156,    0,    0,    0,   14,
   14,    0,  501,  501,  393,    0,   20,   67,   50,   68,
    0,  393,  -92, -144, -237,    0,  501,    0,   -9,    0,
  472,  498,  498,  498,  -21,  -20,   73,  -77, -143, -142,
    0, -141,    0,    0,   77,   75,   20,    0,   62, -141,
    0,    0, -193,    0,  -35,  -76,  -78, -156, -139,    0,
    2,    6,    7,  393,   30, -141,   83,    0,   68,    0,
  393, -116,    0,   74,   78,  -39,    0,   39,  410, -134,
  275,    0, -202,    0,   92,    2,    0,    0,   79,    0,
 -141,    0,    0,    0,    0,  492,    0,    0,    0,    0,
    0,  298,    0, -111,   80,    0,    0,    0,    0,    0,
  321,   15,    0,    0, -178,   84,   21, -142,    0,    0,
    0,  -53,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -159,    0,   86,  347,    0,    0,    0,
    0,    0,  370,  433,    0,  433, -202,   23,   27,    0,
    0, -202,    0,
};
static const short yyrindex[] = {                         0,
  518,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  141,    9,    0,
  -57,    0,    0,    0,  -36,  530,    0,    0,    0,   22,
  -11,    0,    0,    0,    0,    0,   11,    0,    0,   88,
    0,  113,    0,    0,  141,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  541,    0,  116,
    0,    0,    0,    0,    0,  122,   31,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -82,  567,  -34,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   88,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,   41,    0,  128,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -38,   24,   47,   70,
    0,    0,   93,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  117,  140,  163,  186,  209,  248,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   41,    0,    0,    0,
    0,   41,    0,
};
static const short yygindex[] = {                         0,
   18,   16,    0,  153,  171,    0,   26,    0,   19,  -72,
   36,    0,  174,  120,  -19,  109,   90,    0,   91,    0,
  -58,   42,   82,    0,  -89,  -85,  -16,   51,    0,  -10,
  756,    0,   10,    0,  130,  132,  133,    0,    0,    0,
 -149,    0,
};
#define YYTABLESIZE 882
static const short yytable[] = {                         37,
   61,   85,   14,   61,   78,  180,   77,   78,  119,   77,
   85,  109,   61,   61,   42,   17,  107,   16,   24,   91,
   92,    3,   78,  133,   77,   22,   65,   66,   14,   85,
   78,   62,   85,   79,   67,   26,   63,  190,   61,   12,
   13,   74,  193,   17,   86,   16,  159,   85,   84,   69,
   25,   61,   69,  124,   21,  169,   78,  149,   77,  157,
   79,   36,   70,  104,  105,   70,   82,   69,  167,   21,
   17,   21,   16,  145,   21,  161,  146,   43,  172,  173,
   70,   85,  174,   84,   44,   96,   50,  185,   44,   21,
  118,  175,   45,  187,  188,   46,  189,  181,  182,   47,
   52,   53,   58,   57,   61,   64,   70,   42,   71,  152,
   69,   72,   80,   93,   95,   77,    3,  100,  101,  120,
  103,   62,  114,  116,  109,   61,  128,  130,  111,  113,
   43,  125,  122,  134,  129,  148,  123,  150,  163,  171,
    9,  177,    3,  183,  131,  178,   16,  191,   49,  154,
  156,  192,  160,   96,   35,    6,   26,  155,  164,  166,
   12,   13,   97,   96,   77,  104,  165,  158,   29,   48,
   20,   58,   59,   28,   81,   60,  168,   34,   85,   85,
   99,   85,   94,   85,  108,   60,  115,   57,  117,  179,
  132,  170,   89,   88,   56,    0,   90,    0,    0,    0,
   38,    0,    0,   85,   85,    0,   85,    0,   85,    0,
   57,    0,    0,    0,    0,    0,    0,   57,   37,   37,
   37,   39,    0,   39,   37,    0,   37,   78,   37,   77,
   37,   37,   37,   37,   37,   37,   37,   50,   37,   37,
   50,   48,   57,   57,    0,    0,   41,    1,    2,   85,
   85,   83,   85,    4,   85,    5,    0,   61,   61,   61,
    8,    9,   10,   61,   47,   61,    0,   61,    0,   61,
   61,   61,   61,   61,   61,   61,   61,   61,   61,   61,
   36,   36,   36,    0,    0,   40,   36,   51,   36,    0,
   36,    0,   36,   36,   36,   36,   36,   36,   36,   49,
   36,   36,   49,   44,   44,   44,    0,    0,    0,   44,
   52,   44,   14,   44,    0,   44,   44,   44,   44,   44,
   44,   44,   58,   44,   44,   58,   42,   42,   42,    0,
    0,    0,   42,   54,   42,   14,   42,    0,   42,   42,
   42,   42,   42,   42,   42,   56,   42,   42,   56,   43,
   43,   43,    0,    0,    0,   43,    0,   43,   14,   43,
    0,   43,   43,   43,   43,   43,   43,   43,   57,   43,
   43,   57,   53,   35,   35,   35,    0,    0,    0,   35,
    0,   35,    0,   35,   14,   35,   35,   35,   35,   35,
   35,   35,   48,   35,   35,   48,   34,   34,   34,  136,
    0,    0,   34,    0,   34,    0,   34,   14,   34,   34,
   34,   34,   34,   34,   34,   47,   34,   34,   47,   38,
   38,   38,  153,    0,    0,   38,    0,   38,    0,   38,
   14,   38,   38,   38,   38,   38,   38,   38,   51,   38,
   38,   51,   39,   39,   39,    0,    0,   14,   39,    0,
   39,    0,   39,    0,   39,   39,   39,   39,   39,   39,
   39,   52,   39,   39,   52,   41,   41,   41,    0,  184,
   14,   41,    0,   41,    0,   41,    0,   41,   41,   41,
   41,   41,   41,   41,   54,   41,   41,   54,    0,    0,
    0,    0,  186,   14,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   40,   40,   40,    0,    0,   14,
   40,    0,   40,    0,   40,    0,   40,   40,   40,   40,
   40,   40,   40,   53,   40,   40,   53,    0,    0,   14,
    0,    1,    2,    3,  127,   14,    0,    4,   14,    5,
    0,    6,    0,    0,    8,    9,   10,  135,  126,   11,
  151,   12,   13,    0,    1,    2,    3,   25,   90,    0,
    4,   90,    5,    0,    6,    0,    7,    8,    9,   10,
   80,  126,   11,   80,   12,   13,   90,    1,    2,    3,
    0,   85,    0,    4,   85,    5,    0,    6,   80,    7,
    8,    9,   10,  135,  126,   11,    0,   12,   13,   85,
    0,    0,    0,    1,    2,    3,    0,   79,   90,    4,
   79,    5,    0,    6,    0,    0,    8,    9,   10,  135,
  126,   11,   80,   12,   13,   79,    1,    2,    3,    0,
    0,    0,    4,    0,    5,    0,    6,    0,    0,    8,
    9,   10,  135,  126,   11,    0,   12,   13,    0,    1,
    2,    0,    0,    0,    0,    4,    0,    5,    0,   79,
    0,    0,    8,    9,   10,    0,    1,    2,    3,    0,
    0,    0,    4,    0,    5,    0,    6,    0,    0,    8,
    9,   10,    0,  126,   11,    0,   12,   13,    0,    1,
    2,    3,    0,    0,    0,    4,    0,    5,    0,    6,
    0,    0,    8,    9,   10,  135,  126,   11,    0,   12,
   13,    0,    1,    2,    3,    0,    0,    0,    4,    0,
    5,    0,    6,    0,    7,    8,    9,   10,   39,    2,
   11,    0,   12,   13,   85,    0,    5,    0,    0,    0,
    0,    8,    9,   10,    0,    0,    0,    0,   39,    2,
    0,    0,    0,    0,   39,    2,    5,   39,    2,   40,
   41,    8,    9,   10,    0,    5,    0,    8,    9,   10,
    8,    9,   10,    0,    0,    0,    0,   90,   90,   90,
   90,   90,    0,   90,    0,    0,    0,    0,    0,    0,
   80,    0,    0,   80,    0,   80,    0,    0,   41,   41,
   68,   85,   85,    0,   85,    0,   85,   68,    0,    0,
    0,    0,   41,    0,   68,    0,   87,   41,   41,   41,
    0,    0,    0,    0,    0,    0,    0,   79,    0,    0,
   79,    0,   79,    0,    0,    0,    0,    0,    0,    0,
  106,    0,    0,    0,    0,    0,    0,    0,    0,   68,
    0,    0,    0,    0,    0,    0,   68,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   41,
};
static const short yycheck[] = {                         38,
    0,   59,   38,   91,   41,   59,   41,   44,  125,   44,
   93,  123,   91,   91,    5,    0,   93,    0,    0,   41,
   41,  259,   59,  109,   59,    0,   43,   44,   38,   41,
  123,  261,   44,   53,   45,    0,  266,  187,   38,  277,
  278,   52,  192,   28,   61,   28,  132,   59,   59,   41,
   40,   91,   44,   93,   44,  141,   93,  116,   93,  132,
   80,   38,   41,  257,  258,   44,   57,   59,  141,   59,
   55,   41,   55,  276,   44,  134,  279,   40,  257,  258,
   59,   93,  261,   94,   38,   70,  125,  177,   40,   59,
  101,  270,   40,  183,  184,  257,  186,  257,  258,  257,
   40,  257,   59,  264,   91,  262,   40,   38,   59,  126,
   91,   44,  257,   41,  258,  257,  259,   41,   44,  102,
   59,  261,   93,   41,  123,  125,  109,  109,  123,  123,
   38,   93,   59,  268,  109,   44,   59,   59,   59,  125,
    0,   58,  259,   58,  109,  125,   59,  125,  125,  132,
  132,  125,  134,   41,   38,  267,   41,  132,  141,  141,
  277,  278,   41,  148,  257,  125,  141,  132,   41,   17,
    0,  125,  260,    0,   55,  263,  141,   38,  261,  262,
   72,  264,  260,  266,  263,  263,   96,  264,   99,  148,
  109,  141,   63,   62,  125,   -1,   64,   -1,   -1,   -1,
   38,   -1,   -1,  261,  262,   -1,  264,   -1,  266,   -1,
  264,   -1,   -1,   -1,   -1,   -1,   -1,  125,  257,  258,
  259,  257,   -1,   38,  263,   -1,  265,  264,  267,  264,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  125,  264,  264,   -1,   -1,   38,  257,  258,  261,
  262,  261,  264,  263,  266,  265,   -1,  257,  258,  259,
  270,  271,  272,  263,  125,  265,   -1,  267,   -1,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  257,  258,  259,   -1,   -1,   38,  263,  125,  265,   -1,
  267,   -1,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  257,  258,  259,   -1,   -1,   -1,  263,
  125,  265,   38,  267,   -1,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  257,  258,  259,   -1,
   -1,   -1,  263,  125,  265,   38,  267,   -1,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  257,
  258,  259,   -1,   -1,   -1,  263,   -1,  265,   38,  267,
   -1,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  125,  257,  258,  259,   -1,   -1,   -1,  263,
   -1,  265,   -1,  267,   38,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  257,  258,  259,  125,
   -1,   -1,  263,   -1,  265,   -1,  267,   38,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  257,
  258,  259,  125,   -1,   -1,  263,   -1,  265,   -1,  267,
   38,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  257,  258,  259,   -1,   -1,   38,  263,   -1,
  265,   -1,  267,   -1,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  257,  258,  259,   -1,  123,
   38,  263,   -1,  265,   -1,  267,   -1,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,   -1,   -1,
   -1,   -1,  123,   38,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,   38,
  263,   -1,  265,   -1,  267,   -1,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,   -1,   -1,   38,
   -1,  257,  258,  259,  125,   38,   -1,  263,   38,  265,
   -1,  267,   -1,   -1,  270,  271,  272,  273,  274,  275,
   59,  277,  278,   -1,  257,  258,  259,   40,   41,   -1,
  263,   44,  265,   -1,  267,   -1,  269,  270,  271,  272,
   41,  274,  275,   44,  277,  278,   59,  257,  258,  259,
   -1,   41,   -1,  263,   44,  265,   -1,  267,   59,  269,
  270,  271,  272,  273,  274,  275,   -1,  277,  278,   59,
   -1,   -1,   -1,  257,  258,  259,   -1,   41,   91,  263,
   44,  265,   -1,  267,   -1,   -1,  270,  271,  272,  273,
  274,  275,   93,  277,  278,   59,  257,  258,  259,   -1,
   -1,   -1,  263,   -1,  265,   -1,  267,   -1,   -1,  270,
  271,  272,  273,  274,  275,   -1,  277,  278,   -1,  257,
  258,   -1,   -1,   -1,   -1,  263,   -1,  265,   -1,   93,
   -1,   -1,  270,  271,  272,   -1,  257,  258,  259,   -1,
   -1,   -1,  263,   -1,  265,   -1,  267,   -1,   -1,  270,
  271,  272,   -1,  274,  275,   -1,  277,  278,   -1,  257,
  258,  259,   -1,   -1,   -1,  263,   -1,  265,   -1,  267,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,  277,
  278,   -1,  257,  258,  259,   -1,   -1,   -1,  263,   -1,
  265,   -1,  267,   -1,  269,  270,  271,  272,  257,  258,
  275,   -1,  277,  278,  263,   -1,  265,   -1,   -1,   -1,
   -1,  270,  271,  272,   -1,   -1,   -1,   -1,  257,  258,
   -1,   -1,   -1,   -1,  257,  258,  265,  257,  258,    4,
    5,  270,  271,  272,   -1,  265,   -1,  270,  271,  272,
  270,  271,  272,   -1,   -1,   -1,   -1,  260,  261,  262,
  263,  264,   -1,  266,   -1,   -1,   -1,   -1,   -1,   -1,
  261,   -1,   -1,  264,   -1,  266,   -1,   -1,   43,   44,
   45,  261,  262,   -1,  264,   -1,  266,   52,   -1,   -1,
   -1,   -1,   57,   -1,   59,   -1,   61,   62,   63,   64,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   85,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   -1,   -1,   -1,   -1,   -1,   -1,  101,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  126,
};
#define YYFINAL 15
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 279
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'&'",0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"ID","NUM","dtype","assop","sumop","mulop","unary","logicalopbin",
"logicalnot","relop","ifstmt","elsestmt","whilestmt","charcnst","floatcnst",
"stringcnst","breakval","returnval","switchval","casestmt","structs","unions",
"defaultstmt","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : ED",
"ED : program",
"program : expressionsemi",
"program : declarationList",
"program : selectionstmt",
"program : iterationwhile",
"program : switch",
"program : structoruniondefn",
"declarationList : declaration declarationListhelper",
"declarationListhelper :",
"declarationListhelper : declaration declarationListhelper",
"declaration : varDeclaration",
"declaration : funDeclaration",
"varDeclaration : typeSpecifier varDeclList ';'",
"varDeclaration : structspecifier ID varDeclList ';'",
"varDeclList : varDeclInitialize varDeclListhelper",
"varDeclListhelper :",
"varDeclListhelper : ',' varDeclInitialize varDeclListhelper",
"varDeclarationStmt :",
"varDeclarationStmt : varDeclarationStmt varDeclaration",
"varDeclInitialize : varDeclId",
"varDeclId : ID",
"varDeclId : ID '[' NUM ']'",
"typeSpecifier : dtype",
"funDeclaration : typeSpecifier funName '(' params ')' statement",
"funName : ID",
"params :",
"params : paramList",
"paramList : typeSpecifier varDeclId ',' paramList",
"paramList : typeSpecifier varDeclId",
"statement : '{' stmtlist '}'",
"statement : '{' '}'",
"loopstatement : '{' loopstmtlist '}'",
"loopstatement : '{' '}'",
"stmtlist : stmtlist expressionsemi",
"stmtlist : stmtlist varDeclaration",
"stmtlist : expressionsemi",
"stmtlist : varDeclaration",
"stmtlist : stmtlist selectionstmt",
"stmtlist : stmtlist iterationwhile",
"stmtlist : stmtlist returnstmt",
"stmtlist : stmtlist switch",
"stmtlist : switch",
"stmtlist : returnstmt",
"stmtlist : selectionstmt",
"returnstmt : returnval ';'",
"returnstmt : returnval simpleExpression ';'",
"loopstmtlist : stmtlist expressionsemi",
"loopstmtlist : stmtlist varDeclaration",
"loopstmtlist : expressionsemi",
"loopstmtlist : varDeclaration",
"loopstmtlist : stmtlist selectionstmt",
"loopstmtlist : stmtlist iterationwhile",
"loopstmtlist : stmtlist returnstmt",
"loopstmtlist : stmtlist switch",
"loopstmtlist : stmtlist breakstmt",
"loopstmtlist : switch",
"loopstmtlist : returnstmt",
"loopstmtlist : selectionstmt",
"loopstmtlist : breakstmt",
"breakstmt : breakval ';'",
"selectionstmt : ifstmt '(' simpleExpression ')' statement",
"selectionstmt : ifstmt '(' simpleExpression ')' statement elsestmt selectionhelper",
"selectionhelper : selectionstmt",
"selectionhelper : statement",
"expressionsemi : expression ';'",
"expressionsemi : mutable assop sumop NUM ';'",
"expressionsemi : mutable assop sumop ID ';'",
"expression : mutable assop expression",
"expression : simpleExpression",
"expression : unary mutable",
"expression : mutable unary",
"expression : callingnosq",
"simpleExpression : simpleExpression logicalopbin unaryRelExpression",
"simpleExpression : unaryRelExpression",
"unaryRelExpression : logicalnot unaryRelExpression",
"unaryRelExpression : relExpression",
"relExpression : sumExpression relop sumExpression",
"relExpression : sumExpression",
"sumExpression : sumExpression sumop term",
"sumExpression : term",
"term : term mulop factor",
"term : factor",
"iterationwhile : whilestmt '(' simpleExpression ')' loopstatement",
"factor : immutable",
"factor : mutable",
"mutable : mutable '[' simpleExpression ']'",
"mutable : mutable '[' unary mutable ']'",
"mutable : mutable '[' mutable unary ']'",
"mutable : '&' ID",
"mutable : ID",
"immutable : NUM",
"immutable : charcnst",
"immutable : stringcnst",
"immutable : floatcnst",
"callingnosq : funName '(' args ')'",
"args :",
"args : arglist",
"arglist : arglist ',' expression",
"arglist : expression",
"structoruniondefn : structspecifier ID '{' varDeclarationStmt '}' ';'",
"structspecifier : structs",
"structspecifier : unions",
"switch : switchval '(' expression ')' '{' switchstatement '}'",
"switchstatement :",
"switchstatement : casestmt switchimmutable ':' loopstmtlist switchstatement",
"switchstatement : casestmt switchimmutable ':' '{' loopstmtlist '}' switchstatement",
"switchstatement : defaultstmt ':' loopstmtlist",
"switchstatement : defaultstmt ':' '{' loopstmtlist '}'",
"switchimmutable : NUM",
"switchimmutable : charcnst",
"switchimmutable : sumop NUM",
"switchimmutable : sumop ID",
"switchimmutable : ID",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 389 "parser.y"
void yyerror()
{
	printf("Invalid expressions at line %d : \n",line);
}
int main()
{
    int i,j;
	yyin=fopen("testcases/testcase5.c","r");
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
#line 774 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 198 "parser.y"
	{
	printf("Valid Expressions : ");
}
break;
case 13:
#line 223 "parser.y"
	{printf("%sakakak\n%s\n",yystack.l_mark[-2].sval,test);}
break;
case 14:
#line 224 "parser.y"
	{printf("%s\n%s\n",yystack.l_mark[-3].sval,test);}
break;
case 21:
#line 242 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_symbol_table(yystack.l_mark[0].sval,test,line);}
break;
case 22:
#line 244 "parser.y"
	{printf("%s",yystack.l_mark[-3].sval); push_to_symbol_table(yystack.l_mark[-3].sval,test,line);push_to_constants_table(yystack.l_mark[-1].sval,"number",line);}
break;
case 23:
#line 246 "parser.y"
	{strcpy(yyval.sval,yystack.l_mark[0].sval);strcpy(test,yystack.l_mark[0].sval);}
break;
case 24:
#line 249 "parser.y"
	{}
break;
case 25:
#line 251 "parser.y"
	{strcpy(yyval.sval,yystack.l_mark[0].sval); printf("%s",yystack.l_mark[0].sval); push_to_symbol_table(yystack.l_mark[0].sval,"function",line);}
break;
case 68:
#line 310 "parser.y"
	{ /*printf( " found assignment an:   %s\n" ,$2); */}
break;
case 89:
#line 345 "parser.y"
	{printf("%s",yystack.l_mark[0].sval);  push_to_symbol_table(yystack.l_mark[0].sval,"data",line); }
break;
case 90:
#line 346 "parser.y"
	{printf("\n%skkk\n",yystack.l_mark[0].sval);}
break;
case 91:
#line 350 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_constants_table(yystack.l_mark[0].sval,"number",line);}
break;
case 92:
#line 351 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_constants_table(yystack.l_mark[0].sval,"character",line);}
break;
case 93:
#line 352 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_constants_table(yystack.l_mark[0].sval,"string",line);}
break;
case 94:
#line 353 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_constants_table(yystack.l_mark[0].sval,"float",line);}
break;
case 100:
#line 366 "parser.y"
	{"reaching";}
break;
case 101:
#line 369 "parser.y"
	{strcpy(yyval.sval,yystack.l_mark[0].sval); strcpy(test,yystack.l_mark[0].sval);}
break;
case 102:
#line 370 "parser.y"
	{strcpy(yyval.sval,yystack.l_mark[0].sval);}
break;
case 109:
#line 381 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_constants_table(yystack.l_mark[0].sval,"function",line);}
break;
case 110:
#line 382 "parser.y"
	{printf("%s",yystack.l_mark[0].sval); push_to_constants_table(yystack.l_mark[0].sval,"function",line);}
break;
#line 1058 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

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
extern YYSTYPE yylval;

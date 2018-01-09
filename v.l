%{
  int yylineno;


  #define WHILE 1
  #define VOID 2
  #define RETURN 3
  #define MAINFUNC 4
  #define BREAK 5
  #define CONTINUE 7
  #define IF 8

  #define SI 10
  #define USI 11
  #define UI 12
  #define INT 13
  #define LI 14
  #define ULI 15
  #define CHAR 16
  #define SC 17
  #define UC 18
  #define ID 20
  #define CONST 21
  #define LE 22
  #define GE 23
  #define EQ 24
  #define NE 25
  #define L 29
  #define G 30
  #define OR 26
  #define AND 27
  #define NOT 28
  #define ASS 29
  #define ADDASS 30
  #define SUBASS 31
  #define MULASS 32
  #define DIVASS 33
  #define MODASS 34
  #define PLUS 35
  #define SUB 36
  #define MULT 37
  #define DIV 38
  #define MOD 39
  #define PP 40
  #define MM 41
  #define BA 42
  #define BO 43
  #define BC 44
  #define OC 45
  #define LS 46
  #define RS 47
  #define FI 48
  #define FUI 49
  #define FLI 50
  #define FC 51
  #define FLUI 52
  	// %lu

// Miscelaneous tokens
  #define SEMICOLON 53
  #define BA1 54
  	// '(' bracket
  #define BA2 55
  	// ')' bracket
  #define BB1 56
  	// '[' bracket
  #define BB2 57
  	// ']' bracket
  #define BC1 58
  	// '{' bracket
  #define BC2 59
  	//'}' bracket
  #define COMMA 60
  	// ','
  #define Q 61
  	// Quote "
  #define SQ 62
  	// Single Quote '
  #define HEAD 63
  	// Header file
  #define ARR 64
	// Array
  #define SLC 65
	// Single comment '/'
  #define MLCO 66
  	// Multiline Comment Open '/*'
  #define MLCC 67
  	// Multilien Comment Close '*/'
  #define DEF 68
    // Macro
  #define PRINTF 69
  #define SCANF 70
  #define FUNC 71
%}

  alpha [A-Z|a-z]
  digit [0-9]
  und [_]
  space [ ]

%%
  \n	{yylineno++;}
  "main[ ]*(void)" return MAINFUNC;
  "main[ ]*()" return MAINFUNC;
  "main[ ]*(int argc, char **argv)" return MAINFUNC;
  "main[ ]*(int argc, char *argv[])" return MAINFUNC;
  "return"	return RETURN;
  void return VOID;
  break	return BREAK;
  if return IF;
  while return WHILE;
  printf return PRINTF;
  continue return CONTINUE;
  scanf return SCANF;
  "#include[ ]*<{alpha}{alpha}*\.h>" return HEAD;
  "#define {alpha}({alpha}|{digit}|{und})* {digit}+" return DEF;
  "#define {alpha}({alpha}|{digit}|{und})* ({digit}+)\.({digit}+)" return DEF;
  "#define {alpha}({alpha}|{digit}|{und})* {alpha}({alpha}|{digit}|{und})*" return DEF;

  {alpha}({alpha}|{digit}|{und})*    return ID;
  {alpha}({alpha}|{digit}|{und})*\[{digit}*\] return ARR;
  {digit}+    return CONST;
  ({digit}+)\.({digit}+) return CONST;
  "<=" return LE;
  ">=" return GE;
  "==" return EQ;
  "!=" return NE;
  ">" return G;
  "<" return L;
  "||" return OR;
  "&&" return AND;
  "!" return NOT;
  "short int" return SI;
  "unsigned short int" return USI;
  "unsigned int" return UI;
  "int" return INT;
  "long int" return LI;
  "unsigned long int" return ULI;
  "char" return CHAR;
  "signed char" return SC;
  "unsigned char" return UC;

  "=" return ASS;
	//  =	Simple assignment operator.
  "+=" return ADDASS;
  	// +=	Add AND assignment operator.
  "-=" return SUBASS;
  	// -=	Subtract AND assignment operator.
  "*=" return MULASS;
  	// *=	Multiply AND assignment operator.
  "/=" return DIVASS;
 	// /=	Divide AND assignment operator.
  "%=" return MODASS;
  	//	%=	Modulus AND assignment operator.

  "+" return PLUS;
  "-" return SUB;
  "*" return MULT;
  "/" return DIV;
  "%" return MOD;
  "++" return PP;
  "--" return MM;

  "%d" return FI;
  "%u" return FUI;
  "%ld" return FLI;
  "%c" return FC;
  "%lu" return FLUI;

  "&" return BA;
  "|" return BO;
  "!" return BC;
  "~" return OC;
  "<<" return LS;
  ">>" return RS;
  "//" return SLC;
  "/*" return MLCO;
  "*/" return MLCC;

  ";" return SEMICOLON;
  "(" return BA1
  ')' return BA2;
  "[" return BB1;
  ']' return BB2;
  "{" return BC1
  '}' return BC2;
  ',' return COMMA;
  "\"" return Q;
  "'" return SQ;
  printf return PRINTF;
  scanf return SCANF;
%%

struct row
{
	char token[100];
	char attr[100];
	int attrno;
}r[100000];

int main(void)
{

yyin=fopen("tester.c","r");
yylex();
printf("count of characters is %d\n",c);
printf("count of lines is %d\n",l);
return 0;
}

int yywrap(void)
{
	return 1;
}

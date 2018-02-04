%{
#include"y.tab.h"
#include<string.h>
#include <stdlib.h>
%}
num [0-9]+
floatconst [0-9]+[\.][0-9]+
charconst [a-z|A-Z]
strings ["].*["]
dtype void|int|float|char
if if
else else
while while
switch switch
case case
default default
break  break
return return
assignmentgroup =|\+=|\-=|\*=|\/=|%=
unary \+\+|\-\-
sumoperator  [\+|\-]
multoperator [\*|%|/]
logicalopbin &&|\|\|
logicalnot !
relop >|<|<=|>=|==|!=
ID [a-zA-Z][a-zA-Z0-9]*
%%
{num} {
yylval.ival=atoi(yytext);
return NUM;}
{charconst} {
char res;
	strcpy(res, yytext);
	yylval.cval = res;
	return charcnst;
}
{floatconst} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	printf("if");
	return floatcnst;
}
{strings} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	printf("if");
	return stringcnst;
}
{if} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	printf("if");
	return ifstmt;
}
{else} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	return elsestmt;
}
{while} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	return whilestmt;
}
{switch} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	return switchval;
}
{case} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	return casestmt;
}
{default} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	return defaultstmt;
}
{dtype} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;return dtype;}
{break} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;return breakval;}
{return} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;return returnval;}
{ID} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
printf("eurekha");
return ID;}
{assignmentgroup} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return assop;}
{unary} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return unary;
}
{sumoperator} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return sumop;}
{multoperator} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return mulop;}
{logicalopbin} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return logicalopbin;}
{logicalnot} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return logicalnot;}
{relop} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return relop;}
\n return 0;
. return yytext[0];
%% 

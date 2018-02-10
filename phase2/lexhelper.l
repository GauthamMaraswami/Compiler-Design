%{
#include"y.tab.h"
#include<string.h>
#include <stdlib.h>
int line=1;
int comment_stack[100];//for storing comment stack
int stacktop=-1;//top of comment stack
int commentflag=0;//check if thing is inside commnet
%}
preprocessordirective #.*
single_line_comments \/\/.*
multi_line_comments_start \/\*
multi_line_comments_end \*\/
space [\ ]*|\t*
line \n
num [0-9]+
floatconst [0-9]+[\.][0-9]+
charconst ['][a-z|A-Z][']
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
{space} {}
{line} {
++line;
}
{preprocessordirective} {
}
{multi_line_comments_start} {

}
{multi_line_comments_end} {

}
{single_line_comments}	{
++line;

}
{num} {
	char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
return NUM;}
{charconst} {
	char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
	return charcnst;
}
{floatconst} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
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
if(commentflag==0)
{char res[100];
	strcpy(res, yytext);
	yylval.sval = res;return dtype;}
}
{break} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;return breakval;}
{return} {
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;return returnval;}
{ID} {
if(commentflag==0){
char res[100];
	strcpy(res, yytext);
	yylval.sval = res;
//printf("eurekha");
return ID;}
}
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
. {

	return yytext[0];
}
%% 
int yywrap(void)
{
    return 1;
}

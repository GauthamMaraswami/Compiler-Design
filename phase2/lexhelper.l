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
charconst ['][a-z|A-Z][0-9][']
badcharcnst ['][a-z|A-Z][a-z|A-Z]+[0-9][0-9]+[']
strings ["].*["]
dtype void|int|float|char
structs struct
unions union
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
logicalopbin &&|\|\||\^
logicalnot !
otherdefinedsymbols [{]|[}]|;|\(|\)|\]|\[|,|&|:|\'
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
	if(commentflag==0)
	{
	stacktop++;
	comment_stack[stacktop]=1;
	commentflag=1;
	}

}
{multi_line_comments_end} {
	if(commentflag==1){
		commentflag=0;
	}
	else{
		printf("lexixal error at %d\n",line);
	}

}
{single_line_comments}	{
	++line;

}
{num} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return NUM;
	}
}
{charconst} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return charcnst;
	}	
}
{badcharcnst} {
if(commentflag==0)
	{
	char res[100];
	strcpy(res, yytext);
	strcpy(yylval.sval,res);
	return badcharcnst;
	}
}
{floatconst} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return floatcnst;
	}
}
{strings} {
if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return stringcnst;
	}
}
{if} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return ifstmt;
	}
}
{else} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return elsestmt;
	}
}
{while} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return whilestmt;
	}
}
{switch} {
if(commentflag==0)
	{
char res[100];
	strcpy(res, yytext);
	strcpy(yylval.sval,res);
	return switchval;
}
}
{case} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return casestmt;
	}
}
{default} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return defaultstmt;
	}
}
{dtype} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return dtype;
	}
}
{structs} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
	return structs;
	}
}
{unions} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return unions;
	}
}
{break} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return breakval;
	}
}
{return} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return returnval;
	}
}
{ID} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return ID;
	}
}
{otherdefinedsymbols} {
	if(commentflag==0)
	{	
		return yytext[0];
	}
}
{assignmentgroup} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return assop;
	}
}
{unary} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return unary;
	}
}
{sumoperator} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return sumop;
	}
}
{multoperator} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return mulop;
	}
}
{logicalopbin} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return logicalopbin;
	}
}
{logicalnot} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return logicalnot;
	}
}
{relop} {
	if(commentflag==0)
	{
		char res[100];
		strcpy(res, yytext);
		strcpy(yylval.sval,res);
		return relop;
	}
}
. {
	if(commentflag==0)
	{	
		printf("lexixal error at %d\n",line);
		return yytext[0];
	}
	
}
%% 
int yywrap(void)
{
    return 1;
}

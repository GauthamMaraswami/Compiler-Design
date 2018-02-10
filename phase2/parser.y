
%union {
	int ival;
	float fval;
	char cval;
  char* sval;
}

%token <sval> ID
%token <ival> NUM
%token  <sval> dtype
%token <sval> assop
%token <sval> sumop
%token <sval> mulop
%token <sval> unary
%token <sval> logicalopbin
%token <sval> logicalnot
%token <sval> relop
%token <sval> ifstmt
%token <sval> elsestmt
%token <sval> whilestmt
%token <cval> charcnst
%token <sval> floatcnst
%token <sval> stringcnst
%token <sval> breakval
%token <sval> returnval
%token <sval> switchval
%token <sval> casestmt
%token <sval> defaultstmt
%{
	#include<stdio.h>
	FILE *yyin;
%}
%%

ED:program
{
	printf("Valid Expressions : ");
}
;
program:expressionsemi
|declarationList
|selectionstmt
|iterationwhile
|calling
|switch
;


declarationList:declaration declarationListhelper
;
declarationListhelper:
|declaration declarationListhelper
;




declaration: varDeclaration
|funDeclaration
;
varDeclaration: typeSpecifier varDeclList ';'
;

varDeclList:varDeclInitialize varDeclListhelper
;
varDeclListhelper:
|','varDeclInitialize varDeclListhelper
;






varDeclInitialize:varDeclId
;
varDeclId:ID 
|
ID '[' NUM ']' 
;
typeSpecifier:dtype { printf( "yacc found datatype an: %s \n" ,$1); }
;

funDeclaration: typeSpecifier ' ' ID '(' params ')' statement {printf("caught hete");}
;

params: 
|paramList
;

paramList: typeSpecifier ' ' varDeclId ','paramList
|typeSpecifier ' ' varDeclId
;
 
statement: '{' stmtlist '}'
|'{''}'
;

loopstatement: '{'loopstmtlist'}'
|'{''}'
;
stmtlist:stmtlist expressionsemi
|stmtlist varDeclaration
|expressionsemi
|varDeclaration
|selectionstmt
|iterationwhile
|returnstmt
|switch
;


returnstmt: returnval ';'
|returnval ' ' simpleExpression ';'
;
loopstmtlist:stmtlist
|breakval ';'
;
selectionstmt:ifstmt '(' simpleExpression ')' statement
|ifstmt '(' simpleExpression ')' statement elsestmt  selectionhelper
;
selectionhelper:' ' selectionstmt
|statement
;
expressionsemi:expression ';'
;
expression: mutable assop expression  { printf( " found assignment an:   %s\n" ,$2); }
|simpleExpression
|unary mutable
|mutable unary
;
simpleExpression: simpleExpression logicalopbin unaryRelExpression
|unaryRelExpression
;

unaryRelExpression: logicalnot unaryRelExpression
|relExpression
;
relExpression:sumExpression relop sumExpression
|sumExpression
;

sumExpression:sumExpression sumop term 
|term
;

term:term mulop factor
|factor
;

iterationwhile:whilestmt'('simpleExpression')'loopstatement
;

factor:immutable
|mutable
;
mutable:ID
|mutable'['simpleExpression']'
|mutable'['unary mutable']'
|mutable'['mutable unary']'
;


immutable:NUM
|charcnst
|stringcnst
|floatcnst
;

calling:ID'('args')' ';'
;
args:
|arglist
;
arglist:arglist','expression
|expression
;




switch:switchval '(' expression ')' '{' switchstatement '}'
;
switchstatement:
| casestmt ' ' switchimmutable ':' loopstmtlist switchstatement
|casestmt ' ' switchimmutable ':' '{' loopstmtlist '}' switchstatement
|defaultstmt ':' loopstmtlist
|defaultstmt ':' '{'loopstmtlist'}'
;
switchimmutable:NUM
|charcnst
;	
%%
void yyerror()
{
	printf("Invalid expressions : \n");
}
int main()
{
	yyin=fopen("tester.c","r");
	yyparse();
	return 0;
}


%union {
	int ival;
	float fval;
	
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
%{
	#include<stdio.h>
%}
%%

ED:program
{
	printf("Valid Expressions : ");
}
;
program:expressionsemi {printf("exp stmt");}
|declarationList {printf("deck stmt");}
|selectionstmt {printf("selection stmt");}
;
selectionstmt:ifstmt {printf("selection stmt");}
|elsestmt '(' simpleExpression ')'
;

declarationList: declarationList declaration
|declaration
;
declaration: varDeclaration
|funDeclaration
;
varDeclaration: typeSpecifier ' ' varDeclList ';'
;
varDeclList:varDeclList','varDeclInitialize 
|varDeclInitialize
;
varDeclInitialize:varDeclId
;
varDeclId:ID { printf( "yacc found an: %s " ,$1); }
|
ID '[' NUM ']' 
;
typeSpecifier:dtype { printf( "yacc found datatype andd: %s \n" ,$1); }
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
;

stmtlist: stmtlist expressionsemi
|stmtlist varDeclaration
|expressionsemi
|varDeclaration
|selectionstmt
;


expressionsemi:expression ';'
;
expression: mutable assop expression  { printf( " found exp an:   %s\n" ,$2); }
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



factor:immutable
|mutable
;
mutable:ID
|mutable'['simpleExpression']'
|mutable'['unary mutable']'
|mutable'['mutable unary']'
;


immutable:NUM
;




%%
void yyerror()
{
	printf("Invalid expressions : \n");
}
int main()
{
	printf("Enter expression : ");
	yyparse();
return 0;
}

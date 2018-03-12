
%union {
	int ival;
	float fval;
	char cval;
  	char sval[100];
}

%token <sval> ID
%token <sval> NUM
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
%token <sval> charcnst
%token <sval> badcharcnst
%token <sval> floatcnst
%token <sval> stringcnst
%token <sval> breakval
%token <sval> returnval
%token <sval> switchval
%token <sval> casestmt
%token <sval> structs
%token <sval> unions
%token <sval> defaultstmt
%type <sval> varDeclaration
%type <sval>typeSpecifier
%type <sval>funDeclaration
%type <sval>funName
%type <sval>structspecifier

%{
	#include<stdio.h>
	#include<string.h>
	#include "syntax.h"
	FILE *yyin;
	extern int line;
	extern int comment_stack[100];//for storing comment stack
	extern int stacktop;//top of comment stack
	extern int commentflag;
	char test[100];
	

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
|structoruniondefn
|structoruniondefn program
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
|structspecifier ID varDeclList ';' 
;

varDeclList:varDeclInitialize varDeclListhelper
;
varDeclListhelper:
|','varDeclInitialize varDeclListhelper
;

varDeclarationStmt:
|varDeclarationStmt varDeclaration
;




varDeclInitialize:varDeclId
;
varDeclId:ID { push_to_symbol_table($1,test,line);}
|
ID '[' NUM ']' { push_to_symbol_table($1,test,line);push_to_constants_table($3,"number",line);}
;
typeSpecifier:dtype  {strcpy($$,$1);strcpy(test,$1);}
;

funDeclaration: typeSpecifier funName '(' params ')' statement {}
;
funName:ID {strcpy($$,$1);  push_to_symbol_table($1,test,line);}
;
params: 
|paramList 
;

paramList: typeSpecifier varDeclId ','paramList
|typeSpecifier varDeclId
;
 
statement:  statement1 '}' {printf("close");}
| statement2 '}' {printf("close");}
;
statement1: statement2 stmtlist
;
statement2: '{'{printf("open");}
;






loopstatement: '{'loopstmtlist'}'
|'{''}'
;
stmtlist:stmtlist expressionsemi
|stmtlist varDeclaration
|expressionsemi
|varDeclaration
|stmtlist selectionstmt
|stmtlist iterationwhile
|stmtlist returnstmt
|stmtlist switch
|switch
|returnstmt
|selectionstmt
;


returnstmt: returnval ';'
|returnval simpleExpression ';'
;
loopstmtlist:stmtlist expressionsemi
|stmtlist varDeclaration
|expressionsemi
|varDeclaration
|stmtlist selectionstmt
|stmtlist iterationwhile
|stmtlist returnstmt
|stmtlist switch
|stmtlist breakstmt
|switch
|returnstmt
|selectionstmt
|breakstmt
;
breakstmt:breakval ';'
selectionstmt:ifstmt '(' simpleExpression ')' statement
|ifstmt '(' simpleExpression ')' statement ';'
|ifstmt '(' simpleExpression ')' statement elsestmt  selectionhelper
;
selectionhelper: selectionstmt
|statement
;
expressionsemi:expression ';'
|mutable assop sumop NUM ';' 
|mutable assop sumop ID ';'
;
expression: mutable assop expression  { /*printf( " found assignment an:   %s\n" ,$2); */}
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

sumExpression:sumExpression sumop term  {printf("add\n");}
|term
;

term:term mulop factor	 {printf("multiply\n");}
|factor
;

iterationwhile:whilestmt'('simpleExpression')'loopstatement
|whilestmt'('simpleExpression')' ';'
;

factor:immutable
|mutable		{printf("mutable\n");}
|'('simpleExpression')'  {printf("brackets\n");}
|callingnosq	 {printf("calling\n");}
;

mutable:mutable'['simpleExpression']'
|mutable'['unary mutable']'
|mutable'['mutable unary']'
|'&' ID { push_to_symbol_table($2,"data",line); }
|ID	
;


immutable:NUM	{ push_to_constants_table($1,"number",line);}
|charcnst	{ push_to_constants_table($1,"character",line);}
|stringcnst	{ push_to_constants_table($1,"string",line);}
|floatcnst	{ push_to_constants_table($1,"float",line);}
|badcharcnst	{ push_to_constants_table($1,"character",line);}
;


callingnosq:funName'('args')'	
;
args:
|arglist
;
arglist:arglist','expression
|expression
;

structoruniondefn: structspecifier ID '{' varDeclarationStmt '}' ';'
;

structspecifier:structs  {strcpy($$,$1); strcpy(test,$1);}
|unions	 {strcpy($$,$1);}
;

switch:switchval '(' expression ')''{' switchstatement '}'
;
switchstatement:
| casestmt  switchimmutable ':' loopstmtlist switchstatement
|casestmt  switchimmutable ':''{' loopstmtlist '}' switchstatement
|defaultstmt ':' loopstmtlist
|defaultstmt ':''{'loopstmtlist'}'
;
switchimmutable:NUM {push_to_constants_table($1,"number",line);}
|charcnst { push_to_constants_table($1,"number",line);}
|sumop NUM
|sumop ID
|ID
;	

%%
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
/*
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
	}*/
	return 0;
}

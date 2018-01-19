%token ID NUM
%{
	#include<stdio.h>
%}
%%
ED:E
{
	printf("Valid Expressions : ");
}
;
E:E'+'E
|E'-'E
|E'*'E
|E'/'E
|'('E')'
|ID
|NUM
;
%%
void yyerror()
{
	printf("Invalid expressions : ");
}
main()
{
	printf("Enter expression : ");
	yyparse();
}

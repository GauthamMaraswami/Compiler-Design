%{
int count=1;
%}

line \n
text .*
%%
{text} {printf("%d %s\n",count,yytext); 
			
	}
{line} {++count;}
%%
int main()
{
	yyin=fopen("text.txt","r");
	yylex();
	
}
int yywrap()
{
	return(1);
}

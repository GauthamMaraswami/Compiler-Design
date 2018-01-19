%{
int flag=0;
%}

even 0*10*10*
line \n
one 1
zero 0*
%% 
{even} {}
{one}  { flag=1; }
{zero}  { flag=1; printf("%s",yytext);}
%%
int main()
{
	yyin=fopen("numb.txt","r");
	yylex();
	if(flag==0)
	{
		printf("accepted\n");	
	}
	else
	{
		printf("not accepted\n");	
	}


}
int yywrap()
{
	return(1);
}

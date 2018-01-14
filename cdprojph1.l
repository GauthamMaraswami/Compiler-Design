%{
#include<stdio.h>
#include<string.h>
int c=0;
int l=0;

struct symbol{
char name[100];
char type[100];
int lineno[100];
int linecount;
} symboltable[100];
int countsymbol=0;
%}
preprocessordirective #.*
single_line_comments \/\/.*
multi_line_comments \/\*(.|[\r\n])*\*\/
line \n
openparanth [{]
closeparanth [}]
strings ["].*["]
formatspec %d|%f|%c|%s
delimitter [;]
keyword void|for|do|while|if|else|return|auto|break|case|char|const|continue|default|double|enum|extern|float|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile
intconst [0-9]+
floatconst [0-9]+[\.][0-9]+
charconst [a-z|A-Z]
specialsymbols \(|\)|;|\]|\[
operator [\+|-|=|/|\*|%]
identifier [a-z][a-zA-Z0-9]*
%%
{line} {
	printf("newline character found\n");
	++l;	
	}
{preprocessordirective} {
//printf("preprocessor directive found");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"preProcessorDirectory");
symboltable[countsymbol].linecount=0;
printf("%d\n",symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]);
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
++countsymbol;
}
{formatspec} {//printf(//"format specifier found");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"formatspecifier");
symboltable[countsymbol].linecount=0;
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
printf("%d\n",symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]);
++countsymbol;
}
{openparanth} {//printf(//"open paranthesis found");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"openParanthesis");
symboltable[countsymbol].linecount=0;
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
printf("%d\n",symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]);
++countsymbol;}
{closeparanth} {//printf("close paranthesis found");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"closeparanthesis");
symboltable[countsymbol].linecount=0;
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
printf("%d\n",symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]);
++countsymbol;}
{multi_line_comments} {//printf("multi line comments ");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"multilinecomments");
symboltable[countsymbol].linecount=0;
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
printf("%d\n",symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]);
++countsymbol;}
{single_line_comments} {//printf("single line comments found");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"singlelinecomments");
symboltable[countsymbol].linecount=0;
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
printf("%d\n",symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]);
++countsymbol;}

{intconst} {printf("integer constant found");}
{floatconst} {printf("float constant  ");}
{charconst} {printf("character constant");}
{strings} {printf("strings found");}
{specialsymbols} {printf("special symbols");	}
{keyword} {printf("keyword found");
strncpy(symboltable[countsymbol].name,yytext,yyleng);
strcpy(symboltable[countsymbol].type,"keywords");
symboltable[countsymbol].linecount=0;
symboltable[countsymbol].lineno[symboltable[countsymbol].linecount]=l;
++countsymbol;}
{operator} {printf("arithmatic operator found");}
{identifier} { printf("identifier");}
%%
int main()
{
yyin=fopen("tester.c","r");
yylex();
for(int i=0;i<countsymbol;++i)
{
		printf("%s %s %d ",symboltable[i].name,symboltable[i].type,symboltable[i].linecount);
		for(int j=0;j<=symboltable[i].linecount;++j)
		{
			printf("%d",symboltable[i].lineno[j]);
		}
printf("\n");
}
printf("count of characters is %d\n",c);
printf("count of lines is %d\n",l);
return 0;
}
int yywrap()
{
	return(1);
}


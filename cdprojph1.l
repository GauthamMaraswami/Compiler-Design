%{
int c=0;
int l=0;
%}
preprocessordirective #.*
function [a-z]+\([a-z]*\)
openparanth [{]
closeparanth [}]
formatspec %d|%f|%c|%s
line \\n
type int[\ ]|char[\ ]|bool[\ ]|float[\ ]
keyword void|for|do|while|if|else|return|main
digit [0-9]+
operator1 [\(|\)]
operator [\+|-|=|/|\*]
identifier [a-z][a-zA-Z0-9]*
%%
{preprocessordirective} {printf("preprocessor directive found");}
{function} {printf("function found");}
{formatspec} {printf("format specifier found");}
{openparanth} {printf("open paranthesis found");}
{closeparanth} {printf("close paranthesis found");}
{line} {printf("newline character found");}
{type} {printf("integer datatype found");}
{keyword} {printf("keyword found");}
{operator1} {printf("operator found");}
{operator} {printf("arithmatic operator found");}
{digit} { printf("random digit");}
{identifier} { printf("identifier");}
%%
int main()
{
yyin=fopen("tester.c","r");
yylex();
printf("count of characters is %d\n",c);
printf("count of lines is %d\n",l);
}
int yywrap()
{
return(1);
}

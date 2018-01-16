%{
#include<stdio.h>
#include<string.h>
int c=0;
int l=0;

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
struct symbol{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct symbol *next;
} symboltable[65535];

struct constants{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct constants *next;
} constantstable[65535];

int countconstants=0;
int countsymbol=0;
void push_to_symbol_table(char ctemp[],unsigned long map,char type[])
{
	if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)==0)
	{
		
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;

	}
	else if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)!=0)
	{
		int found=0;
		struct symbol * pointer=&symboltable[map];
		while(pointer->next!=NULL)
		{
			if(strcmp(pointer->name,ctemp)==0)
				{
					found=1;
				}
				pointer=pointer->next;
		}
		if(found==0)
		{
			struct symbol * tempsymbol;
			strncpy(tempsymbol->name,yytext,yyleng);
			strcpy(tempsymbol->type,type);
			tempsymbol->linecount=0;
			tempsymbol->valid=1;
			tempsymbol->next=NULL;
			tempsymbol->lineno[tempsymbol->linecount]=l;
			tempsymbol->linecount++;
			pointer->next=tempsymbol;
		}
		if(found==1)
		{
			pointer->lineno[pointer->linecount]=l;
			pointer->linecount++;

		}

	}
	else{
		strncpy(symboltable[map].name,yytext,yyleng);
		strcpy(symboltable[map].type,type);
		symboltable[map].linecount=0;
		symboltable[map].valid=1;
		symboltable[map].next=NULL;
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;
		++countsymbol;
		}
		


}
void push_to_constants_table(char ctemp[],unsigned long map,char type[])
{
	if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)==0)
			{
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				

			}
			else if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)!=0)
			{
				int found=0;
				struct constants * pointer=&constantstable[map];
				while(pointer->next!=NULL)
				{
					if(strcmp(pointer->name,ctemp)==0)
						{
							found=1;
						}
					pointer=pointer->next;
				}
				if(found==0)
				{
					struct constants * tempconstants;
					strncpy(tempconstants->name,yytext,yyleng);
					strcpy(tempconstants->type,type);
					tempconstants->linecount=0;
					tempconstants->valid=1;
					tempconstants->next=NULL;
					tempconstants->lineno[tempconstants->linecount]=l;
					tempconstants->linecount++;
					pointer->next=tempconstants;
				}
				if(found==1)
				{
					pointer->lineno[pointer->linecount]=l;
					pointer->linecount++;

				}

			}
			else{
				strncpy(constantstable[map].name,yytext,yyleng);
				strcpy(constantstable[map].type,type);
				constantstable[map].linecount=0;
				constantstable[map].valid=1;
				constantstable[map].next=NULL;
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				++countconstants;
				}
}

%}
preprocessordirective #.*
single_line_comments \/\/.*
multi_line_comments \/\*(.|[\r\n])*\*\/
line \n
openparanth [{]
closeparanth [}]
strings ["].*["]
keyword void|for|do|while|if|else|return|auto|break|case|char|const|continue|default|double|enum|extern|float|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile
intconst [0-9]+
floatconst [0-9]+[\.][0-9]+
charconst [a-z|A-Z]
functions [a-z][a-zA-Z0-9]*\(.*\)
specialsymbols \(|\)|;|\]|\[
operator [\+|-|=|/|\*|%]
identifier [a-z][a-zA-Z0-9]*
error .*
%%
{line} {
	++l;	
	}
{preprocessordirective} {
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"pre processor directory");
	memset(&ctemp[0], 0, sizeof(ctemp));
	
}

{openparanth} {
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"openParanthesis");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{closeparanth} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"closeparanthesis");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{multi_line_comments} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"multilinecomments");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{single_line_comments} {
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"singlelinecomments");
	memset(&ctemp[0], 0, sizeof(ctemp));
}

{intconst} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"integer constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{floatconst} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"float constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{charconst} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"character constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{strings} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"string constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{specialsymbols} {	
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"special symbols");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{keyword} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"keywords");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{operator} {
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"operator");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{functions} { 
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"functions");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{identifier} { 
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"identifier");
	memset(&ctemp[0], 0, sizeof(ctemp));
}
{error} {
printf("error\n");
}
%%
int main()
{
yyin=fopen("tester.c","r");
yylex();
printf("\nsymbols table\n");
for(int i=0;i<65535;++i)
{
		if(symboltable[i].valid==1)
		{
			struct symbol * pointer=&symboltable[i];
			while(pointer->next!=NULL)
				{
					printf("%s %s %d ",pointer->name,pointer->type,pointer->linecount);
					for(int j=0;j<pointer->linecount;++j)
					{
						printf("%d ",pointer->lineno[j]);
					}
						pointer=pointer->next;
					
				}
		printf("%s %s %d ",pointer->name,pointer->type,pointer->linecount);
					for(int j=0;j<pointer->linecount;++j)
					{
						printf("%d ",pointer->lineno[j]);
					}
						pointer=pointer->next;
		
		printf("\n");
		}
}
printf("constant table\n");
for(int i=0;i<65535;++i)
{
		if(constantstable[i].valid==1)
		{
			struct constants * pointer=&constantstable[i];
			while(pointer->next!=NULL)
				{
					printf("%s %s %d ",pointer->name,pointer->type,pointer->linecount);
					for(int j=0;j<pointer->linecount;++j)
					{
						printf("%d ",pointer->lineno[j]);
					}
					pointer=pointer->next;
					
				}
		printf("%s %s %d ",pointer->name,pointer->type,pointer->linecount);
					for(int j=0;j<pointer->linecount;++j)
					{
						printf("%d ",pointer->lineno[j]);
					}
					pointer=pointer->next;
		
		printf("\n");
		}
}
printf("count of lines is %d\n",l);
return 0;
}
int yywrap()
{
	return(1);
}


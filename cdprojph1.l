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
specialsymbols \(|\)|;|\]|\[
operator [\+|-|=|/|\*|%]
identifier [a-z][a-zA-Z0-9]*
%%
{line} {
	//printf("\n");
	++l;	
	}
{preprocessordirective} {
	////printf("preprocessor directive found");
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	//printf("%ld %s\n",map,ctemp);
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
			strcpy(tempsymbol->type,"preProcessorDirectory");
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
		strcpy(symboltable[map].type,"preProcessorDirectory");
		symboltable[map].linecount=0;
		symboltable[map].valid=1;
		symboltable[map].next=NULL;
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;
		++countsymbol;
		}
		strcpy(ctemp," ");
}

{openparanth} {////printf(//"open paranthesis found");
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	//printf("%ld %s\n",map,ctemp);
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
			strcpy(tempsymbol->type,"openParanthesis");
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
		strcpy(symboltable[map].type,"openParanthesis");
		symboltable[map].linecount=0;
		symboltable[map].valid=1;
		symboltable[map].next=NULL;
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;
		++countsymbol;
		}
memset(&ctemp[0], 0, sizeof(ctemp));
	
}
{closeparanth} {////printf("close paranthesis found");
	
	char ctemp[100];
strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
				strcpy(tempsymbol->type,"closeparanthesis");
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
			strcpy(symboltable[map].type,"closeparanthesis");
			symboltable[map].linecount=0;
			symboltable[map].valid=1;
			symboltable[map].next=NULL;
			symboltable[map].lineno[symboltable[map].linecount]=l;
			symboltable[map].linecount++;
			++countsymbol;
			}
memset(&ctemp[0], 0, sizeof(ctemp));
	
}
{multi_line_comments} {////printf("multi line comments ");
	char ctemp[100];
strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempsymbol->type,"multilinecomments");
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
				strcpy(symboltable[map].type,"multilinecomments");
				symboltable[map].linecount=0;
				symboltable[map].valid=1;
				symboltable[map].next=NULL;
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				++countsymbol;
				}
memset(&ctemp[0], 0, sizeof(ctemp));
}
{single_line_comments} {////printf("single line comments found");
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempsymbol->type,"singlelinecomments");
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
				strcpy(symboltable[map].type,"singlelinecomments");
				symboltable[map].linecount=0;
				symboltable[map].valid=1;
				symboltable[map].next=NULL;
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				++countsymbol;
				}
memset(&ctemp[0], 0, sizeof(ctemp));
}

{intconst} {//printf("integer constant found");
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempconstants->type,"identifier");
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
				strcpy(constantstable[map].type,"identifier");
				constantstable[map].linecount=0;
				constantstable[map].valid=1;
				constantstable[map].next=NULL;
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				++countconstants;
				}
memset(&ctemp[0], 0, sizeof(ctemp));




}
{floatconst} {//printf("float constant  ");
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempconstants->type,"identifier");
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
				strcpy(constantstable[map].type,"identifier");
				constantstable[map].linecount=0;
				constantstable[map].valid=1;
				constantstable[map].next=NULL;
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				++countconstants;
				}
memset(&ctemp[0], 0, sizeof(ctemp));}
{charconst} {//printf("character constant");
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempconstants->type,"identifier");
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
				strcpy(constantstable[map].type,"identifier");
				constantstable[map].linecount=0;
				constantstable[map].valid=1;
				constantstable[map].next=NULL;
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				++countconstants;
				}
memset(&ctemp[0], 0, sizeof(ctemp));}
{strings} {//printf("strings found");
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempconstants->type,"identifier");
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
				strcpy(constantstable[map].type,"identifier");
				constantstable[map].linecount=0;
				constantstable[map].valid=1;
				constantstable[map].next=NULL;
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				++countconstants;
				}
memset(&ctemp[0], 0, sizeof(ctemp));}
{specialsymbols} {//printf("special symbols");	
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)==0)
			{
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				//printf("reaching");

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
					strcpy(tempsymbol->type,"special symbols");
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
				strcpy(symboltable[map].type,"special symbols");
				symboltable[map].linecount=0;
				symboltable[map].valid=1;
				symboltable[map].next=NULL;
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				++countsymbol;
//printf("reaching1");
				}
memset(&ctemp[0], 0, sizeof(ctemp));}
{keyword} {
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)==0)
			{
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				//printf("reaching");

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
					strcpy(tempsymbol->type,"keywords");
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
				strcpy(symboltable[map].type,"keywords");
				symboltable[map].linecount=0;
				symboltable[map].valid=1;
				symboltable[map].next=NULL;
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				++countsymbol;
//printf("reaching1");
				}
memset(&ctemp[0], 0, sizeof(ctemp));

}
{operator} {;
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempsymbol->type,"operator");
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
				strcpy(symboltable[map].type,"operator");
				symboltable[map].linecount=0;
				symboltable[map].valid=1;
				symboltable[map].next=NULL;
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				++countsymbol;
				}
memset(&ctemp[0], 0, sizeof(ctemp));

}
{identifier} { 
char ctemp[100];
strcpy(ctemp," ");
strncpy(ctemp,yytext,yyleng);
unsigned long map=hash(ctemp);
map=map%65535;
//printf("%ld %s\n",map,ctemp);
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
					strcpy(tempsymbol->type,"identifier");
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
				strcpy(symboltable[map].type,"identifier");
				symboltable[map].linecount=0;
				symboltable[map].valid=1;
				symboltable[map].next=NULL;
				symboltable[map].lineno[symboltable[map].linecount]=l;
				symboltable[map].linecount++;
				++countsymbol;
				}
memset(&ctemp[0], 0, sizeof(ctemp));
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


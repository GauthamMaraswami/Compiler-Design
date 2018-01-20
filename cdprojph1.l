%{
#include<stdio.h>
#include<string.h>
int c=0;
int l=0;
int comment_stack[100];//for storing comment stack
int stacktop=-1;//top of comment stack
int commentflag=0;//check if thing is inside commnet
//hash function
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

//symbol table
struct symbol{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct symbol *next;
} symboltable[65535];

//constants table
struct constants{
int valid;
char name[100];
char type[100];
int lineno[100];
int linecount;
struct constants *next;
} constantstable[65535];

//no of constants
int countconstants=0;
int countsymbol=0;
//function to add symbol to symbol table
void push_to_symbol_table(char ctemp[],unsigned long map,char type[])
{
	if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)==0) //case when the symbol is already in table first
	{
		
		symboltable[map].lineno[symboltable[map].linecount]=l;
		symboltable[map].linecount++;

	}
	else if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)!=0)//case when symbol not in table first
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
		if(found==0)													////case when symbol not found
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
		if(found==1)													//case when symbol found at some other position
		{
			pointer->lineno[pointer->linecount]=l;
			pointer->linecount++;

		}

	}
	else{														   //hashtable map is free
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
//function to add constants to constant table
void push_to_constants_table(char ctemp[],unsigned long map,char type[])								//case when the symbol is already in table first
{
	if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)==0)
			{
				constantstable[map].lineno[constantstable[map].linecount]=l;
				constantstable[map].linecount++;
				

			}
			else if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)!=0)		//case when symbol not in table first
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
				if(found==0)														////case when symbol not found
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
				if(found==1)													//case when symbol found at some other position				
				{
					pointer->lineno[pointer->linecount]=l;
					pointer->linecount++;

				}

			}
			else{																				//hashtable map is free
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
multi_line_comments_start \/\*
multi_line_comments_end \*\/
space [\ ]|\t
line \n
openparanth [{]
closeparanth [}]
strings ["].*["]
keyword void|for|do|while|if|else|return|auto|break|case|char|const|continue|default|double|enum|extern|float|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile
intconst [0-9]+
floatconst [0-9]+[\.][0-9]+
charconst ['][a-z|A-Z][']
functions [a-z][a-zA-Z0-9]*\(.*\)
specialsymbols \(|\)|\]|\[|,
delimitter ;
operator [\+|\-|=|/|\*|%|>|<|&|\|]
notIdentifier [^a-zA-Z\t\n\ "\(|\)|\]|\[|,|"|\+|\-|=|/|\*|%|>|<|&|\||_|;][a-zA-Z0-9]*[a-zA-Z][a-zA-Z0-9]*
identifier [a-zA-Z][a-zA-Z0-9]*
error .
%%
{line} {
	++l;	//increment line count
	}
{space} {}
{preprocessordirective} {
	if(commentflag==0){
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"pre processor directory");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
	
}

{openparanth} {
if(commentflag==0){
	char ctemp[100];
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"openParanthesis");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{closeparanth} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"closeparanthesis");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{multi_line_comments_start} {
	stacktop++;
	comment_stack[stacktop]=1;
	commentflag=1;
	printf("comment start at %d :",l);
}
{multi_line_comments_end} {
	if(stacktop==-1){
		printf("comment error at %d \n", l);
	}
	else{
		stacktop--;
		if(stacktop==-1)
			{
				printf("comment end at %d \n", l);
				commentflag=0;
				printf("\n");
			}
	}
}
{single_line_comments} {
	if(commentflag==0){
	printf("comment :%s at %d\n",yytext,l);
		
	}
	else
	{
		printf("%s",yytext);
	}
		++l;
}
{intconst} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"integer constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
	printf("%s",yytext);
	}
}
{floatconst} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"float constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{charconst} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"character constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{strings} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_constants_table(ctemp,map,"string constant");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{specialsymbols} {	
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"special symbols");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{delimitter} {
}
{keyword} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"keywords");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{operator} {
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"operator");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{notIdentifier} {
if(commentflag==0){
printf("Error:Invalid Identifier%s\n ",yytext);
}
else{
printf("%s",yytext);
}

}
{identifier} { 
if(commentflag==0){
	char ctemp[100];
	strcpy(ctemp," ");
	strncpy(ctemp,yytext,yyleng);
	unsigned long map=hash(ctemp);
	map=map%65535;
	push_to_symbol_table(ctemp,map,"identifier");
	memset(&ctemp[0], 0, sizeof(ctemp));
	}
	else
	{
		printf("%s",yytext);
	}
}
{error} {
	if(commentflag==0){
		printf("error at %s  %d\n",yytext,l);
	}
}
%%
int main(int argc, char** argv)
{
	char cfile[10];
	strcpy(cfile,argv[1]);
	yyin=fopen(cfile,"r");
	yylex();
	if(stacktop!=-1)
	{
		printf("comment doesnt match\n");
	}
	printf("\n\t\t\t\t\tsymbols table\n");
	printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \n","ID","name","type","linecount","linenumbers");
	for(int i=0;i<65535;++i)
	{
			if(symboltable[i].valid==1)
			{
				struct symbol * pointer=&symboltable[i];
				while(pointer->next!=NULL)
					{
						printf("%d \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
						for(int j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
							pointer=pointer->next;
						
					}
				printf("%d \t\t %s \t\t %s\t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
						for(int j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
							pointer=pointer->next;
			
				printf("\n");
			}
	}
	printf("\n\n\t\t\t\t\tconstant table\n");
	printf("%s \t\t %s \t\t %s \t\t %s \t\t %s \n","ID","name","type","linecount","linenumbers");
	for(int i=0;i<65535;++i)
	{
			if(constantstable[i].valid==1)
			{
				struct constants * pointer=&constantstable[i];
				while(pointer->next!=NULL)
					{
						printf("%d \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
						for(int j=0;j<pointer->linecount;++j)
						{
							printf("\t%d ",pointer->lineno[j]);
						}
						pointer=pointer->next;
						
					}
				printf("%d \t\t %s \t\t %s \t\t %d ",i,pointer->name,pointer->type,pointer->linecount);
				for(int j=0;j<pointer->linecount;++j)
				{
					printf("\t%d ",pointer->lineno[j]);
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



#include<stdio.h>
#include<string.h>
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
    char scope[100];
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
/
	//no of constants
	int countconstants=0;
	int countsymbol=0;
	//function to add symbol to symbol table
	void push_to_symbol_table(char ctemp[],char type[],int l)
	{
		unsigned long map=hash(ctemp);
		map=map%65535;
		int len=strlen(ctemp);
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
			if(found==0)			////case when symbol not found
			{
				struct symbol * tempsymbol;
				strncpy(tempsymbol->name,ctemp,len);
				strcpy(tempsymbol->type,type);
				tempsymbol->linecount=0;
				tempsymbol->valid=1;
				tempsymbol->next=NULL;
				tempsymbol->lineno[tempsymbol->linecount]=l;
				tempsymbol->linecount++;
				pointer->next=tempsymbol;
			}
			if(found==1)				//case when symbol found at some other position
			{
				pointer->lineno[pointer->linecount]=l;
				pointer->linecount++;

			}

		}
		else        //hashtable map is free
		{										 
			strncpy(symboltable[map].name,ctemp,len);
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
	void push_to_constants_table(char ctemp[],char type[],int l)  //case when the symbol is already in table first
	{
		unsigned long map=hash(ctemp);
		map=map%65535;
		int len=strlen(ctemp);
		if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)==0)
		{
			constantstable[map].lineno[constantstable[map].linecount]=l;
			constantstable[map].linecount++;
		}
		else if(constantstable[map].valid==1&&strcmp(constantstable[map].name,ctemp)!=0)  //case when symbol not in table first
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
			if(found==0)		////case when symbol not found
			{
				struct constants * tempconstants;
				strncpy(tempconstants->name,ctemp,l);
				strcpy(tempconstants->type,type);
				tempconstants->linecount=0;
				tempconstants->valid=1;
				tempconstants->next=NULL;
				tempconstants->lineno[tempconstants->linecount]=l;
				tempconstants->linecount++;
				pointer->next=tempconstants;
			}
			if(found==1)			//case when symbol found at some other position				
			{
				pointer->lineno[pointer->linecount]=l;
				pointer->linecount++;

			}

		}
		else     //hashtable map is free			
		{			
			strncpy(constantstable[map].name,ctemp,l);
			strcpy(constantstable[map].type,type);
			constantstable[map].linecount=0;
			constantstable[map].valid=1;
			constantstable[map].next=NULL;
			constantstable[map].lineno[constantstable[map].linecount]=l;
			constantstable[map].linecount++;
			++countconstants;
		}
	}
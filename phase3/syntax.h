#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <limits.h>
	int countconstants=0;
	int countsymbol=0;


	int stackrep=-1;

unsigned long hash(unsigned char *str)
	{
    		unsigned long hash = 5381;
    		int c;

    		while (c = *str++)
        	hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    		return hash;
	}
	//identifier structure
	struct identifier{
		char name[100];
		char type[100];
	};
	//symbol table
	struct symbol{
	int valid;
	char name[100];
	char type[100];
	int lineno[100];
    char scope[100];
	char arraydimention[10];
	int proc_defn_flag;
	int parameter_count;
	struct identifier parameter_list[100];
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

	//function to add symbol to symbol table
	void push_to_symbol_table(char ctemp[],char type[],char scope[],int l,int fun_def_flag,char arr_dim[],struct identifier parameter_list[],int parameter_count )
	{
		unsigned long map=hash(ctemp);
		map=map%65535;
		int len=strlen(ctemp);
		if(symboltable[map].valid==1&&(strcmp(symboltable[map].name,ctemp)==0)) //case when the symbol is already in table first
		{
			int found=0;
			struct symbol * pointer= (struct symbol *) malloc( sizeof(struct symbol));
			pointer=&symboltable[map];
			if(strcmp(symboltable[map].scope,scope)==0)
			{
				found=1;
			}
			while(pointer->next!=NULL)
			{
				if(strcmp(pointer->scope,scope)==0)				
					{
						found=1;
					}
			}
			if(found==1)
			{
				printf("function already exists in the scope at line %d\n",l);
			}
			else{
				struct symbol * tempsymbol=(struct symbol *) malloc( sizeof(struct symbol));
				strncpy(tempsymbol->name,ctemp,len);
				strcpy(tempsymbol->type,type);
				tempsymbol->linecount=0;
				tempsymbol->valid=1;
				tempsymbol->next=NULL;
				tempsymbol->lineno[tempsymbol->linecount]=l;
				tempsymbol->linecount++;
				tempsymbol->proc_defn_flag=fun_def_flag;
				tempsymbol->parameter_count=parameter_count;
				if(parameter_count>0)
				{
					for(int zz=0;zz<parameter_count;++zz)
					{
						tempsymbol->parameter_list[zz]=parameter_list[zz];
					}
				}
				strcpy(tempsymbol->arraydimention,arr_dim);
				strcpy(tempsymbol->scope,scope);
				pointer->next=tempsymbol;	
			}

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
			symboltable[map].proc_defn_flag=fun_def_flag;
			symboltable[map].parameter_count=parameter_count;
			if(parameter_count>0)
			{
				for(int zz=0;zz<parameter_count;++zz)
				{
					symboltable[map].parameter_list[zz]=parameter_list[zz];
				}
			}
			strcpy(symboltable[map].arraydimention,arr_dim);
			strcpy(symboltable[map].scope,scope);
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



struct string
{
    char val[100];
    int len;
};

struct string converttostring(int temp)
{
    struct string res,resrev;
    res.len=0;
	resrev.len=0;
    while(temp>0)
    {
        int t=temp%10;
        res.val[res.len]='0'+t;
        res.len++;
        temp=temp/10;
    }
	
	 for(int i=(res.len-1);i>=0;--i)
    {
        resrev.val[resrev.len]=res.val[i];
		++resrev.len;
    }
	resrev.val[resrev.len]='\0';
    return resrev;
}
int converttoint(struct string temp)
{
    int res=0;
    for(int i=0;i<temp.len;++i)
    {
        res=res*10+temp.val[i]-'0';
    }
    return res;
}
struct string appendstring(struct string id,struct string temp1)
{
    struct string res;
    res=id;
	//printf("\n%sssop%d\n",res.val,res.len);
    for(int i=0;i<temp1.len;++i)
    {
        res.val[res.len]=temp1.val[i];
        res.len++;
    }
		res.val[res.len]='\0';
		// 
    return res;
}

struct string openbraceencounter(struct string id)
{
    if(stackrep==-1)
		{
		 	id.val[id.len]='1';	
            id.len++;
			id.val[id.len]='\0';
        }
    else if(stackrep!=-1)
        {
            int temp=stackrep;
			// printf("\ngot from stack%d\n",temp);
            temp++;
           	stackrep=-1;
            struct string temp1;
            temp1=converttostring(temp);
			//printf("\nans%s\n",temp1.val);
			//printf("\nidbfcal%s\n",id.val);
            id=appendstring(id,temp1); 		
        }
    return id;

}
struct string closebraceencounter(struct string id)
{
    int temp = converttoint(id);
     //printf("\nstack pushed val%d\n",(temp%10));
   // pushtostack(scopecount,(temp%10));
	stackrep=temp%10;
    temp=temp/10;
	//printf("\ntempend%d\n",temp);
    id=converttostring(temp);
   // printf("\nprevitr%s\n",id.val);
    return id;
}
void printstring(struct string id)
{
                for(int k=0;k<id.len;++k)
                    {
                        printf("%c",id.val[k]);
                    }
                    printf("\n");
}
int checkdeclaration(struct string idinp,char identifier[])
{
	//printf("\n%s",identifier);
	int len=strlen(identifier);
	unsigned long  map=hash(identifier);
	map=map%65535;
	struct symbol ans= symboltable[map];
	if(ans.valid==0)
	{
	//	printf("not found");
		
		return 0;
	}
	int lengthofid=idinp.len;
	while(lengthofid>=0)
	{
	//	printf("+++%s---%s+++\n",idinp.val,ans.scope);
			if(strcmp(ans.scope,idinp.val)==0)
			{
			//	printf("found");
				if(ans.proc_defn_flag==1)
			{
				return -1;
			}
				return 1;
			}
			else{
			struct symbol * pointer1= (struct symbol *) malloc( sizeof(struct symbol));
			pointer1=&ans;
			while(pointer1->next!=NULL)
			{
				//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
				if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						if(ans.proc_defn_flag==1)
						{
							return -1;
						}
						return 1;
						
					}
					pointer1=pointer1->next;
			}
		//	printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
			if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						if(ans.proc_defn_flag==1)
						{
							return -1;
						}
						return 1;
						
					}
	}
	lengthofid--;
			idinp.val[lengthofid]='\0';
	}
	//printf("notfound");
			return 0;

}

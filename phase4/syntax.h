#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <limits.h>
	int countconstants=0;
	int countsymbol=0;


	int stackrep=-1;
	int tempvar=0;
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
		int arr_flag;
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
	char scopeoffunction[100];
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
	void push_to_symbol_table(char ctemp[],char type[],char scope[],int l,int fun_def_flag,char arr_dim[],struct identifier parameter_list[],int parameter_count,char scopeoffunction[] )
	{
		unsigned long map=hash(ctemp);
		map=map%65535;
		int len=strlen(ctemp);
		if(symboltable[map].valid==1&&(strcmp(symboltable[map].name,ctemp)==0)) //case when the symbol is already in table first
		{
			
			int found=0;
			struct symbol * pointer= (struct symbol *) malloc( sizeof(struct symbol));
			pointer=&symboltable[map];
		//	printf("%s %s\n",pointer->scope,scope);
			if(strcmp(symboltable[map].scope,scope)==0)
			{
				//printf("reaching bitch kapil\n");
				found=1;
				//printf("reaching bitch kapil %d\n",l);
			}
			
			while(pointer->next!=NULL)
			{
				
				if(strcmp(pointer->scope,scope)==0)				
					{
						found=1;
					}
				//	printf("%s %s\n",pointer->scope,scope);
					pointer=pointer->next;
					
			}
			if(strcmp(pointer->scope,scope)==0)				
					{
						found=1;
					}
				//	printf("%s %s\n",pointer->scope,scope);
				
			if(found==1)
			{
			//	printf("Identifier %s already exists in the scope at line %d\n",ctemp,l);
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
				strcpy(tempsymbol->scopeoffunction,scopeoffunction);
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
			//	printf("eops\n");
		}
		/*else if(symboltable[map].valid==1&&strcmp(symboltable[map].name,ctemp)!=0)//case when symbol not in table first
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

		}*/
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
			strcpy(symboltable[map].scopeoffunction,scopeoffunction);
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
                        //printf("%c",id.val[k]);
                    }
                    //printf("\n");
}
/*
returns 1 if int;
returns 2 if int arr
returns 3 if char
returns 4 if char arr
returns 5 if void
returns 6 if float
returns 7 if float arr
*/
int checkdeclaration(struct string idinp,char identifier[])
{
	//printf("\n%smf%s nf\n",identifier,idinp.val);
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
				else if(strcmp(ans.type,"void")==0)
				{
					return 5;
				}
				else if(strcmp(ans.type,"float")==0)
				{
					if(strcmp(ans.arraydimention,"0")!=0)
					{
						return 7;
					}
					return 6;
				}
				else if(strcmp(ans.type,"char")==0)
				{
					if(strcmp(ans.arraydimention,"0")!=0)
					{
						return 4;
					}
					return 3;
				}
				else if(strcmp(ans.type,"int")==0)
				{
					if(strcmp(ans.arraydimention,"0")!=0)
					{
						return 2;
					}
					return 1;
				}
			
			}
			else{
				struct symbol * pointer1= (struct symbol *) malloc( sizeof(struct symbol));
				pointer1=&ans;
				while(pointer1->next!=NULL)
				{
					//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
					if(strcmp(pointer1->scope,idinp.val)==0)				
						{
							if(pointer1->proc_defn_flag==1)
							{
								return -1;
							}
							else if(strcmp(pointer1->type,"void")==0)
							{
								return 5;
							}
							else if(strcmp(pointer1->type,"float")==0)
							{
								if(strcmp(pointer1->arraydimention,"0")!=0)
								{
									return 7;
								}
								return 6;
							}
							else if(strcmp(pointer1->type,"char")==0)
							{
								if(strcmp(pointer1->arraydimention,"0")!=0)
								{
									return 4;
								}
								return 3;
							}
							else if(strcmp(pointer1->type,"int")==0)
							{
							if(strcmp(pointer1->arraydimention,"0")!=0)
								{
									return 2;
								}
								return 1;
							}	
						}
						pointer1=pointer1->next;
				}
			//	printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
				if(strcmp(pointer1->scope,idinp.val)==0)				
						{
							if(pointer1->proc_defn_flag==1)
								{
									return -1;
								}
								else if(strcmp(pointer1->type,"void")==0)
								{
									return 5;
								}
								else if(strcmp(pointer1->type,"float")==0)
								{
									if(strcmp(pointer1->arraydimention,"0")!=0)
									{
										return 7;
									}
									return 6;
								}
								else if(strcmp(pointer1->type,"char")==0)
								{
									if(strcmp(pointer1->arraydimention,"0")!=0)
									{
										return 4;
									}
									return 3;
								}
								else if(strcmp(pointer1->type,"int")==0)
								{
									if(strcmp(pointer1->arraydimention,"0")!=0)
									{
										return 2;
									}
									return 1;
								}	
						}
						
					
				}
			lengthofid--;
			idinp.val[lengthofid]='\0';
	}

			return 0;

}
int checkdeclarationfunction(struct string idinp,char identifier[])
{
	//printf("\n%s\n",identifier);
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
		//printf("+++%s---%s+++\n",idinp.val,ans.scope);
			if(strcmp(ans.scope,idinp.val)==0)
			{
			//	printf("found");
				if(ans.proc_defn_flag==0)
				{
					return -1;
				}
				else if(strcmp(ans.type,"void")==0)
						{
							return 5;
						}
						else if(strcmp(ans.type,"float")==0)
						{
							if(strcmp(ans.arraydimention,"0")!=0)
							{
								return -3;
							}
							return 6;
						}
						else if(strcmp(ans.type,"char")==0)
						{
							if(strcmp(ans.arraydimention,"0")!=0)
							{
								return -3;
							}
							return 3;
						}
						else if(strcmp(ans.type,"int")==0)
						{
							if(strcmp(ans.arraydimention,"0")!=0)
							{
								return -3;
							}
							return 1;
						}
			}
			else{
			struct symbol * pointer1= (struct symbol *) malloc( sizeof(struct symbol));
			pointer1=&ans;
			while(pointer1->next!=NULL)
			{
				//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
				if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						if(pointer1->proc_defn_flag==0)
						{
							return -1;
						}
						else if(strcmp(pointer1->type,"void")==0)
						{
							return 5;
						}
						else if(strcmp(pointer1->type,"float")==0)
						{
							if(strcmp(pointer1->arraydimention,"0")!=0)
							{
								return -3;
							}
							return 6;
						}
						else if(strcmp(pointer1->type,"char")==0)
						{
							if(strcmp(pointer1->arraydimention,"0")!=0)
							{
								return -3;
							}
							return 3;
						}
						else if(strcmp(pointer1->type,"int")==0)
						{
							if(strcmp(pointer1->arraydimention,"0")!=0)
							{
								return -3;
							}
							return 1;
						}
						
					}
					pointer1=pointer1->next;
			}
			//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
			if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						if(pointer1->proc_defn_flag==0)
						{
							return -1;
						}
						else if(strcmp(pointer1->type,"void")==0)
						{
							return 5;
						}
						else if(strcmp(pointer1->type,"float")==0)
						{
							if(strcmp(pointer1->arraydimention,"0")!=0)
							{
								return -3;
							}
							return 6;
						}
						else if(strcmp(pointer1->type,"char")==0)
						{
							if(strcmp(pointer1->arraydimention,"0")!=0)
							{
								return -3;
							}
							return 3;
						}
						else if(strcmp(pointer1->type,"int")==0)
						{
							if(strcmp(pointer1->arraydimention,"0")!=0)
							{
								return -3;
							}
							return 1;
						}		
						
						
					}
	}
	lengthofid--;
			idinp.val[lengthofid]='\0';
	}
//	printf("notfound");
			return 0;

}
int getnoofparametes(struct string idinp,char identifier[])
{
	//printf("\n%s\n",identifier);
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
		//printf("+++%s---%s+++\n",idinp.val,ans.scope);
			if(strcmp(ans.scope,idinp.val)==0)
			{
			return ans.parameter_count;
			}
			else{
			struct symbol * pointer1= (struct symbol *) malloc( sizeof(struct symbol));
			pointer1=&ans;
			while(pointer1->next!=NULL)
			{
				//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
				if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						return pointer1->parameter_count;
						
					}
					pointer1=pointer1->next;
			}
			//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
			if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						return pointer1->parameter_count;
						
					}
	}
	lengthofid--;
			idinp.val[lengthofid]='\0';
	}
//	printf("notfound");
			return 0;

}
int match_params(int arglist[],int argument_count,struct string idinp,char identifier[])
{
	struct string curr_scope=idinp;
for(int ix=0;ix<argument_count;++ix)
{
	//printf("%d",arglist[ix]);
}
//printf("done\n");
	//printf("\n%s\n",identifier);
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
		//printf("+++%s---%s+++\n",idinp.val,ans.scope);
			if(strcmp(ans.scope,idinp.val)==0)
			{
		
			int arg_count=0;
			for(int te=ans.parameter_count-1;te>=0;--te)
			{
				struct string scopeoffunction;
				strcpy(scopeoffunction.val,ans.scopeoffunction);
				scopeoffunction.len=strlen(ans.scopeoffunction);
				int answ=checkdeclaration(scopeoffunction,ans.parameter_list[te].name);
				//printf("%d%d",answ,arglist[arg_count]);
					if(answ==2||answ==4||answ==7)
							{
								if(arglist[arg_count]==0)
									return 0;
							}
							else 
								{
									if(arglist[arg_count]==1)
									return 0;
								}
				arg_count++;
				
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
						int arg_count=0;
					
						for(int te=pointer1->parameter_count-1;te>=0;--te)
						{
							struct string scopeoffunction;
				strcpy(scopeoffunction.val,pointer1->scopeoffunction);
				scopeoffunction.len=strlen(pointer1->scopeoffunction);
				int answ=checkdeclaration(scopeoffunction,pointer1->parameter_list[te].name);
								//printf("%d%d",answ,arglist[arg_count]);
								if(answ==2||answ==4||answ==7)
							{
								if(arglist[arg_count]==0)
									return 0;
							}
							else 
								{
									if(arglist[arg_count]==1)
									return 0;
								}
								arg_count++;
						}
						return 1;
						
					}
					pointer1=pointer1->next;
			}
			//printf("+++%s---%s+++\n",idinp.val,pointer1->scope);
			if(strcmp(pointer1->scope,idinp.val)==0)				
					{
						int arg_count=0;
						
						for(int te=pointer1->parameter_count-1;te>=0;--te)
						{
							struct string scopeoffunction;
				strcpy(scopeoffunction.val,pointer1->scopeoffunction);
				scopeoffunction.len=strlen(pointer1->scopeoffunction);
				int answ=checkdeclaration(scopeoffunction,pointer1->parameter_list[te].name);
						//	printf("%d%d",answ,arglist[arg_count]);
							if(answ==2||answ==4||answ==7)
							{
								if(arglist[arg_count]==0)
									return 0;
							}
							else 
								{
									if(arglist[arg_count]==1)
									return 0;
								}
								arg_count++;
						}
						return 1;
						
					}
			}
	lengthofid--;
			idinp.val[lengthofid]='\0';
	}
//	printf("notfound");
			return 0;

}




int min (int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else{
		return b;
	}
}

void CreateTempvar(char c[10])
{
	char ctemp[10];
	sprintf(ctemp, "T%d", tempvar);
	++tempvar;
	strcpy(c,ctemp);
}
struct treeaddressnode{
char res[150];
int label;
int gotoflag;
}treelist[1000];
int stack[100], top = -1;
int  top1 = -1;
struct stack1{
int list[100];
int count;
}stack11[150];

void push(int value,int st){
	if(st==0)
      {
		  top++;
     	 stack[top] = value;
	  }
	  else{
		  top1++;
     	 stack11[top1].list[0] = value;
		  stack11[top1].count=1;
	  }
}
void expand(int value){
     	 stack11[top1].list[ stack11[top1].count] = value;
		  stack11[top1].count++;
		//  printf("reached%d",stack11[top1].list[ stack11[top1].count-1]);
}
void pop(int st){
	if(st==0){
   if(top == -1)
      printf("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      
      top--;
   }
	}
	else{
		if(top1 == -1)
      printf("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      
      top1--;
   }
	}
}
int gettop(int st){
	if(st==0){
   return stack[top];
	}
	else{
		return stack11[top1].list[stack11[top1].count-1];
	}
}

int threecount=0;
void CreateDocument(char res[10],char var1[10],char op[10],char var2[10],int ifflag,int gotoflag )
{
	if(ifflag==1)
	{
		char tempdoc[150];
		sprintf(tempdoc, "IF (%s) goto %d ",res,threecount+3);
		strcpy(treelist[threecount].res,tempdoc);
		treelist[threecount].label=threecount;
		treelist[threecount].gotoflag=threecount+3;
		++threecount;	
	}
	else if(gotoflag==1)
	{
		
		strcpy(treelist[threecount].res,"goto");
		treelist[threecount].label=threecount;
		treelist[threecount].gotoflag=-10;
		push(threecount,0);
		++threecount;
		
	}
	else{
		char tempdoc[150];
	sprintf(tempdoc, "%s: %s %s %s ",res,var1,op,var2);
	strcpy(treelist[threecount].res,tempdoc);
	treelist[threecount].label=threecount;
	treelist[threecount].gotoflag=-1;
	++threecount;
	}
	//printf("%d %s\n",threecount,treelist[threecount-1].res);
}
void update_goto_stmt(int iswhile)
{	int top11=gettop(0);
	//printf("kapil bewafa hai!%d\n",top1);
	if(top>=0)
	{
		
		char tempdoc[200];
		
		
	//	printf("%d %s\n",treelist[top1].label+1,treelist[top1].res);
	if(iswhile==2)
	{
		sprintf(tempdoc, "%s %d ",treelist[top11].res,threecount+2);
		strcpy(treelist[top11].res,tempdoc);
		treelist[top11].gotoflag=threecount+2;
	
	}
		else if(iswhile==1)
		{
			
			sprintf(tempdoc, "%s %d ",treelist[top11].res,threecount+2);
			sprintf(treelist[threecount].res, "goto %d ",top11-1);
			treelist[threecount].label=threecount;
			treelist[threecount].gotoflag=top11-1;
			++threecount;
		}
		else{
			sprintf(tempdoc, "%s %d ",treelist[top11].res,threecount+2);
		}
		strcpy(treelist[top11].res,tempdoc);
		treelist[top11].gotoflag=threecount+2;
		pop(0);
	}
}
void printthreeaddresscode()
{
	for(int i=0;i<threecount;++i)
	{
		printf("%d %s\n",treelist[i].label+1,treelist[i].res);
	}
}
void addgotoonsuccessexec()
{
		char tempdoc[200];
		strcpy(treelist[threecount].res,"goto");
		treelist[threecount].label=threecount;
		treelist[threecount].gotoflag=-10;
		expand(threecount);
		++threecount;
}
void fixgoto()
{
	
	struct stack1 temp;
	if(top1>-1){
	//	printf("kapil bewafagh");
	temp=stack11[top1];
		char tempdoc[200];
		for(int i=1;i<temp.count;++i)
			{
				//printf("\t%d\n",temp.list[i]);
				sprintf(tempdoc, "%s %d ",treelist[temp.list[i]].res,threecount+1);
				strcpy(treelist[temp.list[i]].res,tempdoc);
				treelist[temp.list[i]].gotoflag=threecount+1;
			}
			pop(1);
	}

}
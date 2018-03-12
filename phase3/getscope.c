#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

struct string
{
    char val[100];
    int len;
};


struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
 
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}
 
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int top(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
struct string converttostring(int temp)
{
    struct string res;
    res.len=0;
    while(temp>0)
    {
        int t=temp%10;
        res.val[res.len]='0'+t;
        res.len++;
        temp=temp/10;
    }
    return res;
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
    for(int i=0;i<temp1.len;++i)
    {
        res.val[res.len]=temp1.val[i];
        res.len++;
    }
    return res;
}
void printstring(struct string id)
{
                for(int k=0;k<id.len;++k)
                    {
                        printf("%c",id.val[k]);
                    }
                    printf("\n");
}

int main()
{
    struct Stack* scopecount = createStack(100);
    struct string input;
    input.len=0;
    push(scopecount, -1);
    scanf("%s",input.val);
    input.len=strlen(input.val);
    struct string id;
    id.len=0;
    int i;
    for( i=0;i<input.len;++i)
    {
	if(input.val[i]=='{')
	    {
            if(top(scopecount)==-1)
		    {
		 	id.val[id.len]='1';	
             id.len++;
                
		    }
            else if(top(scopecount)!=-1)
		        {
                    int temp=top(scopecount);
                    temp++;
                    pop(scopecount);
                    struct string temp1;
                    temp1=converttostring(temp);
                    id=appendstring(id,temp1);
                 
                  		
		        }
        }
    else if(input.val[i]=='}')
        {
            int temp = converttoint(id);
           // printf("%d\n",temp);
            push(scopecount,(temp%10));
            temp=temp/10;
            id=converttostring(temp);
           // printstring(id);
           
        }
    else{
        printstring(id);

    }
    }



  
 
    return 0;
}
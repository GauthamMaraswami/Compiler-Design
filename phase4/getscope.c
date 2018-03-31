#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "syntax.h"



int main()
{
 scopecount= createStack(100) ;
    struct string input;
    input.len=0;
    pushtostack(scopecount, -1);
    scanf("%s",input.val);
    input.len=strlen(input.val);
    struct string id;
    id.len=0;
    int i;
    for( i=0;i<input.len;++i)
    {
	if(input.val[i]=='{')
	    {
            id=openbraceencounter(id);
        }
    else if(input.val[i]=='}')
        {
         id=closebraceencounter(id);
        }
    else{
        printstring(id);

    }
    }



  
 
    return 0;
}
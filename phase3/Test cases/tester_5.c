#include<stdio.h>
void fun(float a[10])
{
    return 9;
}

int main()
{
    int a;
     fun(9);
    char b[10];
    
    b=b+10;
    
    b[1]=a[5];
    return 0;
}

/*Expected Output :-
return type mismatch error at line 5 
argument types does not match
identifier b is of type array line 13
identifier b is of type array line 13
variable is  at line is not declared as array 15
*/

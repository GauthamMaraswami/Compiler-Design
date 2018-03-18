//testcase 4 :- returning an array, undeclared variable in scope, calling an ID as a procedure

#include<stdio.h>

int fun()
{
    int p[10];
    return p;
}

int main()
{
    if(1)
    {
        int a;
    }
    
    a=2;
    
    int b;
    b();
    return 0;
}

/*Expected Output :-
identifier p is of type array line 6
return type cannot be array at 6
variable a is not declared in this scope at line 16 
identifier b not declared as procedure at line 19
*/

//Duplicate Declaration Of variable
#include<stdio.h>
int main()
{
    float a;
    int a;
    a=0;
    float b;
    b=0.0;
    if(b)
    {
        b=1.1;
    }
    while (!a)
    {
        int a;
    }
    return 0;
}

//Expected Output :- Variable redeclaration
//expression in test  is not of type int at line 8

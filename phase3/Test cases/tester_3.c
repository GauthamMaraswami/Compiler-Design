#include<stdio.h>
int fun1(int a, int b)
{
    return 1;
}
int fun(void p)
{
    return 2;
}

int main()
{
    fun1(2);
    return 0;
}
//Expected Output :- Parameters of type void are not allowed. Parameter count doesnt match for fun1.

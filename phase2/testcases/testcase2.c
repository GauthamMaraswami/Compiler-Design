#include<stdio.h>
int main()
{
    int a;
    int b;
    scanf("%d",&b);
    if(b>0)
    {
        a=10;
    }
    else if(b==0)
    {
        a=0;
    }
    else
    {
        a=-10;
    }
    switch(a)
    {
        case 10 : 
                    printf("b is positive");
                    break;
        case 0 :
                    printf("b is zero");
                    break;
        case -10 :
                    printf("b is negative");
                    break;
    }
    return 0;
}

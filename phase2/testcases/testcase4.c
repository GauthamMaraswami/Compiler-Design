#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    if(a>0)
    {
        printf("nested while loop");
        int i,j;
        i=0;
        j=0;
        while(i<=j)
        {
            i++;
            while(j<i)
            {
            printf("yay");
            j++;
            }
        }
    }
    else
    {
        printf("normal while loop");
        int i,j;
        i=0;
        j=0;
        while(i<=j)
        {
            i++;
            printf("yay");
            j+3;
            i+1;
            j-2;
            j++;
            i++;
        }
    }
}

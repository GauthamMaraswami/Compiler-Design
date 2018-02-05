#include<stdio.h>
int main()
{
    int a,b;
    printf("enter 2 numbers\n");
    scanf("%d %d",&a,&b);
    int choice;
    printf("enter 1 for or and 2 for and");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : printf("%d",a||b); break;
        case 2 : printf("%d",a&&b); break;
    }
    return 0;
}

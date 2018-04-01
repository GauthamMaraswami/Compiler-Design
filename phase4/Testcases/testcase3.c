//simple condition
#include<stdio.h>
int main()
{
    
    int a,b;
    a=0;
    b=100;
    if(a>10)
    {
        b=10;
    }
    else if(a>11)
    {
        b=11;
    }
    else
    {
        b=-1;
    }
    return 0;
}

/*
Expected output
Valid Expressions :
1 goto 1:
2 a:   0
3 b:   100
4 T0: a > 10
5 IF (T0) goto 7
6 goto 9
7 b:   10
8 goto 15
9 T1: a > 11
10 IF (T1) goto 12
11 goto 14
12 b:   11
13 goto 15
14 b:  - 1
15 return:
*/

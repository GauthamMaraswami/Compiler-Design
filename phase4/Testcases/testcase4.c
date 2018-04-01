//simple operations
#include<stdio.h>
int main()
{
    
    int a,b;
    a=0;
    b=100;
    if(a>10)
    {
        b=10;
        if(b==10)
        {
            a=0;
        }
        else{
            a=10;
        }
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
6 goto 15
7 b:   10
8 T1: b == 10
9 IF (T1) goto 11
10 goto 13
11 a:   0
12 goto 14
13 a:   10
14 goto 21
15 T2: a > 11
16 IF (T2) goto 18
17 goto 20
18 b:   11
19 goto 21
20 b:  - 1
21 return:
*/

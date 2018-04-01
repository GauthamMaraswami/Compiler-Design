//while and nested while
#include<stdio.h>
int main()
{
    
    int a,b;
    a=0;
    b=100;
    while(a>10)
    {
        a--;
        while(b<10)
        {
            b++;
        }
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
6 goto 16
7 T1: a - 1
8 a:   T1
9 T2: b < 10
10 IF (T2) goto 12
11 goto 15
12 T3: b + 1
13 b:   T3
14 goto 9
15 goto 4
16 return:
*/

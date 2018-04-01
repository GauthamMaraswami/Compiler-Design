//simple operations
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
                while(b>0)
                {
                    b++;
                }
            }
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
6 goto 39
7 T1: a - 1
8 a:   T1
9 T2: b < 10
10 IF (T2) goto 12
11 goto 38
12 T3: b + 1
13 b:   T3
14 T4: a > 10
15 IF (T4) goto 17
16 goto 25
17 b:   10
18 T5: b == 10
19 IF (T5) goto 21
20 goto 23
21 a:   0
22 goto 24
23 a:   10
24 goto 37
25 T6: a > 11
26 IF (T6) goto 28
27 goto 30
28 b:   11
29 goto 37
30 b:  - 1
31 T7: b > 0
32 IF (T7) goto 34
33 goto 37
34 T8: b + 1
35 b:   T8
36 goto 31
37 goto 9
38 goto 4
39 return:
*/

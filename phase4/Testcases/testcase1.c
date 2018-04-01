//simple operations
#include<stdio.h>
int main()
{
    
    int a;
    a=0;
    float b;
    b=0.0;
    a=a+10;
    b=a*11;
    a=a%7;
    a=b/13;
    return 0;
}

/*Expected Output :- 
Valid Expressions :
1 goto 1:
2 a:   0
3 b:   0.0
4 T0: a + 10
5 a:   T0
6 T1: a * 11
7 b:   T1
8 T2: a % 7
9 a:   T2
10 T3: b / 13
11 a:   T3
12 return:
*/

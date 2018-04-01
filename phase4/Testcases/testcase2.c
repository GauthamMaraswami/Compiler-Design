//simple operations
#include<stdio.h>
int main()
{
    
    int a;
    a=0;
    int b;
    b++;
    a--;
    a*=10;
    b/=10;
    a%=b;
    a+=b;
    a-=100;
    
    return 0;
}

/*Expected Output :- 

Valid Expressions :
1 goto 1:
2 a:   0
3 T0: b + 1
4 b:   T0
5 T1: a - 1
6 a:   T1
7 T2: a * 10
8 a: T2
9 T3: b / 10
10 b: T3
11 T4: a % b
12 a: T4
13 T5: a + b
14 a: T5
15 T6: a - 100
16 a: T6
17 return:
*/

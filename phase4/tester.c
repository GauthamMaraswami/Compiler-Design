#include<stdio.h>
int ans;
int main(int aa[100],float ans1)
{
   // ans=2*3+ans*(ans++);
    while(ans>10)
    { 
        ans++;
        if(ans>15)
        {
            ans=10*ans;
        }
        else if(ans<21)
        {
            ans=100;
        }
        else{
       ans--;
        }
    }
    return 0;
}

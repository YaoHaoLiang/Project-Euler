#include<bits/stdc++.h>
using namespace std;
int isprim(int n)  //素数判断
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int judge(long long n)
{
    int i=1;
    long long t;
    while((t=(n-2*(i*i)))>0)
    {
        if(isprim(t)) return 1;
        i++;
    }
    return 0;
}

int main()
{
    for(long long i=1001; i<100000000; i+=2)
    {
        if(!isprim(i) && !judge(i))  //不是素数  
        {
            printf("%lld\n",i);
            break;
        }
    }
    return 0;
}
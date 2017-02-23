#include<bits/stdc++.h> 
using namespace std;
int  isprime(int n)
{
    if (n<=1)return 0;
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)return 0;
    return 1;
    
}
int gao(int a, int b) //连续素数的个数 
{
    int cnt = 0;
    for (int i=0;;i++)
    {
        if (isprime(i*i+a*i+b)) //二元产生的是素数 
        {
            cnt++;
        }
        else break;
    }
    return cnt;
}
 
int main()
{
    int maxa,maxb,maxprimes=0;
    for (int a=-1000;a<1000;a++)
    {
        for(int b=-1000;b<1000;b++)
        {
            if(gao(a,b)>maxprimes)
            {
                maxa = a;
                maxb = b;
                maxprimes = gao(a,b);
            }
        }
    }
    cout<<maxa*maxb<<endl;
    return 0;
}
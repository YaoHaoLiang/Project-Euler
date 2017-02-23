#include<bits/stdc++.h>
using namespace std;
 
int factorial(int n)
{
    //return n==1 ? 1: n*factorial(n-1);
    int sum=1;
    for(int i=1;i<=n;i++) sum*=i; return sum;
}
 
int digit_factorial(int n)
{
    int a=0,sum = 0;
    while (n!=0)
    {
        sum += factorial(n % 10);
        n /= 10;
    }
    return sum;
}
 
int main()
{
    vector<int> s;
    for (int i=3;i<=999999;i++)
    {
        if(digit_factorial(i) == i)
        {
            s.push_back(i);
        }
    }
 
    int sum=0;
    
    for (vector<int>::iterator it=s.begin();it!=s.end();it++)
    {
        sum += *it;
    }
    cout<<sum<<endl;
    return 0;
}
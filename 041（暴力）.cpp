#include<bits/stdc++.h>
using namespace std;
int is_pandigital(long long n)
{
    if(n<=0) return 0;
 
    vector<int> v;         
    while(n != 0)
    {
        v.push_back(n%10);
        n/=10;
    }
 
    set<int> set_n(v.begin(),v.end()); //转化为set，去重
 
    int len = v.size();
    if(set_n.size() == len)                 //不含重复值
    {
        sort(v.begin(),v.end());         //默认从小到大排序
        for (int i=0;i<len;i++)             //digits=1,2,3...
        {
            if (v[i] != (i+1))         
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int is_prime(long long n)
{
        if (n == 2)
                return 1;
        if (n % 2 == 0)
                return 0;

        long long i;
        for (i = 3; i * i <= n; i += 2)
                if (n % i == 0)
                        return 0;
        return 1;
}

int main()
{
        long long n;
        for (n = 7654321; n >= 1234567; n -= 2)
                if (is_pandigital(n) && is_prime(n)) break;
        printf("%lld\n", n);
        return 0;
}
#include<bits/stdc++.h>
 
using namespace std;
int is_prime(int n)
{
    if(n <= 1) return 0;
    if(n == 2 || n == 3) return 1;
    else if (n % 2 == 0) return 0;
    else
    {
        for(int i=3;i<(int)sqrt((float)n)+1;i++)
        {
            if(n % i == 0) return 0;
        }
    }
    return 1;
}
int truncatable(int n) //左移右移后是否是素数 
{
    if (n<=0) return 0;
 
    //n的长度
    int len = 0;
    int cpy = n;
    while (cpy !=0) 
    {
        len ++;
        cpy /= 10;
    }
    //右移
    cpy = n;
    while (cpy !=0)
    {
        if(!is_prime(cpy)) 
        {
            return 0;
        }
        cpy /= 10;           
    }
    //左移
    cpy = n;
    while(len>1)
    {
        int x = cpy % (int)pow((float)10,len-1); //低位取模
        if (!is_prime(x))
        {
            return 0;
        }
        len--;
    }
 
    return 1;
}
 
int main()
{
    int cnt = 0,sum=0,i=8;
    while(cnt< 11)
    {
        if (truncatable(i))
        {
            sum += i;
            cnt ++;
            cout<<i<<endl;
        }
        i++;
    }
    cout<<endl;
    cout<<"sum="<<sum<<endl;
    return 0;
}
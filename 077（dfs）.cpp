#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int isprime(int n)
{
    for (int i = 2 ; i*i <= n ; i++)
        if (n%i == 0) return 0;
    return 1;
}

int dfs(int n,int k)
{
    if ( n <2 ) return  n==0;
    int ret = 0;
    for(int i = 2 ; i <= k ; i++ )if (isprime(i))
            ret+=dfs(n - i , i);
    return ret;
    
}

int main()
{
    int n = 10;
    while(n++) if( dfs(n,n) > 5000 ) break;
   //for(int i=1;i<=100;i++)n+=dfs(i,i);
    cout<<n<<endl;
    return 0;
}

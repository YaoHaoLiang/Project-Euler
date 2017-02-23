#include <iostream>
#include <cmath>
using namespace std;

long long power(int n)
{
    long long  ans = 1;
    for (int i=1;i<=n;i++)
    {
        ans *= n;
        ans %= 10000000000; 
    }
    return ans;
}
 
int main()
{
    long long sum = 0;
    for (int i=1;i<=1000;i++)
    {
        sum += power(i);
        sum %= 10000000000; //取模，只保留最低的10位
    }
    cout<<sum<<endl;
	 return 0;
}
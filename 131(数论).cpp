#include <bits/stdc++.h>
using namespace std;
/*
因为p是素数,n^3+n^2p=m^3，所以n^2(n+p)=m^3.
所以只能让n和n+p都为立方数, 所以这两个立方数相减的差就是一个素数p,
又因为a^3 - b^3 = (a-b)(a^2+ab+b^2),所以只有当a-b=1时，a^3 - b^3才可能是一个素数.
所以只需要检查相邻的2个立方数之差是否是素数就可以了.
即(n+1)^3-n^3=3n^2+3n+1。
所以这题就变成了只需要检查3n^2+3n+1是否是素数就可以了。
*/
vector<int> primes;
int prime[1000000];
void getPrimes()
{	
    for(int i = 0 ; i < 1000000; i++){
        prime[i] = 1;   
    }
    for(int i = 2 ; i < 1000000; i++)
	{
        if (prime[i])
		{
            primes.push_back(i);
            if(i <= (int)sqrt((double)1000000))
			{    
                for(int t = i*i ; t<1000000 ; t+=i)//prime[i*i+k*i]=false
				{   
                    prime[t] = 0;
                }
            }
        }
    }
}

int solve(int n)
{
 
  int ans = 0;
  for (int x = 1; x * x * 3 + x * 3 + 1 < n; x++)
  {
    if (prime[x * x * 3 + x * 3 + 1]){
    	ans++;
	}
  }
  return ans;
}

int main()
{
  cout<<	__gcd(3,6)<<endl;
  getPrimes();
  cout<<"init finish!"<<endl;
  cout<<solve(1000000)<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int sum_of_divisors(int n)
{
  int sum= 1;
  int i, k = n;
  for (i = 2; i <= k; i++)
  {
    int p = 1;
    while (k % i == 0)
	{
      p *= i;
      k /= i;
    }
    sum *= (p*i - 1)/(i-1);
  }
  return sum - n; //返回 n 的分解因子和 
}
int main()
{
  int i, d, sum = 0;

  for (i = 2; i < 10000; i++)
  {
    d = sum_of_divisors(i);
    if (i < d && i == sum_of_divisors(d))
	{
      sum += i + d;
    }
  }
  cout<<sum<<endl; 
  return 0;
}

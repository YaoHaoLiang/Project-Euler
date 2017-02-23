#include<bits/stdc++.h>
long long dp[15]={1,1,1,1,1,1,1,1,1,1};
int main()
{
  for(int i=1;i<=100;i++) //100位 
  {
    for(int j=1;j<10;j++)
	{
    	dp[j]+=dp[j-1];
	}
    dp[10]+=(dp[9]+dp[8]-10);
  }
  printf("%lld\n",dp[10]);
  return 0;
  
}
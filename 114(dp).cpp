#include<bits/stdc++.h>
using namespace std;
long long dp[60];
//dp[i]表示从左边某个位置 开始 到位置 i 是红块的方案数 
long long solve(int n)
{
	memset(dp,0,sizeof dp); 
	long long ans=0; 
	for(int i=3;i<=n;i++)
	{
		dp[i]=i-2;
		
		for(int j=3;j<=i-4;j++)
		{
			dp[i]+=(dp[j]*(i-j-3));
		}
		printf("dp[%d]=%lld\n",i,dp[i]); 
		ans+=dp[i];
	}
	ans++; //唯一一种全是黑块的 
	return ans;
}
int main()
{
	cout<<solve(7)<<endl;
	cout<<solve(50)<<endl;
	return 0;
}
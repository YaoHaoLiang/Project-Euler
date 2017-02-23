#include<bits/stdc++.h>
using namespace std;
long long dp[1000];
//dp[i]表示从左边某个位置 开始 到位置 i 是红块的方案数 
long long solve(int n)
{
	memset(dp,0,sizeof dp); 
	long long ans=0; 
	for(int i=50;i<=n;i++)
	{
		dp[i]=i-49;
		
		for(int j=50;j<=i-51;j++)
		{
			dp[i]+=(dp[j]*(i-j-50));
		}
	//	printf("dp[%d]=%lld\n",i,dp[i]); 
		ans+=dp[i];
	}
	ans++; //唯一一种全是黑块的 
	return ans;
}
int main()
{
	
	for(int i=51;;i++)
	{
		if(solve(i)>=1000000)
		{
			cout<<"ans="<<i<<endl;
			break;
		}
	}

//	cout<<solve(7)<<endl;
//	cout<<solve(50)<<endl;
	return 0;
}
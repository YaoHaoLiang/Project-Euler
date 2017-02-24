#include <cstdio>
const int MOD=1000000;
const int N=100000;
int dp[N];

int main()
{
	dp[0]=1;
	for(int i=1;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			dp[j]=(dp[j]+dp[j-i])%MOD;
		}
		if(dp[i]==0)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
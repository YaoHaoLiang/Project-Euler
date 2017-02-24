#include <bits/stdc++.h>
using namespace std;
int dp[110][1100];
int main()
{
	int maxn=0;
	memset(dp,0,sizeof(dp));
	freopen("in.txt","r",stdin);
  for(int i=1;i<=100;i++)
  {
  	for(int j=1;j<=i;j++)
  	{
  		scanf("%d",&dp[i][j]);
  		dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
  		maxn=max(maxn,dp[i][j]);
	  }
  }
  cout<<maxn<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int dp[81][81];
	int ans=0;
	int n=80;
	memset(dp,0,sizeof(dp));
	char b;
	FILE *fp;
	fp=fopen("in.txt","r+");
	for(int i=1;i<=80;i++)
	{
		for(int j=1;j<=80;j++)
		{
			for(;;)
			{
				fread(&b,sizeof(char),1,fp);
				if(feof(fp))
					break;
				if(b>='0' && b<='9')
				{
					dp[i][j]*=10;
					dp[i][j]+=(b-'0');
				}
				else
					break;
			}
		}
	}
	
	for(int i=2;i<=n;i++){
		dp[i][1]+=dp[i-1][1];
		dp[1][i]+=dp[1][i-1];
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
			//ans=min(ans,dp[i][j]);
		}
	}
	//cout<<ans<<endl;
   cout<<dp[n][n]<<endl;
	return 0;
}
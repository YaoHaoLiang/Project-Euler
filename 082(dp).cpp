#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int num = 80; 
int a[num][num], dp[num][num];
//dp[i][j]表示第 i行的第一个 到 j 列的和 
int main ()
{
	freopen("in.txt","r",stdin);
	int n = 80, minn = 1e9 ;
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf ("%d", &a[i][j]);  
	for (int i=0;i<n;i++) dp[i][0] = a[i][0];
	
	for ( int j = 1 ; j < n ; j++ )
	{
		//上到下 
		dp[0][j] = dp[0][j-1] + a[0][j];
		for ( int i = 1 ; i < n ; i++ )
			dp[i][j] =min ( dp[i-1][j], dp[i][j-1] ) + a[i][j]; //min(向右，向下) 
	  //下到上 
		for ( int i = n-2 ; i >= 0 ; --i)
			dp[i][j] = min( dp[i][j] , min ( dp[i+1][j], dp[i][j-1] ) + a[i][j]); //min(向右，向上） 
	}
    //到达最后一列的最小值 
	for (int i=0;i<n;i++) minn = min( minn, dp[i][n-1]);
	cout <<  minn <<endl;

    return 0;
}
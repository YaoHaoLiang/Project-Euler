#include<bits/stdc++.h>
using namespace std;
long long dp[1000][1000];
long long solve(int m,int n)
{
    if(m>n)return 1;
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[m][n]>0)return dp[m][n];
    return  dp[m][n]= solve(m,n-1)+solve(m,n-m);
}
int main()
{
	memset(dp,0,sizeof(dp));
	cout<<solve(2,5)-1<<endl;
	cout<<solve(3,5)-1<<endl;
	cout<<solve(4,5)-1<<endl;
	cout<<"example = "<<solve(2,5)+solve(3,5)+solve(4,5)-3<<endl;
	cout<<endl;
	cout<<solve(2,50)-1<<endl;
	cout<<solve(3,50)-1<<endl;
	cout<<solve(4,50)-1<<endl;
	cout<<"ans = "<<solve(2,50)+solve(3,50)+solve(4,50)-3<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long dp[1000]={0};
//f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4)
long long solve(int n)
{
	if(n<0) return 0;
	if(n==0)return 1;
	if(dp[n]>0)return dp[n];
	return  dp[n]= solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
}
int main()
{
	cout<<solve(5)<<endl;
	cout<<solve(50)<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll primes[16]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,53};
ll ans;
void dfs(ll down, ll upper, ll build, ll cost)
{
	if(cost > ans)return;
	if(build > 7999999) //4000000 * 2 -1
	{
		ans=min(ans, cost);
		return;
	}
	if(down>=16)return;
	
	for(ll i = upper;i>=1;i--)
	{
		ll tmp=1;
		for(int j = 1 ; j <= i ; j++)
		{
			tmp*=primes[down]; 
		}
		
		if((double) tmp*cost > (double)ans) continue;
		
		dfs(down + 1, i , build * ( 2 * i + 1 ), tmp * cost);
	}
}

int main()
{
	ans=1e18;
	dfs(0, 20, 1, 1);
	printf("%lld\n", ans);
	return 0;
}

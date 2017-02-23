#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Q(ll n)
{
	ll c=0;
	while(n>1)
	{
		if(n&1) n=3*n+1;
		else n=n/2; 
		c++;
	}
	return c+1;
}
int main()
{
	ll m=0,ma=0;
	for(ll i=1;i<1000000;i++)
	{
		ll c=Q(i);
		if(c>m)
		{
			m=c;
			ma=i;
		}
	}
	cout<<ma<<endl;
	return 0;
 } 
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll ans = 1;
	for (ll i = 0;i<7830457;i++)
	{
		ans<<=1;
		ans%=10000000000;
	}
	ans*=28433;
	ans%=10000000000;
	ans+=1;
	cout<<res<<endl;
	return 0;
}
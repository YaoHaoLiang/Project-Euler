#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n=21,b=15;
	
	while(n<1000000000000L)
	{
		ll tmp_n=4*b+3*n-3;
		ll tmp_b=3*b+2*n-2;
		n=tmp_n;
		b=tmp_b;
	}
	cout<<b<<endl;
	return 0;
}
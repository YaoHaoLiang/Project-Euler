#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a=0;
	a=100*(100+1)/2;
	cout<<a*a<<endl;
	ll b=0;
	for(int i=1;i<=100;i++)
	{
		b+=i*i;
	}
	cout<<b<<endl;
	cout<<"ans="<<a*a-b<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll i,j,r;
	map<string,int>mp;
	map<string,ll>mp2;
	string s;
	for (i=300;i<50000;i++)
	{
		stringstream stream;
		stream << i*i*i;
		stream >> s;
		sort(s.begin(),s.end());
		mp[s]++;
		if (mp[s]==5) break;
		if (mp[s]==1) mp2[s]=i*i*i;
	}
	printf("%lld\n",mp2[s]);
	return 0;
}
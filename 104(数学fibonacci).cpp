
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000000];
ll g[1000000];
ll sum(ll a,ll b) 
{
	if(a * 5 < b){
		return a + b/10;
	}
	if(a + b >= 10000000000000000) return (a + b) /10;
	return a+b;
}
string tostring(ll a)
{
	string s;
	while(a)
	{
		s += (a % 10+'0');
		a/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	f[0]=0;
	g[0]=0;
	f[1]=1;
	g[1]=1;
	for(int i=2;i<1000000;i++)
	{
		f[i]=(f[i-1]+f[i-2])%1000000000;
		g[i]=sum(g[i-1],g[i-2]);
		string s=tostring(f[i]);
		string t=tostring(g[i]).substr(0,9);
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		if(s==t)
		{
			if(t=="123456789")
			{
				cout<<"第 "<<i<<" 个fibonacci:";
				cout<<g[i]<<" + "<<f[i]<<endl; 
			}
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
/*
long long q_mod(int a,int b)
{
	long long ans=1;
	while(b>0)
	{
		if(b&1)ans=(ans*a);
		b>>=1;
		a=(a*a);
	}
	return ans;
}
*/
int main()
{
	set<double> s;
	for(double i=2;i<=100;i++)
	{
		for(double j=2;j<=100;j++)
		{
			s.insert(pow(i,j));
		}
	}
	cout<<s.size()<<endl;
	return 0;
}
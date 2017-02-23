#include<bits/stdc++.h>
using namespace std;
long long gao(int m,int n)
{
	long long  res=(long long)pow(m,n);
	long long ans=0;
	while(res)
	{
		ans+=res%10;
		res/=10;
	}
	return ans;
}
set<long long>s;
int main()
{
	
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if((long long)gao(j,i)==(long long)j)
			{
			    s.insert(pow(j,i));
			}
		}
	}
	int num=1;
	for(set<long long>::iterator it = s.begin();it !=s.end();it++)
	{
		if(*it>=10)
		cout<<num++<<":"<<*it<<endl;
	}
	return 0;
}
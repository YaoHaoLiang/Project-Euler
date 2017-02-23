#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;
bool isabundant (int n)
{
	long long sum=1;
	int k=n;
	for(int i=2;i<=k;i++)
	{
		int p=1;
		while(k%i==0)
		{
			p*=i;
			k/=i;
		}
		sum*=(p*i-1)/(i-1);
	}
	return sum-n>n;
}
vector<int>abundant;
int main()
{
	int flag[28123]={0};
    int ans=0;
	for(int i=1;i<=28123;i++)
	{
		if(isabundant(i))//abundant数 
		{
			abundant.push_back(i);
		}
	}
	for(int i=0;i<abundant.size();i++)
	for(int j=i;j<abundant.size();j++)
	{
		if(abundant[i]+abundant[j]<28123)
		{
			flag[abundant[i]+abundant[j]]=1;
		}
		else break;
	}
	for(int i=0;i<28123;i++)
	{
		if(flag[i]==0)
		ans+=i;
	}
	cout<<ans<<endl;
	return 0;
}
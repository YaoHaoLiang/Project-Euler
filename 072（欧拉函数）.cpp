#include<bits/stdc++.h>
using namespace std;
//求n的欧拉数
int euler(int n)
{
	int ret=1,i;
	for (i=2;i*i<=n;i++)
		if (n%i==0)
		{
			n/=i,ret*=i-1;
			while (n%i==0)
				n/=i,ret*=i;
		}
		if (n>1)
			ret*=n-1;
		return ret;    //n的欧拉数
}

int main()
{
	long long ans=0;
	for(int i=2;i<=1000000;i++){
		ans+=euler(i);
	}
	cout<<ans<<endl;
	return 0;
}

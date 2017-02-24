#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int phi[1000010];     

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
		return ret;    
}
int main()
{
	double ans=0;
	int res;
	for(int i=1;i<=1000001;i++)
	{
		int tmp=euler(i);
		if((double)i/tmp>ans)
		{
			ans=(double)i/tmp;
			res=i;
		}
	}
	cout<<res<<endl;
	return 0;
}
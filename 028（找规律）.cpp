#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long  ans=1;
	int count=0;
	int k=2;
	for(int i=3;i<=1001*1001;i+=k)
	{
		//cout<<i<<endl;
		ans+=i;
		count++;
		if(count==4)
		{
			k+=2;
			count=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
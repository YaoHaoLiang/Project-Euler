#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a[10]={0,1,2,3,4,5,6,7,8,9};
	int ans=0;
	unsigned long long sum=0;
	do
	{
		if((a[1]*100+a[2]*10+a[3])%2==0)
		{
			if((a[2]*100+a[3]*10+a[4])%3==0)
			{
				if((a[3]*100+a[4]*10+a[5])%5==0)
				{
					if((a[4]*100+a[5]*10+a[6])%7==0)
					{
						if((a[5]*100+a[6]*10+a[7])%11==0)
						{
							if((a[6]*100+a[7]*10+a[8])%13==0)
							{
								if((a[7]*100+a[8]*10+a[9])%17==0)
								{
									ans++;
									sum+=(a[0]*1000000000+a[1]*100000000+a[2]*10000000+a[3]*1000000);
									sum+=(a[4]*100000+a[5]*10000+a[6]*1000+a[7]*100+a[8]*10+a[9]);
									cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<endl;
									
								}
							}
						}
					}
				}
			}
		}
		
	}while(next_permutation(a,a+10));
	cout<<ans<<endl;
	cout<<sum<<endl;
	return 0;
}
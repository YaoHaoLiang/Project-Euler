#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int sum=0;
	for(int a=5;a<=12000;a++)
	{
		for(int b=a/3;b<=a/2;b++)
		{
			if(__gcd(a,b)==1)
			{
				double tmp=(double)b/a;
				if( tmp< 0.5 && tmp>(double)1.0/3)
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}

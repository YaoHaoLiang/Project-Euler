#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//暴力
int main()
{
	int sum=0;
	for(int m=1;m*m<1000000000;m++)
	{
		for(int n=m;;n++)
		{
	   //just focus on all primitive Pythagorean triples(2mn, m^2-n^2, m^2+n^2)
	   //m,n,must be odd 
			if(__gcd(m,n)!=1 || (n&2==1 && m%2==1))continue;
			int a= 2 * min(2*m*n,n*n-m*m); //两条相同的边 
			int b= m*m+n*n; //第三边 
			int ans=a+b+b;
			if(ans>1000000000)break;
			if(abs(a-b)==1)
			{
				sum+=ans;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
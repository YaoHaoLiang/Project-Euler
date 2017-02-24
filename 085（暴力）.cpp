#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=2000000;
	int min=2000000;int area=0;
	int len=(int)sqrt(n)+100;
	for(int i=1;i<=len;i++)
	{
		for(int j=i;j<len;j++)
		{
			int sumx=i*(i+1)/2;
			int sumy=j*(j+1)/2;
			
			int sum=sumx*sumy;
			if(abs(sum-n)<min){
				min=abs(sum-n);
				area=i*j;
			}
		}
	}
	cout<<area<<endl;
	return 0;
 } 
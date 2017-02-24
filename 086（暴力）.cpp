#include<bits/stdc++.h>
using namespace std;

int main()
{
	int count=0;
	for(int a=1;;a++)
	{
		for(int b=1;b<=a;b++)
		{
			for(int c=b;c<=a;c++)
			{
				int sum=(b+c)*(b+c)+a*a;
				int sq=sqrt(sum);
				if(sq*sq==sum) count++;
			}
		}
		if(count>=1000000){
			cout<<a<<endl; break;
		}
	}
	return 0;
}
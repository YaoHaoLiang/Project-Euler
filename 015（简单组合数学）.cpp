#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	long long ans1=1;
	int j=1;
	for(int i=21;i<=40;i++)
	{
		ans1=(ans1*i)/j;
		j++;
		if(j>20)break;
	}
	cout<<ans1<<endl;
	return 0;
}
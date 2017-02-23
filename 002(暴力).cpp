#include<bits/stdc++.h>
using namespace std;
const int ex=4e6;
int main()
{
	int f[300];int sum=10;
	f[1]=2;
	f[2]=8;
	for(int i=3;;i++)
	{
		f[i]=4*f[i-1]+f[i-2];
		if(f[i]<ex) sum+=f[i];
		else break;
	}
	cout<<sum<<endl;
	return 0;
}
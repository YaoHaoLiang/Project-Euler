#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cal(int n,int k)
{
	if(k==1||n==k)return 1;
	if(k>n)return 0;
	return cal(n-1,k-1)+cal(n-k,k);
}
int main()
{
	int sum=0;
    for(int k=1;k<100;k++)
    {
    	sum+=cal(100,k);
	}
	cout<<sum<<endl;
    return 0;
}


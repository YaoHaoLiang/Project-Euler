#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		a[i]=i;
	}
	int num=0;
	do
	{
	   	num++;
	   	if(num==1000000)
	   	{
	   		for(int i=0;i<=9;i++)cout<<a[i]; 
	   		cout<<endl;
		}
	}while(next_permutation(a,a+10));
	return 0;
}
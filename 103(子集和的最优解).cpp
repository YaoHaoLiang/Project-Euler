#include <iostream>
#include<set>
using namespace std;

int main()
{
	int min=1000,a0,b0,c0,d0,e0,f0,g0;
	for(int a=12;a<35;a++)
	for(int b=a+1;b<36;b++)
	for(int c=b+1;c<a+b-4;c++)
	for(int d=c+1;d<a+b-3;d++)
	for(int e=d+1;e<a+b-2;e++)
	for(int f=e+1;f<a+b-1;f++)
	for(int g=f+1;g< a+b;g++)
	if(a+b+c>f+g&&a+b+c+d>e+f+g)
	{
		set<int>sum;
		int num[7]={a,b,c,d,e,f,g};
		for(int i=0;i<4;i++)
		for(int j=i+1;j<5;j++)
		for(int k=j+1;k<6;k++)
		for(int l=k+1;l<7;l++)
		sum.insert(num[i]+num[j]+num[k]+num[l]);
		if(sum.size()>=35 && a+b+c+d+e+f+g < min)
		{
			min=a+b+c+d+e+f+g;
			a0=a;b0=b;c0=c;
			d0=d;e0=e;
			f0=f;g0=g;
		}
	}
	cout<<a0<<b0<<c0<<d0<<e0<<f0<<g0<<endl;	
	return 0;
}
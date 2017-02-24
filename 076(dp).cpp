#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int p[101][101];
int main()
{
	int sum=0;
    for(int r=1;r<=100;r++)
    {
    	p[r][r]=1;
    	p[r][1]=1;
    	for(int n=1;n<r;n++)
    	{
    		p[r][n]=p[r-1][n-1]+p[r-n][n];
		}
	}
	for(int j=2;j<=100;j++) sum+=p[100][j];
	cout<<sum<<endl;
    return 0;
}


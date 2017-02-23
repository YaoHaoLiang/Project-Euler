#include<bits/stdc++.h>
using namespace std;
int x[4],y[4];
int area(int i,int j,int k)
{
	return abs(x[i]*y[j]-x[j]*y[i] + x[j]*y[k]-x[k]*y[j] + x[k]*y[i]-x[i]*y[k]);
}
int main()
{
	//FILE *f=fopen("triangles.txt","r");
	freopen("in.txt","r",stdin);
	int ans=0;
	x[3]=0;
	y[3]=0;
//	while(fscanf(f,"%d,%d,%d,%d,%d,%d",&x[0], &y[0],&x[1],&y[1],&x[2],&y[2])==6) 
	while(scanf("%d%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2])==6)
	{
		if(area(0,1,2)==area(0,1,3)+area(0,2,3)+area(1,2,3)) 
		ans++;
	}
	//fclose(f);
	cout<<ans<<endl;
	return 0;
}

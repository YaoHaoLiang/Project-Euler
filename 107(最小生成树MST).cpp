#include<bits/stdc++.h>
#define MIN INT_MAX
#define MAX_Point 1200   //最大顶点数 
#define MAX_Edge 144000  //最大的边数 
using namespace std;
typedef long long ll;
int flag1 =0;
ll sum;
ll arr_list[MAX_Point][MAX_Point]; 
struct Edge
{
	ll point;
	ll lowcost;
	ll flag;
};
Edge edge[MAX_Edge];
ll prim(int n)
{
	ll i,j,k=1,flag;
	ll min,sum2=0;
	j=1;
	for(i=1;i<=n;i++)
	{
		if(i!=j)
		{
			edge[i].point=i;
			edge[i].lowcost=arr_list[j][i];
			edge[i].flag=0;
		}
	}
	edge[j].lowcost=0;
	edge[j].flag=1;
	for(i=2;i<=n;i++)
	{
		k=1;
		min=MIN;
		flag=0;
		for(j=2;j<=n;j++)
		{
			if(edge[j].flag==0 && edge[j].lowcost<min)
			{
				k=j;
				min=edge[j].lowcost;
				flag=1;
			}
		}
		if(!flag) return -1;
		
		sum2+=min;
		edge[k].flag=1;
		for(j=2;j<=n;j++)
		{
			if(edge[j].flag==0 && arr_list[k][j]<edge[j].lowcost)
			{
				edge[j].point=k;
				edge[j].lowcost=arr_list[k][j];
			}
		}
	}
	return sum2;
}

int main()
{
	
	ll sum0=0;
	freopen("in.txt","r",stdin);
	for(int i=1;i<=40;i++)
	{
		for(int j=1;j<=40;j++)
		{
			cin>>arr_list[i][j];
			sum0 += arr_list[i][j];
			if(arr_list[i][j]==0)
			arr_list[i][j]=0xfffffff;
		//	if(arr_list=='-')
		}
	}
	sum0/=2;
	ll ans=0;
	ans=prim(40);
	cout<<sum0<<endl;
	cout<<sum0-ans<<endl;
	return 0;
}
/*
0 16 12 21 0 0 0
16 0 0 17 20 0 0
12 0 0 28 0 31 0
21 17 28 0 18 19 23
0 20 0 18 0 0 11
0 0 31 19 0 0 27
0 0 0 23 11 27 0
*/
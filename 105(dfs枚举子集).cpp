#include<bits/stdc++.h> 
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int sub[15][10000];
int val[15];
int ans=0;
int merge(int l,int *a,int *b,int *r)
{
	int x=0;
	int y=0;
	for(int i=0; x < l || y < l ;i++)
	{
		if(y==l || (x < l && a[x] <b[y]))
		{
			r[i]=a[x];
			x++;
		}
		else if(x==l || (y < l && b[y] < a[x]))
		{
			r[i]=b[y];
			y++;
		}
		else return 0;
	}
	return 1;
}
void dfs(int d)
{
	if(n==d) 
	{
		int xs=val[0];
		int ys=0;
		for(int i=1 , j = d-1;i < j; i++, j--)
		{
			xs += val[i];
			ys += val[j];
			if(xs < ys) return ;
		}
		int s=0;
		for(int i=0; i < d;i++)
		{
			cout<<val[i]<<" ";
			s+=val[i];
		}
	    cout<<"="<<s<<endl;
		ans += s;
		return ;
	}
	int tmp[13010]={0};
	for(int i=0;i< (1<<d) ;i++) //枚举子集 
	{
		tmp[i]=sub[d][i] + val[d];
	}
	if(merge(1<<d,tmp,sub[d],sub[d+1])) //检查是否特殊合集 
	dfs(d+1);
}
int main()
{
	freopen("in.txt","r",stdin);
	char s[1000];
	for( ; ; )
	{
		s[0]=0;
		gets(s);
		if(!s[0]) break;
		n=0;
		int v=0;
		for(int i=0;;i++)
		{
			if(s[i]==',')
			{
				val[n++] = v;
				v=0;
			}
			else if(!s[i])
			{
				val[n++]=v; break;
			}
			else
			v = v * 10 + s[i] -'0';
		}
		sort(val,val+n);
	//	cout<<n<<endl;
		dfs(0);
	}
	cout<<"ans="<<ans<<endl;
	return 0;
}
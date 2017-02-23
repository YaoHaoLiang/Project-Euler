
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u(int n)
{
	ll ans=1;
	for(int i=1;i<=10;i++)
	{
		ans += pow((-1*n),i);
	}
	return ans;
}

ll OP(int n,int k) //拉格朗日插值 
{
	ll ans=0;
	long double res;
	for(int i=1;i<=k;i++)
	{
		res=1;
		for(int j=1;j<=k;j++)
		{
			if(j!=i) res=res*((n-j)*1.0)/((i-j)*1.0);
		}
 	  ans += res*u(i);
	}
	return ans; //返回不靠谱那个数 
}
int main()
{
	ll ans=0;
	for(int i=1;i<=10;i++)
	{
		//cout<<OP(i+1,i)<<endl;
		ans+=OP(i+1,i);
	}	
	cout<<ans<<endl;
	return 0;
}

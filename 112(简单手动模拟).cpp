#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int increase(ll x)
{
	int p=x%10;
	x/=10;
	while(x>0)
	{
		int c=x%10;
		if(c>p)return 0;
		p=c;
		x/=10;
	 } 
	 return 1;
}
int decrease(ll x)
{
	int p=x%10;
	x/=10;
	while(x>0)
	{
		int c=x%10;
		if(c<p)return 0;
		p=c;
		x/=10;
	 } 
	 return 1;
}
int gao(ll x)
{
	if(increase(x) || decrease(x))return 0;
	else return 1;
}
int main()
{
    ld s=0;
    for(int i=100;i<=10000000;i++)
    {
    	if(gao(i)) s++;
    	if(gao(i) && (s/i)*100.0==99)
    	{
    		cout<<i<<endl;
		}
	}
    return 0;
}
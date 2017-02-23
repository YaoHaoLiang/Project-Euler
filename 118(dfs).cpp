#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0;
vector<int>v;
int isprime(ll n)
{
	if(n==1)return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}
void dfs(int pos,ll now){
	if(pos>=9){
		if(ans<=10){
			//for(int i=0;i<9;i++)
			//cout<<v[i]<<" ";
			//cout<<endl;
		}
		
		ans++;return; 
	}
	ll n = 0;
	while(pos < 9){
		n *= 10;
		n += v[pos];
		if(isprime(n) && n >= now){
			dfs(pos+1,n);
		}
		pos++;
	}
}
int main()
{
	for(int i=1;i<=9;i++){v.push_back(i);}
	do{
		dfs(0,0);
	}while(next_permutation(v.begin(),v.end()));
	cout<<"ans="<<ans<<endl;
	return 0;
}
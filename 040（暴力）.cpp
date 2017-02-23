#include<bits/stdc++.h>
using namespace std;
vector<int> s;
void gao(int n)
{
	int k=n;
	while(k!=0)
	{
		s.push_back(k%10);
		k/=10;
	}
}
int main()
{
	
	for(int n=200000;n>=1;--n)
	{
		 gao(n);
	}
	cout<<s.size()<<endl; //1088895
	
	cout<<s[1088894]<<endl;//1
	cout<<s[1088885]<<endl; //10
	cout<<s[1088795]<<endl;//100
	cout<<s[1088894]*s[1088885]*s[1088795]*s[1087895]*s[1078895]*s[988895]*s[88895]<<endl; //ans
	return 0;
}
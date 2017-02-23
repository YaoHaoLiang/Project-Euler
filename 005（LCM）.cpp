#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans=1;
	for(int i=1;i<=20;i++) ans*= (i/__gcd(ans,i));
	cout<<ans<<endl;
	return 0;
}

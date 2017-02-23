#include <bits/stdc++.h>
using namespace std;
bool palindrome(int x)
{
	int tmp = x, ans = 0;
	while(x)
	{
		ans = ans * 10 + x % 10;
		 x /= 10;
	}
	if(tmp == ans)return 1;
	else return 0;
}
int main()
{
	int ans=0;
	for(int i = 100; i <= 999; i++)
		for(int j = 100; j <= 999; j++)
			if(palindrome(i * j)){
				ans=max(ans,i*j);
			}
	 cout<<ans<<endl;
	return 0;
}

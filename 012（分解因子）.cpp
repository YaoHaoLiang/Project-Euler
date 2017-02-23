#include<bits/stdc++.h>
using namespace std;
int Q(int n)
{
	int c = 0;
	int s = (int)sqrt(n);
	for (int x = 1; x <= s; x++)
		if (n%x == 0)
			c++;
	return 2*c;
}
int main()
{
	int ans = 1, n = 2;
	int factors = 1;
	while (factors < 501)
	{
		ans += n;
		n++;
		factors = Q(ans);
	}
	cout<<ans<<endl;
	return 0;
}


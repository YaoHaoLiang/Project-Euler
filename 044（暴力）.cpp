#include<bits/stdc++.h>
using namespace std;
int calc(int n)
{
	return n*(3 * n - 1) / 2;
}
int solve(int n)
{
	for (int i = 1; i*(3*i-1) <= 2*n; i++)
	{
		if (i*(3 * i - 1) == 2 * n)
			return 1;
	}
	return 0;
}
int main()
{
	int ans=0;
	for (int i = 2; i <= 3000; i++)
	{
		for (int j = 1; j < i; j++)
		{
			int sum = calc(i) + calc(j);
			int diff = calc(i) - calc(j);
			if (solve(sum) && solve(diff))
				cout << diff << endl;
		}
	}
	return 0;
}
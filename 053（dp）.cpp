#include <bits/stdc++.h>
int main()
{
	int f[101][102];
	for (int i=0; i<101; i++)
	{
		f[i][0] = 1;
		f[i][i] = 1;
	}
	int count = 0;
	for (int i=2; i<101; i++)
		for (int j=1; j<i; j++)
		{
			//C(n,k)=C(n-1,k-1)+C(n-1,k)
			f[i][j] = f[i-1][j-1] + f[i-1][j]; 
			if (f[i][j]>=1000000)
			{
				count++;
				f[i][j] = 1000000;//防止之后和会溢出
			}
		}
	printf("%d\n", count);
	return 0;
}
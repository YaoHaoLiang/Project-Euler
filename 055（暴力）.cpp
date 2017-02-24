#include <bits/stdc++.h>
long long reverse(long long n)
{
    long long r = n % 10;
    n=n/10;
    while (n>0)
	{
        r = 10*r + (n % 10);
        n/=10;
    }
    return r;
}
int main()
{
    int total = 0;
    for(int i = 1; i < 10000; i++)
	{
        int it = 1;
        long long num = i;
		long long mun = reverse(i);
        do {
            num += mun;
            if (it++>50)
			{
                total++;
                break;
            }
        }while (num!=(mun = reverse(num)));
    }
    printf("%d\n", total);
    return 0;
}
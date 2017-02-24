#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<bool> isPrime(1000000, true);

void prime()
{
	for(int i=2; i<1000000; i++)
	{
		if(isPrime[i])
		{
			for(int j=2; i*j<1000000; j++)
				isPrime[i*j] = false;
		}
	}
}
 
int giveNextNum(vector<int> &ar, int d, int x, int y, int z)
{
	int num = 0;
	for(int i=0; i<6; i++)
	{
		if(i == x || i == y || i == z)
			num = num*10 + d;
		else
			num = num*10 + ar[i];
	}
	return num;
}

void giveNumVector(int num, vector<int> &ar)
{
	for(int i=0; i<6; i++) //可能导致有前导0 
	{
		ar[5-i] = num%10;
		num /= 10;
	}
}

void primeFamily(int num, int &len)
{
	vector<int> ar(6);
	int orig = num;
	int local_len = 1;
	giveNumVector(num, ar);
	int i=0;
	while(ar[i] == 0) i++; //忽略前导 0 
	
	for(; i<6; i++)
	{
		for(int j=i+1; j<6; j++)
		{
			for(int z=j+1; z<6; z++)
			{
				local_len = 1;
				if(ar[i] == ar[j] && ar[j] == ar[z])
				{
					for(int k=ar[i]+1; k<10; k++)
					{
						num = giveNextNum(ar, k, i, j, z);
						if(isPrime[num])
						{
							local_len++;
						}
					}
				}
				len = max(len, local_len);
			}
		}
	}
}

int main()
{
	prime();
	int len;
	for(int i=2; i<1000000; i++)
	{
		if(isPrime[i])
		{
			len = 1;
			primeFamily(i, len);
			if(len == 8)
			{
				cout<< i << endl;
				return 0;
			}
		}
	}
	return 0;
}
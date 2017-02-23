#include<bits/stdc++.h>
using namespace std;
int is_prime(int n)
{
	if (n <= 1)
	{
		return 0;
	} 
	else if (n == 2 || n == 3)
	{
		return 1;
	}
	else if (n % 2 == 0)
	{
		return 0;
	}
	else
	{
		for (int i=3;i<=(int)sqrt((float)n);i++)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}

int same_digits(int a,int b)
{
	vector<int> va(4);
	vector<int> vb(4);

	while(a != 0 && b != 0)
	{
		va.push_back(a%10);
		vb.push_back(b%10);
		a /= 10;
		b /= 10;
	}

	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());

	return va == vb;
}

int main()
{
	vector<int> primes;       //保存所有四位数的质数
	for (int n=1000;n<=9999;n++)
	{
		if(is_prime(n)) primes.push_back(n);
	}

	int num = primes.size();    //质数个数
	for (int i=0;i<num-2;i++)   //遍历所有质数
	{
		for (int j=i+1;j<num;j++)
		{
			if(same_digits(primes[i],primes[j]))  //判断两个质数是否含有相同的数字
			{
				int diff = primes[j] - primes[i];
				int last = primes[j] + diff;      //等差数列第三个数
				vector<int>::iterator it;
				it = find(primes.begin(),primes.end(),last); //查找第三个数 last 是否在primes中
				if (it != primes.end())               //在primes中  
				{
					if (same_digits(primes[i],last))  //含有相同的数字
					{
						cout<<primes[i]<<" "<<primes[j]<<" "<<last<<endl;
					}
				}

			}
		}
	}
	return 0;
}
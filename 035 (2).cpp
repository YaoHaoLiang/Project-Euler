#include<bits/stdc++.h>
using namespace std;

int isPrime(int n)
{	
	int k = sqrt(n);
	for(int i = 2; i <= k ; i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int numbers[1000000] = {0};
int main()
{	
	int ans = 0;

	for(int i = 2; i < 1000000; i++)
	{
		numbers[i] = isPrime(i);
	}

	int isCircular;
	for(int i = 2; i < 1000000; i++)
	{

		isCircular = 1;
		stringstream ss;
		ss << i;
		string perm = ss.str();			

		for (int j = 0; j < perm.size(); j++)
		{			
			rotate(perm.begin(), perm.begin() + 1, perm.end());			
			if(!numbers[ atoi( perm.c_str() ) ])
			{
				isCircular = 0;
				break;
			}
	 }
   		if(isCircular)
   			ans++;
	}
	cout<<ans<<endl;
	return 0;
}


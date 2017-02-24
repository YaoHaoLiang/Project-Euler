#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<long long> makePrimeVector(const long long n)
{
    vector<long long> primes;
    primes.push_back(2);
    for(long long i = 3; i * i <= n; i+=2)
	{
        bool is_prime = true;
        for(auto prime : primes)
		{
            if(i % prime == 0)
			{
                is_prime = false;
            }
        }
        if(is_prime) primes.push_back(i);
    }
    return primes;
}

long long pow(long long n, long long m)
{
    long long ret = 1;

    for(long long i = 0; i < m; ++i)
	{
        ret *= n;
    }
    return ret;
}

int main()
{
    const long long MAX = 50000000;
    set<long long> ans;

    vector<long long> primes = makePrimeVector(MAX);
    
    for(auto i : primes)
	{
        for(auto j : primes)
		{
            if(pow(i, 2) + pow(j, 3) > MAX) break;
            for(auto k : primes)
			{
                if(pow(i, 2) + pow(j, 3) + pow(k, 4) > MAX) break;
                ans.insert(pow(i, 2) + pow(j, 3) + pow(k, 4));
            }
        }
    }
    cout << ans.size() <<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
int prime[1000000];
void getPrimes(int prime[] )
{	
    for(int i = 0 ; i < 1000000 ; i++){
        prime[i] = 1;   
    }
    for(int i = 2 ; i < 1000000; i++)
	{
        if (prime[i])
		{
            primes.push_back(i);
            if(i <= (int)sqrt((double)1000000))
			{    
                for(int t = i*i ; t<1000000 ; t+=i)//prime[i*i+k*i]=false
				{   
                    prime[t] = 0;
                }
            }
        }
    }
}
int divisors_Of_Squared(int n,int prime[] ) // 
{
    int p, e, i = 0, m = n, result = 1;
    while ( m > 1 )
    {
        e = 1;
        p = primes[i];
        while ( m % p == 0 )
        {
            e += 2;
            m /= p;
        }
        i++;
        result *= e;
    }
    //cout<<result<<endl;
    return result;
}

int factors(int n)
{
        int i = 2, k = 0, m = n, count = 1;
        while(m > 1)
        {
            for(; i <= m; i ++)
                 if(m % i == 0)
                    {
                        k = 1;
                        while(m % i == 0)
                        {
                                k +=2; //k+=2就变成 n^2 的约数个数，k++；就是 n 的约数个数 
                                m /= i;
                        }
                        count *= k;
                    }
        }
        return count;
}

int main()
{
    cout<<factors(2)<<endl;
    int n, s;
    getPrimes(prime);
    
    for (n = 1; ; n ++ )
    {
        // s = (divisors_Of_Squared(n,prime) + 1 ) / 2;  //快 
        s=(factors(n)+1)/2;  //慢 
        if(s>1000)
        {
        	break;
		}
           
    }
    cout<<"ans="<<n<<endl;
    return 0;
}

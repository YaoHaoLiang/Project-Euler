#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
int prime[1000000];
void init()
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
int main()
{    
    init();
    int max = 0;
    int maxlen = 0, maxsum = 0, cursum = 0;
    for(int i = 2 ; i < primes.size() ; i++)
	{
        cursum = 0;
        for(int j = i ; j < primes.size() ; j++)
        {
            cursum+=primes[j];
            if (cursum>=1000000)  break;
            if (prime[cursum] && j - i > maxlen )
            {
                maxlen = j-i;
                maxsum = cursum;
            }
        }
    }
    cout<<maxsum<<endl;;
    return 0;
}
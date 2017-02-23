#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>s;
int isPrime(ll n) 
{
        for(ll i=2;i<=(ll)sqrt(n);i++){
        	if(n%i==0)return 0;
		}
        return 1;
}

void gao(ll num, int pos, int len, int repeat_Dig, int num_repeat_Dig, set<ll>& s)
{
    if(len - pos < num_repeat_Dig) return;
        
    if(pos == len)
	{
        if(isPrime(num))
		{
            s.insert(num);
        }
        return ;
    }
        
    if(num_repeat_Dig != 0 && !(repeat_Dig == 0 && pos == 0))
	{
        gao(num * 10 + repeat_Dig, pos + 1, len, repeat_Dig, num_repeat_Dig - 1, s);
    }

    for(int i = pos == 0 ? 1 : 0; i <= 9; i++)
	{
        if(i == repeat_Dig) continue;
        gao(num * 10 + i, pos + 1, len, repeat_Dig, num_repeat_Dig, s);
    }
    return ;
}
    
int main() 
{
	int n; 
    cin>>n; //位数 
    ll ans = 0;
    for(int dig = 0; dig <= 9; dig++) //数字dig重复次数最多的数 
	{
		s.clear();
    	for(int num_repeat_Dig = n; num_repeat_Dig >= 1; num_repeat_Dig--) 
		{ 
            gao(0, 0, n, dig, num_repeat_Dig, s);
            if(!s.empty())
			{
                ll sum = 0;
                for(set<ll>::iterator it=s.begin();it !=s.end();++it)
				{
                    sum += *it;
                    //cout<<*it<<endl;
                }
                cout<<sum<<endl;
                ans += sum;
                break;
            }
        }
    }
    cout<<"ans="<<ans<<endl;
    return 0;
}

    
   
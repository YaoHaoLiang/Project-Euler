#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int reverse(ll x)
{
    ll r=0;
    while (x>0)
    {
        r=r*10+(x%10);
        x/=10;
    }
    return r;
}

int check_odd(ll x)
{
    int flag=0;
    while (x>0)
    {
        if ((x%10)%2==0){
        	flag=1;
        	break;
		}
        x/=10;
    }
    if (flag) return 0;
    else return 1;
}

int main()
{
    ll count=0;
    //在 1 亿到 10亿之间没有可逆数 
    for (ll i=10;i<=100000000;i+=2)
	{
		if (check_odd(i+reverse(i)) && i%10!=0) 
		count++;
	} 
    cout<<count*2<<endl;
    return 0;
}
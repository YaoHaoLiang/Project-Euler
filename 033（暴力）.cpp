#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector< pair<int,int> > s;
    for (int a=10;a<=98;a++)
    {
        for(int b=a+1;b<=99;b++)
        {
            if (a%10 == b/10)//分子个位==分母十位
            {
                if (b%10 != 0)
                {
                    if (a/(float)b == (a/10)/(float)(b%10) )//删除相同的数字后，仍相等
                    {
                        pair<int,int> p(a,b);
                        s.push_back(p);
                    }
                }
            }
        }
    }
 
    int ans1=1,ans2=1; //记录分子和分母分别的乘积
    vector<pair<int,int> >::iterator it;
    for (it=s.begin(); it!=s.end();++it)
    {
        ans1 *= it->first;
        ans2 *= it->second;
    }

    int ans=__gcd(ans1,ans2);
    ans=ans2/ans;
    cout<<ans<<endl;
    return 0;
}


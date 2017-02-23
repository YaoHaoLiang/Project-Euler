#include<bits/stdc++.h>
using namespace std;
int solve(int n)
{
    int ans = 0;
    for (int a=1;a<n;a++)
    {
        for (int b=a;b<n;b++)
        {
            int c = n-a-b;
            if (c>b)
            {
            	// a+b+c = p, a2+b2=c2 化简:p2 + 2ab = 2p(a+b) 
                if (n*n+2*a*b == 2*n*(a+b))
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}
 
int main()
{
    int max_i=0,max_ans=0;
    for (int i=1;i<=1000;i++)
    {
        int ans = solve(i);
        if( ans > max_ans)
        {
            max_i = i;
            max_ans= ans;
        }
    }
    cout<<max_i<<"  "<<max_ans<<endl;
    return 0;
}
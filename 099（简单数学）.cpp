#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin); //记得去掉逗号存进in.txt里 
    double tmp=0;
    int a,b,ans;
    for(int i=1;i<=1000;i++)
	{
        cin>>a>>b;
        if(tmp<(double)b*log(a)) //a^b
		{
            tmp=(double)b*log(a);
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
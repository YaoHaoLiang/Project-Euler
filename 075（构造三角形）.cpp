#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int Len[1500010]= {0};
int main()
{
    int a,b,c;
	int ans=0,sum;
    for(int m=1; m<=1224; m++)
    {
    	for(int n=1; n<m; n++)
        {
        	//a=m^2-n^2,b = 2mn,c = m^2 + n^2
            a=m*m-n*n;
            b=2*m*n;
            c=m*m+n*n;
            sum=a+b+c;
            if(a>b) swap(a,b);
            if(sum<=1500000&&gcd(c,gcd(b,a))==1)
            {
                for(int s=sum; s<=1500000; s+=sum)
                    Len[s]++;
            }
        }
	}
        
    for(int i=1; i<=1500000; i++)
        if(Len[i]==1) ans++;
    cout<<ans<<endl;
    return 0;
}


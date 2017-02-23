
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n=1;
	int max=1000;
	int count;
	while(n++)
	{
        count=0;
        for(ll x=n+1; x<=2*n;x++)
        {
            if ((n*x)%(x-n)==0)
                count++;
		}
                                 
        if(count>max)
		{
		    cout<<n<<endl;
			break;
		}               
	}
	return 0;
}

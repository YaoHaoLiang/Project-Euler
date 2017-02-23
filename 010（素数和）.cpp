#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int prime[2000100];
int isprime[2000100];
ll ans=0;
void init()  
{  
    int i,j;  
    int k=1;
    for(i=2;i<2000001;i++)  
    {  
        if(isprime[i]==0)  
        {  
            for(j=2;i*j<2000001;j++)  
                isprime[i*j]=1;  
           // prime[k]=i;  
           ans+=i;
           // k++;  
        }  
    }  
   
}  
int main()
{
	init();
	cout<<ans<<endl;
	return 0;
}

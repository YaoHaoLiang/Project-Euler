#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int prime[1000100];
int isprime[1000100];
void init()  
{  
    int i,j;  
    int k=1;
    for(i=2;i<1000000;i++)  
    {  
        if(isprime[i]==0)  
        {  
            for(j=2;i*j<1000000;j++)  
                isprime[i*j]=1;  
            prime[k]=i;  
            k++;  
        }  
    }  
   
}  
int main()
{
	init();
	cout<<prime[10001]<<endl;
	return 0;
}

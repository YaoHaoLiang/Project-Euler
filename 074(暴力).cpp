#include<bits/stdc++.h>
using namespace std;
int F[10];
void factorial()
{
	F[0] = 1;
    F[1] = 1;
    for(int i=2;i<10;i++) F[i] = i*F[i-1];
 
}    
int A[2177300];
int next(int n)
{
    int res = 0;
    while(n)
	{
        res+=F[n%10]; 
        n/=10;
    }      
    return res;
}    
int solve (int n)
{  
    if(A[n]==-1)
	{
        A[n] = -2;
        int m = next(n);
        int x = solve(m);
        if(A[n]==-2) A[n]=1+x;
    }
    else if(A[n]==-2)
	{
        int m = n;
        int ctr = 1;
        while(9)
		{
            m = next(m);
            if(m==n) break;
            ctr++;
        }
        m=n;
        A[n]=ctr;
        while(9)
		{
            m = next(m);
            if(m==n) break;
            A[m]=ctr;
        }    
        
    }    
    return A[n];    
}    
int main()
{
    factorial();
    int res = 0;
    memset(A , -1 , sizeof(A));
    
    for(int i=1;i<=1000000;i++)
	{
        if(solve(i)==60) res++;
       
    }    
    printf("%d\n",res);
    return 0;
}      
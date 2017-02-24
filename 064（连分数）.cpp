#include <iostream>
#include <cmath>
using namespace std;

/*
* sqrt (n) - b            1
* --------------- = -----------------
*       c                 c
*                    ---------------
*                    sqrt (n) - b
*
*                 =                   1
*                   ------------------------------------
*                           c * (sqrt (n) + b)
*                    ----------------------------------
*                    (sqrt (n) - b)*(sqrt (n) + b)
*
*                 =            1
*                   -----------------------
*                    c * (sqrt (n) + b)
*                    ---------------------
*                         n - b * b
*
*                 =            1
*                   -----------------------
*                       sqrt (n) + b
*                    ---------------------
*                      (n - b * b) / c
*
* So the new c value is (n - b * b) / c.
*/
#include <iostream>
#include <cmath>
using namespace std;
int period(int n)
{	
   int a0,b0,c0,a,b,c;
   int ans=0;
   a0=sqrt(n);
   b0=a0;
   c0=n-a0*a0;
   a=a0;
   c=n-a0*a0;
   do
   {
      a=(sqrt(n)+b)/c;
      b=a*c-b;
      c=(n-b*b)/c;
      ans++;
   }while((b0!=b)||(c0!=c));
   
   return ans; //返回周期 
}

int main()
{
   int count=0;
   for(int i=2;i<=10000;i++)
   {
   	  if(sqrt(i)*sqrt(i)!=i)
   	  {
   	    	if(period(i)%2==1)
            count++;
	 }	   
   }
   cout<<"ans="<<count<<endl;
}
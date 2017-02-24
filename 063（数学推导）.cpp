#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
10^(n-1) <= x^n < 10^n

x < 10. 

10^(n-1)=x^n => 0.1*10^n=x^n => log(0.1)+n*log(10)=n*log(x) 
=> log(10)=n*(log(10)-log(x)) => n=log(10)/(log(10)-log(x))

 x   floor(log(10)/(log(10)-log(x)))
-------------------------------------
 1  	 1
 2  	 1
 3  	 1
 4  	 2
 5  	 3
 6  	 4
 7 	  	 6
 8  	 10
 9  	 21
--------------------
Total: 	49
*/
int main() 
{
	int count=0;
	for(int i=1;i<=9;i++)
	{
		count+=floor(log(10)/(log(10)-log(i)));
	}
	cout<<count<<endl;
	return 0;
}
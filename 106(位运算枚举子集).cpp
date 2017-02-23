#include<bits/stdc++.h>
using namespace std;
int total = 0;
void solve (int n)
{
	total=0;
	//不算空集即 0**0这种 
	for (int x = 1; x < (1 << n); x++)  
    {
    	for (int y = 1; y < (1 << n); y++)
		{
			if ((x & y) == 0) //子集对 (x,y) 不相交 
    	   {
           		int d1 = 0, d2 = 0;
            	for (int j = 0; j < n; j++)
           	 	{
            		if ((x & (1 << j)) > 0) d1++; //统计与x有相交元素的子集 
				}
               // cout<<"d1="<<d1<<endl;
           		 for (int j = 0; j < n; j++)
           		 {
            		 if ((y & (1 << j)) > 0) d2++;//统计与y有相交元素的子集 
				}
			    //cout<<"d2="<<d2<<endl<<"--------"<<endl;
			    
            	if (d1 == d2)
            	{
            		
                	int t = 0;
                	bool ok1 = false;
					bool ok2 = false;
                	for (int j = 0; j < n; j++)
               	 	{
                   	 	if ((x & (1 << j)) > 0) t++; 
                    	if ((y & (1 << j)) > 0) t--;
                   	 	if (t > 0) ok1 = true;
                    	if (t < 0) ok2 = true;
                    //	cout<<"ok1="<<ok1<<endl;
                    //	cout<<"ok2="<<ok 2<<endl<<"-----"<<endl;
                   }
                   //统计需要检验的个数 
                   if (ok1==true && ok2==true) total++; 
                   else if(ok1==false && ok2==false) total++; 
                  
               }
           }
	    } 
	    
	}
    cout<<"ans="<<total/2<<endl;//除以 2 ,是因为有重复的 
}
int main()
{
	solve(2);
	solve(3); 
    solve(4);
    solve(7);
    solve(12);
	return 0;
}

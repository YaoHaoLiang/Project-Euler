#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    int num,k,flag;
	int ans = 0 ,ANS = 0 , maxn ;
    num = 1 ;
    for (int i = 1 ; i < 1000 ; i++ )
    {
        num = 1; //分子 
        k = i;  //分母 
        flag = 1;
        s.clear();
        
        //模拟 
        while (flag)
        {
        	if ( num < k )
            num *= 10 ;
        //find():返回给定值的定位器，如果没找到则返回end()。
        	flag = s.find(num%k) == s.end() ? 1: 0;
        //没找到就 insert 
        	if (flag) s.insert(num%k);
        	num = num%k ;
        }
        //统计个数 
        ans = s.size();
        if (ans > ANS )
        {
            ANS = ans ;
            maxn = i ;
        }
    }
    cout<<maxn<<endl;
    return 0;
}
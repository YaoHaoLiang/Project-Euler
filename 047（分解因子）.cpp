#include<bits/stdc++.h>
using namespace std;
void factor(set<int>& s,  int n)
{
    if(n==1)return;
    int k = (int)sqrt(n);
    int num = 2;
    while( n%num != 0)
	{
        if(num >= k) //最后结束条件 
		{
		  s.insert(n); 
		  return;
		}
        if(num > 2) num+=2;
        else num++;
    }
    s.insert(num);
    factor(s, n/num);
}

int main()
{
    set<int> s;
    int counter = 0;
	int ans = 0;
    for(int i=1; ;i++)
	{
        factor(s, i);
        if(s.size()== 4)
		{ 
            if(ans == 0) ans = i;
            counter++;
        }
		else
		{ 
            ans = 0;
            counter = 0;
        }

        if(counter==4)
		{   
			cout<<ans<<endl;
            s.clear();
            break;
        }
        s.clear();
    }
    return 0;

}
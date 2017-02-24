
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;   

vector<int> phi;

void get_phi()
{
    phi.resize(10000001,0);

    for(int i=1;i<10000000;i++)
	{
        phi[i]+=i;
        for(int j=2*i;j<10000000;j+=i) phi[j]-=phi[i];
    }
}
int check(int x)
{
    int n1[10];
    memset(n1,0,sizeof(n1));

    int tm= phi[x];
    while(tm>0)
	{
        n1[tm%10]++;
        tm/=10;
    }
    
    int n2[10];
    memset(n2,0,sizeof(n2));
    while(x>0)
	{
        n2[x%10]++;
        x/=10;
    }
    
    for(int i=0;i<=9;i++) if(n1[i]!=n2[i]) return 0;
    return 1;
}

vector<pair<double,int> >str;
int main()
{
    get_phi();
    for(int i=2;i<10000000;i++)
	{
        if(check(i))
		{
            str.push_back(make_pair((double)i/phi[i],i));
        }
    }
    sort(str.begin(),str.end());
    cout << str[0].second << endl;
    return 0;
}
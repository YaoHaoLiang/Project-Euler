#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned long long factorial[10];
void initFactorial()
{
    factorial[0]=1;
    factorial[1]=1;
    factorial[2]=1*2;
    factorial[3]=1*2*3;
    factorial[4]=1*2*3*4;
    factorial[5]=1*2*3*4*5;
    factorial[6]=1*2*3*4*5*6;
    factorial[7]=1*2*3*4*5*6*7;
    factorial[8]=1*2*3*4*5*6*7*8;
    factorial[9]=1*2*3*4*5*6*7*8*9;
}

inline unsigned long long getNext(unsigned long long num)
{
    unsigned long long res=0;
    while(num>0)
    {
        res+=factorial[num%10];
        num/=10;
    }
    return res;
}

int main()
{
    initFactorial();
    int tot=0;
    for(int i=69;i<1000000;i++)
    {
        vector<unsigned long long> v;
        unsigned long long cur = i;
        while(find(v.begin(),v.end(),cur) == v.end())
        {
            v.push_back(cur);
            cur=getNext(cur);
        }
        int amount = v.size();
        if(amount == 60) tot++;
    }
    cout << "ans=" << tot << endl;
    return 0;
}
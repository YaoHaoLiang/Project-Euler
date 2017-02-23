#include <bits/stdc++.h>
using namespace std;

class BigNumber  //大数类 
{
private:
    int num[1000];

public:
    BigNumber(int tmp)
    {
        for(int i=999; i>=0; i--) //1000位 
        {
            num[i] = tmp%10;
            tmp /=10;
        }
    }

public:
    bool isThousand()
    {
        return num[0]>0;
    }
    BigNumber operator+(const BigNumber& bigNumber)
    {
        BigNumber sum(0);
        int tmp;
        int over =0;
        for(int i=999; i>=0; --i)//1000位 
        {
            tmp = num[i]+bigNumber.num[i]+over;
            sum.num[i] = tmp%10;
            over = tmp/10;
        }
        return sum;
    }

    void print()  //打印输出结果 
    {
        for(int i=0; i<1000; i++)
        {
            cout << num[i];
        }
        cout<<endl;
    }
};

int main()
{
    BigNumber A1(1);
    BigNumber A2(1);
    int i=2;
    while(1)
    {
        i++;
        A1 = A1+A2;
        if(A1.isThousand())
        {
            break;
        }
        
        i++;
        A2 = A1+A2;
        if(A2.isThousand())
        {
            break;
        }
    }
    cout<<i<<endl;
    return 0;

}
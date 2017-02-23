#include <iostream>
#include <algorithm>        //#reverse_copy()
#include <deque>
using namespace std;

void decimal2binary(int n,deque<int>& bin) //十进制转二进制 
{
    if(n<=0)
    {
        bin.push_front(0); //push_front(i)函数将 i 连接到链表的头部。
        return;
    }
 
    while(n != 0)
    {
        bin.push_front(n%2);  //头插
        n /= 2;
    }
}
 
void disp(int elem){cout<<elem;}
 

bool is_palindromic_both(int n) //判断十进制和二进制是否都是回文数 
{
    if (n<=0)
    {
        return false;
    }

    //获取十进制的各位数字
    int cpy = n;
    deque<int> digits;                          //存放各位上的数字
    while (cpy!=0)
    {
        digits.push_front(cpy%10);
        cpy /= 10;
    }
 
    //逆置
    deque<int> digits_rvs(digits.size());      //逆序存放各位上的数字
    reverse_copy(digits.begin(),digits.end(),digits_rvs.begin()); //逆置
 
    //判断正序和逆序是否相等
    bool flag = true;
    deque<int>::iterator it1,it2;
    for (it1=digits.begin(), it2=digits_rvs.begin(); it1!=digits.end() && it2!=digits_rvs.end(); it1++,it2++)
    {
        if (*it1 != *it2)
        {
            flag = false;
            break;
        }
    }
    //十进制不是回文，直接返回false
    if(!flag)
    {
        return false;
    }
 
    //判断二进制是否是回文数
 
    deque<int> bin;           //存放二进制
    decimal2binary(n,bin);
 
    //逆序
    deque<int> bin_rvs(bin.size()); //存放二进制逆序
    reverse_copy(bin.begin(),bin.end(),bin_rvs.begin());
 
    //判断正序和逆序是否相等
    flag = true;
    for (it1=bin.begin(),it2=bin_rvs.begin();it1!=bin.end() && it2!=bin_rvs.end();it1++,it2++)
    {
        if (*it1 != *it2)
        {
            flag = false;
            break;
        }
    }
    //二进制是否回文
    if(flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
int main()
{
    int sum = 0;
    for (int i=1;i<1000000;i++)
    {
        if (is_palindromic_both(i))
        {
            sum += i;
        }
    }
    cout<<sum<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int  is_prime(int n)
{
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    else if (n % 2 == 0) return false;
    else
    {
        for(int i=3;i<(int)sqrt((float)n)+1;i++)
        {
            if(n % i == 0) return 0;
        }
    }
    return 1;
}
 
int rotate_one_bit(int n) //向右旋转一位 
{
    int i=0;
    int len=0;   //n的位数
 
    //获取n的位数 len
    int cpy = n;
    while(cpy!=0)
    {
        len ++;
        cpy /= 10;
    }
 
    //获取个位数字 bit
    int bit = n % 10;
    //将n右移一位，即/10
    n /= 10; 
    //将个位补到最高位
    n += bit * (int)pow((float)10,len-1); 
    //cout<<n<<endl;
    return n;
}
 
int is_circle(int n) //判断旋转后是否是素数 
{
    if (n == 0) return 0;
 
    //判断n中是否含有 '0'，随便计算出n的位数
    int cpy = n;
    int len = 0;
    while (cpy!=0)
    {
        len ++;
        if (cpy % 10 == 0) //出现'0'
        {
            return 0;
        }
        cpy /= 10;
    }
 
    //判断旋转所得的数是否都是质数  
    for (int i=1;i<=len-1;i++)    //向右旋转len-1次
    {
        n = rotate_one_bit(n);
        if (!is_prime(n))         //某个旋转结果不是质数
        {
            return 0;
        }
    }
    return 1;
}
 
int main()
{
    int ans = 0;
    for (int i=1;i<1000000;i++)
    {
        if (is_prime(i))
        {
            if (is_circle(i))
            {
                ans ++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
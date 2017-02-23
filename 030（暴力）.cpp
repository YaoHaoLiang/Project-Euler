#include<bits/stdc++.h>
int sum(int n)
{
    int sum=0;
    int digit = 0;
    while(n!=0)
    {
        digit = n%10;
        sum += (int)pow((float)digit,5);
        n /= 10;
    }
    return sum;
}
int main()
{
    int i;
    int ans = 0;
    for (i=10;i<999999;i++)
    {
        if (sum(i) == i)
        {
            ans += i;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
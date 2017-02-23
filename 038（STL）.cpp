#include<bits/stdc++.h>
using namespace std;

void split_digits(int n, vector<int>& v)
{ 
    int digits[12];
    int len = 0;
    while(n>0)
    {
        digits[len++] = n %10;
        n /= 10;
    }
 
    for(int i=len-1;i>=0;i--)  
    {
        v.push_back(digits[i]);
    }
}
 
void disp(int n){ cout<<n; }
 
int main()
{
    for(int x=1;x<10000;x++)
    {
        vector<int> s;
        int n = 0;    
        while(n<=9)
        {
        	n++;
            split_digits(n*x,s); //n*x 的各位数字加入到 vector<int>s中
            
            if (s.size() == 9)
            {
                set<int> set_product(s.begin(),s.end()); //将vector中的数字保存到set集合中
                if(set_product.size() == 9) //说明没有重复数字
                {
                    //判断是否含有数字 0
                    set<int>::iterator it = set_product.find(0);
                    
                    if (it == set_product.end())  //不含数字 0
                    {
                        //满足条件,输出 
                        cout<<"x="<<x<<" n="<<n<<" ";
                        cout<<"乘积和为：";
                        for_each(s.begin(),s.end(),disp);
                        cout<<endl;
                    }
                }
            }
            else if (s.size() > 9)
            {
                break;  //下一个 x 
            }                
        }
        
    }
    return 0;
}
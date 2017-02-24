#include<bits/stdc++.h>
using namespace std;

int a[14000];
int b[14000];
//set<int>s; 
//num :分解因子个数
//mul ：乘积因子
//sum ： 加法因子 
void solve(int num,int mul,int sum)
{
   //比如 k=3: 6 = 1 × 2 × 3 = 1 + 2 + 3 
   // 3=3+6-6
   //比如 k=4: 8 = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4 
   //4=4+8-8 
	int k=num+mul-sum;
	//cout<<"k="<<k<<endl;
	if(a[k]==0 || a[k] >= mul){
		a[k]=mul;
		//s.insert(mul);
		//cout<<"mul:"<<mul<<endl; 
	}
	//	cout<<"------"<<endl;
	for(int i=2;i*mul<14000;i++)
	{
		solve(num+1,mul*i,sum+i);
	
	}
}
int main()
{
	int sum=0;
	solve(0,1,0);
	for(int i=2;i<=12000;i++)
	{
		if(!b[a[i]])
		{
			b[a[i]]=1;
			sum+=a[i];
		}		
	}
	printf("%d\n",sum);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
double P[1000010];
int main()
{
	 int n=15;
	 P[0]=1; //P[i]表示n轮后抽到 i 个蓝色碟子的概率 
	 for(int i=1;i<=n;i++)
	 {
	 	 double temp=P[0];
	    	P[0]=1.0/(i+1);
	 	for(int j=1;j<=i;j++)
	 	{
	 		double t=P[j];
	 		P[j]=P[0]*(i*P[j]+temp);
	 		temp=t;
		 }
	 }
	  double sum=0;
	 for(int i=n/2+1;i<=n;i++)
	 {
	   //printf("P[%d]=%.14lf\n",i,P[i]);
	 	sum += P[i];
	 }
	 		 
	 cout<<(int)( (1-sum)/sum )+1<<endl;
	 return 0;
}
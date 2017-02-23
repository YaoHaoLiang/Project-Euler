#include<bits/stdc++.h>
using namespace std;

int main()
{
	int count=0;
	double x1=0.0;
	double y1=10.1;
	
	double x0=1.4;
	double y0=-9.6;
	
	while(x0 > 0.01 || x0< -0.01 || y0 <0 )
	{
		double xielv1=(y0-y1)/(x0-x1); //入射线的斜率 
		
		double xielv2= -4*x0/y0; //椭圆切线的斜率
		
		double tan1=(xielv1-xielv2)/(1+xielv1*xielv2); 
		
		//出射线斜率 
		double xielv3=(xielv2-tan1)/(1+tan1*xielv2);
		//出射线截距
		double d= y0 -xielv3*x0;   
		
		double a=4+xielv3*xielv3;
		double b=2*xielv3*d;
		double c=d*d-100;
		
		double ans1=(-b+sqrt(b*b-4*a*c)) / (2*a);
		double ans2=(-b-sqrt(b*b-4*a*c)) / (2*a);
		
		x1=x0;
		y1=y0;
		
		x0=( abs(ans1-x0) > abs(ans2-x0)) ? ans1 :ans2;
		y0= xielv3 * x0 + d;
		
		count++;
	}
	cout<<count<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x0,y0;
	int x1,y1;
	int count=50*50; //直角三角形 
	//枚举其它两个点 
	//x0*y1 - x1*y0 != 0 表示这条直线没有0
	// x0*(x1-x0) + y0*(y1-y0) == 0"表示在 (x0,y0)有个直角 
	for(x0=0; x0<=50; x0++)
	for(y0=0; y0<=50; y0++)
	for(x1=0; x1<=50; x1++)
	for(y1=0; y1<=50; y1++)
	{
		if(x0*y1-x1*y0!=0 && x0*(x1-x0)+y0*(y1-y0)==0)
		count++;
	}
	cout<<count<<endl;
	return 0;
}
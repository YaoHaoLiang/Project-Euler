#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
main()
{
	int D,j,k,cnt=0;
	int fenzi,fenmu,res;
	long double p0,p1,pn,q0,q1,qn,ans=0.0;
	vector<int>v;
	for(D=2;D<=1000;D++)
	{
         //http://blog.sina.com.cn/s/blog_5d06e2390100ll92.html
		v.clear();
		j=(int)sqrt(D);
		if(j*j==D) continue;//D是平方数时，不存在正整数解 
		fenzi=j;
		fenmu=D-j*j;
		v.push_back((j+fenzi)/fenmu);
		while(1)
		{
			if(fenmu==1) break;
			
			fenzi=v[v.size()-1]*fenmu-fenzi;
			fenmu=(D-fenzi*fenzi)/fenmu;
			
			if(fenmu!=1) v.push_back((j+fenzi)/fenmu);
			else  v.push_back(2*fenzi);
		}	
		
		p0=(long double)sqrtl(D);
		p1=(long double)v[0]*p0+1.0;
		q0=1LL,q1=(long double)v[0];
		
		for(j=1;j<v.size()-1;j++)
		{
			pn=(long double)v[j]*p1+p0;
			p0=p1;
			p1=pn;
			qn=(long double)v[j]*q1+q0;
			q0=q1;
			q1=qn;
		}
		if(v.size()%2!=0)
		{
			j=v.size()-1;
			pn=(long double)v[j]*p1+p0;
            p0=p1;
            p1=pn;
            qn=(long double)v[j]*q1+q0;
            q0=q1;
			q1=qn;
			
			for(j=0;j<v.size()-1;j++)
            {
                pn=(long double)v[j]*p1+p0;
                p0=p1;
                p1=pn;
                qn=(long double) v[j]*q1+q0;
                q0=q1;
				q1=qn;
            }
		}		
		//cout<<i<<" "<<pn<<" "<<qn<<endl;
		if(ans< pn)
		{
		   ans=pn;
		   res=D;
		}
		
	}
	cout<<res<<endl;
	return 0;
}

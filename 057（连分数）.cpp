#include <iostream>
#include <vector>
using namespace std;

vector<char> add(vector<char> a, vector<char> b)
{
	vector<char>c;
	vector<char>::iterator ia,ib,i,ie;
	ia = a.begin();
	ib = b.begin();
	char o = 0,s;
	while(ia!=a.end() && ib!=b.end())
	{
		s = (*ia)+(*ib)+o;
		o = s/10;
		s %= 10;
		ia++;
		ib++;
		c.push_back(s);
	};
	if(o && ia==a.end() && ib==b.end())
	{
		c.push_back(o);
	} 
	else
	{
		if(ia==a.end())
		{
			i=ib;
			ie=b.end();
		}
		else 
		{
			i=ia;
			ie=a.end();
		};
		while(i!=ie)
		{
			s = o + (*i);
			o = s/10;
			s %= 10;
			i++;
			c.push_back(s);
		};
		if(o) c.push_back(o);
	};
	return c;
}
int main()
{
	vector<char> n,d,c;
	int i=0,tot=0;
	n.push_back(3);
	d.push_back(2);
	do{
		c = add(d,d);
		c = add(c,n);
		d = add(d,n);
		n = c;
		if(n.size()!=d.size()) tot++;
		i++;
	}while(i<1000);
	cout<<tot<<endl;
	return 0;
}

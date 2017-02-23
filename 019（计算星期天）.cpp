#include <iostream>
using namespace std;

int main()
{
	int days = 1,years = 1900;
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int sundays=0;
	while(years<2001)
	{
		for(int i=0;i<12;i++)
		{
			days+=months[i];
			if(i==1&&(years%4==0&&years%100!=0||years%400==0))
			{
				days+=1;
				cout<<"leap year="<<years<<endl;
			}
			if(days%7==0&&years>=1901)
				sundays++;
		}
		years++;
	}
	cout<<sundays<<endl;

	return 0;
}
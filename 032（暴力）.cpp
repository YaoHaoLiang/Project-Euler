#include<bits/stdc++.h>
using namespace std;


int main()
{
	int ans=0;
	int sum=0;
	set<int> s;
	int a[9]={1,2,3,4,5,6,7,8,9};
	do
	{
		if( a[0]* (a[1]*1000+a[2]*100+a[3]*10+a[4]) == a[5]*1000+a[6]*100+a[7]*10+a[8] ){
			ans++;
			//sum+=a[5]*1000+a[6]*100+a[7]*10+a[8];
			s.insert(a[5]*1000+a[6]*100+a[7]*10+a[8]);
		}
		else if((a[0]*10+a[1]) * (a[2]*100+a[3]*10+a[4]) == a[5]*1000+a[6]*100+a[7]*10+a[8] ){
			ans++;
			//sum+=a[5]*1000+a[6]*100+a[7]*10+a[8];
			s.insert(a[5]*1000+a[6]*100+a[7]*10+a[8]);
		}
		
	}while(next_permutation(a,a+9));
	//cout<<ans<<endl;
	for(set<int>::iterator it=s.begin();it!=s.end();it++) sum+=*it;
	cout<<sum<<endl;
	return 0;
}
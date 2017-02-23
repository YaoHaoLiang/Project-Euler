#include<bits/stdc++.h>
using namespace std;
int main()
{

	vector<int> V(21);
	vector<int> scores(3*20+1,0);
	for (int i = 1; i <= 20; i++)
	{
		V[i-1] = 2*i;
		scores[i]++;  //一倍 
		scores[2*i]++; //两倍 
		scores[3*i]++; //三倍 
	}
	scores[0]++; 
	scores[25]++; 
	scores[50]++; 
	V.back() = 50;

	int ans=0;
	for (int k = 0; k < V.size(); k++)
		for (int i = 0; i < scores.size(); i++)
			for (int j = i; j < scores.size(); j++)
				if (V [k] + i + j < 100)
				{
					if(i!=j)
					{
						ans += scores[i]*scores[j];
					}
					else ans += scores[i]*( scores[i]+1)/2;
				}
	cout<<ans<<endl;
	return 0;
}
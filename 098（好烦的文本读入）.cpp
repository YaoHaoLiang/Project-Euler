#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ifstream inf("in.txt");
ofstream of("out.txt");
char data[2000][20];
char pr[100][2][20];
int m=0;

int compute(int in)
{
	int l = strlen(pr[in][0]);
	l=pow(10,l-1);
	int i=1;
	while(i*i<l) i++;
	int lb = i;
	l*=10;
	while(i*i<l) i++;
	int ub = (i-1);
	for(int i=lb;i<=ub;i++)
	{
		int x = i*i;
		int mark[10];
		int s[100];
		memset(mark,0,sizeof(mark));
		memset(s,0,sizeof(s));
		int l = strlen(pr[in][0]);
		int j;
		for(j=l-1;j>=0;j--)
		{
			if (s[pr[in][0][j]]==0)
			{
				if (mark[x%10]==1) break;
				else
				{
					s[pr[in][0][j]]=x%10;
					mark[x%10]=1;
				}
			}
			else if( s[pr[in][0][j]]!=(x%10) ) break;
			
			x/=10;
		}
		if (j!=-1||s[pr[in][1][0]]==0) continue;
		int sum=0;
		for(int j=0;j<l;j++)
		{
			sum=sum*10+s[pr[in][1][j]];
		}	
	
		int sr = sqrt(sum);
		if (sr*sr==sum)
		{
			m=max(m,max(sum,i*i));
		}
	}
	return 0;
}

int init()
{
	int i=0;
	char ch,v;
	while(inf.eof()!=1)
	{
		inf>>ch>>v;
		int j=0;
		while(v!='"')
		{
			data[i][j++]=v;
			inf>>v;
		}
		inf>>ch;
		i++;
	}
	
	int n = i-1;
	int cn=0;
	for(int i=0;i<n;i++)
	{
		int s[100];
		memset(s,0,sizeof(s));
		int l = strlen(data[i]);
		for(int j=0;j<l;j++)
		{
			s[int(data[i][j])]++;
		}
		
		int f=0;
		for(int j=i+1;j<n;j++)
		{
			if (strcmp(data[i],data[j])==0) continue;
			
			int s1[100];
			memset(s1,0,sizeof(s1));
			
			l=strlen(data[j]);
			for(int k=0;k<l;k++)
			{
				s1[int(data[j][k])]++;
			}
			
			int k;
			for(k=65;k<=90;k++)
			{
				if(s1[k]!=s[k]) break;
			}
			
			if (k==91)
			{
				if (f==0)
				{
					of<<data[i]<<endl;
				} 
			
				of<<data[j]<<endl;
				strcpy(pr[cn][0],data[i]);
				strcpy(pr[cn][1],data[j]);
				cn++;
				f++;
			}
		}
		if (f!=0)
		{
			of<<endl;
		}
	}
	for(int i=0;i<=cn-1;i++)
	{
		compute(i);
	}
	cout<<m<<endl;
	return 0;
}

int main()
{
	clock_t tStart = clock();
	init();
	printf("Times: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
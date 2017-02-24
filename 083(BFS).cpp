#include<bits/stdc++.h>
#define n 80
using namespace std;

typedef struct node
{
	int i, j, w;
}Node;

bool operator<(Node a, Node b)
{
	return a.w > b.w;
}
int cx[] = {0, 1, 0, -1 };
int cy[] = {1, 0, -1, 0 };
int main()
{
	
	int b[n][n];
	freopen("in.txt","r",stdin);
	for(int i = 0; i < 80; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
		int value[n][n];
		memset(value, -1, sizeof(value));
		priority_queue<Node> Q;
		Node t;
		t.i = 0; 
		t.j = 0; 
		t.w = b[0][0];
		Q.push(t);
		value[0][0]=b[0][0];
		while(!Q.empty())
		{
			Node t = Q.top();
			Q.pop();

			for(int k = 0; k < 4; k++)
			{
				int nx = t.i + cx[k];
				int ny = t.j + cy[k];
				if( nx < 0 || nx >= n ) continue;
				if( ny < 0 || ny >= n ) continue;
				if( value[nx][ny] != -1 &&value[t.i][t.j]+b[nx][ny]>=value[nx][ny]) continue;
				Node s;
				s.i = nx; 
				s.j = ny; 
				s.w = value[t.i][t.j]+b[nx][ny];
				value[nx][ny]=s.w;
				Q.push(s);
			}
		}
	printf("%d\n", value[n-1][n-1]);
    return 0;
}

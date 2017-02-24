#include<cstdio>
#include<cstring>
#include<queue>
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
int cx[] = {0, 1, 0};
int cy[] = {1, 0, -1};
int main()
{
	
	int b[n][n];
	int inf = 1<<28;
	freopen("in.txt","r",stdin);
	for(int i = 0; i < 80; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			scanf("%d ", &b[n - j - 1][i]);
		}
	}
	
	int min = inf;
	for(int i = 0; i < n; i++)
	{
		int value[n*n];
		memset(value, -1, sizeof(value));
		priority_queue<Node> Q;
		Node s;
		s.i = 0; 
		s.j = i; 
		s.w = b[0][i];
		Q.push(s);
		while(!Q.empty())
		{
			Node t = Q.top();
			Q.pop();
			if( value[t.i *n  + t.j] != -1 ) continue;
			value[ t.i*n + t.j] = t.w;
			for(int k = 0; k < 3; k++)
			{
				int nx = t.i + cx[k];
				int ny = t.j + cy[k];
				if( nx < 0 || nx >= n ) continue;
				if( ny < 0 || ny >= n ) continue;
				if( value[nx * n + ny] != -1 ) continue;
				s.i = nx; 
				s.j = ny; 
				s.w = t.w + b[nx][ny];
				Q.push(s);
			}
		}
		
		for(int j = 0; j < n; j++)
		{
			if( value[n*n - j - 1] < min )
			{
				min = value[n*n - j - 1];
			}
		}
	}
	printf("%d\n", min);
    return 0;
}

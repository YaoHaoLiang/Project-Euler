# include <stdio.h>

int main()
{
	char b;
	int i,j=0,ii,k,a[80][80]={0},open[40000][3]={-1},first[3],d1[3],d2[3],r=0;
	FILE *fp;
	fp=fopen("in.txt","r+");
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		{
			for(;;)
			{
				fread(&b,sizeof(char),1,fp);
				if(feof(fp))
					break;
				if(b>='0' && b<='9')
				{
					a[i][j]*=10;
					a[i][j]+=(b-'0');
				}
				else
					break;
			}
		}
	}
	for(i=0;i<40000;i++)
	{
		open[i][0]=-1;
		open[i][1]=-1;
		open[i][2]=0;
	}
	open[0][0]=0;
	open[0][1]=0;
	open[0][2]=a[0][0];
	for(;;)
	{
		first[0]=open[0][0];
		first[1]=open[0][1];
		first[2]=open[0][2];
		a[first[0]][first[1]]=-1;
		if(first[0]==-1)
			break;
		for(i=0;i<40000;i++)
		{
			//printf("%d %d %d %d\n",open[i][0],open[i][1],open[i][2],i);
			open[i][0]=open[i+1][0];
			open[i][1]=open[i+1][1];
			open[i][2]=open[i+1][2];
			if(open[i][0]==-1)
				break;
		}
		if(first[0]==79 && first[1]==79)
		{
			printf("%d\n",first[2]);
			break;
		}
		if(first[0]+1<=79 && a[first[0]+1][first[1]]!=-1)
		{j=first[2]+a[first[0]+1][first[1]];
		for(i=0;i<40000;i++)
		{
			if(open[i][0]==first[0]+1 && open[i][1]==first[1])
			{
				if(j<open[i][2])
				{
					for(k=i-1;k>=0;k--)
					{
						if(open[k][2]>j)
						{
							open[k+1][0]=open[k][0];
							open[k+1][1]=open[k][1];
							open[k+1][2]=open[k][2];
						}
						else
						{
							open[k+1][0]=first[0]+1;
							open[k+1][1]=first[1];
							open[k+1][2]=j;
							break;
						}
						if(k==0)
						{
							open[k][0]=first[0]+1;
							open[k][1]=first[1];
							open[k][2]=j;
						}
					}
				}
				break;
			}
			if(j<open[i][2] || open[i][2]==0)
			{
				d1[0]=open[i][0];
				d1[1]=open[i][1];
				d1[2]=open[i][2];
				open[i][0]=first[0]+1;
				open[i][1]=first[1];
				open[i][2]=j;
				for(;i<40000;i++)
				{
					if(open[i+1][0]==-1)
					{
						open[i+1][0]=d1[0];
						open[i+1][1]=d1[1];
						open[i+1][2]=d1[2];
						break;
					}
					else
					{
						d2[0]=open[i+1][0];
						d2[1]=open[i+1][1];
						d2[2]=open[i+1][2];
						open[i+1][0]=d1[0];
						open[i+1][1]=d1[1];
						open[i+1][2]=d1[2];
						d1[0]=d2[0];
						d1[1]=d2[1];
						d1[2]=d2[2];
					}
				}
				break;
			}
		}}
		if(first[1]+1<=79 && a[first[0]][first[1]+1]!=-1)
		{
		j=first[2]+a[first[0]][first[1]+1];
		for(i=0;i<40000;i++)
		{
			if(open[i][0]==first[0] && open[i][1]==first[1]+1)
			{
				if(j<open[i][2])
				{
					for(k=i-1;k>=0;k--)
					{
						if(open[k][2]>j)
						{
							open[k+1][0]=open[k][0];
							open[k+1][1]=open[k][1];
							open[k+1][2]=open[k][2];
						}
						else
						{
							open[k+1][0]=first[0];
							open[k+1][1]=first[1]+1;
							open[k+1][2]=j;
							break;
						}
						if(k==0)
						{
							open[k][0]=first[0];
							open[k][1]=first[1]+1;
							open[k][2]=j;
						}
					}
				}
				break;
			}
			if(j<open[i][2] || open[i][2]==0)
			{
				d1[0]=open[i][0];
				d1[1]=open[i][1];
				d1[2]=open[i][2];
				open[i][0]=first[0];
				open[i][1]=first[1]+1;
				open[i][2]=j;
				for(;i<40000;i++)
				{
					if(open[i+1][0]==-1)
					{
						open[i+1][0]=d1[0];
						open[i+1][1]=d1[1];
						open[i+1][2]=d1[2];
						break;
					}
					else
					{
						d2[0]=open[i+1][0];
						d2[1]=open[i+1][1];
						d2[2]=open[i+1][2];
						open[i+1][0]=d1[0];
						open[i+1][1]=d1[1];
						open[i+1][2]=d1[2];
						d1[0]=d2[0];
						d1[1]=d2[1];
						d1[2]=d2[2];
						//printf("?? %d %d %d\n",open[i+1][0],open[i+1][1],open[i+1][2]);
					}
				}
				break;
			}
		}}
	}
	return 0;
}
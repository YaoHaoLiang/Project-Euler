#include<bits/stdc++.h>
using namespace std;

void mul(char* temp1, int temp2, char* temp3) //大数乘 
{
	int carry =0;
	int total = 1;
	for(int i = strlen(temp1)-1; i>=0; i--)
	{
		total = (temp1[i] - 48) * temp2 + carry;
		carry = total/10;
		temp3[i] = total%10 + 48;
	}
	if(carry)
	{
		char temp4[1000] = {0};
		strcpy(temp4,temp3);
		sprintf(temp3,"%u",carry);
		strcat(temp3,temp4);	
	}
}

void add(char* temp1, char* temp2, char* temp3) //大数加 
{
	int carry =0;
	int total = 0;
	int x = strlen(temp1);
	int y = strlen(temp2);
	int z = 0;
	if(x>y)
		z = x-1;
	else
		z = y-1;
	for(int i = x-1, j = y-1; ; )
	{
		if( i >= 0 && j >= 0)
		{
			total = temp1[i] - 48 + temp2[j] -48 + carry;
			carry = total/10;
			temp3[z] = total%10 + 48;
			i--; 
			j--; 
			z--;
		}
		else if(i >= 0 && j == -1)
		{
			total = temp1[i] - 48 + carry;
			carry = total/10;
			temp3[z] = total%10 + 48;
			i--;
			z--;
		}
		else if(i == -1 && j >= 0)
		{
			total = temp2[j] - 48 + carry;
			carry = total/10;
			temp3[z] = total%10 + 48;
			j--; 
			z--;
		}
		else if( i == -1 && j == -1)
			break;
	}
	if(carry)
	{
		char temp4[1001] = {0};
		strcpy(temp4,temp3);
		sprintf(temp3,"%u",carry);
		strcat(temp3,temp4);		
	}
}

void findNumDen(char* x, char* y, int *val, int length)
{
	char temp1[1001] = {0};
	char temp2[1001] = {0};
	char temp3[1001] = {0};
	char temp4[1001] = {0};
	sprintf(temp2,"%u",val[length-1]);
	sprintf(temp1,"%u",1);
	
	for(int i = length - 2; i>=0; i--)
	{	
		mul(temp2,val[i],temp4);
		add(temp4,temp1,temp3);
		if(i == 0)
		break;
		strcpy(temp1,temp2);
		strcpy(temp2,temp3);
	}
	strcpy(x,temp3);
	strcpy(y,temp2);
}
int main()
{
	long long  count = 3;
	int arr[11000] = {0};	
	//e = [2; 1,2,1, 1,4,1, 1,6,1 , … , 1,2k,1, …]
	arr[0] = 2;
	arr[1] = 1;
	arr[2] = 2;
	int last = 2;
	for(int i = 1; i< 98; i++) // 第98+2项  
	{
		if(i % 3 == 0)
		{
			arr[count++] = 2*last;
			last++;
		}
		else
			arr[count++] = 1;
	}
	char x[1001] = {0};
	char y[1001] = {0};
	
	findNumDen(x, y, arr, count);
	
	count = 0;
	
	for(int k = 0; k <strlen(x); k++)
	{
		printf("%c",x[k]); //分子 
	}
	cout<<endl; 
	for(int k=0;k<strlen(y);k++)
	{
		printf("%c",y[k]); //分母 
	} 
	for(int k = 0; k <strlen(x); k++)
	{
		count += x[k] - '0'; //分子各数和 
	}
	cout<<endl;
	
	printf("%lld\n",count);
	return 0; 
}
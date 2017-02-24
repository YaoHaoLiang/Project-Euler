#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int next(int n)
{
  int count = 0;
  while(n>0)
  {
  	count += (n%10)*(n%10);
  	n /= 10;
  }    
  return count;
}

int main()
{
  	int count = 0;
    for (int i = 1; i < 10000000; i++ )
    {
      int curr = i;
      while ( curr != 1 && curr != 89 ){
      	curr = next(curr);
	  }
	  if(curr==89)
      count ++;
    }
 	cout << count << endl;
  	return 0;
}
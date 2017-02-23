
#include <bits/stdc++.h>
using namespace std;
int main()
{
  //1-9
  int s1[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
 //10-19
  int s2[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
  //20 30 40 50 60 70 80 90
  int s3[] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };

  int hundred = 7;
  int And = 3;
  int thousand = 8;

  int i;
  int sum = 0;
  
  //1-9
  for (i = 1; i < 10; i++)
  {
    sum += s1[i];
  }
  
  //10-19
  for (i = 0; i < 10; i++){
    sum += s2[i];
  }
  
 //20-99
  for (i = 20; i < 100; i++){
    sum += s3[i/10] + s1[i%10];
  }
  
 //100-999
  for (i = 1; i < 10; i++)
  {
    int j;
   //计算hundred 
    sum += s1[i] + hundred;
    // i*100 + j
    for (j = 1; j < 10; j++){
      sum += s1[i] + hundred + And + s1[j];
    }
    //i*100 + j*10 
    for (j = 0; j < 10; j++) {
      sum += s1[i] + hundred + And + s2[j];
    }
    //i*100 +j*10 +k
    for (j = 20; j < 100; j++) {
      sum += s1[i] + hundred + And + s3[j/10] + s1[j%10];
    }
  }
  
  //1000
  sum += 3 + thousand;
  
  cout<<sum<<endl;
  return 0;
}


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int wordScore(string a)
{
  int score = 0;
 
  for(int i=0;i<a.length();i++)
  {
  	if(a[i]>=65&&a[i]<=90)
    score +=( a[i]-'A'+1 );
  }
  return score;
}

bool isTriangular(int a)
{
  double m = (sqrt(8*(double)a+1) - 1) / 2;
  if(floor(m)==m) return true;
  return false;
}

int main()
{	
  int ans = 0;
  string word;
  ifstream fin("words.txt");
  if (fin.is_open())
  {
    while (getline(fin,word,','))
    {
      if(isTriangular( wordScore(word) ) )
	  {
        ans++;
      }
    }
    fin.close();
  }
  cout << ans << endl;
  return 0;
}
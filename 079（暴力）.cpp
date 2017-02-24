#include <iostream>
#include <fstream>
#include <set>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
set<char> s;
vector<char> v;
int main()
{
    char keys[51][3];
    string in;
    int i=0;
    ifstream infile;
    infile.open("in.txt");
    while(infile>>in)
    {

        strcpy(keys[i] , in.c_str());
        i++;
    }
    for(int j=0;j<50;j++)
    {
        for(int i=0;i<3;i++)
        {
              s.insert(keys[j][i]);
        }
    }
    v.assign(s.begin(), s.end());
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(k>j && find(v.begin() ,v.end() , keys[i][j] ) > find(v.begin() ,v.end() , keys[i][k] ) )
                {
                    iter_swap( find(v.begin() ,v.end() , keys[i][j] ), find(v.begin() ,v.end() , keys[i][k] ) );
                }
            }
        }
    }
    for (vector<char>::iterator i =v.begin(); i != v.end(); i++)  cout << *i ;
    return 0;
}

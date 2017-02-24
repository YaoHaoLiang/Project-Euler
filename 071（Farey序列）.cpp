#include <iostream>
using namespace std;
int main()
{
    // Farey neighbours
    //http://nrich.maths.org/6598/solution
    int n = 2;
    int d = 5;
    while(d <= 1000000)
	{
        n += 3;
        d += 7;
    }
    cout<<n-3<<endl;
    return 0;
}
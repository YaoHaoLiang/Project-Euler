#include <iostream>
#include <set>
using namespace std;

set<int> digits(int n)
{
    set<int> res;
    while(n>0)
	{
        res.insert(n%10);
        n/=10;
    }
    return res;
}

int main()
{
    int x = 1;
    while(1)
	{
        if(digits(2*x) == digits(3*x) && digits(3*x) == digits(4*x) && digits(4*x) == digits(5*x) && digits(5*x) == digits(6*x))
		{
            cout << x << endl;
            break;
        }
        x++;
    }
    return 0;
}
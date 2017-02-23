#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int n = 143;
    while (1)
    {
    	n++;
    	//Hexagonal
        double h = n * (2 * n - 1); 
        double Triangle = (sqrt(1 + 8 * h) - 1) / 2;
        double Pentagonal = (sqrt(1 + 24 * h) + 1) / 6;
        double T = (int)Triangle;
        double P = (int)Pentagonal;
 
        if (T == Triangle && P == Pentagonal)
        {
            long long ans = n * (2 * n - 1);  
            cout<<ans<<endl;
            break;
        } 
    }
    return 0;
}
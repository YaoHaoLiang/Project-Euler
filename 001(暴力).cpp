#include<iostream>
using namespace std;
int main()
{
    int n = 1000;
    int sum = 0;

    for(int i = 0; i < n; ++i)
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    cout<< "Sum below 1000 is:" << sum << endl;
}
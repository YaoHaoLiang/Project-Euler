#include <iostream>
#include <cmath>

int *partitions = new int[100000];

//https://en.wikipedia.org/wiki/Pentagonal_number
int main()
{
    partitions[0] = 1;
    int lim, t1, t2, s;
    for(int i=1; i<100000; i++)
	{
        lim = floor((sqrt(24.*i+1)+1)/6);
        partitions[i] = 0;
        s = 1;
        for(int k=1; k<=lim; k++)
		{
            t1 = i-k*(3*k-1)/2;
            t2 = i-k*(3*k+1)/2;
            if(t1 >= 0) partitions[i] += s*partitions[t1];
            if(t2 >= 0) partitions[i] += s*partitions[t2];
            partitions[i] %= 1000000;
            s *= -1;
        }
        if(partitions[i] == 0)
		{
            std::cout << i;
            return 0;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int primes[100000000];
void initPrimes()
{
    long long int i,j;
    for (i=0; i<100000000; i++)
        primes[i]=1;
        
    for (i=2; i*i<100000000; i++)
        if (primes[i])
            for (j=2; i*j<100000000; j++)
                primes[i*j]=0;
}

int Primes (long long int n)
{
	if (n<100000000)
		return primes[n];
	return 0;
}

long long int concat (long long int a, long long int b)
{
	long long int c=b;
	long long int d=a;
	while (c>0)
	{
		d*=10;
		c/=10;
	}
	d+=b;
	return d;
}

int main ()
{
	initPrimes();
	long long  p1=0;
	long long  p2=0;
	long long  p3=0;
	long long  p4=0;
	long long  p5=0;
	long long  t1,t2,t3,t4;
	for (p1=3 ; p1<100000000; p1+=2)
	if (Primes(p1)){
		for (p2=p1 ; (t1=concat(p2,p1))<100000000; p2+=2)
			if (Primes(p2) && Primes(t1) && Primes(concat(p1,p2))){
				for (p3=p2 ; (t2=concat(p3,p2))<100000000; p3+=2)
					if (Primes(p3) && Primes(t2) && Primes(concat(p2,p3)) && Primes(concat(p1,p3)) && Primes(concat(p3,p1)) ){
						for (p4=p3 ; (t3=concat(p4,p3))<100000000; p4+=2)
							if (Primes(p4) && Primes(t3) && Primes(concat(p3,p4)) && Primes(concat(p1,p4)) && Primes(concat(p4,p1)) 
							&& Primes(concat(p2,p4)) && Primes(concat(p4,p2))){
								for (p5=p4 ; (t4=concat(p5,p4))<100000000 ; p5+=2)
									if (Primes(p5) && Primes(t4) && Primes(concat(p4,p5)) && Primes(concat(p1,p5)) && Primes(concat(p5,p1)) 
											&& Primes(concat(p2,p5)) && Primes(concat(p5,p2)) && Primes(concat(p3,p5)) && Primes(concat(p5,p3))){
												printf("%lld,%lld,%lld,%lld,%lld ans=%lld\n",p1,p2,p3,p4,p5,p1+p2+p3+p4+p5);
											}
							}
					}
		}
	}		
	return 0;
}
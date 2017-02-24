#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int values[256] = {};
int takings[10] = {0,1,2,3,2,1,2,3,4,2}; //比如 10 11 12 13 14 15 16 17 18 19 

int main()
{
	values['I'] = 1;
	values['V'] = 5;
	values['X'] = 10;
	values['L'] = 50;
	values['C'] = 100;
	values['D'] = 500;
	values['M'] = 1000;
	int total=0;
	FILE* file = fopen("in.txt", "rb+");
	int num=0;
	int previous = 0xffffff;
/*
VIIII -> IX  (56 x 3)		= 168
XIIII -> XIV (38 x 2)		=  76
LIIII -> LIV  (9 x 2)		=  18
CIIII -> CIV  (5 x 2)		=  10
MIIII -> MIV  (1 x 2)		=   2
 XXXX -> XL   (3 x 2)		=   6
LXXXX -> XC  (48 x 3)	    = 144
CXXXX -> CXL (34 x 2)	    =  68
DXXXX -> DXL  (6 x 2)	    =  12
MXXXX -> MXL  (4 x 2)	    =   8
 CCCC -> CD  (10 x 2)	    =  20
DCCCC -> CM  (43 x 3)	    = 129
MCCCC -> MCD (41 x 2)	    =  82

Total                        = 743
*/
	while(1)
	{
		char n;
		fread(&n, 1, 1, file);
		if (feof(file))
			break;
		num+=values[n];
		total++; //总的字母
		 
		if (previous < values[n])
			num -= previous*2;
			
		if (n=='\n') // \n = 十六进制，0x0a 
		{
			total -= num/1000+2;
			num -= (num/1000)*1000;
			
			while(num>0)
			{
				total -= takings[num%10];			
				num/=10;
			}
		}
		previous = values[n];
	}
	cout<<total<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cubes[210][10]={0};

	int total = 0;

	for (int a1=0; a1<=9; a1++) {
	for (int a2=a1; a2<=9; a2++) {
	if (a2 == a1) {	continue; }
	for (int a3=a2; a3<=9; a3++) {
	if (a3 == a1 || a3 == a2) { continue; }
	for (int a4=a3; a4<=9; a4++) {
	if (a4 == a1 || a4 == a2 || a4 == a3) { continue; }
	for (int a5=a4; a5<=9; a5++) {
	if (a5 == a1 || a5 == a2 || a5 == a3 || a5 == a4) { continue; }
	for (int a6=a5; a6<=9; a6++) {
	if (a6 == a1 || a6 == a2 || a6 == a3 || a6 == a4 || a6 == a5) { continue; }	

		cubes[total][a1] = 1;
		cubes[total][a2] = 1;
		cubes[total][a3] = 1;
		cubes[total][a4] = 1;
		cubes[total][a5] = 1;
		cubes[total][a6] = 1;
		total++;
	}}}}}}
	cout<<total<<endl; //total=210
	int x = 0;

	for (int i=0; i<total; i++){
	for (int j=i; j<total; j++)
	{
		if ((cubes[i][0] && cubes[j][1]) || (cubes[j][0] && cubes[i][1])) {	   // 01
		}
		else { continue; }
		if ((cubes[i][0] && cubes[j][4]) || (cubes[j][0] && cubes[i][4])) {	   // 04
		}
		else { continue; }
		if ((cubes[i][2] && cubes[j][5]) || (cubes[j][2] && cubes[i][5])) {	   // 25
		}
		else { continue; }		
		if ((cubes[i][8] && cubes[j][1]) || (cubes[j][8] && cubes[i][1])) {	 // 81
		}
		else { continue; }		
		
		if ((cubes[i][0] && cubes[j][9]) || (cubes[j][0] && cubes[i][9])) {	  // 09
		} 
		else if ((cubes[i][0] && cubes[j][6]) || (cubes[j][0] && cubes[i][6])) {
		}
		else { continue; }
		
		if ((cubes[i][1] && cubes[j][6]) || (cubes[j][1] && cubes[i][6])) {	    // 16
		}
		else if ((cubes[i][1] && cubes[j][9]) || (cubes[j][1] && cubes[i][9])) {
		}
		else { continue; }			
		
		if ((cubes[i][3] && cubes[j][6]) || (cubes[j][3] && cubes[i][6])) {	    // 36
		}
		else if ((cubes[i][3] && cubes[j][9]) || (cubes[j][3] && cubes[i][9])) {
		}
		else { continue; }			
		
		if ((cubes[i][4] && cubes[j][9]) || (cubes[j][4] && cubes[i][9])) {	     // 49
		}
		else if ((cubes[i][4] && cubes[j][6]) || (cubes[j][4] && cubes[i][6])) {
		}
		else { continue; }
		
		if ((cubes[i][6] && cubes[j][4]) || (cubes[j][6] && cubes[i][4])) {	    // 64	
		}
		else if ((cubes[i][9] && cubes[j][4]) || (cubes[j][9] && cubes[i][4])) {
		}
		else { continue; } 	
		x++;							
	}
}
	cout<<x<<endl;
	return 0;
}
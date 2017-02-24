#include <iostream>
#include <cmath>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;
int main()
{
   
    vector<int> Tria;
    vector<int> Squa;
    vector<int> Pent;
    vector<int> Hexa;
    vector<int> Hept;
    vector<int> Octa;
    int tr,sq,pe,hex,hep,oc;
    for (int i=10; i<200; i++)
	{
        tr=(i+1)*i/2;
        sq=i*i;
        pe=i*(3*i-1)/2;
        hex=i*(2*i-1);
        hep=i*(5*i-3)/2;
        oc=i*(3*i-2);
        if (tr>1000&&tr<10000)
		{
            Tria.push_back(tr);
        }
        if (sq>1000&&sq<10000)
		{
            Squa.push_back(sq);
        }
        if (pe>1000&&pe<10000)
		{
            Pent.push_back(pe);
        }
        if (hex>1000&&hex<10000)
		{
            Hexa.push_back(hex);
        }
        if (hep>1000&&hep<10000)
		{
            Hept.push_back(hep);
        }
        if (oc>1000&&oc<10000)
		{
            Octa.push_back(oc);
        }
    }
    
    map<int,vector<int>> M_1;
    map<int,vector<int>> M_2;
    map<int,vector<int>> M_3;
    map<int,vector<int>> M_4;
    map<int,vector<int>> M_5;
    map<int,vector<int>> M_6;
    for (vector<int>::iterator it_1=Tria.begin(); it_1!=Tria.end(); it_1++)
	{
        if (((*it_1)%100)>=10)
		{
            M_1[(*it_1)/100].push_back((*it_1)%100);
        }
    }
    for (vector<int>::iterator it_1=Squa.begin(); it_1!=Squa.end(); it_1++)
	{
        if (((*it_1)%100)>=10)
		{
            M_3[(*it_1)/100].push_back((*it_1)%100);
        }
    }
    for (vector<int>::iterator it_1=Pent.begin(); it_1!=Pent.end(); it_1++)
	{
        if (((*it_1)%100)>=10)
		{
            M_2[(*it_1)/100].push_back((*it_1)%100);
        }
    }
    for (vector<int>::iterator it_1=Hexa.begin(); it_1!=Hexa.end(); it_1++)
	{
        if (((*it_1)%100)>=10)
		{
            M_4[(*it_1)/100].push_back((*it_1)%100);
        }
    }
    for (vector<int>::iterator it_1=Hept.begin(); it_1!=Hept.end(); it_1++)
	{
        if (((*it_1)%100)>=10)
		{
            M_5[(*it_1)/100].push_back((*it_1)%100);
        }
    }
    for (vector<int>::iterator it_1=Octa.begin(); it_1!=Octa.end(); it_1++)
	{
        if (((*it_1)%100)>=10)
		{
            M_6[(*it_1)/100].push_back((*it_1)%100);
        }
    }
    vector<map<int,vector<int>>> s;
    s.push_back(M_1);
    s.push_back(M_2);
    s.push_back(M_3);
    s.push_back(M_4);
    s.push_back(M_5);
    s.push_back(M_6);
   
    long long n=0;   
    do
	{                  
    	int tem_0,tem_1,tem_2,tem_3,tem_4,tem_5,tem_6;
    	for(map<int,vector<int>>::iterator it=s[0].begin(); it!=s[0].end(); ++it)
		{
        	tem_0=it->first;
        	for(vector<int>::iterator it_2=(it->second).begin(); it_2!=(it->second).end(); it_2++)
			{
            	tem_1=*it_2;
           	    if(s[1][tem_1].size()!=0)
				{
                	for(vector<int>::iterator it_3=s[1][tem_1].begin(); it_3!=s[1][tem_1].end(); it_3++)
					{
                   		tem_2=*it_3;
                    	if(s[2][tem_2].size()!=0)
						{
                        	for(vector<int>::iterator it_4=s[2][tem_2].begin(); it_4!=s[2][tem_2].end(); it_4++)
							{
                           		 tem_3=*it_4;
                           		 if(s[3][tem_3].size()!=0)
								 {
                                	for(vector<int>::iterator it_5=s[3][tem_3].begin(); it_5!=s[3][tem_3].end(); it_5++)
									{
                                  		tem_4=*it_5;
                                  	  	if(s[4][tem_4].size()!=0)
										{
                                      	  	for(vector<int>::iterator it_6=s[4][tem_4].begin(); it_6!=s[4][tem_4].end(); it_6++)
											{
                                          	   tem_5=*it_6;
                                         	   if(s[5][tem_5].size()!=0)
												{
                                            	    for(vector<int>::iterator it_7=s[5][tem_5].begin(); it_7!=s[5][tem_5].end(); it_7++)
													{
                                               	 	    tem_6=*it_7;
                                                	    if(tem_6==tem_0)
														{
                                                   	   	  cout<<"ans="<<(tem_0+tem_1+tem_2+tem_3+tem_4+tem_5)*101<<endl;
                                                  	 	}
                                                   		else
														{
                                                      	  n++;
                                                    	}
                                                	}
                                           		}
                                        	}
                                    	}
                                	}
                            	}
                        	}
                    	}
                	}
            	}
        	}
     	}
   }while(next_permutation(s.begin(), s.end()));
    cout<<n<<endl;
    return 0;
}
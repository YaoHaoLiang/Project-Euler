#include<bits/stdc++.h>
using namespace std;
double calc (double n1, int op, double n2)
{
   switch(op)
   {
      case 0: return n1 + n2;
      case 1: return n1 - n2;
      case 2: return n1 * n2;
      case 3: return n2 != 0 ? n1 / n2 : 0;
   }
   return 0;
}

int checkint (double n)
{
   int cast = (int) n;
   int upcast = cast + 1;

   if (n < 0.5) return -1;
   else if (n - cast < 0.0001) return cast;
   else if (upcast - n < 0.0001) return upcast;
   else return -1;
}

int eval (int n1, int op1, int n2, int op2, int n3, int op3, int n4, int mode)
{
   switch (mode)
   {      
      case 1: return checkint (calc (calc (calc (n1, op1, n2), op2, n3), op3, n4));
      case 2: return checkint (calc (calc (n1, op1, n2), op2, calc (n3, op3, n4)));
      case 3: return checkint (calc (calc (n1, op1, calc (n2, op2, n3)), op3, n4));
      case 4: return checkint (calc (n1, op1, calc (calc (n2, op2, n3), op3, n4)));
      case 5: return checkint (calc (n1, op1, calc (n2, op2, calc (n3, op3, n4))));
   }
   return 0;
}


int main ()
{
   int max = 0;
   string maxstr;

   for (int d1 = '1'; d1 <= '9'; ++d1)
   {
      for (int d2 = d1 + 1; d2 <= '9'; ++d2)
      {
         for (int d3 = d2 + 1; d3 <= '9'; ++d3)
         {
            for (int d4 = d3 + 1; d4 <= '9'; ++d4)
            {
               char dstr [5] = { d1, d2, d3, d4, '\0' };

               set<int> results;
               for(int k = 1; k < 100; ++k) results.insert (k);
               
               do
               {
               	 //四个数 
                  int n1 = dstr [0] - '0';
                  int n2 = dstr [1] - '0';
                  int n3 = dstr [2] - '0';
                  int n4 = dstr [3] - '0';
               
                  for (int op1 = 0; op1 <= 3; ++op1)
                  {
                     for (int op2 = 0; op2 <= 3; ++op2)
                     {
                        for (int op3 = 0; op3 <= 3; ++op3)
                        {
                           for (int mode = 1; mode <= 5; ++mode)
                           {
                              int e = eval (n1, op1, n2, op2, n3, op3, n4, mode);
                              if(e > 0) results.erase (e);  
                           }
                        }
                     }
                  }
                  
               }while(next_permutation (dstr, dstr + 4));

               if (*results.begin () > max)
               {
               	//*results.begins : 连续项的最后一项 
               	  cout<<*results.begin()<<endl; 
                  max = *results.begin ();
                  maxstr = dstr;  //答案 
               }
            }
         }
      }
   }

   printf ("ans=%s\n", maxstr.c_str ()); //输出：1258 
   return 0;
}
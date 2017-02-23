#include<bits/stdc++.h>
/************************************************************************
 * 功能：两个大数的加法
 * 说明：a和b是两个大数，保存在字符串,如1234+789，a="1234",b="789"
 * 返回：a+b和的字符串的指针,big_add函数内部已分配空间。
 ************************************************************************/
char* big_add(char* a, char *b)
{
    char* p1 = NULL;  //指向较长的字符串
    char* p2 = NULL;  //指向较短的字符串
    char* sum = NULL; //指向和
    int len1 = 0;     //较长字符串的长度
    int len2 = 0;     //较短字符串的长度
    int acc = 0;      //加法过程中的进位
    int i,j,k,v,v1,v2;
    char* tmp = NULL;
 
    if(strlen(a)>=strlen(b))
    {
        p1 = a;
        p2 = b;
        len1 = strlen(a);
        len2 = strlen(b);
    }
    else
    {
        p1 = b;
        p2 = a;
        len1 = strlen(b);
        len2 = strlen(a);
    }
 
    //和sum
    sum = (char*)malloc(sizeof(char)*(len1+1)); //初始和较长的字符串等长。+1: \0
 
    //sum = p1
    for (i=0;i<=len1;i++)
    {
        sum[i] = p1[i];
    }
 
    //sum += p2
 
    //sum和p2低位相对应的位相加
 
    acc=0; //初始化低位的进位为0
    for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--)//i是sum的位，j是p2的位，从字符串的高位往低位，即从数字的低位往高位
    {
        v1 = (int)(sum[i]-'0');
        v2 = (int)(p2[j]-'0');
        v = v1+v2+acc;
        acc = v/10;
        sum[i] = (char)((v%10)+'0'); //模10的结果作为和sum[i]
    }
 
    //由于len1>=len2，所以跳出循环时，j == -1
    //如果此时，acc=0,即无进位，sum就是最后的和，结束
    //如果此时，acc!=0,即有进位，sum还需要加上acc
 
    //有进位
    if (acc!=0)
    {
        //i==-1，表明sum和p2同时遍历完了，两者等长，此时sum需要多加一位，存放进位acc
        if(i==-1)
        {
            tmp = (char*)malloc(sizeof(char)*(len1+2));//加:一位空白和一位\0
            for(k=0;k<=len1;k++) //tmp[1...len1] = sum[0,len-1]
            {
                tmp[k+1] = sum[k];
            }
            tmp[0] = acc+'0';               //最高位
 
            delete[] sum;
            sum = tmp;
        }
 
        //sum 还没有遍历完，此时需要对sum+=acc
        else
        {
            //此时，i指向sum将要计算的位置
            for (;i>=0;i--) //对sum继续 + 进位
            {
                v1 = sum[i]-'0';
                v = v1+acc;
                sum[i] = (v%10)+'0'; //模10的结果
                acc = v/10;          //进位
 
                if(acc ==0 )break;   //没有进位了，停止
            }
 
            //跳出循环时，要么acc==0 要么i==-1
            //若是acc=0，则sum就是最后的和
            //若是i==-1, 说明不是break跳出的，此时acc!=0,还有进位
 
            if(i == -1)  //进位
            {
                tmp = (char*)malloc(sizeof(char)*(len1+2));//加:一位空白和一位\0
                for(k=0;k<=len1;k++) //tmp[1...len1] = sum[0,len-1]
                {
                    tmp[k+1] = sum[k];
                }
                tmp[0] = acc+'0';               //最高位
 
                delete[] sum;
                sum = tmp;
            }
        }
    }
    return sum;
}
int main()
{
	char* a = NULL;
	char* b = NULL;
	char* c =NULL;
	int term=2;
 
	a = (char*)malloc(sizeof(char)*2); //使用malloc是为了后面的delete一致
	b = (char*)malloc(sizeof(char)*2);
	a[0] = '1';a[1]='\0';
	b[0] = '1';b[1]='\0';
 
	while (1)
	{
    	c = big_add(a,b);
    	term ++;
    	if(strlen(c) == 1000)
    	{
        	printf("%d\n%s\n",term,c);//输出结果
        	delete[] c;
        	break;
    	}
    	delete[] a;
    	a = b;
    	b = c;
	}
	return 0;
 } 
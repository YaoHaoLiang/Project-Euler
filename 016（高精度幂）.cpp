#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
#define MAX 3410
typedef long long LL;
const double pi=3.141592653589793;
const int INF=1e9;
const double inf=1e20;
const double eps=1e-6;
//高精度加法
string add(string str1,string str2)//高精度加法
{
    string str;

    int len1=str1.length();
    int len2=str2.length();
    //前面补0，弄成长度相同
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}
//高精度乘法
string mul(string str1,string str2)
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    string tempstr;
    for(int i=len2-1;i>=0;i--)
    {
        tempstr="";
        int temp=str2[i]-'0';
        int t=0;
        int cf=0;
        if(temp!=0)
        {
            for(int j=1;j<=len2-1-i;j++)
              tempstr+="0";
            for(int j=len1-1;j>=0;j--)
            {
                t=(temp*(str1[j]-'0')+cf)%10;
                cf=(temp*(str1[j]-'0')+cf)/10;
                tempstr=char(t+'0')+tempstr;
            }
            if(cf!=0) tempstr=char(cf+'0')+tempstr;
        }
        str=add(str,tempstr);
    }
    str.erase(0,str.find_first_not_of('0'));
    if(str.empty()) str="0";
    return str;
}
int main(){
	string s;
	int n,flag;
	while(cin>>s>>n){   //s^n 
		flag=0;
		string s1,s2,s3,s4;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='.'){
				flag=1;
				continue;
			}
			if(!flag) s1+=s[i];
			if(flag) s2+=s[i];			
		}
		int len1=s2.size();
		len1=len1*n;
		s3=s1+s2;
		s4=s3;
		for(int i=0;i<n-1;i++){
			s4=mul(s4, s3);
		}
		int len2=s4.size();
		string s5,s6,s7;
		if(len2>=len1){
			for(int i=len2-1;i>=len2-len1;i--) s5=s4[i]+s5;
			for(int i=len2-len1-1;i>=0;i--) s6=s4[i]+s6;
		}
		else{
			for(int i=len2-1;i>=0;i--) s5=s4[i]+s5;
			for(int i=0;i<len1-len2;i++) s5='0'+s5;
		}
		s6.erase(0,s6.find_first_not_of('0'));
		int len3=s5.size();
		int f=0;
		for(int i=len3-1;i>=0;i--){
			if(!f&&s5[i]=='0') continue;
			if(s5[i]!='0') f=1;
			if(f) s7=s5[i]+s7;
		}
		if(s7.empty()) cout<<s6<<endl;
		else cout<<s6<<'.'<<s7<<endl;
		//------------------------------//
		int ans=0;
		for(int i=0;i<s6.size();i++)
		{
			ans+=s6[i]-'0';
		}
		cout<<ans<<endl;
	}
	return 0;
}

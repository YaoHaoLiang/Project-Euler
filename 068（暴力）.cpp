#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int ans[15] = {0};
    vector<int>answer(ans,ans+15);

    int ngon[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int>s(ngon,ngon+10);
    do
    {
        int S = s[0] + s[1] + s[4];
        if(s[2] + s[4] + s[7] != S)continue;
        if(s[8] + s[7] + s[6] != S)continue;
        if(s[9] + s[6] + s[3] != S)continue;
        if(s[5] + s[3] + s[1] != S)continue;
        if(s[0] != min(s[0],s[2]))continue;
        if(s[0] != min(s[0],s[8]))continue;
        if(s[0] != min(s[0],s[9]))continue;
        if(s[0] != min(s[0],s[5]))continue;

    int ans2[15] = {s[0],s[1],s[4],s[2],s[4],s[7],s[8],s[7],s[6],s[9],s[6],s[3],s[5],s[3],s[1] };
    vector<int>answer2(ans2,ans2+15);
    if(answer2>answer)
    answer=answer2;
    }while(next_permutation(s.begin(),s.end()));
    
    for(int i=0;i<15;i++)
        cout <<answer[i];
        cout<<endl;
    return 0;
}
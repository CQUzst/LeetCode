/* 小Q正在给一条长度为n的道路设计路灯安置方案。

为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。

小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。

小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。
*/
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(s[i-1]=='.'){
                cnt++;
                s[i-1]='X';
                s[i]='X';
                s[i+1]='X';
            }
        }
        if(s[n-1]=='.'||s[n-2]=='.')
            cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}

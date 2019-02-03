//报数功能，将相邻重复字符串用数字放在前面表示重复n次，比如aaaa 输出4a
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while (cin>>s) {
        string res("");
        int count=1;
        if(s.size()==1){
            cout<< to_string(count)+s[0];
        }
        else{
            for(int i=0;i<s.size();i++){
                if(i<s.size()-1)
                    if(s[i]==s[i+1]){
                        count++;
                        continue;
                    }
                if(count==1&&s[i]!=s[i+1]){
                    res+=to_string(count)+s[i];
                    continue;
                }
                if(i==s.size()-1&&count==1)
                    res+=to_string(count)+s[i];
                res+=to_string(count)+s[i];
                count=1;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}

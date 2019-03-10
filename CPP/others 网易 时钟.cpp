#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s[0]-'0'>2){
            s[0]='0';
        }
        if(s[0]=='2'&&s[1]-'3'>0){
            s[0]='0';
        }
        if(s[3]>'5'){
            s[3]='0';
        }
        if(s[6]>'5'){
            s[6]='0';
        }
        cout<<s<<endl;
    }
    return 0;
}


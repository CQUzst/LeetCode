#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//将Z字符转回10输出
string exange(string s1){
    for(int i=0;i<s1.size()-1;i++){
        if(s1[i]=='Z'){
            s1[i]='1';
            s1.insert(i+1,"0");
        }
    }
    return s1;
}

int main(){
    string input;
    map<string,int> m;
    m.insert(pair<string,int>("3",1));
    m.insert(pair<string,int>("4",2));
    m.insert(pair<string,int>("5",3));
    m.insert(pair<string,int>("6",4));
    m.insert(pair<string,int>("7",5));
    m.insert(pair<string,int>("8",6));
    m.insert(pair<string,int>("9",7));
    m.insert(pair<string,int>("Z",8));
    m.insert(pair<string,int>("J",9));
    m.insert(pair<string,int>("Q",10));
    m.insert(pair<string,int>("K",11));
    m.insert(pair<string,int>("A",12));
    m.insert(pair<string,int>("2",13));
    m.insert(pair<string,int>("joker",14));
    m.insert(pair<string,int>("JOKER",15));

    while(getline(cin,input)){
        if(input.size()==0) break;
        //把10替换成Z方便后面单字符比较
        for(int i=0;i<input.size()-1;i++){
            if(input[i]=='1'&&input[i+1]=='0'){
                input.erase(i+1,1);
                input[i]='Z';
            }
        }
        //分割左右字符串
        string left,right;
        int t=input.find('-');
        left=input.substr(0,t);
        right=input.substr(t+1);
        //字符串大小相同说明是同类型牌，比较第一个字符大小即可
        if(left.size()==right.size()){
            string s1=left.substr(0,1);
            string s2=right.substr(0,1);
            if(m[s1]>m[s2]){
                left=exange(left);
                cout<<left<<endl;
                continue;
            }
            else{
                right=exange(right);
                cout<<right<<endl;
                continue;
            }
        }
        else if(left=="joker JOKER"||right=="joker JOKER"){
            cout<<"joker JOKER"<<endl;
            continue;
        }
        //炸弹处理
        else if(left.size()==7){
            left=exange(left);
            cout<<left<<endl;
        }
        else if(right.size()==7){
            right=exange(right);
            cout<<right<<endl;
        }
        else{
            cout<<"ERROR"<<endl;
        }
    }
}

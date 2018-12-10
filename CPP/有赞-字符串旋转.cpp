#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(cin>>str){
        string s1(""),s2("");
        int index=0;
        for(size_t i=0;i<str.size();i++){
            if(str[i]==';'){
                index=i+1;
                break;
            }
            s1+=(str[i]);
        }
        for(size_t i=index;i<str.size();i++){
            s2+=(str[i]);
        }
        if(s1.size()!=s2.size())
        {
            cout<<"false";
            break;
        }
        bool trueFlag=0;
        for(size_t i=0;i<s1.size();i++){
            string firstS(s1.substr(i,s1.size()-i));
            string secondS(s1.substr(0,i));
            string tempS=firstS+secondS;
            if(tempS==s2)
                trueFlag=1;
        }
        if(trueFlag)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
//        bool trueFlag=0;
//        for(int i=0;i<s1.size();i++){
//            char temp=s1[0];
//            for(int j=1;j<s1.size();j++){
//                s1[j-1]=s1[j];
//            }
//            s1[s1.size()-1]=temp;
//            if(s1==s2){
//                trueFlag=1;
//                cout<<"true";
//                break;
//            }
//        }
//        if(!trueFlag)
//        cout<<"false";
    }
    return 0;
}

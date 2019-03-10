#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector <int> session;
        while(N--){
            int num;
            cin>>num;
            session.push_back(num);
        }
        reverse(session.begin(),session.end());
        vector<int> res;
        /*
        for(int i=0;i<session.size();i++){
            int flag=1;
            for(int j=0;j<res.size();j++){
                if(res[j]==session[i]){
                    flag=0;
                }
            }
            if(flag)
                res.push_back(session[i]);
        }
        */
        vector<int>::iterator it;
        for(int i=0;i<session.size();i++){
            it=find(res.begin(),res.end(),session[i]);
            if(it==res.end()){
                res.push_back(session[i]);
            }
        }
        for(int i=0;i<res.size()-1;i++){
            cout<<res[i]<<" ";
        }
        cout<<res[res.size()-1];
        cout<<endl;
    }
}

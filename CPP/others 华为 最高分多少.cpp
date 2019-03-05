#include <iostream>
#include <vector>
using namespace std;
int getMax(vector<int>vec,int A,int B){
    int a=min(A,B);
    int b=max(A,B);
    int res=vec[a-1];
    for(int i=a-1;i<b;i++){
        if(res<vec[i])
            res=vec[i];
    }
    return res;
}
int main(){
    int M,N;
    while(cin>>N>>M){
        vector<int> vec;
        while(N--){
            int score;
            cin>>score;
            vec.push_back(score);
        }
        while(M--){
            char c;
            int A,B;
            cin>>c>>A>>B;
            if('Q'==c){
                int maxNum=getMax(vec,A,B);
                cout<<maxNum<<endl;
            }
            else if('U'==c){
                vec[A-1]=B;
            }
        }
        vec.clear();
    }
    return 0;
}

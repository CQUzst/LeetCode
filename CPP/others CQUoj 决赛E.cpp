//FLOYD
#include <iostream>
#include <vector>
#include <algorithm>
int map[10004][10004];
int path[10004][10004];
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<=t+1;i++){
        for(int j=0;j<=t+1;j++){
            map[i][j]=99999;
        }
    }
    int a,b;
    for(int i=2;i<=t;i++){
        cin>>a>>b;
        map[i][a]=b;
        map[a][i]=b;
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=t;j++){
            for(int k=1;k<=t;k++){
                if(map[i][j]>map[i][k]+map[k][j]){
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }
    for(int i=1;i<=t;i++)
        for(int j=1;j<=t;j++)
            if(i==j)
                map[i][j]=0;
//    for(int i=1;i<=t;i++){
//        for(int j=1;j<=t;j++){
//            cout<<map[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(int i=1;i<=t;i++){
        int maxN=-1;
        for(int j=1;j<=t;j++){
            if(maxN!=99999&&maxN<map[i][j])
                maxN=map[i][j];
        }
        cout<<maxN<<endl;
    }
    return 0;
}

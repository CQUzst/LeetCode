#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

float slide(pair<int,int>a,pair<int,int>b){
    int deltaY= a.second-b.second;
    int deltaX=a.first-b.first;
    if(deltaX==0) return INT_MAX;
    return deltaY/(1.0*deltaX);
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>points;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }

    int count=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                if(slide(points[i],points[j])!=slide(points[j],points[k])){
                    count++;
                }
            }
        }
    }
    cout<<count;
    system("pause");
    return 0;
}

/*
 *  牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;
//t表示第i个零食，sum是背包已占体积
void dfs(LL t,LL sum,LL n,LL w,LL &res,vector<LL> v){
    res++;
    if(t==n-1)//零食全放满，返回
        return;
    for(LL i=t+1;i<n;i++){//遍历判断每种零食放入，然后进入递归即可
        if(sum+v[i]<=w){
            dfs(i,sum+v[i],n,w,res,v);
        }
    }
}

int main(){
    LL n,w;
    cin>>n>>w;
    vector<LL> v;
    LL num,sum=0;
    for(LL i=0;i<n;i++){
        cin>>num;
        sum+=num;
        v.push_back(num);
    }
    if(sum<=w){//所有体积和小于容积，直接返回2的次方
        cout<<(1<<n)<<endl;
        return 0;
    }

    LL res=0;
    dfs(-1,0,n,w,res,v);//递归产生所有可能结果，从-1开始是因为总体积为0也算一种放法
    cout<<res<<endl;
    return 0;
}

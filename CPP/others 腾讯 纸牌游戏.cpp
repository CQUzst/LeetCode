//牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
//牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
//他们的得分等于他们抽到的纸牌数字总和。
//现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。
//输入包括两行。
//第一行包括一个正整数n(1 <= n <= 105),表示纸牌的数量。
//第二行包括n个正整数ai(1 <= ai <= 109),表示每张纸牌上的数字。
//3
//2 7 4
//5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,a_i;
    cin>>n;
    vector <int> vec;
    while(n--){
        cin>>a_i;
        vec.push_back(a_i);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    long sum=0;
    int flag=1;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i]*flag;
        if(flag==1)
            flag=-1;
        else if(flag==-1)
            flag=1;
    }
    cout<<sum<<endl;
    return 0;
}

//问题描述：
//小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，
//每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。 
//输入描述:
//每个输入包含一个测试用例。
//每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
//接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。
//输出描述:
//输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。
//示例1
//输入
//5
//2 3 3 3
//输出
//9
#include <iostream>
using namespace std;
int main(){
    int k,a,x,b,y;
    cin>>k;
    cin>>a>>x>>b>>y;
    const int mod=1000000007;
    long long dp[104][104];//第一维是排列的下标，第二维是排列的上标
    //初始化组合表,即C(i,j),i中选j个元素组合的个数
    dp[0][0]=1;
    for(int i=1;i<101;i++){
        dp[i][0]=1;
        for(int j=1;j<101;j++){
            if(j>i)//不存在j>i的情况
                break;
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
    long long res=0;
    for(int i=0;i<=x;i++){
        //a类的个数i*a长度要小于k，且余数要可以被b整除，且y的个数要够
        if(i*a<=k&&(k-i*a)%b==0&&(k-i*a)/b<=y){
            res=(res+dp[x][i]*dp[y][(k-i*a)/b])%mod;
        }
    }
    cout<<res<<endl;
    return 0;
}

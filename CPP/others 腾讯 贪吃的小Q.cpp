//小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，
//但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力
//每个输入包含一个测试用例。
//每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。
//输出一个数表示小Q第一天最多能吃多少块巧克力。
//3 7
//4
#include <iostream>
#include <cmath>
using namespace std;
int isRight(int n, int m, int maxNum){
    while(n && m && maxNum != 1){
        n--, m -= maxNum;
        if(m < n) //剩下的巧克力数小于天数，不够吃了，false
            return false;
        maxNum = ceil(maxNum / 2.0);//max向上取整
    }
    return true;
}
int main(){
    int n, m, maxNum;
    cin >> n >> m;
    for(maxNum = m; ; maxNum--) //从最大开始一个个往小试
        if(isRight(n, m, maxNum))
            break;
    cout << maxNum << endl;
    return 0;
}

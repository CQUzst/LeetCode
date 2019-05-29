/* 小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

并且小Q对于能否被3整除这个性质很感兴趣。

小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
*/
//数学规律：一个数能被3整除的等价情况就是这个数的各个位上的数的和能被3整除
//转化为sum（x）%3
#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ll a,b,ans=0;
    cin >> a >> b;
    for(ll i=a;i<=b;i++){
        if((i*(i+1)/2)%3==0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

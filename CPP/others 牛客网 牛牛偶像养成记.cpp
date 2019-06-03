#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
    int start, ed;
};
node a[maxn];
 //先按结束时间升序，相同结束时间的情况下选更早还是更晚对结果没影响
bool cmp(node x,node y) {
    return x.ed<y.ed;
//    if(x.ed != y.ed)
//        return x.ed < y.ed;
//    else
//        return x.start < y.start;//or x.start > y.start
}
int main() {
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].start >> m;
        a[i].ed = a[i].start + m;
    }
    sort(a, a + n, cmp);
    int ans = 0, t = 0;
    for(int i = 0; i < n; i++) {
        if(t <= a[i].start) {
            ans++;
            t = a[i].ed;
        }
    }
    cout << ans << endl;
    return 0;
}

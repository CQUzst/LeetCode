//给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：

//区间中的最小数 * 区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出具体的区间。
//如给定序列  [6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:
//https://www.nowcoder.com/questionTerminal/e6e57ef2771541dfa2f1720e50bebc9a
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x[n];
    for (int i=0; i<n; i++)
        cin>>x[i];
    int max=0;
    for (int i=0; i<n; i++){
        int right=i;
        int left=i-1;
        int sum=0;
        while(x[i]<=x[right] && right<n){
            sum+=x[right];
            right++;
        }
        while(x[i]<=x[left] && left>=0){
            sum+=x[left];
            left--;
        }
        int temp=sum;
        if (x[i]*temp>max)
            max=x[i]*temp;
        
    }
    cout << max << endl;
    
    return 0;
}

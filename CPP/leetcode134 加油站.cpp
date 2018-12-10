#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //自己的解法 18min 33%
        // int res=-1,len=gas.size();
        // bool OKflag=0;
        // for(int startIndex=0;startIndex<len&&!OKflag;startIndex++){
        //     int startGas=gas[startIndex];
        //     int index=startIndex;
        //     for(int step=0;step<len;){
        //         if(startGas>=cost[index]){
        //             step++;
        //             startGas=startGas-cost[index];
        //             index++;
        //             if(index>=len)//尾部循环到前面
        //                 index=0;
        //             startGas+=gas[index];
        //         }
        //         else
        //             break;
        //         if(step>=len){
        //             res=startIndex;
        //             OKflag=1;
        //             break;
        //         }
        //     }
        // }
        // return res;


        int rest=0;
        int start=0;
        int remain=0;

        //负增长说明这段路程肯定通不过，从后面开始比前面开始好
        //根据是否正增长来得到开始位置，并且将负增长前面的消耗算出来
        //算出油量之和-消耗之和去判断有没有可能绕一圈
        for(int i=0;i<gas.size();i++){
            remain+=gas.at(i)-cost.at(i);
            if(remain<0){
                //不是正增长则从下一个位置开始判断
                rest+=remain;
                remain=0;
                start=i+1;
            }
        }

        return ((rest+remain)>=0) ? start : -1;
    }
}s;
int main(){
    int gas[]={1,2,3,4,5};
    int cost[]={3,4,5,1,2};
    vector<int> vecGas(gas,gas+5);
    vector<int> vecCost(cost,cost+5);
    int res=s.canCompleteCircuit(vecGas,vecCost);
    cout<<res;
    return 0;
}

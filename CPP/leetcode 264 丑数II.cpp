
class Solution {
public:
    
/*动态规划思想。后面的丑数一定是由前面的丑数乘以2、3或5得到
第n个丑数一定是由前n-1个数中的某3个丑数（分别记为index2、index3、index5）分别乘以2、3或者5得到的数中的最小数
index2，index3，index5有个特点，即分别乘以2、3、5得到的数一定含有比第n-1个丑数大（可利用反证法：否则第n-1个丑数就是它们当中的一个）
最小丑数，即第n个丑数由u[index2]*2、u[index3]*3、u[index5]*5中的最小数得出
让它们分别和第n个丑数比较，若和第n个丑数相等，则更新它们的值。注：一次最少更新一个值（如遇到第n个丑数是6时，index2和index3都要更新）。*/
    int nthUglyNumber(int n) {
        int *res=new int[n];
        res[0]=1;
        int index2=0;
        int index3=0;
        int index5=0;
        int k=1;
        while(k<n){
            res[k]=min(res[index2]*2,res[index3]*3,res[index5]*5);
            if(res[index2]*2==res[k])
                index2++;
            if(res[index3]*3==res[k])
                index3++;
            if(res[index5]*5==res[k])
                index5++;
            k++;
        }
        return res[n-1];
    }
    int min(int a,int b,int c){
        return a>b?(b<c?b:c):(a<c?a:c);
    }
};


//超时
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         vector<int> vec;
//         int i=1;
//         while(vec.size()<n){
//             if(isUglyNumber(i))
//                 vec.push_back(i);
//             i++;
//         }
//         return vec[n-1];
//     }
// private:
//      bool isUglyNumber(int i){
//          if(i==0) return false;
//          if(i==1) return true;
//          if(i%2==0) return isUglyNumber(i/2);
//          else if(i%3==0) return isUglyNumber(i/3);
//          else if(i%5==0) return isUglyNumber(i/5);
//          else return false;
//      }
// };
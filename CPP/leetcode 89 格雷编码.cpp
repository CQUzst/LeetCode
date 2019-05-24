class Solution {
public:
    vector<int> grayCode(int n) {
        //方法一：递归，会超时
        //方法二：自底向上，递归改循环
//         vector<int> res;
//         if(n == 0 || n ==1){
//             for(int i =0;i<=n;i++)
//                 res.push_back(i);
//             return res;
//         } 

//         res.push_back(0);
//         res.push_back(1);
        
//         for(int i = 2;i<=n;i++){
//             vector<int> temp = res;
//             reverse(temp.begin(),temp.end());
//             for(auto t :temp)
//                 res.push_back(t + pow(2,i-1));
//         }
        
//         return res;
        //方法三：公式
        //二进制码转换成二进制格雷码，其法则是保留二进制码的最高位作为格雷码的最高位
        //而次高位格雷码为二进制码的高位与次高位相异或
        vector<int> res;
        for(int i=0;i<pow(2,n);i++)
            res.push_back( i^(i>>1) );
        return res;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        int array[128]={0};
        int res=0;
        for(int i=0;i<s.size();i++)
            array[s[i]]++;//哈希表一一映射
        
        bool flag=false;//判断中间字符
        for(int j=0;j<128;j++){
            if(array[j]%2==0)//相同字符为偶数，必可以成为回文串，直接加字符个数
                res+=array[j];
            else{
                if(array[j]>=1)//注意是else，所以是奇数，3，5，7等等中可用2，4，6个。。。只要有一个奇数，就可以放中间，res后面要+1
                {
                    res+=array[j]-1;
                    flag=true;
                }
            }  
        }
        if(flag) res++;
        return res;
    }
};
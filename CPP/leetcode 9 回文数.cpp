class Solution {
public:
    bool isPalindrome(int x) {
        // string str = to_string(x);//将int转换成string
        // for(int i=0;i<str.size()/2;i++)
        // {
        //     if(str[i]!=str[str.size()-i-1])
        //         return false;
        // }
        // return true;
        
        if(x < 0)//负数直接返回false
            return false;
        int y = x;
        long long ans = 0;
        while(x)//逐位取反
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if(y == ans)
            return true;
        else
            return false;
    }
};
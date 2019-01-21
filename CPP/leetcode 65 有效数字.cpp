class Solution {
public:
    bool isNumber(string s) {
        //int index = 0;
        // if( !s.empty())//字符串去空格
        //     while((index = s.find(' ',index)) != string::npos) s.erase(index,1);
        
        // 跳过前导空格
        int i=0;
        for( ; i < s.size() && ' ' == s[i]; ++ i);
        // 处理正负号
        if('+' == s[i] || '-' == s[i]) ++i;
        //处理后面数字部分
        bool digit = false, dot = false, exp = false;
        for( ; i < s.size(); ++ i){
            if('.' == s[i] && !dot) // '.'不能出现2次，'.'前面能够没有数字
                dot = true;
            else if('e' == s[i] && !exp && digit) // 'e'不能出现2次，'e'前面必须有数字
            {
                // e后面不能出现.了，只是整数（能够是正的或负的）
                dot = exp = true;
                if(i + 1 < s.size() && ('+' == s[i + 1] || '-' == s[i + 1]))//如果有符号将符号加上
                    ++ i;
                if(i + 1 >= s.size() || !(s[i + 1] >= '0' && s[i + 1] <= '9'))//判断e后面是否越界，或者是否非数字
                    return false;
            }
            else if(s[i] >= '0' && s[i] <= '9')
                digit = true;
            else
                break;
        }
        //跳过后面空格
        for( ; i < s.size() && ' ' == s[i]; ++ i);
        return digit&&i==s.size();
    }
};

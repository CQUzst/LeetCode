class Solution {
public:
    bool isMatch(string s, string p) {

        //- 若p为空，若s也为空，返回true，反之返回false
        if (p.empty()) //p空了就没有东西匹配s了，这时候s空了返回正确，s没空p也没东西匹配了，返回false
            return s.empty();
        
        //- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false
        if (p.size() == 1) //字符模式只有1个字符
        {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));//s必须也只有1个，s0和p0必须相等，或者p0=.
        }
        
        //- 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配
        if (p[1] != '*') 
        {
            if (s.empty())//*可以代表空，s空了，p没有东西能匹配空
                return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));//s0和p0必须相等，或者p0=.，并且从第二个位置开始递归
        }
        
        //- 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) 
        {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        //- 返回调用递归函数匹配s和去掉前两个字符的p的结果*/
        return isMatch(s, p.substr(2));
 
    }
};
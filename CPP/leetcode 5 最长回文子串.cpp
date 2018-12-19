class Solution {
public:
    string longestPalindrome(string s)
    {
       if(s.empty() || s.size() == 1)
            return s;

        int left, right, len = 0, start = 0;
        //遍历每一个位置
        for(int i = 0; i < s.size(); ++i)
        {
            left = right = i;

            while(right < s.size() - 1 && s[right+1] == s[right]) right++;//有两个一样的right直接+1
            while(left > 0 && right < s.size() - 1 &&s[left-1] == s[right+1])//当前位置左边和右边相等，左减右加，一直循环，直到把当前位置的回文字符串全找完
            {
                left--;
                right++;
            }
            if(len < right - left + 1)//更新最大长度和起点
            {
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};
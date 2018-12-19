class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {      
         //建立一个256位大小的整型数组来代替哈希表，ASCII表共能表示256个字符
         int m[256] = {0}, res = 0, left = 0;
         for (int i = 0; i < s.size(); ++i)
         {
             //如果哈希表中该字符串对应的值为0，说明没有遇到过该字符
             //m[s[i]] < left说明当前位置的字符之前保存过，但是不在滑动窗口内，那么就没事，当前字符可以加进来
            if (m[s[i]] == 0 || m[s[i]] < left)
            {
                 res = max(res, i - left + 1);
            } 
            else //当前字符前面有保存，而且就在滑动条内部，将当前字符设置为起始位置，最大值前面已经保存过了
            {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
    return res;
        
        // vector<int> dic(256, -1);
        // int st = -1, res = 0;
        // for (int i = 0; i < s.size(); i ++)
        // {
        //     if (st < dic[s[i]]) 
        //         st = dic[s[i]];//如果第i个字符代表的号之前出现过，st更新
        //     dic[s[i]] = i;//字符串代表的ASC号置i
        //     res = max(res, i - st);
        // }
        // return res;
    }
};
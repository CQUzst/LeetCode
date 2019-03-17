class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || t.size() > s.size()) return "";
        string ans = "";
        int cnt = 0, left = 0, right = 0, minLen = s.size() + 1;
        unordered_map<char, int> myMap;

        for (int i = 0; i < t.size(); ++i) {
            if (myMap.count(t[i])) 
                ++myMap[t[i]];
            else 
                myMap[t[i]] = 1;
        }

        for (; right < s.size(); ++right) {
            if (myMap.count(s[right])) {
                --myMap[s[right]];
                // 这里，如果 < 0，说明窗口内该字符的计数已经超过 t 中含有的，因此不需要再 ++cnt
                if (myMap[s[right]] >= 0) 
                    ++cnt; 
                while(cnt == t.size()) 
                {
                    if (right - left + 1 < minLen) 
                    {
                        minLen = right - left + 1;
                        ans = s.substr(left, minLen);
                    }
                    
                    // 我们要准备往右滑动左边界了，所以要看看左边界是不是包含了t里面的字符
                    if (myMap.count(s[left])) { 
                        ++myMap[s[left]];
                        //如果 < 0，说明窗口内该字符的计数已经超过t中个数，因此不需要再++cnt
                        if (myMap[s[left]] > 0)
                            --cnt;
                    }
                    ++left;
                }
            }
        }
        return ans;
    }
};

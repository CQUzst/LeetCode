class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12) 
            return res;
        vector<string> path;
        helper(s, res, path, 0);
        return res;
    }
    void helper(const string& s, vector<string>& res, vector<string> path, int start) {
        if (start > s.size() || path.size() > 4)
            return;
        if (start == s.size() && path.size() == 4) 
        {
            res.push_back(path[0] + '.' + path[1] + '.' + path[2] + '.' + path[3]);
            return;
        }
        for (int i = 1; i <= 3; i++)//子串一次性最多放入3个字符
        {
            string sub = s.substr(start, i);
            //过滤非法情况：子串为空非法，0开头的整数数字非法（0合法），大于255非法
            if (sub.size() == 0 || (sub.size() > 1 && sub[0] == '0') || stoi(sub) > 255) 
                continue;
            path.push_back(sub);
            helper(s, res, path, start + i);
            path.pop_back();
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
//         if (strs.size() == 0)
//           return "";
//         string prefix = strs[0];
//         for (int i = 1; i < strs.size(); ++i){
//             if (prefix.length() == 0 || strs[i].length() == 0)
//                  return "";
//             int len=0;
//             if(prefix.length() < strs[i].length())
//                 len=prefix.length();
//             else
//                 len=strs[i].length();
//             int j=0;
//             for (; j < len; ++j)
//             {
//                 if (prefix[j] != strs[i][j])
//                     break;
//             }
//             //获得字符串s中 从第0位开始的长度为j的字符串
//             prefix = prefix.substr(0,j);
//         }
        
//         return prefix;
        if(strs.size()==0)
            return string("");
        
        sort(strs.begin(),strs.end());
        string first=strs[0], last=strs[strs.size()-1];
        string res;
        for(int i=0; i<first.size() && i<last.size(); i++){
            if(first[i] == last[i])
                res+=first[i];
            else
                return res;
        }
        return res;
    }
};
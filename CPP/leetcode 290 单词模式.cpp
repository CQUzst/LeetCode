class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        string s1("");
        str+=' ';
        for(int i=0;i<str.size();i++){
            if(str[i]!=' '){
                s1+=str[i];
            }
            else{
                strs.push_back(s1);
                s1="";
            }
        }
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        if(pattern.size()!=strs.size())
            return false;
        for(int i=0;i<pattern.size();i++){
            if(m1.find(pattern[i])==m1.end())
                m1[pattern[i]]=strs[i];
            if(m2.find(strs[i])==m2.end())
                m2[strs[i]]=pattern[i];
            if(m1[pattern[i]]!=strs[i]||m2[strs[i]]!=pattern[i])
                return false;
        }
        return true;
    }
};
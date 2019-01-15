class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.length()<needle.length())
            return -1;
        for(int i=0;i<=haystack.length()-needle.length();++i){
            for(int j=0;j<needle.length();++j){
                if(haystack[i+j]!=needle[j])
                    break;
                if(j==needle.length()-1)  //needle到底了   
                    return i;
            }
        }
        return -1;       
    }
};
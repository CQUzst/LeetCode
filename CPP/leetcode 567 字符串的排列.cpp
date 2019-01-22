class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //几乎超时
        // if(s1.size()>s2.size())
        //     return false;
        // sort(s1.begin(),s1.end());
        // for(int j=0;j<=s2.size()-s1.size();j++){
        //     string s3=s2.substr(j,s1.size());
        //     sort(s3.begin(),s3.end());
        //     if(s1==s3)
        //         return true;
        // }
        // return false;
        
//         //滑动窗口解法
        int n1=s1.size(),n2=s2.size();
        vector<int>c1(26),c2(26);
        for(auto c:s1)
            c1[c-'a']++;
         
        for(int i=0;i<n2;i++)
        {
            if(i>=n1)
                --c2[s2[i-n1]-'a'];//删除左边界的字符
            c2[s2[i]-'a']++;//加入右边界字符
            if(c1==c2)//vector是可以比较的，std已经重载
                return true;
        }
        return false;
        
        
        // //哈希表加上双指针
        // //用一个变量cnt来表示还需要匹配的s1中的字符的个数，初始化为s1的长度
        // int n1 = s1.size(), n2 = s2.size(), cnt = n1, left = 0;
        // vector<int> m(128);
        // for (char c : s1) ++m[c];
        // //遍历s2中的字符，如果该字符在哈希表中存在，说明匹配上了，cnt自减1，哈希表中的次数也应该自减1
        // for (int right = 0; right < n2; ++right) {
        //     if (m[s2[right]]-- > 0) 
        //         --cnt;
        //     //然后如果cnt减为0了，说明s1的字符都匹配上了，如果此时窗口的大小正好为s1的长度，那么说明找到了s1的全排列，返回true
        //     while (cnt == 0) {
        //         if (right - left + 1 == n1) 
        //             return true;
        //         //否则说明窗口过大，里面有一些非s1中的字符，我们将左边界右移，同时将移除的字符串在哈希表中的次数自增1,cnt自增1
        //         else if (++m[s2[left++]] > 0) 
        //             ++cnt;
        //     }
        // }
        // return false;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int wordsNumber=words.size(),wordsLength=words[0].size();
        unordered_map<string,int> m1;//建立map映射，将words放入map中，并标记每个words数量
        for(int i=0;i<wordsNumber;i++)
            m1[words[i]]++;
        if(s.size()<wordsLength*wordsNumber) return res;
        //j要小于等于，如果s的size等于length*number那j<0了
        //注意这里的s.size()是unsigned int，要强制转换为int，不然uint-int会转换为uint
        for(int j=0;j<=(int)s.size()-wordsLength*wordsNumber;j++){
            unordered_map<string,int> m2;
            int k=0;
            for(;k<wordsNumber;k++){
                string subS=s.substr(j+k*wordsLength,wordsLength);
                if(m1.find(subS)==m1.end()) break;//找出给定单词长度的子串，看其是否在第一个哈希表里
                m2[subS]++;//如果没有，则break，如果有，则加入第二个哈希表
                if(m2[subS]>m1[subS])break;//相同的词只能出现一次，如果多了，也break
            }
            if(wordsNumber==k)res.push_back(j);
        }
        return res;
    }
};



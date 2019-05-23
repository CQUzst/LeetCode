class Solution {
public:
    string reverseWords(string s) {
        // if(s.size()<=1)
        //     return s;
        // vector<string> vec;
        // string tmp;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]==' '){
        //         vec.push_back(tmp);
        //         tmp="";
        //     }
        //     else if(i==s.size()-1){
        //         tmp+=s[i];
        //         vec.push_back(tmp);
        //     }
        //     else
        //         tmp+=s[i];
        // }
        // string res="";
        // for(int i=0;i<vec.size()-1;i++){
        //     reverse(vec[i].begin(),vec[i].end());
        //     res+=vec[i];
        //     res+=" ";
        // }
        // reverse(vec[vec.size()-1].begin(),vec[vec.size()-1].end());
        // res+=vec[vec.size()-1];
        // return res;
        int start=0,end=0,n=s.size();
        while(start<n&&end<n){
            while(end<n&&s[end]!=' ')//子串end增加
                end++;
            for(int i=start,j=end-1;i<j;i++,j--){
                swap(s[i],s[j]);
            }
            start=++end;
        }
        return s;
    }
};

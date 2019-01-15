class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;

        mytolower(s);
        string s1("");
        for(int i=0;i<s.size();i++)
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
                s1+=s[i];
        int left=0,right=s1.size()-1;
        while(left<right){
            if(s1[left++]!=s1[right--])
                return false;
        }
        return true;
    }
private:
    void mytolower(string& s){    
        int len=s.size();    
        for(int i=0;i<len;i++){   
            if(s[i]>='A'&&s[i]<='Z'){    
                s[i]+=32;//+32转换为小写   
                //s[i]=s[i]-'A'+'a';        
            }    
        }
    }
};
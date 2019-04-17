class Solution {
    public int lengthOfLongestSubstring(String s) {
        //开辟一个 hash 数组来存储该字符上次出现的位置
        //比如 hash[a] = 3 就是代表 a 字符前一次出现的索引在 3
        //遍历该字符串，获取到上次出现的最大索引
        int len=s.length();
        if(s==null||len==0)
            return 0;
        
        int pre=0,max=0;
        int [] hash=new int[128];
        for(int i=0;i<len;i++){
            char c=s.charAt(i);
            if(hash[c]>pre)
                pre=hash[c];
            int l=i-pre+1;
            hash[c]=i+1;
            if(l>max)
                max=l;
        }
        return max;
    }
}

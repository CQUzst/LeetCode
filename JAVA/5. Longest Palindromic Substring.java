class Solution {
    public String longestPalindrome(String s) {
        if(s.length() <= 1)
            return s;
        //以每一个字符为中心，像两边扩散来寻找回文串
        int left= 0, right= 0, len = 0, start = 0;
        for(int i = 0; i < s.length(); ++i){
            left = right = i;
            //有两个一样的right直接+1，避免奇偶分开讨论
            while(right < s.length() - 1 && s.charAt(right+1)==s.charAt(right))
                right++;
            //当前位置左边和右边相等，左减右加，一直循环，直到把当前位置的回文字符串全找完
            while(left > 0 && right < s.length()- 1 &&s.charAt(left-1) == s.charAt(right+1)){
                left--;
                right++;
            }
            if(len < right - left + 1)//更新最大长度和起点
            {
                len = right - left + 1;
                start = left;
            }
        }
        //注意 java substring二个输入参数，第一个是起始位置，第二个是终止位置
        return s.substring(start, start+len);
        
    }
}

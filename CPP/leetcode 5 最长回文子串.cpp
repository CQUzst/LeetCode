class Solution {
public:
    string longestPalindrome(string s)
    {
        //  //以每一个字符为中心，像两边扩散来寻找回文串
       // if(s.empty() || s.size() == 1)
       //      return s;
       //  int left= 0, right= 0, len = 0, start = 0;
       //  for(int i = 0; i < s.size(); ++i){
       //      left = right = i;
       //      //有两个一样的right直接+1，避免奇偶分开讨论
       //      while(right < s.size() - 1 && s[right+1] == s[right]) right++;
       //      //当前位置左边和右边相等，左减右加，一直循环，直到把当前位置的回文字符串全找完
       //      while(left > 0 && right < s.size() - 1 &&s[left-1] == s[right+1]){
       //          left--;
       //          right++;
       //      }
       //      if(len < right - left + 1)//更新最大长度和起点
       //      {
       //          len = right - left + 1;
       //          start = left;
       //      }
       //  }
       //  return s.substr(start, len);
        
        
        //DP动态规划
        //dp[i][j]表示字符串区间[i, j]是否为回文串，当i = j时，只有一个字符，肯定是回文串
        //如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]
        //如果i和j不相邻，即i - j >= 2时，除了判断s[i]和s[j]相等之外，dp[j + 1][i - 1]若为真，就是回文串
        //初始状态：dp[i][i]=1
        //状态转移方程：dp[i][i+1]=1 if str[i]==str[i+1] else dp[i][i+1]=0
        if (s.empty()||s.size()==1) 
            return s;
        int n=s.size(),len = 1,start = 0;
        int dp[n][n] = {0}; 
        for (int right = 0; right < s.size(); ++right) {
            for (int left = 0; left < right; ++left) {
                if(s[right] == s[left] && (right - left < 2 || dp[left + 1][right - 1]))//i-j<2说明只隔1个位置或者相邻
                    dp[left][right]=1;
                else 
                    dp[left][right]=0;

                if (dp[left][right] && len <= right - left + 1) {
                    start=left;
                    len = right - left + 1;
                }
            }
            dp[right][right] = 1;
        }
        return s.substr(start, len);
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1]={0};
        dp[0]=0;
        //初始化
        for(int i=1;i<=amount;i++)
            dp[i]=INT_MAX-1;
        //动态规划
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0)
					if(dp[i]>dp[i-coins[j]]+1)
						dp[i]=dp[i-coins[j]]+1;
			}
        }
        if(dp[amount]==INT_MAX-1)
            return -1;
        return dp[amount];
    }
};

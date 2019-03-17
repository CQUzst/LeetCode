class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        long dp[m][n];
        long max_num=9999;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=max_num;
            }
        }
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                int left=max_num,right=max_num,up=max_num,down=max_num;
                if(i-1>=0)
                    left=dp[i-1][j]+grid[i][j];
                if(j-1>=0)
                    up=dp[i][j-1]+grid[i][j];
                if(i+1<m)
                    right=dp[i+1][j]+grid[i][j];
                if(j+1<n)
                    down=dp[i][j+1]+grid[i][j];
                dp[i][j]=min(min(left,right),min(up,down));
            }
        }
        return dp[m-1][n-1];
    }
};

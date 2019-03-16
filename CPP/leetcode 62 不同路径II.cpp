class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        long dp[m][n];//注意：测试用例里面有大于int的值，坑
        for(int i=0;i<m;i++)
           for(int j=0;j<n;j++)
               dp[i][j]=0;
        //第一行障碍处理
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]!=1)
                dp[0][i]=1;
            else
                break;
        }
        //第一列障碍处理
        for(int j=0;j<m;j++){
            if(obstacleGrid[j][0]!=1)
                dp[j][0]=1;
            else
                break;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)   //如果该位置是障碍，则到达该点的路径条数为0
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }      
        return dp[m-1][n-1];
    }
};


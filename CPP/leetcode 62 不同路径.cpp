//递归：超时
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int res=0;
//         res=recursion(1,1,m,n);
//         return res;
//     }
//     int recursion(int row,int col,int m,int n){
//         if(row==m&&col==n){
//             return 1;
//         }
//         if(row==m)
//             return recursion(row,col+1,m,n);
//         if(col==n)
//             return recursion(row+1,col,m,n);
//         return recursion(row+1,col,m,n)+recursion(row,col+1,m,n);
//     }
// };

//动态规划
//重点条件：只能向下或者向右移动一步
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};

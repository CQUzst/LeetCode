#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*dp[i][j]表示以i,j为右下角的正方形的最大边长
dp[i][j]更新考虑下列情况：
    1.i,j位置本身为‘0’，直接置0
    2.最好的情况是是它的上方，左方和左上方为右下角的正方形的大小一样，
    这样加上该点就可以构成一个更大的正方形
    3.但如果它的上方，左方和左上方为右下角的正方形的大小不一样，合起来就会缺了某个角落，
    这时候只能取那三个正方形中最小的正方形的边长加1了
    即：i，j最多比它的上方/左方/左上方为右下角的正方形的边长多1，三者取最小，然后+1
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //先初始化dp左边和上边的边界
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix;
    vector<char> v1{'1','0','1','0','0'};
    vector<char> v2{'1','0','1','1','1'};
    vector<char> v3{'1','1','1','1','1'};
    vector<char> v4{'1','0','0','1','0'};
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    int area=s.maximalSquare(matrix);
    cout<<area<<endl;
    return 0;
}

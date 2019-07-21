class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        vector<int> dp(matrix[0].size(),0);//dp用于记录以某一层为底，与之前的所有上层可以形成的连续高度
        int maxArea = 0;
        /*
        循环中调用amxRectangleArea()算法，
        用于找到在一层中结点matrix[i][j]完整包含dp[j]高度的最大宽度
        面积就等于找到的长 * 宽
        */
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                dp[j] = (matrix[i][j]=='1') ? dp[j]+1 : 0;
            }
            maxArea=max(maxArea,maxRectangleArea(dp));
        }
        return maxArea;
    }
private:
    //84.柱状图中最大的矩形 的代码，
    //用于找到nums中完整包含当前高度的最长宽度
    int maxRectangleArea(vector<int> &nums){
        int maxArea = 0;
        for(int i=0;i<nums.size();++i){
            if(i+1<nums.size()&&nums[i]<nums[i+1]){
                continue;
            }
            int minH=nums[i];//当前位置最高了
            for(int j=i;j>=0;j--){
                minH=min(minH,nums[j]);
                int area=minH*(i-j+1);
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
};

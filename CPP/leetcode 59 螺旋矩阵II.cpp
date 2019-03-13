class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int count=1;
        int left=0,top=0,right=n-1,bottom=n-1;
        while(count<=n*n)//一次遍历四条边界，缩小边界，中间穿插判断
        {
            for(int i=left;i<=right;i++)//上边界
            {
                res[top][i] = count;
                count++;
            }
            if(++top>bottom)break;
            for(int i=top;i<=bottom;i++)//右边界
            {
                res[i][right] = count;
                count++;
            }
            if(--right<left)break;
            for(int i=right;i>=left;i--)//下边界
            {
                res[bottom][i]=count;
                count++;
            }
            if(--bottom<top)break;
            for(int i=bottom;i>=top;i--)//左边界
            {
                res[i][left]=count;
                count++;
            }
            if(++left>right)break;
        }
        return res;
    }
};

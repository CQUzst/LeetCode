class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // int m = matrix.size(), n = matrix[0].size();
        // vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};//四个方向
        // queue<pair<int, int>> q;//建立一个队列
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (matrix[i][j] == 0) 
        //             q.push({i, j});//将矩阵里的0都压入队列中
        //         else 
        //             matrix[i][j] = INT_MAX;//非0元素置MAX，准备从边缘往内部+1递增
        //     }
        // }
        // while (!q.empty()) {
        //     auto t = q.front(); q.pop();//每次取队列里的0元素为t，弹出
        //     for (auto dir : dirs) {//遍历4个方向
        //         int x = t.first + dir[0], y = t.second + dir[1];
        //         if (x < 0 || x >= m || y < 0 || y >= n ||
        //         matrix[x][y] <= matrix[t.first][t.second]) //如果四周越界或者四周的数小于等于t，跳过
        //             continue;
        //         matrix[x][y] = matrix[t.first][t.second] + 1;//比t大的数修改为t+1，将q压入队列
        //         q.push({x, y});
        //     }
        // }
        // return matrix;
        int m= matrix.size(),n = matrix[0].size();
        vector<vector<int>> res(m,vector<int>(n,INT_MAX-2));
        for(int i=0;i<m;i++)//从左上到右下递增+1
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                    res[i][j] = 0;
                else{
                    if(i>0)  
                        res[i][j] = min(res[i][j],res[i-1][j]+1);
                    if(j>0) 
                        res[i][j] = min(res[i][j],res[i][j-1]+1);
                }
                
            }
        for(int i=m-1;i>=0;--i)//从右下到左上递增+1
            for(int j=n-1;j>=0;--j){
                if(res[i][j]!=0&&res[i][j]!=1){
                    if(i<m-1)  
                        res[i][j] = min(res[i][j],res[i+1][j]+1);
                    if(j<n-1) 
                        res[i][j] = min(res[i][j],res[i][j+1]+1);
                }
                
            }
        return res;
    }
};

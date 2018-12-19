//给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
//一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
//你可以假设网格的四个边均被水包围.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
//         if(grid.empty()||grid[0].empty())return 0;
//         int m=grid.size(),n=grid[0].size(),res=0;
//         vector<vector<bool>>visited(m,vector<bool>(n,false));
//         for(size_t i=0;i<m;i++){
//             for(size_t j=0;j<n;j++){
//                 if(grid[i][j]=='1'&&!visited[i][j]){
//                     islandBFS(grid,visited,i,j);
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// private:
//     void islandBFS(vector<vector<char>> &grid,
//                    vector<vector<bool>> &visited,int x,int y){
//         if(x<0||x>=grid.size()) return;
//         if(y<0||y>=grid[0].size()) return;
//         if(grid[x][y]!='1'||visited[x][y]) return;
//         visited[x][y]=true;
//         islandBFS(grid,visited,x-1,y);
//         islandBFS(grid,visited,x+1,y);
//         islandBFS(grid,visited,x,y-1);
//         islandBFS(grid,visited,x,y+1);
        if(grid.empty()||grid[0].empty())return 0;
        int m=grid.size(),n=grid[0].size(),res=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&visited[i][j]==false){
                    DFS(grid,visited,i,j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void DFS(vector<vector<char>>&grid,vector<vector<bool>> &visited,int x,int y){
        if(x<0||x>=grid.size())return;
        if(y<0||y>=grid[0].size())return;
        if(grid[x][y]!='1'||visited[x][y])return;
        visited[x][y]=true;
        DFS(grid,visited,x-1,y);
        DFS(grid,visited,x+1,y);
        DFS(grid,visited,x,y-1);
        DFS(grid,visited,x,y+1);
    }    
};

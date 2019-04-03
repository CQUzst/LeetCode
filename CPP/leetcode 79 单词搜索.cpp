class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m = 0, n = 0;
    
public:
    bool exist(vector<vector<char>> &board, string word) {
        int index = 0;
        m = board.size();
        if (m == 0) return word.empty();
        n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    vis[i][j] = true;
                    bool ans = dfs(board, 1, word, i, j, vis);
                    vis[i][j] = false;//递归后保护现场
                    if (ans) return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, int index, string &word, int cur_x, int cur_y, vector<vector<bool>> &vis) 
    {
        if (index >= word.length()) 
            return true;
        for (int i = 0; i < 4; i++) 
        {
            int x = cur_x + dx[i];
            int y = cur_y + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n) 
            {
                if (word[index] == board[x][y] && !vis[x][y]) //这一步相当于剪枝
                {
                    vis[x][y] = true;
                    bool ans = dfs(board, index + 1, word, x, y, vis);
                    vis[x][y] = false;
                    if (ans) return true;
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         if(board.empty() || word.empty()) return false;
//         int row = board.size(), col = board[0].size();
//         vector<vector<int>> f(row, vector<int>(col,0));
//         for(int i = 0;i<row;i++){
//             for(int j = 0;j<col;j++){
//                 if(dfs(board,word,0,i,j,f)) return true;
//             }
//         }
//         return false;
//     }
//     bool dfs (vector<vector<char>>& board, string& word, int size, int x, int y, vector<vector<int>>& f){
//         if(size ==  word.size()) return true;
//         if(x<0 || x>=board.size() || y<0 ||y>=board[0].size()||board[x][y] != word[size]) return false;
//         if(f[x][y] == 0){
//             f[x][y] = 1;
//             if(dfs(board,word,size+1,x-1,y,f)
//                || dfs(board,word,size+1,x,y+1,f)
//                || dfs(board,word,size+1,x+1,y,f)
//                || dfs(board,word,size+1,x,y-1,f)){
//                 return true;
//             }
//             f[x][y] = 0;
//         }
//         return false;
//     }
// };

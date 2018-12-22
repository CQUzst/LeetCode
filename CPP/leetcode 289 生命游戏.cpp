class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size(),cols=board[0].size();
        if(rows==0||cols==0)
            return;
        //0到1 复活设为3，1到0 死亡设为2
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                int neighbors=getNeighbors(board,i,j);
                if(neighbors==2)//邻居为2，cell状态保持到下一代
                    continue;
                else if(neighbors==3)//3个邻居，如果cell为0，复活为3，为1 还是1
                    board[i][j]=board[i][j]==0?3:1;
                else //邻居太少或者太多，1变死亡，为0还是0
                    board[i][j]=board[i][j]==1?2:0;

            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                board[i][j]=board[i][j]%2;
            }
        }
        return;
    }
private:
    int getNeighbors(vector<vector<int>>& board,int x,int y){
        int sum=0;
        for(int i=x-1;i<x+2;i++){
            for(int j=y-1;j<y+2;j++){
                if(i==x&&j==y)
                    continue;
                if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&(board[i][j]==1||board[i][j]==2))
                    sum++;
            }
        }
        return sum;
    }
};

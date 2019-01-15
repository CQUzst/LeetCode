class Solution {
public:
    int totalNQueens(int n) {
		int res = 0;
		vector<int> pos(n, -1);
		solveNQueens(res, pos, 0);
		return res;
	}
	void solveNQueens(int& res, vector<int>& pos, int row){
		int n = pos.size();
		if (row == n)
			++res;
		else{
			for(int col=0;col<n;++col)
				if (isValid(pos, row, col))
				{
					pos[row] = col;
					solveNQueens(res, pos, row + 1);
					pos[row] = -1;
				}
		}
	}
	bool isValid(vector<int>& pos, int row, int col){
		for (int i = 0; i < row; ++i)
			if (col == pos[i] || abs(row - i) == abs(col - pos[i]))
				return false;
		return true;
	}
};
//思路：从左下角开始比较
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=array.size();
        int col=array[0].size();
        int i=row-1,j=0;
        while(i>=0&&j<col){
            if(array[i][j]==target)
                return true;
            else if(array[i][j]<target)
                j++;
            else if(array[i][j]>target)
                i--;
        }
        return false;
    }
};

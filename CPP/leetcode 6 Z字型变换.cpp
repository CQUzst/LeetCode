class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) 
            return s;
        string res = "";
        int lenth=s.size();
        int size = 2 * nRows - 2;//首位两行中相邻两个元素的index之差跟行数是相关的，为2*nRows-2
        
        for (int i = 0; i < nRows; ++i) //遍历所有行
        {
            for (int j = i; j < lenth; j += size)
            {
                res += s[j];
                int tmp = j + size - 2 * i;//第i行的相邻两个元素之间的位置差
                if (i != 0 && i != nRows - 1 && tmp < lenth) //第i行的除了首位的字母的所有中间字母
                    res += s[tmp];
            }
        }
        return res;
    }
};
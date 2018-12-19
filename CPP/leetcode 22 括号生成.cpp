class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out="";
        generateParenthesisDFS(n, n, out, res);
        return res;
    }
    //定义两个变量left和right分别表示剩余左右括号的个数,string out表示一个结果
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) 
    {
        if (left > right) //生成的字符串中右括号的个数大于左括号的个数，即会出现')('这样的非法串，所以这种情况直接返回
            return;
        if (left == 0 && right == 0) //如果left和right都为0，则说明此时所有括号都用完了，则存入结果中后返回
            res.push_back(out);
        else 
        {
            if (left > 0) 
                generateParenthesisDFS(left - 1, right, out + '(', res);//递归实现从开始左括号为3,2,1个等情况
            if (right > 0) 
                generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};
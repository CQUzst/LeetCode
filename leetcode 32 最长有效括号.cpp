class Solution {
public:
	int longestValidParentheses(string s) {
        //堆栈方法
		int res = 0, start = 0;
		stack<int> m;//m存放位置下标i
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') //如果遇到左括号，则将当前下标压入栈
				m.push(i);
			else if (s[i] == ')') {
				if (m.empty()) //如果遇到右括号，如果当前栈为空，则将下一个坐标位置记录到start
					start = i + 1;
				else {
					m.pop();//如果栈不为空，必有栈顶为左括号，将栈顶元素取出
					if (m.empty())//若此时栈为空，则更新结果和i - start + 1中的较大值
						res = max(res, i - start + 1);
					else//否则更新结果和i - 栈顶元素中的较大值
						res= max(res, i - m.top());
				}
			}
		}
		return res;

	}
};
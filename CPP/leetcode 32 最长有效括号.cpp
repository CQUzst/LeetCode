class Solution {
public:
	int longestValidParentheses(string s) {
        //堆栈方法
		int res = 0, start = 0;//start为第一个遇到的左括号，后面可能更新
		stack<int> m;//m存放位置下标i
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') //如果遇到左括号，则将当前下标压入栈
				m.push(i);
			else if (s[i] == ')') //遇到右括号
            {
				if (m.empty()) //如果当前栈为空，说明前面没有左括号，移动start，将下一个坐标位置记录到start
					start = i + 1;
				else {
					m.pop();//如果栈不为空，必有栈顶为左括号，将栈顶元素取出
					if (m.empty())//若此时栈为空，说明这是最左边的括号了，更新结果，i - start + 1
						res = max(res, i - start + 1);
					else//栈不为空，说明左边还有括号，这次括号是嵌套在内部的括号，右边可能没有右括号了，所以也可能是最大的，更新结果为此次内部括号的长度，栈顶元素即此次括号外的左括号（此次括号的左括号已经弹出了），距离：i - 栈顶元素
						res= max(res, i - m.top());
				}
			}
		}
		return res;

	}
};
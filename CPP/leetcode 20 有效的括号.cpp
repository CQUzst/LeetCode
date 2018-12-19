class Solution {
public:
    bool isValid(string s) 
    {
        if(s.empty()) return true;//首先判断字符串是否为空，如果为空，直接认为是有效字符串，返回true
        stack<char> sta;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')//如果是左括号，就打入栈中
                sta.push(s[i]);
            else if(sta.empty())//如果是右括号，判断栈是否为空，为空则返回false
                return false;
            else if((s[i] == ')' && sta.top()=='(') ||(s[i] == ']' && sta.top()=='[')||(s[i] == '}' && sta.top()=='{'))//再判断栈顶是不是对应的左括号，如果是，则将栈顶的元素出栈
                sta.pop();
            else//如果不是，则返回false
                return false;
        }
            return sta.empty();
    }
};
class Solution {
//     stack <string> st;
// private:
//     void calc(stack <string> &st,string token){
//         string num1=st.top();st.pop();
//         string num2=st.top();st.pop();
//         string temp;
//         int b = atoi(num1.c_str());
//         int a = atoi(num2.c_str());
//         if(token=="+")
//             temp=to_string(a+b);
//         else if(token=="-")
//             temp=to_string(a-b);
//         else if(token=="*")
//             temp=to_string(a*b);
//         else if(token=="/")
//             temp=to_string(a/b);
//         st.push(temp);
//     }
// public:
//     int evalRPN(vector<string>& tokens) {
//         int res=0;
//         for(size_t i=0;i<tokens.size();i++){
//             if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
//                 calc(st,tokens[i]);
//             else
//                 st.push(tokens[i]);
//         }
//         //cout<<st.top()<<endl;
//         res=atoi(st.top().c_str());
//         return res;
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for(string token : tokens)
        {
            if(token == "+")
            {
                int b = result.top();
                result.pop();
                result.top() += b;
            }
            else if(token == "-")
            {
                int b = result.top();
                result.pop();
                result.top() -= b;
            }
            else if(token == "*")
            {
                int b = result.top();
                result.pop();
                result.top() *= b;
            }
            else if(token == "/")
            {
                int b = result.top();
                result.pop();
                result.top() /= b;
            }
            else
                result.push(stoi(token));
        }
        return result.top();
    }
};
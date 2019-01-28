class MyStack {
private:
    queue<int> q1,q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        //q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q2.size()==1){
            int res=q2.back();
            q2.pop();
            return res;
        }
            
        while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
        int res=q2.front();
        q2.pop();//q2的前面几个都复制到q1，q2的最后一个弹出
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }
        return res; 
        
    }
    
    /** Get the top element. */
    int top() {
        return q2.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
class MyQueue {
private:
    stack<int> s1, s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        ;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        //先将s2内容复制到s1，清空，然后添加x到栈顶（队列头部），再把s1的内容复制到s2后面
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(x);
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a = s2.top();
        s2.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
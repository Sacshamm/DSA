class MyQueue {
public:
    stack<int>ip,op;
    MyQueue() {
        
    }
    
    void push(int x) {
       ip.push(x); 
    }
    
    int pop() {
        int ans;
        if(!op.empty()) {
            ans = op.top();
            op.pop();
        }
        else{
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
            ans = op.top();
            op.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans;
        if(!op.empty()) {
            ans = op.top();
        }
        else{
            while(!ip.empty()){
                op.push(ip.top());
                ip.pop();
            }
            ans = op.top();
        }
        return ans;
    }
    
    bool empty() {
        if(ip.empty() && op.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

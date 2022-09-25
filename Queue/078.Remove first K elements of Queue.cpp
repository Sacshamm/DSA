queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>st;
    
    //push first k elements into stack
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        st.push(val);
    }
    //now pop from stack in reversed order and push_back into queue
    while(!st.empty()){
        int val=st.top();
        st.pop();
        q.push(val);
    }
    
    //now remove the remaining elemts from front and push them at back of orignal queue
    int rem= q.size()-k;
    while(rem){
        int val=q.front();
        q.pop();
        q.push(val);
        rem--;
    }
    return q;
    
}

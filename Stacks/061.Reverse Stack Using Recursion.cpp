
//[1 2 3   to 3 2 1 

void insertAtBottom(stack<int> &stack,int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }
    int num=stack.top();
    stack.pop();
    insertAtBottom(stack , x);
    stack.push(num);
    
}

void reverseStack(stack<int> &stack) {
    // REACH TILL BOTTOM
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}
// firstly reverse() call will execute until stack gets empty and have 1 2 3 in its stack space
//After that insertAtBottom() call will execute with 1 as top 
//bottom function will again pop until stack gets empty and at last insert 1 then return with 2 aand then 3
//top became 3

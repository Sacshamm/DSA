void solve(stack<int>& mystack, int x){
    if(mystack.empty()){
       mystack.push(x);//pushing x when stack is empty
        return;
    }
    //simply poping until stack gets empty.
    int ele=mystack.top();//storing top 
    mystack.pop();//poping that stored element
    solve(mystack,x);//callling function again
    mystack.push(ele);//pushing the popped element while returning
}

stack<int> pushAtBottom(stack<int>& mystack, int x) 
{
    solve ( mystack, x);
    return mystack;
}

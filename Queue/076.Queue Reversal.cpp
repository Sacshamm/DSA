
//Recursive approach
// void  fun(queue<int> &q){
//     if(q.empty())
//         return ;
    
//     int num = q.front();
//     q.pop();
    
//     fun(q);
//     q.push(num);
// }
// queue<int> rev(queue<int> q)
// {
//     fun(q);
//     return q;
// }



//iterative using stack
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> st;
    while(!q.empty()){
        int val=q.front();
        st.push(val);
        q.pop();
    }
    
    while(!st.empty()){
        int val=st.top();
        q.push(val);
        st.pop();
    }
    
    return q;
}

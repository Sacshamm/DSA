/*Let num = 6
    |9|
  -------
    |5|
    |2|
when 5(which is s.top())<6 then push 6
*/




void sorted(stack<int> &s, int num){
    if(s.empty() || (!s.empty()) && s.top()<num){// checking either if stack is empty then push. Or before checking s.top() with num is our stack is not empty
        s.push(num);
        return;
    }
    
    int temp=s.top();
    s.pop();
    sorted(s,num);//recursive call
    s.push(temp);
}

void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   int num=s.top();
   s.pop();
   
   sort();//recursive call 
   
   sorted(s,num);
}

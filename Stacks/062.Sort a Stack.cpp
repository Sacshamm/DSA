void sorted(stack<int> &s, int num){
    if(s.empty() || (!s.empty()) && s.top()<num){
        s.push(num);
        return;
    }
    
    int temp=s.top();
    s.pop();
    sorted(s,num);
    s.push(temp);
}

void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   int num=s.top();
   s.pop();
   
   sort();
   
   sorted(s,num);
}

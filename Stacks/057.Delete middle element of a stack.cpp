class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int size, int count){
        if(count==size/2){
            s.pop();
            return;
        }
        int ans=s.top();
        s.pop();
        solve(s,size,count+1);
        s.push(ans);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack){
        int count =0;
        solve(s,sizeOfStack,count);
    }
    
    
    
    
    // void deleteMid(stack<int>&s, int sizeOfStack){
    //   vector<int>v;
    //   int c=0;
    //   for(int i=0;i<sizeOfStack/2;i++)
    //   {
    //       v.push_back(s.top());
    //       s.pop();
    //       c++;
    //   }
    //   s.pop();
    //   for(int i=c-1;i>=0;i--)
    //   {
    //       s.push(v[i]);
    //   }
    //   s.top();
    //   }
};

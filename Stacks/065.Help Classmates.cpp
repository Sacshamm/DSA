class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>st;
        st.push(-1);
        vector<int>v(n);
        
        for(int i=n-1; i>=0;i--){
            int curr = arr[i];
            while(curr<=st.top()){
                st.pop();
            }
            v[i]=st.top();
            st.push(curr);
        }
        return v;
    } 
};

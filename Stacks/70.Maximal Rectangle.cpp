class Solution {
    private:
    int largestRectangleArea(vector<int> &heights) {
    int maxArea = 0;
        int n = heights.size();
        int left[n], right[n];
        stack<int>st;
        
        // searching for left smaller element than i
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>= heights[i]) {
                st.pop();
            }
            
              if(st.empty()) left[i]=0;
              else left[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // searching for right smaller element than i
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            
              if(st.empty()) right[i]=n-1;
              else right[i]=st.top()-1;
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            maxArea= max(maxArea , (right[i]-left[i]+1)*heights[i]);
        }
        return maxArea;
}
public:
   int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()){
        return 0;
    }
    int maxRec = 0;
       //compute area of 1st row
    vector<int> heights(matrix[0].size());
       
       //traversing matrix
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == '0')
                heights[j] = 0;    
            else
                heights[j]++;  //if val is 1 increment it by 1    
        }
        maxRec = max(maxRec, largestRectangleArea(heights));//passing the updated/incremented row again to function
    }
    return maxRec;
}

};
